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

#ifndef RDB_LPP_H_
#define RDB_LPP_H_

#define FX3_LPP_ID                            0xE0007F00 /* Block Identification and Version Number */
#define FX3_LPP_POWER                         0xE0007F04 /* Power, Clock, and Reset Control */

#define FX3_LPP_ID_BLOCK_VERSION_SHIFT                   16
#define FX3_LPP_ID_BLOCK_VERSION_BITS                    16
#define FX3_LPP_ID_BLOCK_VERSION_MASK                    (0xffffUL << 16)
#define FX3_LPP_ID_BLOCK_ID_SHIFT                        0
#define FX3_LPP_ID_BLOCK_ID_BITS                         16
#define FX3_LPP_ID_BLOCK_ID_MASK                         (0xffffUL << 0)

#define FX3_LPP_POWER_RESETN                             (1UL << 31)
#define FX3_LPP_POWER_ACTIVE                             (1UL << 0)

#endif /* RDB_LPP_H_ */
