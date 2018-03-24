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

#ifndef RDB_I2S_H_
#define RDB_I2S_H_

#define FX3_I2S_CONFIG                        0xE0000000 /* I2S Configuration and Mode Register */
#define FX3_I2S_STATUS                        0xE0000004 /* I2S Status Register */
#define FX3_I2S_INTR                          0xE0000008 /* I2S Interrupt Request Register */
#define FX3_I2S_INTR_MASK                     0xE000000C /* I2S Interrupt Mask Register */
#define FX3_I2S_EGRESS_DATA_LEFT              0xE0000010 /* I2S Egress Data Register (Left) */
#define FX3_I2S_EGRESS_DATA_RIGHT             0xE0000014 /* I2S Egress Data Register (Right) */
#define FX3_I2S_COUNTER                       0xE0000018 /* I2S Sample Counter Register */
#define FX3_I2S_SOCKET                        0xE0000304 /* I2S Socket Register */
#define FX3_I2S_ID                            0xE00003F0 /* Block Identification and Version Number */
#define FX3_I2S_POWER                         0xE00003F4 /* Power, Clock, and Reset Control */

#define FX3_I2S_CONFIG_ENABLE                            (1UL << 31)
#define FX3_I2S_CONFIG_TX_CLEAR                          (1UL << 30)
#define FX3_I2S_CONFIG_MODE_SHIFT                        11
#define FX3_I2S_CONFIG_MODE_BITS                         2
#define FX3_I2S_CONFIG_MODE_MASK                         (0x3UL << 11)
#define FX3_I2S_CONFIG_BIT_WIDTH_SHIFT                   8
#define FX3_I2S_CONFIG_BIT_WIDTH_BITS                    3
#define FX3_I2S_CONFIG_BIT_WIDTH_MASK                    (0x7UL << 8)
#define FX3_I2S_CONFIG_DMA_MODE                          (1UL << 6)
#define FX3_I2S_CONFIG_MONO                              (1UL << 5)
#define FX3_I2S_CONFIG_FIXED_SCK                         (1UL << 4)
#define FX3_I2S_CONFIG_WSMODE                            (1UL << 3)
#define FX3_I2S_CONFIG_ENDIAN                            (1UL << 2)
#define FX3_I2S_CONFIG_MUTE                              (1UL << 1)
#define FX3_I2S_CONFIG_PAUSE                             (1UL << 0)

#define FX3_I2S_STATUS_BUSY                              (1UL << 28)
#define FX3_I2S_STATUS_ERROR_CODE_SHIFT                  24
#define FX3_I2S_STATUS_ERROR_CODE_BITS                   4
#define FX3_I2S_STATUS_ERROR_CODE_MASK                   (0xfUL << 24)
#define FX3_I2S_STATUS_ERROR                             (1UL << 8)
#define FX3_I2S_STATUS_NO_DATA                           (1UL << 7)
#define FX3_I2S_STATUS_PAUSED                            (1UL << 6)
#define FX3_I2S_STATUS_TXR_HALF                          (1UL << 5)
#define FX3_I2S_STATUS_TXR_SPACE                         (1UL << 4)
#define FX3_I2S_STATUS_TXR_DONE                          (1UL << 3)
#define FX3_I2S_STATUS_TXL_HALF                          (1UL << 2)
#define FX3_I2S_STATUS_TXL_SPACE                         (1UL << 1)
#define FX3_I2S_STATUS_TXL_DONE                          (1UL << 0)

#define FX3_I2S_INTR_ERROR                               (1UL << 8)
#define FX3_I2S_INTR_NO_DATA                             (1UL << 7)
#define FX3_I2S_INTR_PAUSED                              (1UL << 6)
#define FX3_I2S_INTR_TXR_HALF                            (1UL << 5)
#define FX3_I2S_INTR_TXR_SPACE                           (1UL << 4)
#define FX3_I2S_INTR_TXR_DONE                            (1UL << 3)
#define FX3_I2S_INTR_TXL_HALF                            (1UL << 2)
#define FX3_I2S_INTR_TXL_SPACE                           (1UL << 1)
#define FX3_I2S_INTR_TXL_DONE                            (1UL << 0)

#define FX3_I2S_INTR_MASK_ERROR                          (1UL << 8)
#define FX3_I2S_INTR_MASK_NO_DATA                        (1UL << 7)
#define FX3_I2S_INTR_MASK_PAUSED                         (1UL << 6)
#define FX3_I2S_INTR_MASK_TXR_HALF                       (1UL << 5)
#define FX3_I2S_INTR_MASK_TXR_SPACE                      (1UL << 4)
#define FX3_I2S_INTR_MASK_TXR_DONE                       (1UL << 3)
#define FX3_I2S_INTR_MASK_TXL_HALF                       (1UL << 2)
#define FX3_I2S_INTR_MASK_TXL_SPACE                      (1UL << 1)
#define FX3_I2S_INTR_MASK_TXL_DONE                       (1UL << 0)

#define FX3_I2S_SOCKET_RIGHT_SOCKET_SHIFT                8
#define FX3_I2S_SOCKET_RIGHT_SOCKET_BITS                 8
#define FX3_I2S_SOCKET_RIGHT_SOCKET_MASK                 (0xffUL << 8)
#define FX3_I2S_SOCKET_LEFT_SOCKET_SHIFT                 0
#define FX3_I2S_SOCKET_LEFT_SOCKET_BITS                  8
#define FX3_I2S_SOCKET_LEFT_SOCKET_MASK                  (0xffUL << 0)

#define FX3_I2S_ID_BLOCK_VERSION_SHIFT                   16
#define FX3_I2S_ID_BLOCK_VERSION_BITS                    16
#define FX3_I2S_ID_BLOCK_VERSION_MASK                    (0xffffUL << 16)
#define FX3_I2S_ID_BLOCK_ID_SHIFT                        0
#define FX3_I2S_ID_BLOCK_ID_BITS                         16
#define FX3_I2S_ID_BLOCK_ID_MASK                         (0xffffUL << 0)

#define FX3_I2S_POWER_RESETN                             (1UL << 31)
#define FX3_I2S_POWER_ACTIVE                             (1UL << 0)

#endif /* RDB_I2S_H_ */
