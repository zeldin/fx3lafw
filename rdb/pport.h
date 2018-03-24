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

#ifndef RDB_PPORT_H_
#define RDB_PPORT_H_

#define FX3_PP_ID                             0xE0017E00 /* P-Port Device ID Register */
#define FX3_PP_INIT                           0xE0017E04 /* P-Port Reset and Power Control Register */
#define FX3_PP_CONFIG                         0xE0017E08 /* P-Port Configuration Register */
#define FX3_PP_INTR_MASK                      0xE0017E1C /* P-Port Interrupt Mask Register */
#define FX3_PP_DRQR5_MASK                     0xE0017E20 /* P-Port DRQ/R5 Mask Register */
#define FX3_PP_SOCK_MASK                      0xE0017E24 /* P-Port Socket Mask Register */
#define FX3_PP_ERROR                          0xE0017E28 /* P-Port Error Indicator Register */
#define FX3_PP_DMA_XFER                       0xE0017E2C /* P-Port DMA Transfer Register */
#define FX3_PP_DMA_SIZE                       0xE0017E30 /* P-Port DMA Transfer Size Register */
#define FX3_PP_WR_MAILBOX                     0xE0017E34 /* P-Port Write (Ingress) Mailbox Registers */
#define FX3_PP_MMIO_ADDR                      0xE0017E3C /* P-Port MMIO Address Registers */
#define FX3_PP_MMIO_DATA                      0xE0017E40 /* P-Port MMIO Data Registers */
#define FX3_PP_MMIO                           0xE0017E44 /* P-Port MMIO Control Registers */
#define FX3_PP_EVENT                          0xE0017E48 /* P-Port Event Register */
#define FX3_PP_RD_MAILBOX                     0xE0017E4C /* P-Port Read (Egress) Mailbox Registers */
#define FX3_PP_SOCK_STAT                      0xE0017E54 /* P-Port Socket Status Register */
#define FX3_PP_BUF_SIZE_CNT                   0xE0017E?? /* P-Port Socket Buffer Size or Count Register */

#define FX3_PP_ID_DEVICE_ID_SHIFT                        0
#define FX3_PP_ID_DEVICE_ID_BITS                         16
#define FX3_PP_ID_DEVICE_ID_MASK                         (0xffffUL << 0)

#define FX3_PP_INIT_BIG_ENDIAN                           (1UL << 15)
#define FX3_PP_INIT_HARD_RESET_N                         (1UL << 11)
#define FX3_PP_INIT_CPU_RESET_N                          (1UL << 10)
#define FX3_PP_INIT_WAKEUP_CLK                           (1UL << 4)
#define FX3_PP_INIT_WAKEUP_PWR                           (1UL << 3)
#define FX3_PP_INIT_WDT_RESET                            (1UL << 2)
#define FX3_PP_INIT_SW_RESET                             (1UL << 1)
#define FX3_PP_INIT_POR                                  (1UL << 0)

#define FX3_PP_CONFIG_DACK_POLARITY                      (1UL << 15)
#define FX3_PP_CONFIG_DRQ_POLARITY                       (1UL << 14)
#define FX3_PP_CONFIG_DRQ_VALUE                          (1UL << 13)
#define FX3_PP_CONFIG_DRQ_OVERRIDE                       (1UL << 12)
#define FX3_PP_CONFIG_INTR_POLARITY                      (1UL << 11)
#define FX3_PP_CONFIG_INTR_VALUE                         (1UL << 10)
#define FX3_PP_CONFIG_INTR_OVERRIDE                      (1UL << 9)
#define FX3_PP_CONFIG_DRQMODE                            (1UL << 7)
#define FX3_PP_CONFIG_CFGMODE                            (1UL << 6)
#define FX3_PP_CONFIG_BURSTSIZE_SHIFT                    0
#define FX3_PP_CONFIG_BURSTSIZE_BITS                     4
#define FX3_PP_CONFIG_BURSTSIZE_MASK                     (0xfUL << 0)

#define FX3_PP_INTR_MASK_WAKEUP                          (1UL << 15)
#define FX3_PP_INTR_MASK_WR_MB_EMPTY                     (1UL << 14)
#define FX3_PP_INTR_MASK_RD_MB_FULL                      (1UL << 13)
#define FX3_PP_INTR_MASK_DMA_READY_EV                    (1UL << 12)
#define FX3_PP_INTR_MASK_DMA_WMARK_EV                    (1UL << 11)
#define FX3_PP_INTR_MASK_GPIF_ERR                        (1UL << 7)
#define FX3_PP_INTR_MASK_PIB_ERR                         (1UL << 5)
#define FX3_PP_INTR_MASK_GPIF_INT                        (1UL << 4)
#define FX3_PP_INTR_MASK_SOCK_AGG_BH                     (1UL << 3)
#define FX3_PP_INTR_MASK_SOCK_AGG_BL                     (1UL << 2)
#define FX3_PP_INTR_MASK_SOCK_AGG_AH                     (1UL << 1)
#define FX3_PP_INTR_MASK_SOCK_AGG_AL                     (1UL << 0)

