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

#ifndef BSP_UART_H_
#define BSP_UART_H_

#include <stdint.h>
#include <stddef.h>
#include <rdb/uart.h>

typedef enum {
  FX3_UART_NO_PARITY    = 0,
  FX3_UART_EVEN_PARITY  = FX3_UART_CONFIG_PARITY,
  FX3_UART_ODD_PARITY   = FX3_UART_CONFIG_PARITY | FX3_UART_CONFIG_PARITY_ODD,
  FX3_UART_SPACE_PARITY = FX3_UART_CONFIG_PARITY | FX3_UART_CONFIG_PARITY_STICKY,
  FX3_UART_MARK_PARITY  = FX3_UART_CONFIG_PARITY | FX3_UART_CONFIG_PARITY_STICKY | FX3_UART_CONFIG_TX_STICKY_BIT | FX3_UART_CONFIG_RX_STICKY_BIT,
} Fx3UartParity_t;

typedef enum {
  FX3_UART_1_STOP_BIT  = 1UL << FX3_UART_CONFIG_STOP_BITS_SHIFT,
  FX3_UART_2_STOP_BITS = 2UL << FX3_UART_CONFIG_STOP_BITS_SHIFT,
} Fx3UartStopBits_t;

extern void Fx3UartInit(uint32_t baud_rate, Fx3UartParity_t parity, Fx3UartStopBits_t stop_bits);
extern void Fx3UartTxByte(uint8_t byte);
extern void Fx3UartTxBytes(const uint8_t *byte, size_t cnt);
extern void Fx3UartTxChar(char c);
extern void Fx3UartTxString(const char *str);
extern void Fx3UartTxFlush(void);

#endif /* BSP_UART_H_ */
