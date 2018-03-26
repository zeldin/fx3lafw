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

#ifndef BSP_IRQ_H_
#define BSP_IRQ_H_

#include <stdint.h>

static inline void Fx3IrqEnableInterrupts(void)
{
  uint32_t cpsr;
  __asm__ __volatile__("mrs %0,cpsr" : "=r"(cpsr));
  __asm__ __volatile__("msr cpsr_c,%0" : : "r"(cpsr&0x3f));
}

static inline void Fx3IrqDisableInterrupts(void)
{
  uint32_t cpsr;
  __asm__ __volatile__("mrs %0,cpsr" : "=r"(cpsr));
  __asm__ __volatile__("msr cpsr_c,%0" : : "r"(cpsr|0xc0));
}

extern void Fx3IrqInit(void);
extern void Fx3IrqInstallVectors(void);

#endif /* BSP_IRQ_H_ */
