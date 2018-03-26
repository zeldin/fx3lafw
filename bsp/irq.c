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

#include <bsp/irq.h>
#include <bsp/regaccess.h>
#include <bsp/cache.h>
#include <rdb/vic.h>

void Fx3IrqInit(void)
{
  Fx3WriteReg32(FX3_VIC_INT_CLEAR, ~0UL);
  Fx3WriteReg32(FX3_VIC_INT_SELECT, 0UL);
  Fx3IrqInstallVectors();
  Fx3CacheCleanDCache();
  Fx3CacheInvalidateICache();

  /* Move vector base to 0 */
  uint32_t creg;
  __asm__ __volatile__("mrc p15, 0, %0, c1, c0, 0" : "=r"(creg));
  creg &= ~(1UL << 13);
  __asm__ __volatile__("mcr p15, 0, %0, c1, c0, 0" : : "r"(creg));
}
