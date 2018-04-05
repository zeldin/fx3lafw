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

#ifndef RDB_GPIF_H_
#define RDB_GPIF_H_

#define FX3_GPIF_CONFIG                       0xE0014000 /* GPIF Configuration Register */
#define FX3_GPIF_BUS_CONFIG                   0xE0014004 /* Bus Configuration Register */
#define FX3_GPIF_BUS_CONFIG2                  0xE0014008 /* Bus Configuration Register #2 */
#define FX3_GPIF_AD_CONFIG                    0xE001400C /* Address/Data Configuration Register */
#define FX3_GPIF_STATUS                       0xE0014010 /* GPIF Status Register */
#define FX3_GPIF_INTR                         0xE0014014 /* GPIF Interrupt Request Register */
#define FX3_GPIF_INTR_MASK                    0xE0014018 /* GPIF Interrupt Mask Register */
#define FX3_GPIF_SERIAL_IN_CONFIG             0XE001401C /* Serial Input Configuration Register */
#define FX3_GPIF_SERIAL_OUT_CONFIG            0XE0014020 /* Serial Output Configuration Register */
#define FX3_GPIF_CTRL_BUS_DIRECTION           0xE0014024 /* Control Bus In/Out Direction Register */
#define FX3_GPIF_CTRL_BUS_DEFAULT             0xE0014028 /* Control Bus Default Values Register */
#define FX3_GPIF_CTRL_BUS_POLARITY            0xE001402C /* Control Bus SIgnal Polarity Register */
#define FX3_GPIF_CTRL_BUS_TOGGLE              0xE0014030 /* Control Bus Output Toggle Mode Register */
#define FX3_GPIF_CTRL_BUS_SELECT              0xE0014034 /* Control Bus Connection Matrix Register */
#define FX3_GPIF_CTRL_COUNT_CONFIG            0xE0014074 /* Control Counter Configuration Register */
#define FX3_GPIF_CTRL_COUNT_RESET             0xE0014078 /* Control Counter Reset Register */
#define FX3_GPIF_CTRL_COUNT_LIMIT             0xE001407C /* Control Counter Reset Register */
#define FX3_GPIF_ADDR_COUNT_CONFIG            0xE0014080 /* Address Counter Configuration Register */
#define FX3_GPIF_ADDR_COUNT_RESET             0xE0014084 /* Address Counter Reset Register */
#define FX3_GPIF_ADDR_COUNT_LIMIT             0xE0014088 /* Address Counter Limit Register */
#define FX3_GPIF_STATE_COUNT_CONFIG           0xE001408C /* State Counter Configuration Register */
#define FX3_GPIF_STATE_COUNT_LIMIT            0xE0014090 /* State Counter Limit Register */
#define FX3_GPIF_DATA_COUNT_CONFIG            0xE0014094 /* Data Counter Configuration Register */
#define FX3_GPIF_DATA_COUNT_RESET             0xE0014098 /* Data Counter Reset Register */
#define FX3_GPIF_DATA_COUNT_LIMIT             0xE001409C /* Data Counter Limit Register */
#define FX3_GPIF_CTRL_COMP_VALUE              0xE00140A0 /* Control Comparator Value Register */
#define FX3_GPIF_CTRL_COMP_MASK               0xE00140A4 /* Control Comparator Mask Register */
#define FX3_GPIF_DATA_COMP_VALUE              0xE00140A8 /* Data Comparator Value Register */
#define FX3_GPIF_DATA_COMP_MASK               0xE00140AC /* Data Comparator Mask Register */
#define FX3_GPIF_ADDR_COMP_VALUE              0xE00140B0 /* Address Comparator Value Register */
#define FX3_GPIF_ADDR_COMP_MASK               0xE00140B4 /* Address Comparator Mask Register */
#define FX3_GPIF_DATA_CTRL                    0xE00140B8 /* Data Control Register */
#define FX3_GPIF_INGRESS_DATA                 0xE00140BC /* Socket Ingress Data Register */
#define FX3_GPIF_EGRESS_DATA                  0xE00140CC /* Socket Egress Data Register */
#define FX3_GPIF_INGRESS_ADDRESS              0xE00140DC /* Thread Ingress Address Register */
#define FX3_GPIF_EGRESS_ADDRESS               0xE00140EC /* Thread Egress Address Register */
#define FX3_GPIF_THREAD_CONFIG                0xE00140FC /* Thread Configuration Register */
#define FX3_GPIF_LAMBDA_STAT                  0xE001410C /* Lambda Status Register */
#define FX3_GPIF_ALPHA_STAT                   0xE0014110 /* Alpha Status Register */
#define FX3_GPIF_BETA_STAT                    0xE0014114 /* Beta Status Register */
#define FX3_GPIF_WAVEFORM_CTRL_STAT           0xE0014118 /* Waveform Program Control Register */
#define FX3_GPIF_WAVEFORM_SWITCH              0xE001411C /* Waveform Switch Control Register */
#define FX3_GPIF_WAVEFORM_SWITCH_TIMEOUT      0xE0014120 /* Waveform Timeout Register */
#define FX3_GPIF_CRC_CONFIG                   0xE0014124 /* CRC Configuration Register */
#define FX3_GPIF_CRC_DATA                     0xE0014128 /* CRC Data Register */
#define FX3_GPIF_BETA_DEASSERT                0xE001412C /* Beta Deassert Register */
#define FX3_GPIF_FUNCTION                     0xE0014130 /* Transition Function Registers */
#define FX3_GPIF_LEFT_WAVEFORM                0xE0015000 /* Left Edge Waveform Memory Register */
#define FX3_GPIF_RIGHT_WAVEFORM               0xE0016000 /* Right Edge Waveform Memory Register */

