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

#ifndef RDB_PIB_H_
#define RDB_PIB_H_

#define FX3_PIB_CONFIG                        0xE0010000 /* PIB Configuration Register */
#define FX3_PIB_INTR                          0xE0010004 /* PIB Interrupt Request Register */
#define FX3_PIB_INTR_MASK                     0xE0010008 /* PIB Interrupt Mask Register */
#define FX3_PIB_CLOCK_DETECT                  0xE001000C /* PIB Clock Detector Configuration Register */
#define FX3_PIB_RD_MAILBOX                    0xE0010010 /* Read (Egress) Mailbox Register */
#define FX3_PIB_WR_MAILBOX                    0xE0010018 /* Write (Ingress) Mailbox Register */
#define FX3_PIB_ERROR                         0xE0010020 /* PIB Error Indicator Register */
#define FX3_PIB EOP/EOT                       0xE0010024 /* Configuration Register */
#define FX3_PIB_DLL_CTRL                      0xE0010028 /* DLL Configuration Register */
#define FX3_PIB_WR_THRESHOLD                  0xE001002C /* Write Threshold Register */
#define FX3_PIB_RD_THRESHOLD                  0xE0010030 /* Read Threshold Register */
#define FX3_PIB_ID                            0xE0017F00 /* Block Identification and Version Number Register */
#define FX3_PIB_POWER                         0xE0017F04 /* Power, Clock, and Reset Control Register */

#define FX3_PIB_CONFIG_ENABLE                            (1UL << 31)
#define FX3_PIB_CONFIG_MMIO_ENABLE                       (1UL << 30)
#define FX3_PIB_CONFIG_PP_CFGMODE                        (1UL << 29)
#define FX3_PIB_CONFIG_PCFG                              (1UL << 28)
#define FX3_PIB_CONFIG_DEVICE_ID_SHIFT                   8
#define FX3_PIB_CONFIG_DEVICE_ID_BITS                    8
#define FX3_PIB_CONFIG_DEVICE_ID_MASK                    (0xffUL << 8)

#define FX3_PIB_INTR_GPIF_ERR                            (1UL << 31)
#define FX3_PIB_INTR_PIB_ERR                             (1UL << 29)
#define FX3_PIB_INTR_RD_THRESHOLD                        (1UL << 10)
#define FX3_PIB_INTR_WR_THRESHOLD                        (1UL << 9)
#define FX3_PIB_INTR_CONFIG_CHANGE                       (1UL << 8)
#define FX3_PIB_INTR_CLOCK_LOST                          (1UL << 7)
#define FX3_PIB_INTR_DLL_LOST_LOCK                       (1UL << 6)
#define FX3_PIB_INTR_DLL_LOCKED                          (1UL << 5)
#define FX3_PIB_INTR_GPIF_INTERRUPT                      (1UL << 4)
#define FX3_PIB_INTR_WR_MB_FULL                          (1UL << 1)
#define FX3_PIB_INTR_RD_MB_EMPTY                         (1UL << 0)

#define FX3_PIB_INTR_MASK_GPIF_ERR                       (1UL << 31)
#define FX3_PIB_INTR_MASK_PIB_ERR                        (1UL << 29)
#define FX3_PIB_INTR_MASK_RD_THRESHOLD                   (1UL << 10)
#define FX3_PIB_INTR_MASK_WR_THRESHOLD                   (1UL << 9)
#define FX3_PIB_INTR_MASK_CONFIG_CHANGE                  (1UL << 8)
#define FX3_PIB_INTR_MASK_CLOCK_LOST                     (1UL << 7)
#define FX3_PIB_INTR_MASK_DLL_LOST_LOCK                  (1UL << 6)
#define FX3_PIB_INTR_MASK_DLL_LOCKED                     (1UL << 5)
#define FX3_PIB_INTR_MASK_GPIF_INTERRUPT                 (1UL << 4)
#define FX3_PIB_INTR_MASK_WR_MB_FULL                     (1UL << 1)
#define FX3_PIB_INTR_MASK_RD_MB_EMPTY                    (1UL << 0)

