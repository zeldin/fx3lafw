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

#include <bsp/gpio.h>
#include <bsp/regaccess.h>
#include <rdb/gpio.h>
#include <rdb/gctl.h>

void Fx3GpioSetupSimple(uint8_t num, uint32_t config)
{
  if (num < 61) {
    Fx3WriteReg32(FX3_GPIO_SIMPLE + (num << 2), config);
    Fx3SetReg32(FX3_GCTL_GPIO_SIMPLE + ((num & 32) >> 3),
		1UL << (num & 31));
  }
}

void Fx3GpioSetOutputValue(uint8_t num, uint8_t value)
{
  if (num < 61) {
    Fx3WriteReg32(FX3_GPIO_SIMPLE + (num << 2),
		  (Fx3ReadReg32(FX3_GPIO_SIMPLE + (num << 2)) &
		   ~(FX3_GPIO_SIMPLE_INTR | FX3_GPIO_SIMPLE_OUT_VALUE)) |
		  (value & FX3_GPIO_SIMPLE_OUT_VALUE));
  }
}

uint8_t Fx3GpioGetInputValue(uint8_t num)
{
  if (num < 61) {
    return (Fx3ReadReg32(FX3_GPIO_SIMPLE + (num << 2)) & FX3_GPIO_SIMPLE_IN_VALUE) >> 1;
  } else {
    return 0;
  }
}
