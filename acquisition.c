#include <bsp/gpif.h>
#include <bsp/dma.h>
#include <bsp/usb.h>
#include <bsp/uart.h>
#include <stdio.h>

#define NUM_DMA_BUFFERS 10
#define DMA_BUFFER_SIZE 6144 /* Needs to be divisable by 12 */

static const uint16_t functions[]  = {
  [0] = 0U,  /* Constant 0 */
  [1] = (uint16_t)~0U, /* Constant 1 */
  [2] = FX3_GPIF_FUNCTION_Fa, /* Fa */
  [3] = (uint16_t)~FX3_GPIF_FUNCTION_Fa, /* !Fa */
  [4] = FX3_GPIF_FUNCTION_Fb, /* Fb */
};

static const Fx3GpifWaveform_t waveforms[] = {
  [0] = { GPIF_START_STATE(0), .left=13 },
  [1] = { GPIF_START_STATE(1), .left=8 },
  [2] = { GPIF_START_STATE(2), .left=3 },

  /* Delay >= 2 */

  [3] = { GPIF_STATE(3, FX3_GPIF_LAMBDA_INDEX_DMA_RDY, 0, 0, 0, 2, 0,
		     0, 0,
		     FX3_GPIF_BETA_THREAD_0 |
		     FX3_GPIF_BETA_LD_DATA_COUNT |
		     FX3_GPIF_BETA_LD_ADDR_COUNT, 0, 0), .left = 4 },

  /* Thread 0 */

  [4] = { GPIF_STATE(4, FX3_GPIF_LAMBDA_INDEX_ADDR_CNT_HIT /* Fa */,
		     FX3_GPIF_LAMBDA_INDEX_DATA_CNT_HIT /* Fb */,
		     0, 0, 4, 2,
		     FX3_GPIF_ALPHA_SAMPLE_DIN, 0,
		     FX3_GPIF_BETA_THREAD_0 |
		     FX3_GPIF_BETA_COUNT_DATA, 0, 0), .left = 5, .right = 6 },
  [5] = { GPIF_STATE(5, FX3_GPIF_LAMBDA_INDEX_DMA_RDY, 0, 0, 0, 3, 1,
		     0, 0,
		     FX3_GPIF_BETA_THREAD_0 |
		     FX3_GPIF_BETA_WQ_PUSH |
		     FX3_GPIF_BETA_COUNT_DATA |
		     FX3_GPIF_BETA_COUNT_ADDR,
		     0, 0), .left = 16, .right=4 },

  /* Thread 1 */

  [6] = { GPIF_STATE(6, FX3_GPIF_LAMBDA_INDEX_ADDR_CNT_HIT /* Fa */,
		     FX3_GPIF_LAMBDA_INDEX_DATA_CNT_HIT /* Fb */,
		     0, 0, 4, 2,
		     FX3_GPIF_ALPHA_SAMPLE_DIN, 0,
		     FX3_GPIF_BETA_THREAD_1 |
		     FX3_GPIF_BETA_COUNT_DATA, 0, 0), .left = 7, .right = 4 },
  [7] = { GPIF_STATE(7, FX3_GPIF_LAMBDA_INDEX_DMA_RDY, 0, 0, 0, 3, 1,
		     0, 0,
		     FX3_GPIF_BETA_THREAD_1 |
		     FX3_GPIF_BETA_WQ_PUSH |
		     FX3_GPIF_BETA_COUNT_DATA |
		     FX3_GPIF_BETA_COUNT_ADDR,
		     0, 0), .left = 16, .right=6 },

  /* Delay == 1 */

  [8] = { GPIF_STATE(8, FX3_GPIF_LAMBDA_INDEX_DMA_RDY, 0, 0, 0, 2, 0,
		     0, 0,
		     FX3_GPIF_BETA_THREAD_0 |
		     FX3_GPIF_BETA_LD_ADDR_COUNT, 0, 0), .left = 9 },

  /* Thread 0 */

  [9] = { GPIF_STATE(9, FX3_GPIF_LAMBDA_INDEX_ADDR_CNT_HIT, 0, 0, 0, 2, 1,
		     FX3_GPIF_ALPHA_SAMPLE_DIN, 0,
		     FX3_GPIF_BETA_THREAD_0, 0, 0), .left = 12, .right = 10 },
  [10] = { GPIF_STATE(10, FX3_GPIF_LAMBDA_INDEX_DMA_RDY, 0, 0, 0, 3, 1,
		      0, 0,
		      FX3_GPIF_BETA_THREAD_0 |
		      FX3_GPIF_BETA_WQ_PUSH |
		      FX3_GPIF_BETA_COUNT_ADDR,
		      0, 0), .left = 16, .right=9 },

  /* Thread 1 */

  [11] = { GPIF_STATE(11, FX3_GPIF_LAMBDA_INDEX_ADDR_CNT_HIT, 0, 0, 0, 2, 1,
		      FX3_GPIF_ALPHA_SAMPLE_DIN, 0,
		      FX3_GPIF_BETA_THREAD_1, 0, 0), .left = 9, .right = 12 },
  [12] = { GPIF_STATE(12, FX3_GPIF_LAMBDA_INDEX_DMA_RDY, 0, 0, 0, 3, 1,
		      0, 0,
		      FX3_GPIF_BETA_THREAD_1 |
		      FX3_GPIF_BETA_WQ_PUSH |
		      FX3_GPIF_BETA_COUNT_ADDR,
		      0, 0), .left = 16, .right=11 },

  /* Delay == 0 */

  [13] = { GPIF_STATE(13, FX3_GPIF_LAMBDA_INDEX_DMA_RDY, 0, 0, 0, 2, 0,
		      FX3_GPIF_ALPHA_SAMPLE_DIN, 0,
		      FX3_GPIF_BETA_THREAD_0 |
		      FX3_GPIF_BETA_LD_ADDR_COUNT, 0, 0), .left = 14 },

  /* Thread 0 */

  [14] = { GPIF_STATE(14, FX3_GPIF_LAMBDA_INDEX_DMA_RDY /* Fa */,
		      FX3_GPIF_LAMBDA_INDEX_ADDR_CNT_HIT /* Fb */,
		      0, 0, 3, 4,
		      0, FX3_GPIF_ALPHA_SAMPLE_DIN,
		      FX3_GPIF_BETA_THREAD_0 |
		      FX3_GPIF_BETA_WQ_PUSH |
		      FX3_GPIF_BETA_COUNT_ADDR, 0, 0), .left = 16, .right = 15 },

  /* Thread 1 */

  [15] = { GPIF_STATE(15, FX3_GPIF_LAMBDA_INDEX_DMA_RDY /* Fa */,
		      FX3_GPIF_LAMBDA_INDEX_ADDR_CNT_HIT /* Fb */,
		      0, 0, 3, 4,
		      0, FX3_GPIF_ALPHA_SAMPLE_DIN,
		      FX3_GPIF_BETA_THREAD_1 |
		      FX3_GPIF_BETA_WQ_PUSH |
		      FX3_GPIF_BETA_COUNT_ADDR, 0, 0), .left = 16, .right = 14 },

  /* Done */

  [16] = { GPIF_STATE(16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), .left = 0 },
};

