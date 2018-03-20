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

#ifndef BSP_REGACCESS_H_
#define BSP_REGACCESS_H_

#include <stdint.h>

#define Fx3ReadReg32(a)        (*(volatile uint32_t *)(void*)(a))
#define Fx3WriteReg32(a, v)    ((*(volatile uint32_t *)(void*)(a))=(uint32_t)(v))
#define Fx3SetReg32(a, v)      Fx3WriteReg32((a), Fx3ReadReg32((a)) | (v))
#define Fx3ClearReg32(a, v)    Fx3WriteReg32((a), Fx3ReadReg32((a)) & ~(v))
#define Fx3SetField32(a, f, v) Fx3WriteReg32((a), (Fx3ReadReg32((a)) & ~(a ## _ ## f ## _MASK)) | (((v) << (a ## _ ## f ## _SHIFT)) & (a ## _ ## f ## _MASK)))
#define Fx3GetField32(a, f)    ((Fx3ReadReg32((a)) & (a ## _ ## f ## _MASK)) >> (a ## _ ## f ## _SHIFT))

#endif /* BSP_REGACCESS_H_ */
