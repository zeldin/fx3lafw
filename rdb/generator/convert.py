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

# This register definition is mysteriously absent from the TRM, even though
# it refers to it from other places...
missing = [
    ('gctl', 'GCTL_CONTROL', 'Global control', '0xE0050000',
     [('31', 'HARD_RESET_N'), ('30', 'CPU_RESET_N'), ('29', 'WARM_BOOT'),
      ('28', 'BOOTROM_EN'), ('26', 'MAIN_POWER_EN'), ('25', 'MAIN_CLOCK_EN'),
      ('24', 'FREEZE_IO'), ('22', 'USB_VBAT_EN'), ('21', 'USB_POWER_EN'),
      ('18', 'ANALOG_SWITCH'), ('17:16', 'WDT_PROTECT[1:0]'),
      ('15', 'NO_SBYWFI'), ('14', 'SYSMEM_BIST_EN'), ('12', 'WAKEUP_CPU_INT'),
      ('11', 'WAKEUP_AP_INT'), ('10', 'RAM_SLEEP'), ('9', 'DEBUG_MODE'),
      ('8', 'BOOT_COMPLETE'), ('4', 'WAKEUP_CLK'), ('3', 'WAKEUP_PWR'),
      ('2', 'WDT_RESET'), ('1', 'SW_RESET'), ('0', 'POR')]),

# More missing regs...
    ('uib', 'PROT_LMP_PORT_CAPABILITY_TIMER', 'Capability Timer Register', '0xE0033418', []),
    ('uib', 'PROT_LMP_PORT_CONFIGURATION_TIMER', 'Configuration Timer Register', '0xE003341C', []),
    ('uib', 'PROT_LMP_RECEIVED', 'Received Register', '0xE003345C', []),
    ('uib', 'PROT_STREAM_ERROR_DISABLE', 'Stream Error Disable Register', '0xE0033700', []),
    ('uib', 'PROT_STREAM_ERROR_STATUS', 'Stream Error Status Register', '0xE0033704', []),
    ('gpif', 'GPIF_SERIAL_IN_CONFIG', 'Serial Input Configuration Register', '0XE001401C', []),
    ('gpif', 'GPIF_SERIAL_OUT_CONFIG', 'Serial Output Configuration Register', '0XE0014020', []),
]

# Missing register fields
missing_fields = {
    'LNK_LTSSM_STATE' : [('11:6', 'LTSSM_OVERRIDE_VALUE[5:0]'),
                         ('12', 'LTSSM_OVERRIDE_EN'),
                         ('13', 'LTSSM_OVERRIDE_GO'),
                         ('14', 'LOOPBACK_MASTER'),
                         ('15', 'DISABLE_SCRAMBLING'),
                         ('16', 'LOOPBACK_ERROR'),
                         ('17', 'LOOPBACK_GOOD'),
                         ('31', 'LTSSM_FREEZE')],
}

# Fixes for typos in TRM
reg_name_fixups = {
    '0xE0000BF0': ('I2C_ID', 'UART_ID'),
    '0xE003151C': ('DEV_CTRL_INTR_MASK', 'DEV_CTRL_INTR'),
    '0xE003205C': ('OHCI_RH_PORT_STATUS', 'EHCI_HCCPARAMS'),
    '0xE0032060': ('OHCI_RH_PORT_STATUS', 'EHCI_USBCMD'),
    '0x00': ('SCK_INTR', 'SCK_INTR0'),
}
reg_addr_fixups = {
    'OHCI_REVISION': ('0xE0032010', '0xE0032024'),
}
field_name_fixups = {
    'OTG_CTRL': {'11': ('B_SESS_VALID', 'B_END_SESS')},
}
field_bits_fixups = {
    'GPIF_ADDR_COUNT_CONFIG': {'INCREMENT': ('7:0', '15:8')},
    'GPIF_DATA_COUNT_CONFIG': {'INCREMENT': ('7:0', '15:8')},
}

class Register:
    rdb_prefix='FX3_'
    pad_size=34
    pad_size_field=45
    
    def __init__(self, group, name, description, address, fields):
        try:
            fixup = reg_name_fixups[address]
            if name == fixup[0]:
                name = fixup[1]
        except KeyError:
            pass
        try:
            fixup = reg_addr_fixups[name]
            if address == fixup[0]:
                address = fixup[1]
        except KeyError:
            pass
        try:
            fields += missing_fields[name]
        except KeyError:
            pass

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
                name = field[1].replace('{','[').split('[')
                try:
                    fixup = field_name_fixups[self.name][field[0]]
                    if name[0] == fixup[0]:
                        name[0] = fixup[1]
                except KeyError:
                    pass
                try:
                    fixup = field_bits_fixups[self.name][name[0]]
                    if field[0] == fixup[0]:
                        bits = fixup[1].split(':')
                except KeyError:
                    pass
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

    def getfont(self, id, bold, italic):
        fontname = id and self.fonts[id]
        if bold and fontname:
            fontname = '*'+fontname
        if italic and fontname:
            fontname = '~'+fontname
        return fontname

class RegDefParser:
    reg_detail_font = '*Times/9'
    reg_detail_alt_font = 'Times/9'
    reg_detail_superscript_font = '*Times/7'

    def __init__(self, group):
        self.group = group
        self.details = []
        self.detail = []
        self.info = []
        self.combine = False
        self.fontsel = False

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

    def feedtext(self, font, text, leftcol):
        if text.strip() == '':
            pass
        elif font == self.reg_detail_font or (leftcol and not self.fontsel and font == self.reg_detail_alt_font):
            if self.combine:
                self.detail[-1] = self.detail[-1] + text
                self.combine = False
            else:
                self.detail.append(text)
            if font == self.reg_detail_font:
                self.fontsel = True
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

    def feedtext(self, font, text, left):
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
            self.register.feedtext(font, text, left < 250)

    def add_missing(self, group, name, *rest):
        if next((r for r in self.registers[group] if r.name == name), False):
            pass
        else:
            self.registers[group].append(Register(group, name, *rest))

fontdb = FontDatabase()
finder = RegDefFinder()

file = open('trm.xml', 'r')

for event, elem in ElementTree.iterparse(file):
    if elem.tag == 'text':
        finder.feedtext(fontdb.getfont(elem.get('font'), elem.find('b') != None, elem.find('i') != None),
                        ''.join(elem.itertext()), int(elem.get('left')))
    elif elem.tag == 'fontspec':
        fontdb.addfont(**elem.attrib)
    elif elem.tag == 'page':
        elem.clear()  # save memory

file.close()
finder.flush()
for m in missing:
    finder.add_missing(*m)

for group, registers in finder.registers.items():
    if group != 'dma':
        registers = sorted(registers, key=lambda r: int(r.address.replace('?', 'F'), 16))
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

