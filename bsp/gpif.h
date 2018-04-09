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

#ifndef BSP_GPIF_H_
#define BSP_GPIF_H_

#include <stdint.h>
#include <rdb/gpif.h>

/* Perform bitwise operations on the following constants to achieve the
   corresponding logical operations on the four 1-bit operands */

#define FX3_GPIF_FUNCTION_Fa  0xAAAAU
#define FX3_GPIF_FUNCTION_Fb  0xCCCCU
#define FX3_GPIF_FUNCTION_Fc  0xF0F0U
#define FX3_GPIF_FUNCTION_Fd  0xFF00U



/* Fixed function alphas and betas */
/* (Alpha 4-7 and Beta 0-3 are user defined) */

#define FX3_GPIO_ALPHA_DQ_OEN             (1UL<<0) /* Alpha 0 */
#define FX3_GPIO_ALPHA_UPDATE_DOUT        (1UL<<1) /* Alpha 1 */
#define FX3_GPIO_ALPHA_SAMPLE_DIN         (1UL<<2) /* Alpha 2 */
#define FX3_GPIO_ALPHA_SAMPLE_AIN         (1UL<<3) /* Alpha 3 */

#define FX3_GPIO_BETA_THREAD_0            (0UL<<4)  /* Beta 4&5 */
#define FX3_GPIO_BETA_THREAD_1            (1UL<<4)  /*  - " -   */
#define FX3_GPIO_BETA_THREAD_2            (2UL<<4)  /*  - " -   */
#define FX3_GPIO_BETA_THREAD_3            (3UL<<4)  /*  - " -   */
#define FX3_GPIO_BETA_RQ_POP              (1UL<<6)  /* Beta 6 */
#define FX3_GPIO_BETA_WQ_PUSH             (1UL<<7)  /* Beta 7 */
#define FX3_GPIO_BETA_RQ_POP_ADDR         (1UL<<8)  /* Beta 8 */
#define FX3_GPIO_BETA_WQ_PUSH_ADDR        (1UL<<9)  /* Beta 9 */
#define FX3_GPIO_BETA_A_OEN               (1UL<<10) /* Beta 10 */
  /* 11 = ? */
#define FX3_GPIO_BETA_COUNT_CTRL          (1UL<<12) /* Beta 12 */
#define FX3_GPIO_BETA_LD_CTRL_COUNT       (1UL<<13) /* Beta 13 */
#define FX3_GPIO_BETA_COUNT_ADDR          (1UL<<14) /* Beta 14 */
#define FX3_GPIO_BETA_LD_ADDR_COUNT       (1UL<<15) /* Beta 15 */
#define FX3_GPIO_BETA_COUNT_DATA          (1UL<<16) /* Beta 16 */
#define FX3_GPIO_BETA_LD_DATA_COUNT       (1UL<<17) /* Beta 17 */
#define FX3_GPIO_BETA_INTR_CPU            (1UL<<18) /* Beta 18 */
#define FX3_GPIO_BETA_INTR_HOST           (1UL<<19) /* Beta 19 */
#define FX3_GPIO_BETA_UPDATE_AOUT         (1UL<<20) /* Beta 20 */
#define FX3_GPIO_BETA_REGISTER_ACCESS     (1UL<<21) /* Beta 21 */
  /* 22, 23, 24 = ? */
#define FX3_GPIO_BETA_ASSERT_DRQ          (1UL<<25) /* Beta 25 */
#define FX3_GPIO_BETA_DEASSERT_DRQ        (1UL<<26) /* Beta 26 */
  /* 27, 28, 29 = ? */
#define FX3_GPIO_BETA_COMMIT              (1UL<<30) /* Beta 30 */
#define FX3_GPIO_BETA_PP_ACCESS           (1UL<<31) /* Beta 31 */


/* For compatibility with GPIF II Designer output */

typedef struct {
  uint32_t left[3], right[3];
} Fx3GpifWaveformCompat_t;


typedef struct {
  uint32_t state[3];
  uint16_t left, right;
} Fx3GpifWaveform_t;