#define FX3_GPIF_CONFIG_ENABLE                           (1UL << 31)
#define FX3_GPIF_CONFIG_PP_MODE                          (1UL << 30)
#define FX3_GPIF_CONFIG_A7OVERRIDE                       (1UL << 19)
#define FX3_GPIF_CONFIG_THREAD_IN_STATE                  (1UL << 15)
#define FX3_GPIF_CONFIG_DATA_COMP_TOGGLE                 (1UL << 13)
#define FX3_GPIF_CONFIG_CTRL_COMP_TOGGLE                 (1UL << 12)
#define FX3_GPIF_CONFIG_ADDR_COMP_TOGGLE                 (1UL << 11)
#define FX3_GPIF_CONFIG_ENDIAN                           (1UL << 10)
#define FX3_GPIF_CONFIG_SYNC                             (1UL << 8)
#define FX3_GPIF_CONFIG_DOUT_POP_EN                      (1UL << 7)
#define FX3_GPIF_CONFIG_DDR_MODE                         (1UL << 6)
#define FX3_GPIF_CONFIG_CLK_OUT                          (1UL << 5)
#define FX3_GPIF_CONFIG_CLK_SOURCE                       (1UL << 4)
#define FX3_GPIF_CONFIG_CLK_INVERT                       (1UL << 3)
#define FX3_GPIF_CONFIG_DATA_COMP_ENABLE                 (1UL << 2)
#define FX3_GPIF_CONFIG_ADDR_COMP_ENABLE                 (1UL << 1)
#define FX3_GPIF_CONFIG_CTRL_COMP_ENABLE                 (1UL << 0)

#define FX3_GPIF_BUS_CONFIG_FIO1_CONF_SHIFT              28
#define FX3_GPIF_BUS_CONFIG_FIO1_CONF_BITS               4
#define FX3_GPIF_BUS_CONFIG_FIO1_CONF_MASK               (0xfUL << 28)
#define FX3_GPIF_BUS_CONFIG_FIO0_CONF_SHIFT              24
#define FX3_GPIF_BUS_CONFIG_FIO0_CONF_BITS               4
#define FX3_GPIF_BUS_CONFIG_FIO0_CONF_MASK               (0xfUL << 24)
#define FX3_GPIF_BUS_CONFIG_CE_CLKSTOP                   (1UL << 23)
#define FX3_GPIF_BUS_CONFIG_INT_CTRL                     (1UL << 22)
#define FX3_GPIF_BUS_CONFIG_DRQ_ASSERT_MODE              (1UL << 20)
#define FX3_GPIF_BUS_CONFIG_DRQ_MODE_SHIFT               18
#define FX3_GPIF_BUS_CONFIG_DRQ_MODE_BITS                2
#define FX3_GPIF_BUS_CONFIG_DRQ_MODE_MASK                (0x3UL << 18)
#define FX3_GPIF_BUS_CONFIG_ALE_PRESENT                  (1UL << 17)
#define FX3_GPIF_BUS_CONFIG_CNTR_PRESENT                 (1UL << 16)
#define FX3_GPIF_BUS_CONFIG_FIO1_PRESENT                 (1UL << 15)
#define FX3_GPIF_BUS_CONFIG_FIO0_PRESENT                 (1UL << 14)
#define FX3_GPIF_BUS_CONFIG_DRQ_PRESENT                  (1UL << 13)
#define FX3_GPIF_BUS_CONFIG_OE_PRESENT                   (1UL << 12)
#define FX3_GPIF_BUS_CONFIG_DLE_PRESENT                  (1UL << 11)
#define FX3_GPIF_BUS_CONFIG_WE_PRESENT                   (1UL << 10)
#define FX3_GPIF_BUS_CONFIG_CE_PRESENT                   (1UL << 9)
#define FX3_GPIF_BUS_CONFIG_ADR_CTRL_SHIFT               5
#define FX3_GPIF_BUS_CONFIG_ADR_CTRL_BITS                4
#define FX3_GPIF_BUS_CONFIG_ADR_CTRL_MASK                (0xfUL << 5)
#define FX3_GPIF_BUS_CONFIG_MUX_MODE                     (1UL << 4)
#define FX3_GPIF_BUS_CONFIG_BUS_WIDTH_SHIFT              2
#define FX3_GPIF_BUS_CONFIG_BUS_WIDTH_BITS               2
#define FX3_GPIF_BUS_CONFIG_BUS_WIDTH_MASK               (0x3UL << 2)
#define FX3_GPIF_BUS_CONFIG_PIN_COUNT_SHIFT              0
#define FX3_GPIF_BUS_CONFIG_PIN_COUNT_BITS               2
#define FX3_GPIF_BUS_CONFIG_PIN_COUNT_MASK               (0x3UL << 0)

