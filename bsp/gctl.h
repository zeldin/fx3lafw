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

#ifndef BSP_GCTL_H_
#define BSP_GCTL_H_

#include <stdint.h>

/* Alternate function for GPIO 33-57 */
typedef enum {
  FX3_GCTL_ALTFUNC_GPIO = 0,
  FX3_GCTL_ALTFUNC_GPIO_UART = 1,
  FX3_GCTL_ALTFUNC_GPIO_SPI = 2,
  FX3_GCTL_ALTFUNC_GPIO_I2S = 3,
  FX3_GCTL_ALTFUNC_UART_SPI_I2S = 4,
  FX3_GCTL_ALTFUNC_GPIF32BIT_UART_I2S = 5
} Fx3GctlPinAltFunc_t;

extern void Fx3GctlInitClock(void);
extern void Fx3GctlInitIoMatrix(Fx3GctlPinAltFunc_t alt_func);
extern void Fx3GctlHardReset(void);

#endif /* BSP_GCTL_H_ */