#define GPIF_START_STATE(n) {(n)&0xff,0,0}
#define GPIF_STATE(n,Fa,Fb,Fc,Fd,f0,f1,AL,AR,B,rep,BD) {		\
  ((n)&0xff)|(((Fa)&0x1f)<<8)|(((Fb)&0x1f)<<13)|(((Fc)&0x1f)<<18)|(((Fd)&0x1f)<<23)|(((f0)&0xf)<<28), \
  (((f0)&0x10)>>4)|(((f1)&0x1f)<<1)|(((AL)&0xff)<<6)|(((AR)&0xff)<<14)|(((B)&0x3ff)<<22), \
  (((B)&0xfffffc00)>>10)|(((rep)&0xff)<<22)|(((BD)&1)<<30)|(1UL<<31)}

typedef enum {
  FX3_GPIO_CTRL_BUS_DIRECTION_INPUT = 0,
  FX3_GPIO_CTRL_BUS_DIRECTION_OUTPUT,
  FX3_GPIO_CTRL_BUS_DIRECTION_BIDIR,
  FX3_GPIO_CTRL_BUS_DIRECTION_OPEN_DRAIN,
} Fx3GpifCtrlBusDirection_t;

typedef enum {
  FX3_GPIO_OEN_CFG_OUTPUT = 0,
  FX3_GPIO_OEN_CFG_INPUT,
  FX3_GPIO_OEN_CFG_DYNAMIC, /* Controlled by alpha/beta */
} Fx3GpifOenCfg_t;

typedef enum {
  FX3_GPIO_LAMBDA_INDEX_CTL0 = 0, /* GPIO 17 */
  FX3_GPIO_LAMBDA_INDEX_CTL1,     /* GPIO 18 */
  FX3_GPIO_LAMBDA_INDEX_CTL2,     /* GPIO 19 */
  FX3_GPIO_LAMBDA_INDEX_CTL3,     /* GPIO 20 */
  FX3_GPIO_LAMBDA_INDEX_CTL4,     /* GPIO 21 */
  FX3_GPIO_LAMBDA_INDEX_CTL5,     /* GPIO 22 */
  FX3_GPIO_LAMBDA_INDEX_CTL6,     /* GPIO 23 */
  FX3_GPIO_LAMBDA_INDEX_CTL7,     /* GPIO 24 */
  FX3_GPIO_LAMBDA_INDEX_CTL8,     /* GPIO 25 */
  FX3_GPIO_LAMBDA_INDEX_CTL9,     /* GPIO 26 */
  FX3_GPIO_LAMBDA_INDEX_CTL10,    /* GPIO 27 */
  FX3_GPIO_LAMBDA_INDEX_CTL11,    /* GPIO 28 */
  FX3_GPIO_LAMBDA_INDEX_CTL12,    /* GPIO 29 */
  FX3_GPIO_LAMBDA_INDEX_CTL13,    /* GPIO 49 */
  FX3_GPIO_LAMBDA_INDEX_CTL14,    /* GPIO 48 */
  FX3_GPIO_LAMBDA_INDEX_CTL15,    /* GPIO 47 */
  FX3_GPIO_LAMBDA_INDEX_OUT_REG_CR_VALID = 16,
  FX3_GPIO_LAMBDA_INDEX_IN_REG_CR_VALID  = 17,
  FX3_GPIO_LAMBDA_INDEX_CTRL_CNT_HIT     = 18,
  FX3_GPIO_LAMBDA_INDEX_ADDR_CNT_HIT     = 19,
  FX3_GPIO_LAMBDA_INDEX_DATA_CNT_HIT     = 20,
  FX3_GPIO_LAMBDA_INDEX_CTRL_CMP_MATCH   = 21,
  FX3_GPIO_LAMBDA_INDEX_ADDR_CMP_MATCH   = 22,
  FX3_GPIO_LAMBDA_INDEX_DATA_CMP_MATCH   = 23,
  FX3_GPIO_LAMBDA_INDEX_DMA_WM           = 24,
  FX3_GPIO_LAMBDA_INDEX_DMA_RDY_ADDR     = 25,
  FX3_GPIO_LAMBDA_INDEX_DMA_RDY          = 26,
  /* 27, 28 = ? */
  FX3_GPIO_LAMBDA_INDEX_INTR_PEND        = 29,
  FX3_GPIO_LAMBDA_INDEX_FW_TRG           = 30,
  FX3_GPIO_LAMBDA_INDEX_OUT_ADDR_VALID   = 31,
} Fx3GpifLambdaIndex_t;