#define FX3_GPIF_BUS_CONFIG2_STATE7_SHIFT                24
#define FX3_GPIF_BUS_CONFIG2_STATE7_BITS                 5
#define FX3_GPIF_BUS_CONFIG2_STATE7_MASK                 (0x1fUL << 24)
#define FX3_GPIF_BUS_CONFIG2_STATE6_SHIFT                16
#define FX3_GPIF_BUS_CONFIG2_STATE6_BITS                 5
#define FX3_GPIF_BUS_CONFIG2_STATE6_MASK                 (0x1fUL << 16)
#define FX3_GPIF_BUS_CONFIG2_STATE5_SHIFT                8
#define FX3_GPIF_BUS_CONFIG2_STATE5_BITS                 5
#define FX3_GPIF_BUS_CONFIG2_STATE5_MASK                 (0x1fUL << 8)
#define FX3_GPIF_BUS_CONFIG2_STATE_FROM_CTRL_SHIFT       0
#define FX3_GPIF_BUS_CONFIG2_STATE_FROM_CTRL_BITS        3
#define FX3_GPIF_BUS_CONFIG2_STATE_FROM_CTRL_MASK        (0x7UL << 0)

#define FX3_GPIF_AD_CONFIG_DATA_THREAD_SHIFT             18
#define FX3_GPIF_AD_CONFIG_DATA_THREAD_BITS              2
#define FX3_GPIF_AD_CONFIG_DATA_THREAD_MASK              (0x3UL << 18)
#define FX3_GPIF_AD_CONFIG_ADDRESS_THREAD_SHIFT          16
#define FX3_GPIF_AD_CONFIG_ADDRESS_THREAD_BITS           2
#define FX3_GPIF_AD_CONFIG_ADDRESS_THREAD_MASK           (0x3UL << 16)
#define FX3_GPIF_AD_CONFIG_AIN_DATA                      (1UL << 9)
#define FX3_GPIF_AD_CONFIG_DOUT_SELECT                   (1UL << 8)
#define FX3_GPIF_AD_CONFIG_AOUT_SELECT_SHIFT             6
#define FX3_GPIF_AD_CONFIG_AOUT_SELECT_BITS              2
#define FX3_GPIF_AD_CONFIG_AOUT_SELECT_MASK              (0x3UL << 6)
#define FX3_GPIF_AD_CONFIG_AIN_SELECT_SHIFT              4
#define FX3_GPIF_AD_CONFIG_AIN_SELECT_BITS               2
#define FX3_GPIF_AD_CONFIG_AIN_SELECT_MASK               (0x3UL << 4)
#define FX3_GPIF_AD_CONFIG_A_OEN_CFG_SHIFT               2
#define FX3_GPIF_AD_CONFIG_A_OEN_CFG_BITS                2
#define FX3_GPIF_AD_CONFIG_A_OEN_CFG_MASK                (0x3UL << 2)
#define FX3_GPIF_AD_CONFIG_DQ_OEN_CFG_SHIFT              0
#define FX3_GPIF_AD_CONFIG_DQ_OEN_CFG_BITS               2
#define FX3_GPIF_AD_CONFIG_DQ_OEN_CFG_MASK               (0x3UL << 0)

#define FX3_GPIF_STATUS_INTERRUPT_STATE_SHIFT            24
#define FX3_GPIF_STATUS_INTERRUPT_STATE_BITS             8
#define FX3_GPIF_STATUS_INTERRUPT_STATE_MASK             (0xffUL << 24)
#define FX3_GPIF_STATUS_IN_DATA_VALID_SHIFT              20
#define FX3_GPIF_STATUS_IN_DATA_VALID_BITS               4
#define FX3_GPIF_STATUS_IN_DATA_VALID_MASK               (0xfUL << 20)
#define FX3_GPIF_STATUS_EG_DATA_EMPTY_SHIFT              16
#define FX3_GPIF_STATUS_EG_DATA_EMPTY_BITS               4
#define FX3_GPIF_STATUS_EG_DATA_EMPTY_MASK               (0xfUL << 16)
#define FX3_GPIF_STATUS_WAVEFORM_BUSY                    (1UL << 10)
#define FX3_GPIF_STATUS_CTRL_COMP_HIT                    (1UL << 9)
#define FX3_GPIF_STATUS_DATA_COMP_HIT                    (1UL << 8)
#define FX3_GPIF_STATUS_ADDR_COMP_HIT                    (1UL << 7)
#define FX3_GPIF_STATUS_CTRL_COUNT_HIT                   (1UL << 6)
#define FX3_GPIF_STATUS_DATA_COUNT_HIT                   (1UL << 5)
#define FX3_GPIF_STATUS_ADDR_COUNT_HIT                   (1UL << 4)
#define FX3_GPIF_STATUS_CRC_ERROR                        (1UL << 3)
#define FX3_GPIF_STATUS_SWITCH_TIMEOUT                   (1UL << 2)
#define FX3_GPIF_STATUS_GPIF_INTR                        (1UL << 1)
#define FX3_GPIF_STATUS_GPIF_DONE                        (1UL << 0)

