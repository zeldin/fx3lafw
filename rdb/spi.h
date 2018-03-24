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

#ifndef RDB_SPI_H_
#define RDB_SPI_H_

#define FX3_SPI_CONFIG                        0xE0000C00 /* SPI Configuration and Modes Register */
#define FX3_SPI_STATUS                        0xE0000C04 /* SPI Status Register */
#define FX3_SPI_INTR                          0xE0000C08 /* SPI Interrupt Request Register */
#define FX3_SPI_INTR_MASK                     0xE0000C0C /* SPI Interrupt Mask Register */
#define FX3_SPI_EGRESS_DATA                   0xE0000C10 /* SPI Egress Data Register */
#define FX3_SPI_INGRESS_DATA                  0xE0000C14 /* SPI Ingress Data Register */
#define FX3_SPI_SOCKET                        0xE0000C18 /* SPI Socket Register */
#define FX3_SPI_RX_BYTE_COUNT                 0xE0000C1C /* SPI Receive Byte Count Register */
#define FX3_SPI_TX_BYTE_COUNT                 0xE0000C20 /* SPI Transmit Byte Count Register */
#define FX3_SPI_ID                            0xE0000FF0 /* Block Identification and Version Number */
#define FX3_SPI_POWER                         0xE0000FF4 /* Power, Clock, and Reset Control */

#define FX3_SPI_CONFIG_ENABLE                            (1UL << 31)
#define FX3_SPI_CONFIG_TX_CLEAR                          (1UL << 30)
#define FX3_SPI_CONFIG_RX_CLEAR                          (1UL << 29)
#define FX3_SPI_CONFIG_DESELECT                          (1UL << 23)
#define FX3_SPI_CONFIG_WL_SHIFT                          17
#define FX3_SPI_CONFIG_WL_BITS                           6
#define FX3_SPI_CONFIG_WL_MASK                           (0x3fUL << 17)
#define FX3_SPI_CONFIG_SSPOL                             (1UL << 16)
#define FX3_SPI_CONFIG_LAG_SHIFT                         14
#define FX3_SPI_CONFIG_LAG_BITS                          2
#define FX3_SPI_CONFIG_LAG_MASK                          (0x3UL << 14)
#define FX3_SPI_CONFIG_LEAD_SHIFT                        12
#define FX3_SPI_CONFIG_LEAD_BITS                         2
#define FX3_SPI_CONFIG_LEAD_MASK                         (0x3UL << 12)
#define FX3_SPI_CONFIG_CPHA                              (1UL << 11)
#define FX3_SPI_CONFIG_CPOL                              (1UL << 10)
#define FX3_SPI_CONFIG_SSNCTRL_SHIFT                     8
#define FX3_SPI_CONFIG_SSNCTRL_BITS                      2
#define FX3_SPI_CONFIG_SSNCTRL_MASK                      (0x3UL << 8)
#define FX3_SPI_CONFIG_LOOPBACK                          (1UL << 5)
#define FX3_SPI_CONFIG_SSN_BIT                           (1UL << 4)
#define FX3_SPI_CONFIG_ENDIAN                            (1UL << 3)
#define FX3_SPI_CONFIG_DMA_MODE                          (1UL << 2)
#define FX3_SPI_CONFIG_TX_ENABLE                         (1UL << 1)
#define FX3_SPI_CONFIG_RX_ENABLE                         (1UL << 0)

#define FX3_SPI_STATUS_BUSY                              (1UL << 28)
#define FX3_SPI_STATUS_ERROR_CODE_SHIFT                  24
#define FX3_SPI_STATUS_ERROR_CODE_BITS                   4
#define FX3_SPI_STATUS_ERROR_CODE_MASK                   (0xfUL << 24)
#define FX3_SPI_STATUS_ERROR                             (1UL << 6)
#define FX3_SPI_STATUS_TX_HALF                           (1UL << 5)
#define FX3_SPI_STATUS_TX_SPACE                          (1UL << 4)
#define FX3_SPI_STATUS_TX_DONE                           (1UL << 3)
#define FX3_SPI_STATUS_RX_HALF                           (1UL << 2)
#define FX3_SPI_STATUS_RX_DATA                           (1UL << 1)
#define FX3_SPI_STATUS_RX_DONE                           (1UL << 0)

#define FX3_SPI_INTR_ERROR                               (1UL << 6)
#define FX3_SPI_INTR_TX_HALF                             (1UL << 5)
#define FX3_SPI_INTR_TX_SPACE                            (1UL << 4)
#define FX3_SPI_INTR_TX_DONE                             (1UL << 3)
#define FX3_SPI_INTR_RX_HALF                             (1UL << 2)
#define FX3_SPI_INTR_RX_DATA                             (1UL << 1)
#define FX3_SPI_INTR_RX_DONE                             (1UL << 0)

#define FX3_SPI_INTR_MASK_ERROR                          (1UL << 6)
#define FX3_SPI_INTR_MASK_TX_HALF                        (1UL << 5)
#define FX3_SPI_INTR_MASK_TX_SPACE                       (1UL << 4)
#define FX3_SPI_INTR_MASK_TX_DONE                        (1UL << 3)
#define FX3_SPI_INTR_MASK_RX_HALF                        (1UL << 2)
#define FX3_SPI_INTR_MASK_RX_DATA                        (1UL << 1)
#define FX3_SPI_INTR_MASK_RX_DONE                        (1UL << 0)

#define FX3_SPI_SOCKET_INGRESS_SOCKET_SHIFT              8
#define FX3_SPI_SOCKET_INGRESS_SOCKET_BITS               8
#define FX3_SPI_SOCKET_INGRESS_SOCKET_MASK               (0xffUL << 8)
#define FX3_SPI_SOCKET_EGRESS_SOCKET_SHIFT               0
#define FX3_SPI_SOCKET_EGRESS_SOCKET_BITS                8
#define FX3_SPI_SOCKET_EGRESS_SOCKET_MASK                (0xffUL << 0)

#define FX3_SPI_ID_BLOCK_VERSION_SHIFT                   16
#define FX3_SPI_ID_BLOCK_VERSION_BITS                    16
#define FX3_SPI_ID_BLOCK_VERSION_MASK                    (0xffffUL << 16)
#define FX3_SPI_ID_BLOCK_ID_SHIFT                        0
#define FX3_SPI_ID_BLOCK_ID_BITS                         16
#define FX3_SPI_ID_BLOCK_ID_MASK                         (0xffffUL << 0)

#define FX3_SPI_POWER_RESETN                             (1UL << 31)
#define FX3_SPI_POWER_ACTIVE                             (1UL << 0)

#endif /* RDB_SPI_H_ */
