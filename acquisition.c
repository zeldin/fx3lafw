#include <bsp/gpif.h>
#include <bsp/dma.h>
#include <bsp/usb.h>
#include <bsp/uart.h>
#include <stdio.h>

#define NUM_DMA_BUFFERS 8
#define DMA_BUFFER_SIZE 8192

static const uint16_t functions[]  = {
  [0] = 0U,  /* Constant 0 */
  [1] = (uint16_t)~0U, /* Constant 1 */
  [2] = FX3_GPIF_FUNCTION_Fa, /* Fa */
  [3] = FX3_GPIF_FUNCTION_Fa & ~FX3_GPIF_FUNCTION_Fb, /* Fa & !Fb */
};

#define START_STATE  0
#define START_ALPHA  0

static const Fx3GpifWaveform_t waveforms[] = {
  [0] = { GPIF_START_STATE(0), .left=1 },
  [1] = { GPIF_STATE(1, FX3_GPIO_LAMBDA_INDEX_DMA_RDY, 0, 0, 0, 2, 0,
		     FX3_GPIO_ALPHA_SAMPLE_DIN, 0,
		     0, 0, 0), .left = 2 },
  [2] = { GPIF_STATE(2, FX3_GPIO_LAMBDA_INDEX_DATA_CNT_HIT /* Fa */,
		     FX3_GPIO_LAMBDA_INDEX_DMA_RDY /* Fb */, 0, 0, 3, 2,
		     0, FX3_GPIO_ALPHA_SAMPLE_DIN,
		     FX3_GPIO_BETA_WQ_PUSH |
		     FX3_GPIO_BETA_COUNT_DATA, 0, 1), .left=3, .right=2 },
  [3] = { GPIF_STATE(3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), .left=0 },
};

static Fx3GpifRegisters_t registers = {
  .config = (FX3_GPIF_CONFIG_ENABLE |
	     FX3_GPIF_CONFIG_THREAD_IN_STATE |
	     FX3_GPIF_CONFIG_CLK_SOURCE),
  .ad_config = (FX3_GPIO_OEN_CFG_INPUT << FX3_GPIF_AD_CONFIG_A_OEN_CFG_SHIFT) |
               (FX3_GPIO_OEN_CFG_INPUT << FX3_GPIF_AD_CONFIG_DQ_OEN_CFG_SHIFT),
  .data_count_config = (1UL << FX3_GPIF_DATA_COUNT_CONFIG_INCREMENT_SHIFT) |
                       FX3_GPIF_DATA_COUNT_CONFIG_DOWN_UP |
                       FX3_GPIF_DATA_COUNT_CONFIG_SW_RESET |
                       FX3_GPIF_DATA_COUNT_CONFIG_RELOAD |
                       FX3_GPIF_DATA_COUNT_CONFIG_ENABLE,
  .thread_config[0] = (FX3_GPIF_THREAD_CONFIG_ENABLE |
		       (1UL << FX3_GPIF_THREAD_CONFIG_WATERMARK_SHIFT) |
		       (4UL << FX3_GPIF_THREAD_CONFIG_BURST_SIZE_SHIFT)),
  .waveform_switch = ((3UL << FX3_GPIF_WAVEFORM_SWITCH_DONE_STATE_SHIFT) |
		      FX3_GPIF_WAVEFORM_SWITCH_DONE_ENABLE),
  .beta_deassert = FX3_GPIO_BETA_WQ_PUSH,
};

static volatile uint8_t gpif_buf[NUM_DMA_BUFFERS][DMA_BUFFER_SIZE] __attribute__((aligned(32)));
static uint32_t dma_buffer_descriptor[NUM_DMA_BUFFERS];

static void stop_acquisition(void)
{
  Fx3DmaAbortSocket(FX3_PIB_DMA_SCK(0));
  Fx3DmaAbortSocket(FX3_UIB_DMA_SCK(2));
  Fx3GpifStop();
  Fx3GpifPibStop();
  Fx3UsbFlushInEndpoint(2);
}

static void setup_descriptors(void)
{
  unsigned i;
  for(i=0; i<NUM_DMA_BUFFERS; i++) {
    unsigned next = (i==NUM_DMA_BUFFERS-1? 0 : i+1);
    Fx3DmaFillDescriptorThrough(FX3_PIB_DMA_SCK(0), FX3_UIB_DMA_SCK(2),
				dma_buffer_descriptor[i], gpif_buf[i],
				DMA_BUFFER_SIZE, dma_buffer_descriptor[next]);
  }
}

void start_acquisition(uint8_t bits, uint32_t delay, uint16_t clock_divisor_x2)
{
  registers.bus_config &= ~FX3_GPIF_BUS_CONFIG_BUS_WIDTH_MASK;
  registers.bus_config |= ((bits >> 3) - 1) << FX3_GPIF_BUS_CONFIG_BUS_WIDTH_SHIFT;

  registers.data_count_limit = delay;

  stop_acquisition();
  setup_descriptors();

  Fx3GpifPibStart(clock_divisor_x2);
  Fx3GpifConfigure(waveforms,
		   sizeof(waveforms)/sizeof(waveforms[0]),
		   functions, sizeof(functions)/sizeof(functions[0]),
		   &registers);

  Fx3GpifStart(START_STATE, START_ALPHA);

  Fx3DmaStartProducer(FX3_PIB_DMA_SCK(0), dma_buffer_descriptor[0], 0, 0);
  Fx3DmaStartConsumer(FX3_UIB_DMA_SCK(2), dma_buffer_descriptor[0], 0, 0);
}

void setup_acquisition(void)
{
  unsigned i;
  for(i=0; i<NUM_DMA_BUFFERS; i++)
    dma_buffer_descriptor[i] = Fx3DmaAllocateDescriptor();
}