#define FX3_GPIF_INTR_IN_DATA_VALID_SHIFT                20
#define FX3_GPIF_INTR_IN_DATA_VALID_BITS                 4
#define FX3_GPIF_INTR_IN_DATA_VALID_MASK                 (0xfUL << 20)
#define FX3_GPIF_INTR_EG_DATA_EMPTY_SHIFT                16
#define FX3_GPIF_INTR_EG_DATA_EMPTY_BITS                 4
#define FX3_GPIF_INTR_EG_DATA_EMPTY_MASK                 (0xfUL << 16)
#define FX3_GPIF_INTR_WAVEFORM_BUSY                      (1UL << 10)
#define FX3_GPIF_INTR_CTRL_COMP_HIT                      (1UL << 9)
#define FX3_GPIF_INTR_DATA_COMP_HIT                      (1UL << 8)
#define FX3_GPIF_INTR_ADDR_COMP_HIT                      (1UL << 7)
#define FX3_GPIF_INTR_CTRL_COUNT_HIT                     (1UL << 6)
#define FX3_GPIF_INTR_DATA_COUNT_HIT                     (1UL << 5)
#define FX3_GPIF_INTR_ADDR_COUNT_HIT                     (1UL << 4)
#define FX3_GPIF_INTR_CRC_ERROR                          (1UL << 3)
#define FX3_GPIF_INTR_SWITCH_TIMEOUT                     (1UL << 2)
#define FX3_GPIF_INTR_GPIF_INTR                          (1UL << 1)
#define FX3_GPIF_INTR_GPIF_DONE                          (1UL << 0)

#define FX3_GPIF_INTR_MASK_IN_DATA_VALID_SHIFT           20
#define FX3_GPIF_INTR_MASK_IN_DATA_VALID_BITS            4
#define FX3_GPIF_INTR_MASK_IN_DATA_VALID_MASK            (0xfUL << 20)
#define FX3_GPIF_INTR_MASK_EG_DATA_EMPTY_SHIFT           16
#define FX3_GPIF_INTR_MASK_EG_DATA_EMPTY_BITS            4
#define FX3_GPIF_INTR_MASK_EG_DATA_EMPTY_MASK            (0xfUL << 16)
#define FX3_GPIF_INTR_MASK_WAVEFORM_BUSY                 (1UL << 10)
#define FX3_GPIF_INTR_MASK_CTRL_COMP_HIT                 (1UL << 9)
#define FX3_GPIF_INTR_MASK_DATA_COMP_HIT                 (1UL << 8)
#define FX3_GPIF_INTR_MASK_ADDR_COMP_HIT                 (1UL << 7)
#define FX3_GPIF_INTR_MASK_CTRL_COUNT_HIT                (1UL << 6)
#define FX3_GPIF_INTR_MASK_DATA_COUNT_HIT                (1UL << 5)
#define FX3_GPIF_INTR_MASK_ADDR_COUNT_HIT                (1UL << 4)
#define FX3_GPIF_INTR_MASK_CRC_ERROR                     (1UL << 3)
#define FX3_GPIF_INTR_MASK_SWITCH_TIMEOUT                (1UL << 2)
#define FX3_GPIF_INTR_MASK_GPIF_INTR                     (1UL << 1)
#define FX3_GPIF_INTR_MASK_GPIF_DONE                     (1UL << 0)

#define FX3_GPIF_CTRL_BUS_DEFAULT_DEFAULT_SHIFT          0
#define FX3_GPIF_CTRL_BUS_DEFAULT_DEFAULT_BITS           16
#define FX3_GPIF_CTRL_BUS_DEFAULT_DEFAULT_MASK           (0xffffUL << 0)

#define FX3_GPIF_CTRL_BUS_POLARITY_POLARITY_SHIFT        0
#define FX3_GPIF_CTRL_BUS_POLARITY_POLARITY_BITS         16
#define FX3_GPIF_CTRL_BUS_POLARITY_POLARITY_MASK         (0xffffUL << 0)

#define FX3_GPIF_CTRL_BUS_TOGGLE_TOGGLE_SHIFT            0
#define FX3_GPIF_CTRL_BUS_TOGGLE_TOGGLE_BITS             16
#define FX3_GPIF_CTRL_BUS_TOGGLE_TOGGLE_MASK             (0xffffUL << 0)

