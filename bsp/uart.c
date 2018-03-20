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

#include <bsp/uart.h>
#include <bsp/regaccess.h>
#include <bsp/util.h>
#include <rdb/uart.h>
#include <rdb/gctl.h>

void Fx3UartInit(uint32_t baud_rate, Fx3UartParity_t parity, Fx3UartStopBits_t stop_bits)
{
  /* Configure baud rate generator */
  Fx3WriteReg32(FX3_GCTL_UART_CORE_CLK,
		(((SYS_CLK/8 / baud_rate - 1) << FX3_GCTL_UART_CORE_CLK_DIV_SHIFT) & FX3_GCTL_UART_CORE_CLK_DIV_MASK) |
		(3UL << FX3_GCTL_UART_CORE_CLK_SRC_SHIFT) |
		FX3_GCTL_UART_CORE_CLK_CLK_EN);

  /* Reset UART */
  Fx3WriteReg32(FX3_UART_POWER, 0);
  Fx3UtilDelayUs(10);
  Fx3WriteReg32(FX3_UART_POWER, FX3_UART_POWER_RESETN);
  while(!(Fx3ReadReg32(FX3_UART_POWER) & FX3_UART_POWER_ACTIVE))
    ;

  /* Configure and enable UART */
  Fx3WriteReg32(FX3_UART_CONFIG,
		stop_bits | parity |
		FX3_UART_CONFIG_ENABLE |
		FX3_UART_CONFIG_TX_ENABLE);
}

void Fx3UartTxByte(uint8_t byte)
{
  while(!(Fx3ReadReg32(FX3_UART_STATUS) & FX3_UART_STATUS_TX_SPACE))
    ;
  Fx3WriteReg32(FX3_UART_EGRESS_DATA, byte);
}

void Fx3UartTxBytes(const uint8_t *byte, size_t cnt)
{
  while(cnt--)
    Fx3UartTxByte(*byte++);
}

extern void Fx3UartTxChar(char c)
{
  if (c == '\n')
    Fx3UartTxByte('\r');
  Fx3UartTxByte(c);
}

extern void Fx3UartTxString(const char *str)
{
  char c;
  while ((c = *str++))
    Fx3UartTxChar(c);
}

void Fx3UartTxFlush(void)
{
  while(!(Fx3ReadReg32(FX3_UART_STATUS) & FX3_UART_STATUS_TX_DONE))
    ;
}
