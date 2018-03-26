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

ENTRY(_start)

SECTIONS
{
	. = 0x40003000;

	/* Stacks in DTCM */
	__stack_sys =   0x10002000; /* 6KB */
	__stack_undef = 0x10000800; /* 128B */
	__stack_abort = 0x10000780; /* 128B */
	__stack_firq =  0x10000700; /* 256B */
	__stack_irq =   0x10000600; /* 1KB */
	__stack_super = 0x10000200; /* 512B */

	.text :
	{
		*(.init*)
		*(.text*)
		*(.fini*)
		*(.rodata*)
		*(.eh_frame*)
		. = ALIGN(4);
	}

	.data :
	{
		*(.init_array*)
		*(.fini_array*)
		*(.got)
		*(.data*)
		. = ALIGN(4);
	}

	.bss :
	{
		__bss_start__ = .;
		*(.bss*)
		. = ALIGN(4);
		__bss_end__ = .;
	}

	.ARM.extab :
	{
		*(.ARM.extab* .gnu.linkonce.armextab.*)
	}
	__exidx_start = .;
	.ARM.exidx :
	{
		*(.ARM.exidx* .gnu.linkonce.armexidx.*)
	}
	__exidx_end = .;

	_end = .;

	__heap_end = 0x40040000;
}
