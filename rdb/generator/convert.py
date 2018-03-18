#!/usr/bin/env python3

import sys
import xml.etree.ElementTree as ElementTree

boilerplate = '''\
/*
 * Copyright (C) 2018 Marcus Comstedt
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

'''

ppguard_prefix = 'RDB_'

class Register:
    rdb_prefix='FX3_'
    pad_size=30
    pad_size_field=45
    
    def __init__(self, group, name, description, address, fields):
        # Fix for typo in TRM
        if group == 'uart' and name == 'I2C_ID':
            name = 'UART_ID'

        self.group = group
        self.name = name
        self.description = description
        self.address = address
        self.fields = fields

    def print_reg_def(self, file):
        file.write('#define %s%s%s%s /* %s */\n' % (self.rdb_prefix, self.name, ' '*(self.pad_size - len(self.name)), self.address, self.description))

    def print_field_defs(self, file):
        if self.fields and (len(self.fields)>1 or (self.fields[0][0] != '0:31' and self.fields[0][0] != '31:0')):
            file.write('\n')
            for field in self.fields:
                bits = field[0].split(':')
                name = field[1].split('[')
                if len(bits) == 1 and len(name) == 2 and (name[0] == 'EN_GPIO' or name[0] == 'EV_GPIO' or name[0] == 'POL_GPIO'):
                    name = [name[0]+'_'+name[1].split(']')[0]]
                pad_size = self.pad_size_field
                while pad_size <= len(self.name+'_'+name[0]+'_SHIFT'):
                    pad_size = pad_size + 1
                if len(bits)>1:
                    lsb = int(bits[0])
                    msb = int(bits[1])
                    if lsb > msb:
                        (lsb, msb) = (msb, lsb)
                    if len(name) > 1:
                        name_range = name[1].split(']')[0].split(':')
                        nmsb = int(name_range[0])
                        nlsb = int(name_range[1])
                        if nmsb-nlsb != msb-lsb:
                            print('Field size mismatch!  %s != %s (%s %s)'%(nmsb-nlsb+1, msb-lsb+1, self.name, name[0]))
                            if nmsb == msb and nlsb == 0:
                                lsb = 0
                    file.write('#define %s%s_%s_SHIFT%s%s\n' % (self.rdb_prefix, self.name, name[0], ' '*(pad_size - len(self.name+'_'+name[0]+'_SHIFT')), lsb))
                    file.write('#define %s%s_%s_BITS%s%s\n' % (self.rdb_prefix, self.name, name[0], ' '*(pad_size - len(self.name+'_'+name[0]+'_BITS')), msb-lsb+1))
                    file.write('#define %s%s_%s_MASK%s(%sUL << %s)\n' % (self.rdb_prefix, self.name, name[0], ' '*(pad_size - len(self.name+'_'+name[0]+'_MASK')), hex((1<<(msb-lsb+1))-1), lsb))
                else:
                    file.write('#define %s%s_%s%s(1UL << %s)\n' % (self.rdb_prefix, self.name, name[0], ' '*(pad_size - len(self.name+'_'+name[0])), bits[0]))

class FontDatabase:
    def __init__(self):
        self.fonts = {}

    def addfont(self, id, size, family, color, **extra):
        if color == '#000000':
            color = ''
        self.fonts[id] = family+'/'+size+color

    def getfont(self, id, bold):
        fontname = id and self.fonts[id]
        if bold and fontname:
            fontname = '*'+fontname
        return fontname

class RegDefParser:
    reg_detail_font = '*Times/9'
    reg_detail_superscript_font = '*Times/7'
    
    def __init__(self, group):
        self.group = group
        self.details = []
        self.detail = []
        self.info = []
        self.combine = False

    def flush(self):
        if self.detail:
            if len(self.detail) == 1:
                pass
            elif self.info and len(self.detail) == 2 and self.detail[0] == self.info[0]:
                pass
            elif len(self.detail) == 2 and '0123456789'.find(self.detail[0][:1]) < 0:
                pass
            elif len(self.detail) == 3:
                if self.info:
                    sys.exit('Multiple info candidates! %s %s'%(self.info, self.detail))
                else:
                    self.info = self.detail
            else:
                self.details.append(self.detail)
            self.detail = []
            self.combine = False

    def feedtext(self, font, text):
        if text.strip() == '':
            pass
        elif font == self.reg_detail_font:
            if self.combine:
                self.detail[-1] = self.detail[-1] + text
                self.combine = False
            else:
                self.detail.append(text)
        elif font == self.reg_detail_superscript_font and self.detail:
            if text == '2':
                text = '²'
            else:
                sys.exit('Unable to handle superscript text: %s' % text)
            self.detail[-1] = self.detail[-1] + text
            self.combine = True
        else:
            self.flush()

    def finalize(self):
        self.flush()
        if not self.details and not self.info:
            return None
        if self.info:
            return Register(self.group, *self.info, fields=self.details)
        else:
            sys.exit('Incomplete register details')
            return None

class RegDefFinder:
    chapter_font = 'Times/34#fbfbfb'
    heading_font = '*Times/18'
    register_chapter = '10'
    register_sections = {
        '3': 'vic',
        '4': 'gctl',
        '5': 'gctl',
        '6': 'pib',
        '7': 'gpif',
        '8': 'pport',
        '9': 'uib',
        '10': 'uib',
        '11': 'uib',
        '12': 'uib',
        '13': 'uib',
        '14': 'uib',
        '15': 'uib',
        '16': 'uib',
        '17': 'uibin',
        '18': 'i2s',
        '19': 'i2c',
        '20': 'uart',
        '21': 'spi',
        '22': 'gpio',
        '23': 'gpio',
        '24': 'lpp',
        '25': 'dma',
        '26': 'dma'
    }

    def __init__(self):
        self.chapter_number = None
        self.section = None
        self.register = None
        self.registers = {group: [] for group in self.register_sections.values()}

    def flush(self):
        if self.register:
            reg = self.register.finalize()
            if reg:
                self.registers[reg.group].append(reg)
        self.register = None

    def feedtext(self, font, text):
        if font == self.chapter_font:
            self.chapter_number = text.split('.')[0]
            self.section = None
        elif self.chapter_number != self.register_chapter:
            pass
        elif font == self.heading_font:
            if text.startswith(self.register_chapter+'.'):
                section = text.split()[0]
                if section != self.section:
                    self.flush()
                    self.section = section
                    secnr = section.split('.')
                    if len(secnr) == 3:
                        self.register = RegDefParser(self.register_sections[secnr[1]])
        elif self.register:
            self.register.feedtext(font, text)

fontdb = FontDatabase()
finder = RegDefFinder()

file = open('trm.xml', 'r')

for event, elem in ElementTree.iterparse(file):
    if elem.tag == 'text':
        finder.feedtext(fontdb.getfont(elem.get('font'), elem.find('b') != None), ''.join(elem.itertext()))
    elif elem.tag == 'fontspec':
        fontdb.addfont(**elem.attrib)
    elif elem.tag == 'page':
        elem.clear()  # save memory

file.close()
finder.flush()

for group, registers in finder.registers.items():
    ppguard = '%s%s_H_' % (ppguard_prefix, group.upper())
    file = open('%s.h' % group, 'w')
    file.write(boilerplate)
    file.write('#ifndef %s\n#define %s\n\n' % (ppguard, ppguard))
    for reg in registers:
        reg.print_reg_def(file)
    for reg in registers:
        reg.print_field_defs(file)
    file.write('\n#endif /* %s */\n' % ppguard)
    file.close()

