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

	.text

	.globl	Fx3IrqVectors, Fx3IrqInstallVectors

Fx3IrqVectors:
1:	ldr	pc, ._start	/* Reset */
1:	b	1b		/* Undefined */
1:	b	1b		/* Swi */
1:	b	1b		/* Prefetch */
1:	b	1b		/* Abort */
1:	b	1b		/* Reserved */
	ldr	pc, Fx3IrqVectors - 0x100    /* IRQ - use vectored address */
1:	b	1b		/* FIQ */

._start:
	.word	_start

Fx3IrqInstallVectors:
	mov	a1, #0
	adr	a2, Fx3IrqVectors
	adr	a3, Fx3IrqInstallVectors
	sub	a3, a3, a2
	b	memcpy

	.end