#define FX3_PIB_CLOCK_DETECT_ENABLE                      (1UL << 31)
#define FX3_PIB_CLOCK_DETECT_CLOCK_PRESENT               (1UL << 30)
#define FX3_PIB_CLOCK_DETECT_INTF_CYCLES_SHIFT           16
#define FX3_PIB_CLOCK_DETECT_INTF_CYCLES_BITS            4
#define FX3_PIB_CLOCK_DETECT_INTF_CYCLES_MASK            (0xfUL << 16)
#define FX3_PIB_CLOCK_DETECT_BUS_CYCLES_SHIFT            0
#define FX3_PIB_CLOCK_DETECT_BUS_CYCLES_BITS             16
#define FX3_PIB_CLOCK_DETECT_BUS_CYCLES_MASK             (0xffffUL << 0)

#define FX3_PIB_RD_MAILBOX_PP_RD_MAILBOX_SHIFT           0
#define FX3_PIB_RD_MAILBOX_PP_RD_MAILBOX_BITS            64
#define FX3_PIB_RD_MAILBOX_PP_RD_MAILBOX_MASK            (0xffffffffffffffffUL << 0)

#define FX3_PIB_WR_MAILBOX_PP_WR_MAILBOX_SHIFT           0
#define FX3_PIB_WR_MAILBOX_PP_WR_MAILBOX_BITS            64
#define FX3_PIB_WR_MAILBOX_PP_WR_MAILBOX_MASK            (0xffffffffffffffffUL << 0)

#define FX3_PIB_ERROR_GPIF_ERR_CODE_SHIFT                10
#define FX3_PIB_ERROR_GPIF_ERR_CODE_BITS                 5
#define FX3_PIB_ERROR_GPIF_ERR_CODE_MASK                 (0x1fUL << 10)
#define FX3_PIB_ERROR_PIB_ERR_CODE_SHIFT                 0
#define FX3_PIB_ERROR_PIB_ERR_CODE_BITS                  6
#define FX3_PIB_ERROR_PIB_ERR_CODE_MASK                  (0x3fUL << 0)

#define FX3_PIB_DLL_CTRL_ENABLE_RESET_ON_ERR             (1UL << 31)
#define FX3_PIB_DLL_CTRL_DLL_RESET_N                     (1UL << 30)
#define FX3_PIB_DLL_CTRL_DLL_STAT                        (1UL << 2)
#define FX3_PIB_DLL_CTRL_HIGH_FREQ                       (1UL << 1)
#define FX3_PIB_DLL_CTRL_ENABLE                          (1UL << 0)

#define FX3_PIB_WR_THRESHOLD_VALUE16_SHIFT               0
#define FX3_PIB_WR_THRESHOLD_VALUE16_BITS                16
#define FX3_PIB_WR_THRESHOLD_VALUE16_MASK                (0xffffUL << 0)

#define FX3_PIB_RD_THRESHOLD_VALUE16_SHIFT               0
#define FX3_PIB_RD_THRESHOLD_VALUE16_BITS                16
#define FX3_PIB_RD_THRESHOLD_VALUE16_MASK                (0xffffUL << 0)

#define FX3_PIB_ID_BLOCK_VERSION_SHIFT                   16
#define FX3_PIB_ID_BLOCK_VERSION_BITS                    16
#define FX3_PIB_ID_BLOCK_VERSION_MASK                    (0xffffUL << 16)
#define FX3_PIB_ID_BLOCK_ID_SHIFT                        0
#define FX3_PIB_ID_BLOCK_ID_BITS                         16
#define FX3_PIB_ID_BLOCK_ID_MASK                         (0xffffUL << 0)

#define FX3_PIB_POWER_RESETN                             (1UL << 31)
#define FX3_PIB_POWER_ACTIVE                             (1UL << 0)

#endif /* RDB_PIB_H_ */
