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

#ifndef RDB_GPIO_H_
#define RDB_GPIO_H_

#define FX3_PIN_STATUS                        0xE0001000 /* Configuration, mode and status of IO Pin */
#define FX3_PIN_TIMER                         0xE0001004 /* Timer/counter for pulse and measurement modes */
#define FX3_PIN_PERIOD                        0xE0001008 /* Period length for revolving counter GPIO_TIMER */
#define FX3_PIN_THRESHOLD                     0xE000100C /* Threshold or Measurement Register */
#define FX3_GPIO_SIMPLE                       0xE0001100 /* Simple General Purpose IO Register (one pin) */
#define FX3_GPIO_INVALUE0                     0xE00013D0 /* GPIO Input Value Vector */
#define FX3_GPIO_INVALUE1                     0xE00013D4 /* GPIO Input Value Vector */
#define FX3_GPIO_INTR0                        0xE00013E0 /* GPIO Interrupt Vector */
#define FX3_GPIO_INTR1                        0xE00013E4 /* GPIO Interrupt Vector */
#define FX3_GPIO_INTR                         0xE00013E8 /* GPIO Interrupt Vector for PINs */
#define FX3_GPIO_ID                           0xE00013F0 /* Block Identification and Version Number */
#define FX3_GPIO_POWER                        0xE00013F4 /* Power, Clock, and Reset Control */

#define FX3_PIN_STATUS_ENABLE                            (1UL << 31)
#define FX3_PIN_STATUS_TIMER_MODE_SHIFT                  28
#define FX3_PIN_STATUS_TIMER_MODE_BITS                   3
#define FX3_PIN_STATUS_TIMER_MODE_MASK                   (0x7UL << 28)
#define FX3_PIN_STATUS_INTR                              (1UL << 27)
#define FX3_PIN_STATUS_INTRMODE_SHIFT                    24
#define FX3_PIN_STATUS_INTRMODE_BITS                     3
#define FX3_PIN_STATUS_INTRMODE_MASK                     (0x7UL << 24)
#define FX3_PIN_STATUS_MODE_SHIFT                        8
#define FX3_PIN_STATUS_MODE_BITS                         4
#define FX3_PIN_STATUS_MODE_MASK                         (0xfUL << 8)
#define FX3_PIN_STATUS_INPUT_EN                          (1UL << 6)
#define FX3_PIN_STATUS_DRIVE_HI_EN                       (1UL << 5)
#define FX3_PIN_STATUS_DRIVE_LO_EN                       (1UL << 4)
#define FX3_PIN_STATUS_IN_VALUE                          (1UL << 1)
#define FX3_PIN_STATUS_OUT_VALUE                         (1UL << 0)

#define FX3_GPIO_SIMPLE_ENABLE                           (1UL << 31)
#define FX3_GPIO_SIMPLE_INTR                             (1UL << 27)
#define FX3_GPIO_SIMPLE_INTRMODE_SHIFT                   24
#define FX3_GPIO_SIMPLE_INTRMODE_BITS                    3
#define FX3_GPIO_SIMPLE_INTRMODE_MASK                    (0x7UL << 24)
#define FX3_GPIO_SIMPLE_INPUT_EN                         (1UL << 6)
#define FX3_GPIO_SIMPLE_DRIVE_HI_EN                      (1UL << 5)
#define FX3_GPIO_SIMPLE_DRIVE_LO_EN                      (1UL << 4)
#define FX3_GPIO_SIMPLE_IN_VALUE                         (1UL << 1)
#define FX3_GPIO_SIMPLE_OUT_VALUE                        (1UL << 0)

#define FX3_GPIO_INVALUE1_INVALUE1_SHIFT                 0
#define FX3_GPIO_INVALUE1_INVALUE1_BITS                  29
#define FX3_GPIO_INVALUE1_INVALUE1_MASK                  (0x1fffffffUL << 0)

#define FX3_GPIO_INTR1_INTR1_SHIFT                       0
#define FX3_GPIO_INTR1_INTR1_BITS                        29
#define FX3_GPIO_INTR1_INTR1_MASK                        (0x1fffffffUL << 0)

#define FX3_GPIO_INTR_INTR7                              (1UL << 7)
#define FX3_GPIO_INTR_INTR6                              (1UL << 6)
#define FX3_GPIO_INTR_INTR5                              (1UL << 5)
#define FX3_GPIO_INTR_INTR4                              (1UL << 4)
#define FX3_GPIO_INTR_INTR3                              (1UL << 3)
#define FX3_GPIO_INTR_INTR2                              (1UL << 2)
#define FX3_GPIO_INTR_INTR1                              (1UL << 1)
#define FX3_GPIO_INTR_INTR0                              (1UL << 0)

#define FX3_GPIO_ID_BLOCK_VERSION_SHIFT                  16
#define FX3_GPIO_ID_BLOCK_VERSION_BITS                   16
#define FX3_GPIO_ID_BLOCK_VERSION_MASK                   (0xffffUL << 16)
#define FX3_GPIO_ID_BLOCK_ID_SHIFT                       0
#define FX3_GPIO_ID_BLOCK_ID_BITS                        16
#define FX3_GPIO_ID_BLOCK_ID_MASK                        (0xffffUL << 0)

#define FX3_GPIO_POWER_RESETN                            (1UL << 31)
#define FX3_GPIO_POWER_ACTIVE                            (1UL << 0)

#endif /* RDB_GPIO_H_ */
