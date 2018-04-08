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

#include <bsp/gpif.h>
#include <bsp/regaccess.h>
#include <bsp/util.h>
#include <bsp/uart.h>
#include <rdb/gctl.h>
#include <rdb/pib.h>
#include <rdb/vic.h>

static void Fx3GpifPibIsr(void) __attribute__ ((isr ("IRQ")));

static void Fx3GpifPibIsr(void)
{
  uint32_t req = Fx3ReadReg32(FX3_PIB_INTR) & Fx3ReadReg32(FX3_PIB_INTR_MASK);
  Fx3WriteReg32(FX3_PIB_INTR, req);

  Fx3UartTxString("Fx3GpifPibIsr\n");

  Fx3WriteReg32(FX3_VIC_ADDRESS, 0);
}


void Fx3GpifStart(uint8_t state, uint8_t alpha)
{
  Fx3SetField32(FX3_GPIF_WAVEFORM_CTRL_STAT, ALPHA_INIT, alpha);
  Fx3SetReg32(FX3_GPIF_WAVEFORM_CTRL_STAT,
	      FX3_GPIF_WAVEFORM_CTRL_STAT_WAVEFORM_VALID);
  Fx3WriteReg32(FX3_GPIF_WAVEFORM_SWITCH,
		(Fx3ReadReg32(FX3_GPIF_WAVEFORM_SWITCH) &
		 ~(FX3_GPIF_WAVEFORM_SWITCH_DESTINATION_STATE_SHIFT |
		   FX3_GPIF_WAVEFORM_SWITCH_TERMINAL_STATE_MASK |
		   FX3_GPIF_WAVEFORM_SWITCH_SWITCH_NOW |
		   FX3_GPIF_WAVEFORM_SWITCH_WAVEFORM_SWITCH)) |
		(state << FX3_GPIF_WAVEFORM_SWITCH_DESTINATION_STATE_SHIFT));
  Fx3SetReg32(FX3_GPIF_WAVEFORM_SWITCH,
	      FX3_GPIF_WAVEFORM_SWITCH_SWITCH_NOW |
	      FX3_GPIF_WAVEFORM_SWITCH_WAVEFORM_SWITCH);
}

void Fx3GpifStop(void)
{
  Fx3SetReg32(FX3_GPIF_WAVEFORM_CTRL_STAT, FX3_GPIF_WAVEFORM_CTRL_STAT_PAUSE);
  Fx3UtilDelayUs(10);
  Fx3WriteReg32(FX3_GPIF_WAVEFORM_CTRL_STAT, 0);
}

void Fx3GpifInvalidate(void)
{
  unsigned i;
  Fx3WriteReg32(FX3_GPIF_CONFIG, 0x220);
  for (i=0; i<256; i++) {
    Fx3WriteReg32(FX3_GPIF_LEFT_WAVEFORM + i*16 + 8, 0);
    Fx3WriteReg32(FX3_GPIF_RIGHT_WAVEFORM + i*16 + 8, 0);
  }
  for (i=0; i<4; i++)
    Fx3WriteReg32(FX3_GPIF_THREAD_CONFIG + i*4, 0);
}

static void Fx3GpifConfigureCommon(const uint16_t *functions,
				   uint16_t num_functions,
				   const uint32_t *registers,
				   uint16_t num_registers)
{
  unsigned i;
  if (functions && num_functions) {
    if (num_functions > 32)
      num_functions = 32;
    for(i=0; i<num_functions; i++) {
      Fx3WriteReg32(FX3_GPIF_FUNCTION + i*4, functions[i]);
    }
  }
  if (registers && num_registers) {
    for(i=num_registers; i--; )
      Fx3WriteReg32(FX3_GPIF_CONFIG + i*4, registers[i]);
  }
}


void Fx3GpifConfigure(const Fx3GpifWaveform_t *waveforms,
		      uint16_t num_waveforms,
		      const uint16_t *functions, uint16_t num_functions,
		      const Fx3GpifRegisters_t *registers)
{
  unsigned i;
  if (waveforms && num_waveforms) {
    for(i=0; i<num_waveforms; i++) {
      const Fx3GpifWaveform_t *left = &waveforms[waveforms[i].left];
      const Fx3GpifWaveform_t *right = &waveforms[waveforms[i].right];
      unsigned pos = waveforms[i].state[0] & FX3_GPIF_LEFT_WAVEFORM_NEXT_STATE_MASK;
      Fx3WriteReg32(FX3_GPIF_LEFT_WAVEFORM + pos*16 + 0, left->state[0]);
      Fx3WriteReg32(FX3_GPIF_LEFT_WAVEFORM + pos*16 + 4, left->state[1]);
      Fx3WriteReg32(FX3_GPIF_LEFT_WAVEFORM + pos*16 + 8, left->state[2]);
      Fx3WriteReg32(FX3_GPIF_RIGHT_WAVEFORM + pos*16 + 0, right->state[0]);
      Fx3WriteReg32(FX3_GPIF_RIGHT_WAVEFORM + pos*16 + 4, right->state[1]);
      Fx3WriteReg32(FX3_GPIF_RIGHT_WAVEFORM + pos*16 + 8, right->state[2]);
    }
  }
  Fx3GpifConfigureCommon(functions, num_functions, &registers->config,
			 sizeof(*registers)/sizeof(uint32_t));
}

