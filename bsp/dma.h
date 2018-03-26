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

#ifndef BSP_DMA_H_
#define BSP_DMA_H_

#include <stdint.h>

#define FX3_LPP_DMA_SCK(n)   (0xE0008000+((n)<<7))
#define FX3_PIB_DMA_SCK(n)   (0xE0018000+((n)<<7))
#define FX3_UIB_DMA_SCK(n)   (0xE0038000+((n)<<7))
#define FX3_UIBIN_DMA_SCK(n) (0xE0048000+((n)<<7))

#define FX3_DMA_SOCKET_IP(s)  (((s) >> 16) & 0x3FUL)
#define FX3_DMA_SOCKET_SCK(s) (((s) >> 7)  & 0xFFUL)

#define FX3_DMA_DESCRIPTOR(n) /* 1 <= n < 768 */   \
  ((volatile struct Fx3DmaDescriptor *)(void *)(0x40000000 + ((n) << 4)))

struct Fx3DmaDescriptor {
  uint32_t dscr_buffer;
  uint32_t dscr_sync;
  uint32_t dscr_chain;
  uint32_t dscr_size;
};

extern uint16_t Fx3DmaAllocateDescriptor(void);
extern void Fx3DmaFreeDescriptor(uint16_t d);
extern void Fx3DmaAbortSocket(uint32_t socket);
extern void Fx3DmaSimpleTransferRead(uint32_t socket, uint16_t descriptor,
				     const volatile void *buffer, uint16_t length);
extern void Fx3DmaSimpleTransferWrite(uint32_t socket, uint16_t descriptor,
				      volatile void *buffer, uint16_t length);

#endif /* BSP_DMA_H_ */