static Fx3GpifRegisters_t registers = {
  .config = (FX3_GPIF_CONFIG_ENABLE |
	     FX3_GPIF_CONFIG_THREAD_IN_STATE |
	     FX3_GPIF_CONFIG_CLK_SOURCE),
  .ad_config = (FX3_GPIF_OEN_CFG_INPUT << FX3_GPIF_AD_CONFIG_A_OEN_CFG_SHIFT) |
               (FX3_GPIF_OEN_CFG_INPUT << FX3_GPIF_AD_CONFIG_DQ_OEN_CFG_SHIFT),
  .data_count_config = (1UL << FX3_GPIF_DATA_COUNT_CONFIG_INCREMENT_SHIFT) |
                       FX3_GPIF_DATA_COUNT_CONFIG_DOWN_UP |
                       FX3_GPIF_DATA_COUNT_CONFIG_RELOAD |
                       FX3_GPIF_DATA_COUNT_CONFIG_ENABLE,
  .addr_count_config = (1UL << FX3_GPIF_ADDR_COUNT_CONFIG_INCREMENT_SHIFT) |
                       FX3_GPIF_ADDR_COUNT_CONFIG_DOWN_UP |
                       FX3_GPIF_ADDR_COUNT_CONFIG_RELOAD |
                       FX3_GPIF_ADDR_COUNT_CONFIG_ENABLE,
  .thread_config[0] = (FX3_GPIF_THREAD_CONFIG_ENABLE |
		       (1UL << FX3_GPIF_THREAD_CONFIG_WATERMARK_SHIFT) |
		       (4UL << FX3_GPIF_THREAD_CONFIG_BURST_SIZE_SHIFT) |
		       (0UL << FX3_GPIF_THREAD_CONFIG_THREAD_SOCK_SHIFT)),
  .thread_config[1] = (FX3_GPIF_THREAD_CONFIG_ENABLE |
		       (1UL << FX3_GPIF_THREAD_CONFIG_WATERMARK_SHIFT) |
		       (4UL << FX3_GPIF_THREAD_CONFIG_BURST_SIZE_SHIFT) |
		       (1UL << FX3_GPIF_THREAD_CONFIG_THREAD_SOCK_SHIFT)),
  .waveform_switch = ((16UL << FX3_GPIF_WAVEFORM_SWITCH_DONE_STATE_SHIFT) |
		      FX3_GPIF_WAVEFORM_SWITCH_DONE_ENABLE),
};

