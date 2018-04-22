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

#include <bsp/dma.h>
#include <bsp/regaccess.h>
#include <bsp/cache.h>
#include <bsp/uart.h>
#include <rdb/dma.h>

#define FX3_SCK_STATUS_DEFAULT			\
  ( FX3_SCK_STATUS_SUSP_TRANS	   |		\
    FX3_SCK_STATUS_EN_CONS_EVENTS  |		\
    FX3_SCK_STATUS_EN_PROD_EVENTS  |		\
    FX3_SCK_STATUS_TRUNCATE )

static uint16_t Fx3DmaDescriptorFirstUnallocated = 1;
static uint16_t Fx3DmaDescriptorFreeListHead = 0;

uint16_t Fx3DmaAllocateDescriptor(void)
{
  uint16_t r;
  if ((r = Fx3DmaDescriptorFreeListHead)) {
    /* Pick first off free list */
    volatile struct Fx3DmaDescriptor *desc = FX3_DMA_DESCRIPTOR(r);
    Fx3DmaDescriptorFreeListHead = desc->dscr_chain;
  } else if(Fx3DmaDescriptorFirstUnallocated < 768) {
    /* Allocate a fresh one */
    r = Fx3DmaDescriptorFirstUnallocated++;
  }
  return r;
}

void Fx3DmaFreeDescriptor(uint16_t d)
{
  if (d) {
    /* Put on head of free list */
    volatile struct Fx3DmaDescriptor *desc = FX3_DMA_DESCRIPTOR(d);
    desc->dscr_chain = Fx3DmaDescriptorFreeListHead;
    Fx3DmaDescriptorFreeListHead = d;
  }
}

void Fx3DmaAbortSocket(uint32_t socket)
{
  Fx3ClearReg32(socket + FX3_SCK_STATUS,
		FX3_SCK_STATUS_GO_ENABLE |
		FX3_SCK_STATUS_WRAPUP);
  Fx3WriteReg32(socket + FX3_SCK_INTR, ~0);
  while((Fx3ReadReg32(socket + FX3_SCK_STATUS) & FX3_SCK_STATUS_ENABLED))
    ;
}

static void Fx3DmaFillDescriptor(uint16_t descriptor, uint32_t buffer,
				 uint32_t sync, uint32_t size, uint16_t chain)
{
  volatile struct Fx3DmaDescriptor *desc = FX3_DMA_DESCRIPTOR(descriptor);

  if (!(size & FX3_DSCR_SIZE_BUFFER_SIZE_MASK))
    size |= 1UL << FX3_DSCR_SIZE_BUFFER_SIZE_SHIFT;

  desc->dscr_buffer = buffer;
  desc->dscr_sync = sync;
  desc->dscr_size = size;
  desc->dscr_chain =
    (chain << FX3_DSCR_CHAIN_WR_NEXT_DSCR_SHIFT) |
    (chain << FX3_DSCR_CHAIN_RD_NEXT_DSCR_SHIFT);

  Fx3CacheCleanDCacheEntry(desc);
}

static void Fx3DmaTransferStart(uint32_t socket, uint16_t descriptor,
				uint32_t status, uint32_t size, uint32_t count)
{
  Fx3WriteReg32(socket + FX3_SCK_STATUS, FX3_SCK_STATUS_DEFAULT);
  while((Fx3ReadReg32(socket + FX3_SCK_STATUS) & FX3_SCK_STATUS_ENABLED))
    ;

  Fx3WriteReg32(socket + FX3_SCK_STATUS, status);
  Fx3WriteReg32(socket + FX3_SCK_INTR, ~0UL);
  Fx3WriteReg32(socket + FX3_SCK_DSCR,
		(0UL << FX3_SCK_DSCR_DSCR_LOW_SHIFT) |
		(0UL << FX3_SCK_DSCR_DSCR_COUNT_SHIFT) |
		(descriptor << FX3_SCK_DSCR_DSCR_NUMBER_SHIFT));
  Fx3WriteReg32(socket + FX3_SCK_SIZE, size);
  Fx3WriteReg32(socket + FX3_SCK_COUNT, count);

  Fx3SetReg32(socket + FX3_SCK_STATUS,
	      FX3_SCK_STATUS_GO_ENABLE);
}

static void Fx3DmaWaitForEvent(uint32_t socket, uint32_t event)
{
  for(;;) {
    uint32_t status = Fx3ReadReg32(socket + FX3_SCK_INTR);
    if (status & FX3_SCK_INTR_ERROR) {
      Fx3UartTxString("DMA error\n");
      return;
    }
    if (status & event)
      return;

    /* timeout? */
  }
}

