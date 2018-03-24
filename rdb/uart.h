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

#ifndef RDB_UART_H_
#define RDB_UART_H_

#define FX3_UART_CONFIG                       0xE0000800 /* UART Configuration and Mode Register */
#define FX3_UART_STATUS                       0xE0000804 /* UART Status Register */
#define FX3_UART_INTR                         0xE0000808 /* UART Interrupt Request Register */
#define FX3_UART_INTR_MASK                    0xE000080C /* UART Interrupt Mask Register */
#define FX3_UART_EGRESS_DATA                  0xE0000810 /* UART Egress Data Register */
#define FX3_UART_INGRESS_DATA                 0xE0000814 /* UART Ingress Data Register */
#define FX3_UART_SOCKET                       0xE0000818 /* UART Socket Register */
#define FX3_UART_RX_BYTE_COUNT                0xE000081C /* UART Receive Byte Count Register */
#define FX3_UART_TX_BYTE_COUNT                0xE0000820 /* UART Transmit Byte Count Register */
#define FX3_UART_ID                           0xE0000BF0 /* Block Identification and Version Number */
#define FX3_UART_POWER                        0xE0000BF4 /* Power, Clock, and Reset Control */

#define FX3_UART_CONFIG_ENABLE                           (1UL << 31)
#define FX3_UART_CONFIG_TX_CLEAR                         (1UL << 30)
#define FX3_UART_CONFIG_RX_CLEAR                         (1UL << 29)
#define FX3_UART_CONFIG_RX_POLL_SHIFT                    16
#define FX3_UART_CONFIG_RX_POLL_BITS                     4
#define FX3_UART_CONFIG_RX_POLL_MASK                     (0xfUL << 16)
#define FX3_UART_CONFIG_TX_BREAK                         (1UL << 15)
#define FX3_UART_CONFIG_RX_FLOW_CTRL_ENBL                (1UL << 14)
#define FX3_UART_CONFIG_TX_FLOW_CTRL_ENBL                (1UL << 13)
#define FX3_UART_CONFIG_RTS                              (1UL << 12)
#define FX3_UART_CONFIG_DMA_MODE                         (1UL << 10)
#define FX3_UART_CONFIG_STOP_BITS_SHIFT                  8
#define FX3_UART_CONFIG_STOP_BITS_BITS                   2
#define FX3_UART_CONFIG_STOP_BITS_MASK                   (0x3UL << 8)
#define FX3_UART_CONFIG_RX_STICKY_BIT                    (1UL << 7)
#define FX3_UART_CONFIG_TX_STICKY_BIT                    (1UL << 6)
#define FX3_UART_CONFIG_PARITY_STICKY                    (1UL << 5)
#define FX3_UART_CONFIG_PARITY_ODD                       (1UL << 4)
#define FX3_UART_CONFIG_PARITY                           (1UL << 3)
#define FX3_UART_CONFIG_LOOP_BACK                        (1UL << 2)
#define FX3_UART_CONFIG_TX_ENABLE                        (1UL << 1)
#define FX3_UART_CONFIG_RX_ENABLE                        (1UL << 0)

#define FX3_UART_STATUS_BUSY                             (1UL << 28)
#define FX3_UART_STATUS_ERROR_CODE_SHIFT                 24
#define FX3_UART_STATUS_ERROR_CODE_BITS                  4
#define FX3_UART_STATUS_ERROR_CODE_MASK                  (0xfUL << 24)
#define FX3_UART_STATUS_ERROR                            (1UL << 9)
#define FX3_UART_STATUS_BREAK                            (1UL << 8)
#define FX3_UART_STATUS_CTS_TOGGLE                       (1UL << 7)
#define FX3_UART_STATUS_CTS_STAT                         (1UL << 6)
#define FX3_UART_STATUS_TX_HALF                          (1UL << 5)
#define FX3_UART_STATUS_TX_SPACE                         (1UL << 4)
#define FX3_UART_STATUS_TX_DONE                          (1UL << 3)
#define FX3_UART_STATUS_RX_HALF                          (1UL << 2)
#define FX3_UART_STATUS_RX_DATA                          (1UL << 1)
#define FX3_UART_STATUS_RX_DONE                          (1UL << 0)

#define FX3_UART_INTR_ERROR                              (1UL << 9)
#define FX3_UART_INTR_BREAK                              (1UL << 8)
#define FX3_UART_INTR_CTS_TOGGLE                         (1UL << 7)
#define FX3_UART_INTR_CTS_STAT                           (1UL << 6)
#define FX3_UART_INTR_TX_HALF                            (1UL << 5)
#define FX3_UART_INTR_TX_SPACE                           (1UL << 4)
#define FX3_UART_INTR_TX_DONE                            (1UL << 3)
#define FX3_UART_INTR_RX_HALF                            (1UL << 2)
#define FX3_UART_INTR_RX_DATA                            (1UL << 1)
#define FX3_UART_INTR_RX_DONE                            (1UL << 0)

#define FX3_UART_INTR_MASK_ERROR                         (1UL << 9)
#define FX3_UART_INTR_MASK_BREAK                         (1UL << 8)
#define FX3_UART_INTR_MASK_CTS_TOGGLE                    (1UL << 7)
#define FX3_UART_INTR_MASK_CTS_STAT                      (1UL << 6)
#define FX3_UART_INTR_MASK_TX_HALF                       (1UL << 5)
#define FX3_UART_INTR_MASK_TX_SPACE                      (1UL << 4)
#define FX3_UART_INTR_MASK_TX_DONE                       (1UL << 3)
#define FX3_UART_INTR_MASK_RX_HALF                       (1UL << 2)
#define FX3_UART_INTR_MASK_RX_DATA                       (1UL << 1)
#define FX3_UART_INTR_MASK_RX_DONE                       (1UL << 0)

#define FX3_UART_EGRESS_DATA_DATA_SHIFT                  0
#define FX3_UART_EGRESS_DATA_DATA_BITS                   8
#define FX3_UART_EGRESS_DATA_DATA_MASK                   (0xffUL << 0)

#define FX3_UART_INGRESS_DATA_DATA_SHIFT                 0
#define FX3_UART_INGRESS_DATA_DATA_BITS                  8
#define FX3_UART_INGRESS_DATA_DATA_MASK                  (0xffUL << 0)

#define FX3_UART_SOCKET_INGRESS_SOCKET_SHIFT             8
#define FX3_UART_SOCKET_INGRESS_SOCKET_BITS              8
#define FX3_UART_SOCKET_INGRESS_SOCKET_MASK              (0xffUL << 8)
#define FX3_UART_SOCKET_EGRESS_SOCKET_SHIFT              0
#define FX3_UART_SOCKET_EGRESS_SOCKET_BITS               8
#define FX3_UART_SOCKET_EGRESS_SOCKET_MASK               (0xffUL << 0)

#define FX3_UART_ID_BLOCK_VERSION_SHIFT                  16
#define FX3_UART_ID_BLOCK_VERSION_BITS                   16
#define FX3_UART_ID_BLOCK_VERSION_MASK                   (0xffffUL << 16)
#define FX3_UART_ID_BLOCK_ID_SHIFT                       0
#define FX3_UART_ID_BLOCK_ID_BITS                        16
#define FX3_UART_ID_BLOCK_ID_MASK                        (0xffffUL << 0)

#define FX3_UART_POWER_RESETN                            (1UL << 31)
#define FX3_UART_POWER_ACTIVE                            (1UL << 0)

#endif /* RDB_UART_H_ */