typedef enum {
  FX3_GPIF_OMEGA_INDEX_ALPHA4 = 0,
  FX3_GPIF_OMEGA_INDEX_ALPHA5,
  FX3_GPIF_OMEGA_INDEX_ALPHA6,
  FX3_GPIF_OMEGA_INDEX_ALPHA7,
  FX3_GPIF_OMEGA_INDEX_BETA0 = 8,
  FX3_GPIF_OMEGA_INDEX_BETA1,
  FX3_GPIF_OMEGA_INDEX_BETA2,
  FX3_GPIF_OMEGA_INDEX_BETA3,
  FX3_GPIO_OMEGA_INDEX_EMPTY_FULL_TH0 = 16,
  FX3_GPIO_OMEGA_INDEX_EMPTY_FULL_TH1,
  FX3_GPIO_OMEGA_INDEX_EMPTY_FULL_TH2,
  FX3_GPIO_OMEGA_INDEX_EMPTY_FULL_TH3,
  FX3_GPIO_OMEGA_INDEX_PARTIAL_TH0,
  FX3_GPIO_OMEGA_INDEX_PARTIAL_TH1,
  FX3_GPIO_OMEGA_INDEX_PARTIAL_TH2,
  FX3_GPIO_OMEGA_INDEX_PARTIAL_TH3,
  FX3_GPIO_OMEGA_INDEX_EMPTY_FULL_CURRENT,
  FX3_GPIO_OMEGA_INDEX_PARTIAL_CURRENT,
  FX3_GPIO_OMEGA_INDEX_PP_DRQR5,
  FX3_GPIO_OMEGA_INDEX_CONSTANT_0 = 31
} Fx3GpifOmegaIndex_t;

typedef struct {
  uint32_t config;
  uint32_t bus_config;
  uint32_t bus_config2;
  uint32_t ad_config;
  uint32_t status;
  uint32_t intr;
  uint32_t intr_mask;
  uint32_t serial_in_config;
  uint32_t serial_out_config;
  uint32_t ctrl_bus_direction;
  uint32_t ctrl_bus_default;
  uint32_t ctrl_bus_polarity;
  uint32_t ctrl_bus_toggle;
  uint32_t ctrl_bus_select[16];
  uint32_t ctrl_count_config;
  uint32_t ctrl_count_reset;
  uint32_t ctrl_count_limit;
  uint32_t addr_count_config;
  uint32_t addr_count_reset;
  uint32_t addr_count_limit;
  uint32_t state_count_config;
  uint32_t state_count_limit;
  uint32_t data_count_config;
  uint32_t data_count_reset;
  uint32_t data_count_limit;
  uint32_t ctrl_comp_value;
  uint32_t ctrl_comp_mask;
  uint32_t data_comp_value;
  uint32_t data_comp_mask;
  uint32_t addr_comp_value;
  uint32_t addr_comp_mask;
  uint32_t data_ctrl;
  uint32_t ingress_data[4];
  uint32_t egress_data[4];
  uint32_t ingress_address[4];
  uint32_t egress_address[4];
  uint32_t thread_config[4];
  uint32_t lambda_stat;
  uint32_t alpha_stat;
  uint32_t beta_stat;
  uint32_t waveform_ctrl_stat;
  uint32_t waveform_switch;
  uint32_t waveform_switch_timeout;
  uint32_t crc_config;
  uint32_t crc_data;
  uint32_t beta_deassert;
} Fx3GpifRegisters_t;

extern void Fx3GpifStart(uint8_t state, uint8_t alpha);
extern void Fx3GpifStop(void);
extern void Fx3GpifInvalidate(void);
extern void Fx3GpifConfigure(const Fx3GpifWaveform_t *waveforms,
			     uint16_t num_waveforms,
			     const uint16_t *functions, uint16_t num_functions,
			     const Fx3GpifRegisters_t *registers);
extern void Fx3GpifConfigureCompat(const Fx3GpifWaveformCompat_t *waveforms,
				   const uint8_t *waveform_select,
				   uint16_t num_waveforms,
				   const uint16_t *functions, uint16_t num_functions,
				   const uint32_t *registers, uint16_t num_registers);
extern void Fx3GpifPibStart(uint16_t clock_divisor_x2);
extern void Fx3GpifPibStop(void);

#endif /* BSP_GPIF_H_ */