static volatile uint8_t gpif_buf[NUM_DMA_BUFFERS][DMA_BUFFER_SIZE] __attribute__((aligned(32)));
static uint32_t dma_buffer_descriptor[NUM_DMA_BUFFERS];

static void stop_acquisition(void)
{
  Fx3DmaAbortSocket(FX3_PIB_DMA_SCK(0));
  Fx3DmaAbortSocket(FX3_PIB_DMA_SCK(1));
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
    unsigned nextnext = (next==NUM_DMA_BUFFERS-1? 0 : next+1);
    Fx3DmaFillDescriptorThrough(FX3_PIB_DMA_SCK(i&1), FX3_UIB_DMA_SCK(2),
				dma_buffer_descriptor[i], gpif_buf[i],
				DMA_BUFFER_SIZE,
				dma_buffer_descriptor[nextnext],
				dma_buffer_descriptor[next]);
  }
}

void start_acquisition(uint8_t bits, uint32_t delay, uint16_t clock_divisor_x2)
{
  registers.bus_config &= ~FX3_GPIF_BUS_CONFIG_BUS_WIDTH_MASK;
  registers.bus_config |= ((bits >> 3) - 1) << FX3_GPIF_BUS_CONFIG_BUS_WIDTH_SHIFT;

  uint32_t samples_per_buffer =  DMA_BUFFER_SIZE * 8 / bits;
  if (!delay)
    --samples_per_buffer;
  registers.data_count_limit = delay;
  registers.addr_count_limit = samples_per_buffer;

  stop_acquisition();
  setup_descriptors();

  Fx3GpifPibStart(clock_divisor_x2);
  Fx3GpifConfigure(waveforms,
		   sizeof(waveforms)/sizeof(waveforms[0]),
		   functions, sizeof(functions)/sizeof(functions[0]),
		   &registers);

  Fx3GpifStart((delay < 2? delay : 2), 0);

  Fx3DmaStartProducer(FX3_PIB_DMA_SCK(1), dma_buffer_descriptor[1], 0, 0);
  Fx3DmaStartProducer(FX3_PIB_DMA_SCK(0), dma_buffer_descriptor[0], 0, 0);
  Fx3DmaStartConsumer(FX3_UIB_DMA_SCK(2), dma_buffer_descriptor[0], 0, 0);
}

void setup_acquisition(void)
{
  unsigned i;
  for(i=0; i<NUM_DMA_BUFFERS; i++)
    dma_buffer_descriptor[i] = Fx3DmaAllocateDescriptor();
}

void poll_acquisition(void)
{
  if (Fx3GpifGetStat(NULL) == FX3_GPIF_PAUSED) {
    Fx3UartTxString("GPIF done, stopping DMA\n");
    stop_acquisition();
  }
}
