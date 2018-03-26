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


#define DTCM_BASE 0x10000000
#define DTCM_SIZE 4 /* 512 << 4 = 8K */

#define ITCM_BASE 0x00000000
#define ITCM_SIZE 5 /* 512 << 5 = 16K */


	.text

	.globl	Fx3IrqInstallVectors, _start

Fx3IrqVectors:
_start:
1:	ldr	pc, ._reset	/* Reset */
1:	b	1b		/* Undefined */
1:	b	1b		/* Swi */
1:	b	1b		/* Prefetch */
1:	b	1b		/* Abort */
1:	b	1b		/* Reserved */
	ldr	pc, Fx3IrqVectors - 0x100    /* IRQ - use vectored address */
1:	b	1b		/* FIQ */

._reset:
	.word	Reset

Fx3IrqInstallVectors:
	mov	a1, #0
	adr	a2, Fx3IrqVectors
	adr	a3, Fx3IrqInstallVectors
	sub	a3, a3, a2
	b	memcpy

Reset:
	msr	CPSR_c, #0xD1	/* FIRQ mode, interrupts disabled */

	/* Enable TCM */
	mov	r0, #DTCM_BASE
	orr	r0, r0, #((DTCM_SIZE << 2) | 1)
	mcr	p15, 0, r0, c9, c1, 0
	mov	r0, #ITCM_BASE
	orr	r0, r0, #((ITCM_SIZE << 2) | 1)
	mcr	p15, 0, r0, c9, c1, 1

	ldr	sp, =__stack_firq-8
	msr	CPSR_c, #0xD7	/* Abort mode, interrupts disabled */
	ldr	sp, =__stack_abort-8
	msr	CPSR_c, #0xDB	/* Undefined mode, interrupts disabled */
	ldr	sp, =__stack_undef-8
	msr	CPSR_c, #0xD2	/* IRQ mode, interrupts disabled */
	ldr	sp, =__stack_irq-8
	msr	CPSR_c, #0xD3	/* Supervisory mode, interrupts disabled */
	ldr	sp, =__stack_super-8
	msr	CPSR_c, #0xDF	/* System mode, interrupts disabled */
	ldr	sp, =__stack_sys-8

	/* Zero the memory in the .bss section.	 */
	movs	a2, #0			/* Second arg: fill value */
	mov	fp, a2			/* Null frame pointer */
	mov	r7, a2			/* Null frame pointer for Thumb */

	ldr	a1, =__bss_start__	/* First arg: start of memory block */
	ldr	a3, =__bss_end__
	subs	a3, a3, a1		/* Third arg: length of block */
	bl	memset

	mov	r0, #0
	mov	r1, #0
	bl	main
	b	exit

	.end