#define FX3_GPIF_CTRL_BUS_SELECT_OMEGA_INDEX_SHIFT       0
#define FX3_GPIF_CTRL_BUS_SELECT_OMEGA_INDEX_BITS        5
#define FX3_GPIF_CTRL_BUS_SELECT_OMEGA_INDEX_MASK        (0x1fUL << 0)

#define FX3_GPIF_CTRL_COUNT_CONFIG_CONNECT_SHIFT         4
#define FX3_GPIF_CTRL_COUNT_CONFIG_CONNECT_BITS          4
#define FX3_GPIF_CTRL_COUNT_CONFIG_CONNECT_MASK          (0xfUL << 4)
#define FX3_GPIF_CTRL_COUNT_CONFIG_SW_RESET              (1UL << 3)
#define FX3_GPIF_CTRL_COUNT_CONFIG_RELOAD                (1UL << 2)
#define FX3_GPIF_CTRL_COUNT_CONFIG_DOWN_UP               (1UL << 1)
#define FX3_GPIF_CTRL_COUNT_CONFIG_ENABLE                (1UL << 0)

#define FX3_GPIF_CTRL_COUNT_RESET_RESET_LOAD_SHIFT       0
#define FX3_GPIF_CTRL_COUNT_RESET_RESET_LOAD_BITS        16
#define FX3_GPIF_CTRL_COUNT_RESET_RESET_LOAD_MASK        (0xffffUL << 0)

#define FX3_GPIF_CTRL_COUNT_LIMIT_LIMIT_SHIFT            0
#define FX3_GPIF_CTRL_COUNT_LIMIT_LIMIT_BITS             16
#define FX3_GPIF_CTRL_COUNT_LIMIT_LIMIT_MASK             (0xffffUL << 0)

#define FX3_GPIF_ADDR_COUNT_CONFIG_INCREMENT_SHIFT       0
#define FX3_GPIF_ADDR_COUNT_CONFIG_INCREMENT_BITS        8
#define FX3_GPIF_ADDR_COUNT_CONFIG_INCREMENT_MASK        (0xffUL << 0)
#define FX3_GPIF_ADDR_COUNT_CONFIG_DOWN_UP               (1UL << 3)
#define FX3_GPIF_ADDR_COUNT_CONFIG_SW_RESET              (1UL << 2)
#define FX3_GPIF_ADDR_COUNT_CONFIG_RELOAD                (1UL << 1)
#define FX3_GPIF_ADDR_COUNT_CONFIG_ENABLE                (1UL << 0)

#define FX3_GPIF_STATE_COUNT_CONFIG_SW_RESET             (1UL << 1)
#define FX3_GPIF_STATE_COUNT_CONFIG_ENABLE               (1UL << 0)

#define FX3_GPIF_STATE_COUNT_LIMIT_LIMIT_SHIFT           0
#define FX3_GPIF_STATE_COUNT_LIMIT_LIMIT_BITS            16
#define FX3_GPIF_STATE_COUNT_LIMIT_LIMIT_MASK            (0xffffUL << 0)

#define FX3_GPIF_DATA_COUNT_CONFIG_INCREMENT_SHIFT       0
#define FX3_GPIF_DATA_COUNT_CONFIG_INCREMENT_BITS        8
#define FX3_GPIF_DATA_COUNT_CONFIG_INCREMENT_MASK        (0xffUL << 0)
#define FX3_GPIF_DATA_COUNT_CONFIG_DOWN_UP               (1UL << 3)
#define FX3_GPIF_DATA_COUNT_CONFIG_SW_RESET              (1UL << 2)
#define FX3_GPIF_DATA_COUNT_CONFIG_RELOAD                (1UL << 1)
#define FX3_GPIF_DATA_COUNT_CONFIG_ENABLE                (1UL << 0)

#define FX3_GPIF_CTRL_COMP_VALUE_VALUE_SHIFT             0
#define FX3_GPIF_CTRL_COMP_VALUE_VALUE_BITS              16
#define FX3_GPIF_CTRL_COMP_VALUE_VALUE_MASK              (0xffffUL << 0)

#define FX3_GPIF_CTRL_COMP_MASK_MASK_SHIFT               0
#define FX3_GPIF_CTRL_COMP_MASK_MASK_BITS                16
#define FX3_GPIF_CTRL_COMP_MASK_MASK_MASK                (0xffffUL << 0)

