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

#ifndef BSP_GPIO_H_
#define BSP_GPIO_H_

#include <stdint.h>
#include <rdb/gpio.h>
#include <bsp/gctl.h>

#ifndef GPIO_FAST_DIV
#define GPIO_FAST_DIV 2
#endif

#ifndef GPIO_SLOW_DIV
#define GPIO_SLOW_DIV 48
#endif

#define GPIO_FAST_CLK (SYS_CLK / GPIO_FAST_DIV)

#define GPIO_SLOW_CLK (GPIO_FAST_CLK / GPIO_SLOW_DIV)


typedef enum {
  FX3_GPIO_TIMER_MODE_SHUTDOWN = 0,
  FX3_GPIO_TIMER_MODE_FAST_CLK,
  FX3_GPIO_TIMER_MODE_SLOW_CLK,
  FX3_GPIO_TIMER_MODE_STANDBY_CLK,
  FX3_GPIO_TIMER_MODE_POS_EDGE,
  FX3_GPIO_TIMER_MODE_NEG_EDGE,
  FX3_GPIO_TIMER_MODE_ANY_EDGE,
} Fx3GpioTimerMode_t;

typedef enum {
  FX3_GPIO_INTR_MODE_NONE = 0,
  FX3_GPIO_INTR_MODE_POS_EDGE,
  FX3_GPIO_INTR_MODE_NEG_EDGE,
  FX3_GPIO_INTR_MODE_ANY_EDGE,
  FX3_GPIO_INTR_MODE_LOW_LEVEL,
  FX3_GPIO_INTR_MODE_HIGH_LEVEL,
  FX3_GPIO_INTR_MODE_TIMER_THRESHOLD,
  FX3_GPIO_INTR_MODE_TIMER_0,
} Fx3GpioIntrMode_t;

typedef enum {
  FX3_GPIO_PIN_MODE_STATIC = 0,
  FX3_GPIO_PIN_MODE_TOGGLE,
  FX3_GPIO_PIN_MODE_SAMPLENOW,
  FX3_GPIO_PIN_MODE_PULSENOW,
  FX3_GPIO_PIN_MODE_PULSE,
  FX3_GPIO_PIN_MODE_PWM,
  FX3_GPIO_PIN_MODE_MEASURE_LOW,
  FX3_GPIO_PIN_MODE_MEASURE_HIGH,
  FX3_GPIO_PIN_MODE_MEASURE_LOW_ONCE,
  FX3_GPIO_PIN_MODE_MEASURE_HIGH_ONCE,
  FX3_GPIO_PIN_MODE_MEASURE_NEG,
  FX3_GPIO_PIN_MODE_MEASURE_POS,
  FX3_GPIO_PIN_MODE_MEASURE_ANY,
  FX3_GPIO_PIN_MODE_MEASURE_NEG_ONCE,
  FX3_GPIO_PIN_MODE_MEASURE_POS_ONCE,
  FX3_GPIO_PIN_MODE_MEASURE_ANY_ONCE,
} Fx3GpioPinMode_t;

extern void Fx3GpioInitClock(void);
extern void Fx3GpioSetupSimple(uint8_t num, uint32_t config);
extern void Fx3GpioSetupComplex(uint8_t num, uint32_t config, uint32_t timer,
				uint32_t period, uint32_t threshold);
extern void Fx3GpioSetOutputValueSimple(uint8_t num, uint8_t value);
extern uint8_t Fx3GpioGetInputValueSimple(uint8_t num);

#endif /* BSP_GPIO_H_ */
