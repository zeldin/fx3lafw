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

#ifndef RDB_I2C_H_
#define RDB_I2C_H_

#define FX3_I2C_CONFIG                        0xE0000400 /* I²C Configuration and Mode Register */
#define FX3_I2C_STATUS                        0xE0000404 /* I²C Status Register */
#define FX3_I2C_INTR                          0xE0000408 /* I²C Interrupt Request Register */
#define FX3_I2C_INTR_MASK                     0xE000040C /* I²C Interrupt Mask Register */
#define FX3_I2C_TIMEOUT                       0xE0000410 /* Timeout Register */
#define FX3_I2C_DMA_TIMEOUT                   0xE0000414 /* DMA Timeout Register */
#define FX3_I2C_PREAMBLE_CTRL                 0xE0000418 /* I²C Preamble Control Register */
#define FX3_I2C_PREAMBLE_DATA                 0xE000041C /* I²C Preamble Data Register */
#define FX3_I2C_PREAMBLE_RPT                  0xE0000424 /* I²C Preamble Repeat Register */
#define FX3_I2C_COMMAND                       0xE0000428 /* I²C Command Register */
#define FX3_I2C_EGRESS_DATA                   0xE000042C /* I²C Egress Data Register */
#define FX3_I2C_INGRESS_DATA                  0xE0000430 /* I²C Ingress Data Register */
#define FX3_I2C_CLOCK_LOW_COUNT               0xE0000434 /* I²C Clock Low Count Register */
#define FX3_I2C_BYTE_COUNT                    0xE0000438 /* I²C Byte Count Register */
#define FX3_I2C_BYTES_TRANSFERRED             0xE000043C /* Number of Bytes Transferred in the Data Phase */
#define FX3_I2C_SOCKET                        0xE0000440 /* I²C Socket Register */
#define FX3_I2C_ID                            0xE00007F0 /* Block Identification and Version Number */
#define FX3_I2C_POWER                         0xE00007F4 /* Power, Clock, and Reset Control */

#define FX3_I2C_CONFIG_ENABLE                            (1UL << 31)
#define FX3_I2C_CONFIG_TX_CLEAR                          (1UL << 30)
#define FX3_I2C_CONFIG_RX_CLEAR                          (1UL << 29)
#define FX3_I2C_CONFIG_I2C_100KHz                        (1UL << 2)
#define FX3_I2C_CONFIG_CONTINUE_ON_NACK                  (1UL << 1)
#define FX3_I2C_CONFIG_DMA_MODE                          (1UL << 0)

#define FX3_I2C_STATUS_SDA_STAT                          (1UL << 31)
#define FX3_I2C_STATUS_SCL_STAT                          (1UL << 30)
#define FX3_I2C_STATUS_BUS_BUSY                          (1UL << 29)
#define FX3_I2C_STATUS_BUSY                              (1UL << 28)
#define FX3_I2C_STATUS_ERROR_CODE_SHIFT                  24
#define FX3_I2C_STATUS_ERROR_CODE_BITS                   4
#define FX3_I2C_STATUS_ERROR_CODE_MASK                   (0xfUL << 24)
#define FX3_I2C_STATUS_ERROR                             (1UL << 8)
#define FX3_I2C_STATUS_LOST_ARBITRATION                  (1UL << 7)
#define FX3_I2C_STATUS_TIMEOUT                           (1UL << 6)
#define FX3_I2C_STATUS_TX_HALF                           (1UL << 5)
#define FX3_I2C_STATUS_TX_SPACE                          (1UL << 4)
#define FX3_I2C_STATUS_TX_DONE                           (1UL << 3)
#define FX3_I2C_STATUS_RX_HALF                           (1UL << 2)
#define FX3_I2C_STATUS_RX_DATA                           (1UL << 1)
#define FX3_I2C_STATUS_RX_DONE                           (1UL << 0)

#define FX3_I2C_INTR_ERROR                               (1UL << 8)
#define FX3_I2C_INTR_LOST_ARBITRATION                    (1UL << 7)
#define FX3_I2C_INTR_TIMEOUT                             (1UL << 6)
#define FX3_I2C_INTR_TX_HALF                             (1UL << 5)
#define FX3_I2C_INTR_TX_SPACE                            (1UL << 4)
#define FX3_I2C_INTR_TX_DONE                             (1UL << 3)
#define FX3_I2C_INTR_RX_HALF                             (1UL << 2)
#define FX3_I2C_INTR_RX_DATA                             (1UL << 1)
#define FX3_I2C_INTR_RX_DONE                             (1UL << 0)