#define FX3_GPIF_DATA_CTRL_EG_ADDR_VALID_SHIFT           12
#define FX3_GPIF_DATA_CTRL_EG_ADDR_VALID_BITS            4
#define FX3_GPIF_DATA_CTRL_EG_ADDR_VALID_MASK            (0xfUL << 12)
#define FX3_GPIF_DATA_CTRL_IN_ADDR_VALID_SHIFT           8
#define FX3_GPIF_DATA_CTRL_IN_ADDR_VALID_BITS            4
#define FX3_GPIF_DATA_CTRL_IN_ADDR_VALID_MASK            (0xfUL << 8)
#define FX3_GPIF_DATA_CTRL_EG_DATA_VALID_SHIFT           4
#define FX3_GPIF_DATA_CTRL_EG_DATA_VALID_BITS            4
#define FX3_GPIF_DATA_CTRL_EG_DATA_VALID_MASK            (0xfUL << 4)
#define FX3_GPIF_DATA_CTRL_IN_DATA_VALID_SHIFT           0
#define FX3_GPIF_DATA_CTRL_IN_DATA_VALID_BITS            4
#define FX3_GPIF_DATA_CTRL_IN_DATA_VALID_MASK            (0xfUL << 0)

#define FX3_GPIF_THREAD_CONFIG_ENABLE                    (1UL << 31)
#define FX3_GPIF_THREAD_CONFIG_WATERMARK_SHIFT           16
#define FX3_GPIF_THREAD_CONFIG_WATERMARK_BITS            14
#define FX3_GPIF_THREAD_CONFIG_WATERMARK_MASK            (0x3fffUL << 16)
#define FX3_GPIF_THREAD_CONFIG_BURST_SIZE_SHIFT          8
#define FX3_GPIF_THREAD_CONFIG_BURST_SIZE_BITS           4
#define FX3_GPIF_THREAD_CONFIG_BURST_SIZE_MASK           (0xfUL << 8)
#define FX3_GPIF_THREAD_CONFIG_WM_CFG                    (1UL << 7)
#define FX3_GPIF_THREAD_CONFIG_THREAD_SOCK_SHIFT         0
#define FX3_GPIF_THREAD_CONFIG_THREAD_SOCK_BITS          5
#define FX3_GPIF_THREAD_CONFIG_THREAD_SOCK_MASK          (0x1fUL << 0)

#define FX3_GPIF_ALPHA_STAT_ALPHA_SHIFT                  0
#define FX3_GPIF_ALPHA_STAT_ALPHA_BITS                   8
#define FX3_GPIF_ALPHA_STAT_ALPHA_MASK                   (0xffUL << 0)

#define FX3_GPIF_WAVEFORM_CTRL_STAT_CURRENT_STATE_SHIFT  24
#define FX3_GPIF_WAVEFORM_CTRL_STAT_CURRENT_STATE_BITS   8
#define FX3_GPIF_WAVEFORM_CTRL_STAT_CURRENT_STATE_MASK   (0xffUL << 24)
#define FX3_GPIF_WAVEFORM_CTRL_STAT_ALPHA_INIT_SHIFT     16
#define FX3_GPIF_WAVEFORM_CTRL_STAT_ALPHA_INIT_BITS      8
#define FX3_GPIF_WAVEFORM_CTRL_STAT_ALPHA_INIT_MASK      (0xffUL << 16)
#define FX3_GPIF_WAVEFORM_CTRL_STAT_CPU_LAMBDA           (1UL << 11)
#define FX3_GPIF_WAVEFORM_CTRL_STAT_GPIF_STAT_SHIFT      8
#define FX3_GPIF_WAVEFORM_CTRL_STAT_GPIF_STAT_BITS       3
#define FX3_GPIF_WAVEFORM_CTRL_STAT_GPIF_STAT_MASK       (0x7UL << 8)
#define FX3_GPIF_WAVEFORM_CTRL_STAT_PAUSE                (1UL << 1)
#define FX3_GPIF_WAVEFORM_CTRL_STAT_WAVEFORM_VALID       (1UL << 0)

#define FX3_GPIF_WAVEFORM_SWITCH_DONE_STATE_SHIFT        24
#define FX3_GPIF_WAVEFORM_SWITCH_DONE_STATE_BITS         8
#define FX3_GPIF_WAVEFORM_SWITCH_DONE_STATE_MASK         (0xffUL << 24)
#define FX3_GPIF_WAVEFORM_SWITCH_DESTINATION_STATE_SHIFT 16
#define FX3_GPIF_WAVEFORM_SWITCH_DESTINATION_STATE_BITS  8
#define FX3_GPIF_WAVEFORM_SWITCH_DESTINATION_STATE_MASK  (0xffUL << 16)
#define FX3_GPIF_WAVEFORM_SWITCH_TERMINAL_STATE_SHIFT    8
#define FX3_GPIF_WAVEFORM_SWITCH_TERMINAL_STATE_BITS     8
#define FX3_GPIF_WAVEFORM_SWITCH_TERMINAL_STATE_MASK     (0xffUL << 8)
#define FX3_GPIF_WAVEFORM_SWITCH_TERMINATED              (1UL << 7)
#define FX3_GPIF_WAVEFORM_SWITCH_TIMEOUT_REACHED         (1UL << 6)
#define FX3_GPIF_WAVEFORM_SWITCH_TIMEOUT_MODE_SHIFT      3
#define FX3_GPIF_WAVEFORM_SWITCH_TIMEOUT_MODE_BITS       3
#define FX3_GPIF_WAVEFORM_SWITCH_TIMEOUT_MODE_MASK       (0x7UL << 3)
#define FX3_GPIF_WAVEFORM_SWITCH_SWITCH_NOW              (1UL << 2)
#define FX3_GPIF_WAVEFORM_SWITCH_DONE_ENABLE             (1UL << 1)
#define FX3_GPIF_WAVEFORM_SWITCH_WAVEFORM_SWITCH         (1UL << 0)

