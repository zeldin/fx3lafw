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

#ifndef BSP_CACHE_H_
#define BSP_CACHE_H_

#include <stdint.h>

static inline void Fx3CacheInvalidateICacheAndDCache(void)
{
  __asm__ __volatile__("mcr p15, 0, %0, c7, c7, 0" : : "r"(0));
}

static inline void Fx3CacheInvalidateICache(void)
{
  __asm__ __volatile__("mcr p15, 0, %0, c7, c5, 0" : : "r"(0));
}

static inline void Fx3CacheCleanDCache(void)
{
  __asm__ __volatile__("1: mrc p15, 0, r15, c7, c10, 3;	bne 1b" ::: "cc");
}

static inline void Fx3CacheCleanDCacheEntry(volatile void *ptr)
{
  __asm__ __volatile__("mcr p15, 0, %0, c7, c10, 1" : : "r"(((uint32_t)ptr) & ~0x1FUL));
}

static inline void Fx3CacheInvalidateDCacheEntry(volatile void *ptr)
{
  __asm__ __volatile__("mcr p15, 0, %0, c7, c6, 1" : : "r"(((uint32_t)ptr) & ~0x1FUL));
}

extern void Fx3CacheEnableCaches(void);

#endif /* BSP_CACHE_H_ */
