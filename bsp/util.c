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

#include <bsp/util.h>
#include <bsp/gctl.h>

#include <errno.h>

void Fx3UtilDelayUs(uint32_t delay_us)
{
  /* Each loop is 4 instruction cycles */
  uint32_t cnt = delay_us * (CPU_CLK / 4 / 1000000);
  __asm__ __volatile__("1: subs %0,%0,#1; bcs 1b" : "=r"(cnt) : "0"(cnt) : "cc");
}

void exit(int status)
{
  (void)status;

  Fx3GctlHardReset();

  for(;;)
    ;
}

void *_sbrk(intptr_t increment)
{
  extern char _end[];
  extern char __heap_end[];
  static void *current_brk = _end;

  if (increment > __heap_end - (char *)current_brk) {
    errno = ENOMEM;
    return (void *)-1;
  }

  void *ret = current_brk;
  current_brk = increment + (char *)current_brk;
  return ret;
}