#define FX3_GPIF_CRC_CONFIG_ENABLE                       (1UL << 31)
#define FX3_GPIF_CRC_CONFIG_CRC_ERROR                    (1UL << 22)
#define FX3_GPIF_CRC_CONFIG_BYTE_ENDIAN                  (1UL << 21)
#define FX3_GPIF_CRC_CONFIG_BIT_ENDIAN                   (1UL << 20)
#define FX3_GPIF_CRC_CONFIG_CRC_RECEIVED_SHIFT           0
#define FX3_GPIF_CRC_CONFIG_CRC_RECEIVED_BITS            16
#define FX3_GPIF_CRC_CONFIG_CRC_RECEIVED_MASK            (0xffffUL << 0)

#define FX3_GPIF_CRC_DATA_CRC_VALUE_SHIFT                16
#define FX3_GPIF_CRC_DATA_CRC_VALUE_BITS                 16
#define FX3_GPIF_CRC_DATA_CRC_VALUE_MASK                 (0xffffUL << 16)
#define FX3_GPIF_CRC_DATA_INITIAL_VALUE_SHIFT            0
#define FX3_GPIF_CRC_DATA_INITIAL_VALUE_BITS             16
#define FX3_GPIF_CRC_DATA_INITIAL_VALUE_MASK             (0xffffUL << 0)

#define FX3_GPIF_FUNCTION_FUNCTION_SHIFT                 0
#define FX3_GPIF_FUNCTION_FUNCTION_BITS                  16
#define FX3_GPIF_FUNCTION_FUNCTION_MASK                  (0xffffUL << 0)

#define FX3_GPIF_LEFT_WAVEFORM_UNUSED_SHIFT              96
#define FX3_GPIF_LEFT_WAVEFORM_UNUSED_BITS               32
#define FX3_GPIF_LEFT_WAVEFORM_UNUSED_MASK               (0xffffffffUL << 96)
#define FX3_GPIF_LEFT_WAVEFORM_VALID                     (1UL << 95)
#define FX3_GPIF_LEFT_WAVEFORM_BETA_DEASSERT             (1UL << 94)
#define FX3_GPIF_LEFT_WAVEFORM_REPEAT_COUNT_SHIFT        86
#define FX3_GPIF_LEFT_WAVEFORM_REPEAT_COUNT_BITS         8
#define FX3_GPIF_LEFT_WAVEFORM_REPEAT_COUNT_MASK         (0xffUL << 86)
#define FX3_GPIF_LEFT_WAVEFORM_Beta_SHIFT                54
#define FX3_GPIF_LEFT_WAVEFORM_Beta_BITS                 32
#define FX3_GPIF_LEFT_WAVEFORM_Beta_MASK                 (0xffffffffUL << 54)
#define FX3_GPIF_LEFT_WAVEFORM_Alpha_Right_SHIFT         46
#define FX3_GPIF_LEFT_WAVEFORM_Alpha_Right_BITS          8
#define FX3_GPIF_LEFT_WAVEFORM_Alpha_Right_MASK          (0xffUL << 46)
#define FX3_GPIF_LEFT_WAVEFORM_Alpha_Left_SHIFT          38
#define FX3_GPIF_LEFT_WAVEFORM_Alpha_Left_BITS           8
#define FX3_GPIF_LEFT_WAVEFORM_Alpha_Left_MASK           (0xffUL << 38)
#define FX3_GPIF_LEFT_WAVEFORM_f1_SHIFT                  33
#define FX3_GPIF_LEFT_WAVEFORM_f1_BITS                   5
#define FX3_GPIF_LEFT_WAVEFORM_f1_MASK                   (0x1fUL << 33)
#define FX3_GPIF_LEFT_WAVEFORM_f0_SHIFT                  28
#define FX3_GPIF_LEFT_WAVEFORM_f0_BITS                   5
#define FX3_GPIF_LEFT_WAVEFORM_f0_MASK                   (0x1fUL << 28)
#define FX3_GPIF_LEFT_WAVEFORM_Fd_SHIFT                  23
#define FX3_GPIF_LEFT_WAVEFORM_Fd_BITS                   5
#define FX3_GPIF_LEFT_WAVEFORM_Fd_MASK                   (0x1fUL << 23)
#define FX3_GPIF_LEFT_WAVEFORM_Fc_SHIFT                  18
#define FX3_GPIF_LEFT_WAVEFORM_Fc_BITS                   5
#define FX3_GPIF_LEFT_WAVEFORM_Fc_MASK                   (0x1fUL << 18)
#define FX3_GPIF_LEFT_WAVEFORM_Fb_SHIFT                  13
#define FX3_GPIF_LEFT_WAVEFORM_Fb_BITS                   5
#define FX3_GPIF_LEFT_WAVEFORM_Fb_MASK                   (0x1fUL << 13)
#define FX3_GPIF_LEFT_WAVEFORM_Fa_SHIFT                  8
#define FX3_GPIF_LEFT_WAVEFORM_Fa_BITS                   5
#define FX3_GPIF_LEFT_WAVEFORM_Fa_MASK                   (0x1fUL << 8)
#define FX3_GPIF_LEFT_WAVEFORM_NEXT_STATE_SHIFT          0
#define FX3_GPIF_LEFT_WAVEFORM_NEXT_STATE_BITS           8
#define FX3_GPIF_LEFT_WAVEFORM_NEXT_STATE_MASK           (0xffUL << 0)