#define FX3_I2C_INTR_MASK_ERROR                          (1UL << 8)
#define FX3_I2C_INTR_MASK_LOST_ARBITRATION               (1UL << 7)
#define FX3_I2C_INTR_MASK_TIMEOUT                        (1UL << 6)
#define FX3_I2C_INTR_MASK_TX_HALF                        (1UL << 5)
#define FX3_I2C_INTR_MASK_TX_SPACE                       (1UL << 4)
#define FX3_I2C_INTR_MASK_TX_DONE                        (1UL << 3)
#define FX3_I2C_INTR_MASK_RX_HALF                        (1UL << 2)
#define FX3_I2C_INTR_MASK_RX_DATA                        (1UL << 1)
#define FX3_I2C_INTR_MASK_RX_DONE                        (1UL << 0)

#define FX3_I2C_DMA_TIMEOUT_TIMEOUT16_SHIFT              0
#define FX3_I2C_DMA_TIMEOUT_TIMEOUT16_BITS               16
#define FX3_I2C_DMA_TIMEOUT_TIMEOUT16_MASK               (0xffffUL << 0)

#define FX3_I2C_PREAMBLE_CTRL_STOP_SHIFT                 8
#define FX3_I2C_PREAMBLE_CTRL_STOP_BITS                  8
#define FX3_I2C_PREAMBLE_CTRL_STOP_MASK                  (0xffUL << 8)
#define FX3_I2C_PREAMBLE_CTRL_START_SHIFT                0
#define FX3_I2C_PREAMBLE_CTRL_START_BITS                 8
#define FX3_I2C_PREAMBLE_CTRL_START_MASK                 (0xffUL << 0)

#define FX3_I2C_PREAMBLE_DATA_DATA_SHIFT                 0
#define FX3_I2C_PREAMBLE_DATA_DATA_BITS                  64
#define FX3_I2C_PREAMBLE_DATA_DATA_MASK                  (0xffffffffffffffffUL << 0)

#define FX3_I2C_PREAMBLE_RPT_COUNT_SHIFT                 8
#define FX3_I2C_PREAMBLE_RPT_COUNT_BITS                  24
#define FX3_I2C_PREAMBLE_RPT_COUNT_MASK                  (0xffffffUL << 8)
#define FX3_I2C_PREAMBLE_RPT_STOP_ON_NACK                (1UL << 2)
#define FX3_I2C_PREAMBLE_RPT_STOP_ON_ACK                 (1UL << 1)
#define FX3_I2C_PREAMBLE_RPT_RPT_ENABLE                  (1UL << 0)

#define FX3_I2C_COMMAND_I2C_STAT_SHIFT                   30
#define FX3_I2C_COMMAND_I2C_STAT_BITS                    2
#define FX3_I2C_COMMAND_I2C_STAT_MASK                    (0x3UL << 30)
#define FX3_I2C_COMMAND_READ                             (1UL << 28)
#define FX3_I2C_COMMAND_START_FIRST                      (1UL << 7)
#define FX3_I2C_COMMAND_STOP_LAST                        (1UL << 6)
#define FX3_I2C_COMMAND_NAK_LAST                         (1UL << 5)
#define FX3_I2C_COMMAND_PREAMBLE_VALID                   (1UL << 4)
#define FX3_I2C_COMMAND_PREAMBLE_LEN_SHIFT               0
#define FX3_I2C_COMMAND_PREAMBLE_LEN_BITS                4
#define FX3_I2C_COMMAND_PREAMBLE_LEN_MASK                (0xfUL << 0)

#define FX3_I2C_EGRESS_DATA_DATA_SHIFT                   0
#define FX3_I2C_EGRESS_DATA_DATA_BITS                    8
#define FX3_I2C_EGRESS_DATA_DATA_MASK                    (0xffUL << 0)

#define FX3_I2C_INGRESS_DATA_DATA_SHIFT                  0
#define FX3_I2C_INGRESS_DATA_DATA_BITS                   8
#define FX3_I2C_INGRESS_DATA_DATA_MASK                   (0xffUL << 0)

#define FX3_I2C_SOCKET_INGRESS_SOCKET_SHIFT              8
#define FX3_I2C_SOCKET_INGRESS_SOCKET_BITS               8
#define FX3_I2C_SOCKET_INGRESS_SOCKET_MASK               (0xffUL << 8)
#define FX3_I2C_SOCKET_EGRESS_SOCKET_SHIFT               0
#define FX3_I2C_SOCKET_EGRESS_SOCKET_BITS                8
#define FX3_I2C_SOCKET_EGRESS_SOCKET_MASK                (0xffUL << 0)

#define FX3_I2C_ID_BLOCK_VERSION_SHIFT                   16
#define FX3_I2C_ID_BLOCK_VERSION_BITS                    16
#define FX3_I2C_ID_BLOCK_VERSION_MASK                    (0xffffUL << 16)
#define FX3_I2C_ID_BLOCK_ID_SHIFT                        0
#define FX3_I2C_ID_BLOCK_ID_BITS                         16
#define FX3_I2C_ID_BLOCK_ID_MASK                         (0xffffUL << 0)

#define FX3_I2C_POWER_RESETN                             (1UL << 31)
#define FX3_I2C_POWER_ACTIVE                             (1UL << 0)

#endif /* RDB_I2C_H_ */