#define FX3_PP_DRQR5_MASK_WAKEUP                         (1UL << 15)
#define FX3_PP_DRQR5_MASK_WR_MB_EMPTY                    (1UL << 14)
#define FX3_PP_DRQR5_MASK_RD_MB_FULL                     (1UL << 13)
#define FX3_PP_DRQR5_MASK_DMA_READY_EV                   (1UL << 12)
#define FX3_PP_DRQR5_MASK_DMA_WMARK_EV                   (1UL << 11)
#define FX3_PP_DRQR5_MASK_GPIF_ERR                       (1UL << 7)
#define FX3_PP_DRQR5_MASK_PIB_ERR                        (1UL << 5)
#define FX3_PP_DRQR5_MASK_GPIF_INT                       (1UL << 4)
#define FX3_PP_DRQR5_MASK_SOCK_AGG_BH                    (1UL << 3)
#define FX3_PP_DRQR5_MASK_SOCK_AGG_BL                    (1UL << 2)
#define FX3_PP_DRQR5_MASK_SOCK_AGG_AH                    (1UL << 1)
#define FX3_PP_DRQR5_MASK_SOCK_AGG_AL                    (1UL << 0)

#define FX3_PP_ERROR_GPIF_ERR_CODE_SHIFT                 10
#define FX3_PP_ERROR_GPIF_ERR_CODE_BITS                  5
#define FX3_PP_ERROR_GPIF_ERR_CODE_MASK                  (0x1fUL << 10)
#define FX3_PP_ERROR_PIB_ERR_CODE_SHIFT                  0
#define FX3_PP_ERROR_PIB_ERR_CODE_BITS                   6
#define FX3_PP_ERROR_PIB_ERR_CODE_MASK                   (0x3fUL << 0)

#define FX3_PP_DMA_XFER_DMA_READY                        (1UL << 15)
#define FX3_PP_DMA_XFER_DMA_ERROR                        (1UL << 14)
#define FX3_PP_DMA_XFER_DMA_BUSY                         (1UL << 13)
#define FX3_PP_DMA_XFER_SIZE_VALID                       (1UL << 12)
#define FX3_PP_DMA_XFER_LONG_TRANSFER                    (1UL << 10)
#define FX3_PP_DMA_XFER_DMA_DIRECTION                    (1UL << 9)
#define FX3_PP_DMA_XFER_DMA_ENABLE                       (1UL << 8)
#define FX3_PP_DMA_XFER_DMA_SOCK_SHIFT                   0
#define FX3_PP_DMA_XFER_DMA_SOCK_BITS                    8
#define FX3_PP_DMA_XFER_DMA_SOCK_MASK                    (0xffUL << 0)

#define FX3_PP_DMA_SIZE_DMA_SIZE_SHIFT                   0
#define FX3_PP_DMA_SIZE_DMA_SIZE_BITS                    16
#define FX3_PP_DMA_SIZE_DMA_SIZE_MASK                    (0xffffUL << 0)

#define FX3_PP_WR_MAILBOX_WR_MAILBOX_SHIFT               0
#define FX3_PP_WR_MAILBOX_WR_MAILBOX_BITS                64
#define FX3_PP_WR_MAILBOX_WR_MAILBOX_MASK                (0xffffffffffffffffUL << 0)

#define FX3_PP_MMIO_MMIO_FAIL                            (1UL << 3)
#define FX3_PP_MMIO_MMIO_BUSY                            (1UL << 2)
#define FX3_PP_MMIO_MMIO_WR                              (1UL << 1)
#define FX3_PP_MMIO_MMIO_RD                              (1UL << 0)

#define FX3_PP_EVENT_WAKEUP                              (1UL << 15)
#define FX3_PP_EVENT_WR_MB_EMPTY                         (1UL << 14)
#define FX3_PP_EVENT_RD_MB_FULL                          (1UL << 13)
#define FX3_PP_EVENT_DMA_READY_EV                        (1UL << 12)
#define FX3_PP_EVENT_DMA_WMARK_EV                        (1UL << 11)
#define FX3_PP_EVENT_GPIF_ERR                            (1UL << 7)
#define FX3_PP_EVENT_PIB_ERR                             (1UL << 5)
#define FX3_PP_EVENT_GPIF_INT                            (1UL << 4)
#define FX3_PP_EVENT_SOCK_AGG_BH                         (1UL << 3)
#define FX3_PP_EVENT_SOCK_AGG_BL                         (1UL << 2)
#define FX3_PP_EVENT_SOCK_AGG_AH                         (1UL << 1)
#define FX3_PP_EVENT_SOCK_AGG_AL                         (1UL << 0)

#define FX3_PP_RD_MAILBOX_RD_MAILBOX_SHIFT               0
#define FX3_PP_RD_MAILBOX_RD_MAILBOX_BITS                64
#define FX3_PP_RD_MAILBOX_RD_MAILBOX_MASK                (0xffffffffffffffffUL << 0)

#define FX3_PP_BUF_SIZE_CNT_SIZE_CNT_SHIFT               0
#define FX3_PP_BUF_SIZE_CNT_SIZE_CNT_BITS                16
#define FX3_PP_BUF_SIZE_CNT_SIZE_CNT_MASK                (0xffffUL << 0)

#endif /* RDB_PPORT_H_ */