#define FX3_GPIF_RIGHT_WAVEFORM_UNUSED_SHIFT             96
#define FX3_GPIF_RIGHT_WAVEFORM_UNUSED_BITS              32
#define FX3_GPIF_RIGHT_WAVEFORM_UNUSED_MASK              (0xffffffffUL << 96)
#define FX3_GPIF_RIGHT_WAVEFORM_VALID                    (1UL << 95)
#define FX3_GPIF_RIGHT_WAVEFORM_BETA_DEASSERT            (1UL << 94)
#define FX3_GPIF_RIGHT_WAVEFORM_REPEAT_COUNT_SHIFT       86
#define FX3_GPIF_RIGHT_WAVEFORM_REPEAT_COUNT_BITS        8
#define FX3_GPIF_RIGHT_WAVEFORM_REPEAT_COUNT_MASK        (0xffUL << 86)
#define FX3_GPIF_RIGHT_WAVEFORM_Beta_SHIFT               54
#define FX3_GPIF_RIGHT_WAVEFORM_Beta_BITS                32
#define FX3_GPIF_RIGHT_WAVEFORM_Beta_MASK                (0xffffffffUL << 54)
#define FX3_GPIF_RIGHT_WAVEFORM_Alpha_Right_SHIFT        46
#define FX3_GPIF_RIGHT_WAVEFORM_Alpha_Right_BITS         8
#define FX3_GPIF_RIGHT_WAVEFORM_Alpha_Right_MASK         (0xffUL << 46)
#define FX3_GPIF_RIGHT_WAVEFORM_Alpha_Left_SHIFT         38
#define FX3_GPIF_RIGHT_WAVEFORM_Alpha_Left_BITS          8
#define FX3_GPIF_RIGHT_WAVEFORM_Alpha_Left_MASK          (0xffUL << 38)
#define FX3_GPIF_RIGHT_WAVEFORM_f1_SHIFT                 33
#define FX3_GPIF_RIGHT_WAVEFORM_f1_BITS                  5
#define FX3_GPIF_RIGHT_WAVEFORM_f1_MASK                  (0x1fUL << 33)
#define FX3_GPIF_RIGHT_WAVEFORM_f0_SHIFT                 28
#define FX3_GPIF_RIGHT_WAVEFORM_f0_BITS                  5
#define FX3_GPIF_RIGHT_WAVEFORM_f0_MASK                  (0x1fUL << 28)
#define FX3_GPIF_RIGHT_WAVEFORM_Fd_SHIFT                 23
#define FX3_GPIF_RIGHT_WAVEFORM_Fd_BITS                  5
#define FX3_GPIF_RIGHT_WAVEFORM_Fd_MASK                  (0x1fUL << 23)
#define FX3_GPIF_RIGHT_WAVEFORM_Fc_SHIFT                 18
#define FX3_GPIF_RIGHT_WAVEFORM_Fc_BITS                  5
#define FX3_GPIF_RIGHT_WAVEFORM_Fc_MASK                  (0x1fUL << 18)
#define FX3_GPIF_RIGHT_WAVEFORM_Fb_SHIFT                 13
#define FX3_GPIF_RIGHT_WAVEFORM_Fb_BITS                  5
#define FX3_GPIF_RIGHT_WAVEFORM_Fb_MASK                  (0x1fUL << 13)
#define FX3_GPIF_RIGHT_WAVEFORM_Fa_SHIFT                 8
#define FX3_GPIF_RIGHT_WAVEFORM_Fa_BITS                  5
#define FX3_GPIF_RIGHT_WAVEFORM_Fa_MASK                  (0x1fUL << 8)
#define FX3_GPIF_RIGHT_WAVEFORM_NEXT_STATE_SHIFT         0
#define FX3_GPIF_RIGHT_WAVEFORM_NEXT_STATE_BITS          8
#define FX3_GPIF_RIGHT_WAVEFORM_NEXT_STATE_MASK          (0xffUL << 0)

#endif /* RDB_GPIF_H_ */