void Fx3GpifConfigureCompat(const Fx3GpifWaveformCompat_t *waveforms,
			    const uint8_t *waveform_select,
			    uint16_t num_waveforms,
			    const uint16_t *functions, uint16_t num_functions,
			    const uint32_t *registers, uint16_t num_registers)
{
  unsigned i;
  if (waveforms && num_waveforms) {
    for(i=0; i<num_waveforms; i++) {
      const Fx3GpifWaveformCompat_t *w =
	&waveforms[waveform_select? waveform_select[i]:i];
      Fx3WriteReg32(FX3_GPIF_LEFT_WAVEFORM + i*16 + 0, w->left[0]);
      Fx3WriteReg32(FX3_GPIF_LEFT_WAVEFORM + i*16 + 4, w->left[1]);
      Fx3WriteReg32(FX3_GPIF_LEFT_WAVEFORM + i*16 + 8, w->left[2]);
      Fx3WriteReg32(FX3_GPIF_RIGHT_WAVEFORM + i*16 + 0, w->right[0]);
      Fx3WriteReg32(FX3_GPIF_RIGHT_WAVEFORM + i*16 + 4, w->right[1]);
      Fx3WriteReg32(FX3_GPIF_RIGHT_WAVEFORM + i*16 + 8, w->right[2]);
    }
  }
  Fx3GpifConfigureCommon(functions, num_functions, registers, num_registers);
}

void Fx3GpifPibStart(uint16_t clock_divisor_x2)
{
  Fx3WriteReg32(FX3_GCTL_PIB_CORE_CLK,
		(((clock_divisor_x2 >> 1)-1) << FX3_GCTL_PIB_CORE_CLK_DIV_SHIFT) |
		(3UL << FX3_GCTL_PIB_CORE_CLK_SRC_SHIFT));
  if (clock_divisor_x2 & 1)
    Fx3SetReg32(FX3_GCTL_PIB_CORE_CLK, FX3_GCTL_PIB_CORE_CLK_HALFDIV);
  Fx3SetReg32(FX3_GCTL_PIB_CORE_CLK, FX3_GCTL_PIB_CORE_CLK_CLK_EN);

  Fx3WriteReg32(FX3_PIB_POWER, 0);
  Fx3UtilDelayUs(10);
  Fx3SetReg32(FX3_PIB_POWER, FX3_PIB_POWER_RESETN);
  while(!(Fx3ReadReg32(FX3_PIB_POWER) & FX3_PIB_POWER_ACTIVE))
    ;

  Fx3ClearReg32(FX3_PIB_DLL_CTRL, FX3_PIB_DLL_CTRL_ENABLE);
  Fx3UtilDelayUs(1);
  Fx3WriteReg32(FX3_PIB_DLL_CTRL,
		FX3_PIB_DLL_CTRL_HIGH_FREQ |
		FX3_PIB_DLL_CTRL_ENABLE);
  Fx3UtilDelayUs(1);
  Fx3ClearReg32(FX3_PIB_DLL_CTRL, FX3_PIB_DLL_CTRL_DLL_RESET_N);
  Fx3UtilDelayUs(1);
  Fx3SetReg32(FX3_PIB_DLL_CTRL, FX3_PIB_DLL_CTRL_DLL_RESET_N);
  Fx3UtilDelayUs(1);
  while(!(Fx3ReadReg32(FX3_PIB_DLL_CTRL) & FX3_PIB_DLL_CTRL_DLL_STAT))
    ;

  Fx3WriteReg32(FX3_VIC_VEC_ADDRESS + (7<<2), Fx3GpifPibIsr);
  Fx3WriteReg32(FX3_PIB_INTR, Fx3ReadReg32(FX3_PIB_INTR));
  Fx3WriteReg32(FX3_PIB_INTR_MASK, FX3_PIB_INTR_MASK_GPIF_INTERRUPT);
  Fx3WriteReg32(FX3_VIC_INT_ENABLE, (1UL << 7));
}

void Fx3GpifPibStop(void)
{
  Fx3WriteReg32(FX3_PIB_INTR_MASK, 0UL);
  Fx3WriteReg32(FX3_VIC_INT_CLEAR, (1UL << 7));
  Fx3WriteReg32(FX3_PIB_INTR_MASK, 0UL);
  Fx3WriteReg32(FX3_PIB_INTR, ~0UL);
  Fx3WriteReg32(FX3_PIB_POWER, 0UL);
  Fx3UtilDelayUs(10);
  Fx3ClearReg32(FX3_GCTL_PIB_CORE_CLK, FX3_GCTL_PIB_CORE_CLK_CLK_EN);
}
