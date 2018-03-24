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

#ifndef RDB_VIC_H_
#define RDB_VIC_H_

#define FX3_VIC_IRQ_STATUS                    0xFFFFF000 /* IRQ Status after Masking */
#define FX3_VIC_FIQ_STATUS                    0xFFFFF004 /* FIQ Status after Masking */
#define FX3_VIC_RAW_STATUS                    0xFFFFF008 /* IRQ Status before Masking */
#define FX3_VIC_INT_SELECT                    0xFFFFF00C /* IRQ/FIQ Designation Register */
#define FX3_VIC_INT_ENABLE                    0xFFFFF010 /* Interrupt Enable Register */
#define FX3_VIC_INT_CLEAR                     0xFFFFF014 /* Interrupt Clear Register */
#define FX3_VIC_PRIORITY_MASK                 0xFFFFF024 /* Per-Priority Interrupt Mask Register */
#define FX3_VIC_VEC_ADDRESS                   0xFFFFF100 /* Interrupt Vector Register */
#define FX3_VIC_VECT_PRIORITY                 0xFFFFF200 /* Interrupt Priority Register */
#define FX3_VIC_ADDRESS                       0xFFFFFF00 /* Active ISR Address Register */

#define FX3_VIC_PRIORITY_MASK_PRIO_MASK_SHIFT            0
#define FX3_VIC_PRIORITY_MASK_PRIO_MASK_BITS             16
#define FX3_VIC_PRIORITY_MASK_PRIO_MASK_MASK             (0xffffUL << 0)

#define FX3_VIC_VECT_PRIORITY_VIC_INTR_PRI_SHIFT         0
#define FX3_VIC_VECT_PRIORITY_VIC_INTR_PRI_BITS          4
#define FX3_VIC_VECT_PRIORITY_VIC_INTR_PRI_MASK          (0xfUL << 0)

#endif /* RDB_VIC_H_ */
