#!/usr/bin/env python3

# Copyright (C) 2018 Marcus Comstedt
# 
# Permission is hereby granted, free of charge, to any person obtaining
# a copy of this software and associated documentation files (the
# "Software"), to deal in the Software without restriction, including
# without limitation the rights to use, copy, modify, merge, publish,
# distribute, sublicense, and/or sell copies of the Software, and to
# permit persons to whom the Software is furnished to do so, subject to
# the following conditions:
# 
# The above copyright notice and this permission notice shall be
# included in all copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
# IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
# CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
# TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
# SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

import sys
import struct

class elf:

    def read_struct(this, struct_fmt, struct_fields):
        fmt = this.elf_endianprefix+str.translate(struct_fmt, this.elf_format);
        fields = struct.unpack(fmt, this.file.read(struct.calcsize(fmt)))
        return dict(zip(struct_fields, fields))

    def read_ehdr(this):
        return this.read_struct('16sHHWNNNWHHHHHH',
                                ('e_ident', 'e_type', 'e_machine', 'e_version',
                                 'e_entry', 'e_phoff', 'e_shoff', 'e_flags',
                                 'e_ehsize', 'e_phentsize', 'e_phnum',
                                 'e_shentsize', 'e_shnum', 'e_shstrndx'))

    def read_phdr(this):
        if this.elf_wordsize == 64:
            return this.read_struct('WWNNNXXX',
                                    ('p_type', 'p_flags', 'p_offset', 'p_vaddr',
                                     'p_paddr', 'p_filesz', 'p_memsz', 'p_align'))
        else:
            return this.read_struct('WNNNWWWW',
                                    ('p_type', 'p_offset', 'p_vaddr', 'p_paddr',
                                     'p_filesz', 'p_memsz', 'p_flags', 'p_align'))

    def __init__(this, filename):
        this.file = open(filename, 'rb')
        magic = this.file.read(16)

        if magic[:4] != b'\x7fELF':
            raise Exception("ELF signature not found")

        if magic[4] == 1:
            this.elf_wordsize = 32
            nativeint = 'Ii'
        elif magic[4] == 2:
            this.elf_wordsize = 64
            nativeint = 'Qq'
        else:
            raise Exception("Invalid ELF file class")

        if magic[5] == 1:
            this.elf_endianprefix = '<'
        elif magic[5] == 2:
            this.elf_endianprefix = '>'
        else:
            raise Exception("Invalid ELF data encoding")

        this.elf_format = str.maketrans('HWwXxNn', 'HIiQq'+nativeint)

        this.file.seek(0)
        this.ehdr = this.read_ehdr()

        this.file.seek(this.ehdr['e_phoff'])
        this.phdrs = [this.read_phdr() for i in range(this.ehdr['e_phnum'])]

def copy_segment(phdr, infile, outfile):
    checksum = 0
    infile.seek(phdr['p_offset'])
    filesz = phdr['p_filesz']
    memsz = phdr['p_memsz']
    if (filesz > memsz):
        print("Warning: File size larger than mem size, fixing...")
        memsz = filesz
    if (memsz & 3) != 0:
        print("Warning: Unaligned memsize of segment, padding...")
        memsz = (memsz + 3) & ~3
    vaddr = phdr['p_vaddr']
    while (memsz > 0):
        chunksz = 65536 if memsz > 65536 else memsz
        outfile.write(struct.pack('<2I', chunksz >> 2, vaddr))
        vaddr += chunksz
        memsz -= chunksz
        while chunksz > 0:
            slicesz = 8192 if chunksz > 8192 else chunksz
            if filesz > 0:
                readsz = slicesz if filesz > slicesz else filesz
                block = infile.read(readsz)
                if len(block) == 0:
                    print("Warning: EOF on reading input ELF")
                    filesz = 0
                else:
                    filesz -= len(block)
            else:
                block = b''
            if filesz == 0 and len(block) < slicesz:
                block += b'\0' * (slicesz - len(block))
            checksum += sum(struct.unpack('<%dI'%(len(block) >> 2), block))
            outfile.write(block)
            chunksz -= len(block)
    return checksum

def usage():
    print("elf2img.py <elffile> <imgfile>")
    sys.exit(1)

#
# main
#

if len(sys.argv) != 3:
    usage()

elf_filename = sys.argv[1]
img_filename = sys.argv[2]
i2c_config = 0x1c
image_type = 0xb0
checksum = 0

e = elf(elf_filename)
i = open(img_filename, 'wb')
i.write(struct.pack('<4B', ord(b'C'), ord(b'Y'), i2c_config, image_type))
for p in e.phdrs:
    if p['p_type'] == 1:
        checksum += copy_segment(p, e.file, i)
i.write(struct.pack('<3I', 0, e.ehdr['e_entry'], checksum & 0xffffffff))
i.close()
