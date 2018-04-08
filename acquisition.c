#include <bsp/gpif.h>
#include <bsp/dma.h>
#include <bsp/usb.h>
#include <bsp/uart.h>
#include <stdio.h>

static volatile uint8_t gpif_buf[8192] __attribute__((aligned(32)));

static const uint16_t functions[]  = {
  [0] = 0U,  /* Constant 0 */
  [1] = (uint16_t)~0U, /* Constant 1 */
};

#define START_STATE  0
#define START_ALPHA  FX3_GPIO_ALPHA_SAMPLE_DIN

static Fx3GpifWaveform_t waveforms[] = {
  [0] = { GPIF_START_STATE(0), .left=1 },
  [1] = { GPIF_STATE(1, 0, 0, 0, 0, 0, 1, 0, FX3_GPIO_ALPHA_SAMPLE_DIN,
		     FX3_GPIO_BETA_WQ_PUSH, 0, 1), .right=1 },
};

static Fx3GpifRegisters_t registers = {
  .config = (FX3_GPIF_CONFIG_ENABLE |
	     FX3_GPIF_CONFIG_THREAD_IN_STATE |
	     FX3_GPIF_CONFIG_CLK_SOURCE),
  .ad_config = (FX3_GPIO_OEN_CFG_INPUT << FX3_GPIF_AD_CONFIG_A_OEN_CFG_SHIFT) |
               (FX3_GPIO_OEN_CFG_INPUT << FX3_GPIF_AD_CONFIG_DQ_OEN_CFG_SHIFT),
  .thread_config[0] = (FX3_GPIF_THREAD_CONFIG_ENABLE |
		       (1UL << FX3_GPIF_THREAD_CONFIG_WATERMARK_SHIFT) |
		       (4UL << FX3_GPIF_THREAD_CONFIG_BURST_SIZE_SHIFT)),
  .beta_deassert = FX3_GPIO_BETA_WQ_PUSH,
};

void start_acquisition(uint8_t bits, uint8_t delay)
{
  registers.bus_config &= ~FX3_GPIF_BUS_CONFIG_BUS_WIDTH_MASK;
  registers.bus_config |= ((bits >> 3) - 1) << FX3_GPIF_BUS_CONFIG_BUS_WIDTH_SHIFT;
  waveforms[1].state[2] &= ~(0xFFUL << (FX3_GPIF_LEFT_WAVEFORM_REPEAT_COUNT_SHIFT - 64));
  waveforms[1].state[2] |= delay << (FX3_GPIF_LEFT_WAVEFORM_REPEAT_COUNT_SHIFT - 64);

  Fx3GpifPibStart(4); /* Minimum divisor = 2.0 */
  Fx3GpifConfigure(waveforms,
		   sizeof(waveforms)/sizeof(waveforms[0]),
		   functions, sizeof(functions)/sizeof(functions[0]),
		   &registers);
  Fx3GpifStart(START_STATE, START_ALPHA);
  uint16_t desc = Fx3DmaAllocateDescriptor();
  Fx3DmaSimpleTransferWrite(FX3_PIB_DMA_SCK(0), desc,
			    gpif_buf, sizeof(gpif_buf));
  Fx3DmaFreeDescriptor(desc);
  Fx3GpifStop();
  Fx3GpifPibStop();

  Fx3UsbDmaDataIn(2, gpif_buf, sizeof(gpif_buf));

  unsigned i, z=0, nz=0, szr=sizeof(gpif_buf), lzr=0, snzr=sizeof(gpif_buf), lnzr=0, run=0, match=gpif_buf[0], valid=0;
  for(i=0; i<sizeof(gpif_buf); i++) {
    if(gpif_buf[i])
      nz++;
    else
      z++;
    if ((!gpif_buf[i]) == (!match))
      run++;
    else {
      if (valid) {
	if (match) {
	  if (run > lnzr)
	    lnzr = run;
	  if (run < snzr)
	    snzr = run;
	} else {
	  if (run > lzr)
	    lzr = run;
	  if (run < szr)
	    szr = run;
	}
      }
      run = 0;
      valid = 1;
      match = gpif_buf[i];
    }
  }
  char buf[64];
  snprintf(buf, sizeof(buf), "Xfer done, #0: %u (%u-%u) #nz: %u (%u-%u)\n", z,  szr, lzr, nz, snzr, lnzr);
  Fx3UartTxString(buf);
}