void Fx3DmaFillDescriptorThrough(uint32_t prod_socket, uint32_t cons_socket,
				 uint16_t descriptor, volatile void *buffer,
				 uint16_t length, uint16_t chain)
{
  Fx3DmaFillDescriptor(descriptor, (uint32_t)buffer,
		       FX3_DSCR_SYNC_EN_PROD_INT |
		       FX3_DSCR_SYNC_EN_PROD_EVENT |
		       (FX3_DMA_SOCKET_IP(prod_socket) << FX3_DSCR_SYNC_PROD_IP_SHIFT) |
		       (FX3_DMA_SOCKET_SCK(prod_socket) << FX3_DSCR_SYNC_PROD_SCK_SHIFT) |
		       FX3_DSCR_SYNC_EN_CONS_INT |
		       FX3_DSCR_SYNC_EN_CONS_EVENT |
		       (FX3_DMA_SOCKET_IP(cons_socket) << FX3_DSCR_SYNC_CONS_IP_SHIFT) |
		       (FX3_DMA_SOCKET_SCK(cons_socket) << FX3_DSCR_SYNC_CONS_SCK_SHIFT),
		       (length + 15) & FX3_DSCR_SIZE_BUFFER_SIZE_MASK, chain);
}

void Fx3DmaFillDescriptorRead(uint32_t socket, uint16_t descriptor,
			      const volatile void *buffer, uint16_t length,
			      uint16_t chain)
{
  Fx3DmaFillDescriptor(descriptor, (uint32_t)buffer,
		       FX3_DSCR_SYNC_EN_PROD_INT |
		       FX3_DSCR_SYNC_EN_PROD_EVENT |
		       (0x3FUL << FX3_DSCR_SYNC_PROD_IP_SHIFT) |
		       FX3_DSCR_SYNC_EN_CONS_INT |
		       FX3_DSCR_SYNC_EN_CONS_EVENT |
		       (FX3_DMA_SOCKET_IP(socket) << FX3_DSCR_SYNC_CONS_IP_SHIFT) |
		       (FX3_DMA_SOCKET_SCK(socket) << FX3_DSCR_SYNC_CONS_SCK_SHIFT),
		       (length << FX3_DSCR_SIZE_BYTE_COUNT_SHIFT) |
		       ((length + 15) & FX3_DSCR_SIZE_BUFFER_SIZE_MASK) |
		       FX3_DSCR_SIZE_BUFFER_OCCUPIED, chain);
}

void Fx3DmaFillDescriptorWrite(uint32_t socket, uint16_t descriptor,
			       volatile void *buffer, uint16_t length,
			       uint16_t chain)
{
  Fx3DmaFillDescriptor(descriptor, (uint32_t)buffer,
		       FX3_DSCR_SYNC_EN_PROD_INT |
		       FX3_DSCR_SYNC_EN_PROD_EVENT |
		       (FX3_DMA_SOCKET_IP(socket) << FX3_DSCR_SYNC_PROD_IP_SHIFT) |
		       (FX3_DMA_SOCKET_SCK(socket) << FX3_DSCR_SYNC_PROD_SCK_SHIFT) |
		       FX3_DSCR_SYNC_EN_CONS_INT |
		       FX3_DSCR_SYNC_EN_CONS_EVENT |
		       (0x3FUL << FX3_DSCR_SYNC_CONS_IP_SHIFT),
		       (length + 15) & FX3_DSCR_SIZE_BUFFER_SIZE_MASK, chain);
}

void Fx3DmaSimpleTransferRead(uint32_t socket, uint16_t descriptor,
			      const volatile void *buffer, uint16_t length)
{
  Fx3DmaFillDescriptorRead(socket, descriptor, buffer, length, 0xFFFFU);
  Fx3DmaTransferStart(socket, descriptor,
		      FX3_SCK_STATUS_DEFAULT | FX3_SCK_STATUS_UNIT, 1, 0);
  Fx3DmaWaitForEvent(socket, FX3_SCK_INTR_CONSUME_EVENT);
}

void Fx3DmaSimpleTransferWrite(uint32_t socket, uint16_t descriptor,
			       volatile void *buffer, uint16_t length)
{
  Fx3DmaFillDescriptorWrite(socket, descriptor, buffer, length, 0xFFFFU);
  Fx3DmaTransferStart(socket, descriptor,
		      FX3_SCK_STATUS_DEFAULT | FX3_SCK_STATUS_UNIT, 1, 0);
  Fx3DmaWaitForEvent(socket, FX3_SCK_INTR_PRODUCE_EVENT);
}

void Fx3DmaStartProducer(uint32_t socket, uint16_t descriptor,
			 uint32_t size, uint32_t count)
{
  Fx3DmaTransferStart(socket, descriptor,
		      FX3_SCK_STATUS_SUSP_TRANS	|
		      FX3_SCK_STATUS_EN_PROD_EVENTS |
		      FX3_SCK_STATUS_TRUNCATE,
		      size, count);
}

void Fx3DmaStartConsumer(uint32_t socket, uint16_t descriptor,
			 uint32_t size, uint32_t count)
{
  Fx3DmaTransferStart(socket, descriptor,
		      FX3_SCK_STATUS_SUSP_TRANS	|
		      FX3_SCK_STATUS_EN_CONS_EVENTS |
		      FX3_SCK_STATUS_TRUNCATE,
		      size, count);
}
