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

#include <bsp/gctl.h>
#include <bsp/regaccess.h>
#include <bsp/util.h>
#include <rdb/gctl.h>

void Fx3GctlInitClock(void)
{
  /* Select minimum scalers for all clocks */
  Fx3WriteReg32(FX3_GCTL_CPU_CLK_CFG,
		(1UL << FX3_GCTL_CPU_CLK_CFG_MMIO_DIV_SHIFT) |
		(1UL << FX3_GCTL_CPU_CLK_CFG_DMA_DIV_SHIFT) |
		(3UL << FX3_GCTL_CPU_CLK_CFG_SRC_SHIFT) |
		(1UL << FX3_GCTL_CPU_CLK_CFG_CPU_DIV_SHIFT));
  Fx3UtilDelayUs(10);

  /* Change PLL divisor from 20 to 21 */
  if (Fx3GetField32(FX3_GCTL_PLL_CFG, FBDIV) != 21) {
    Fx3SetField32(FX3_GCTL_PLL_CFG, FBDIV, 21);
    Fx3UtilDelayUs(10);
    while ((Fx3ReadReg32(FX3_GCTL_PLL_CFG) & FX3_GCTL_PLL_CFG_PLL_LOCK) == 0)
      ;
    Fx3UtilDelayUs(10);
  }
}

void Fx3GctlInitIoMatrix(Fx3GctlPinAltFunc_t alt_func)
{
  /* Disable all GPIO overrides */
  Fx3WriteReg32(FX3_GCTL_GPIO_SIMPLE, 0);
  Fx3WriteReg32(FX3_GCTL_GPIO_SIMPLE+4, 0);
  Fx3WriteReg32(FX3_GCTL_GPIO_COMPLEX, 0);
  Fx3WriteReg32(FX3_GCTL_GPIO_COMPLEX+4, 0);

  Fx3UtilDelayUs(1);

  /* Configure matrix */
  Fx3WriteReg32(FX3_GCTL_IOMATRIX,
		(alt_func << FX3_GCTL_IOMATRIX_S1CFG_SHIFT) |
		(alt_func == FX3_GCTL_ALTFUNC_GPIF32BIT_UART_I2S?
		 FX3_GCTL_IOMATRIX_S0CFG : 0));
}
