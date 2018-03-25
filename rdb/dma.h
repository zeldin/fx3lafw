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

#ifndef RDB_DMA_H_
#define RDB_DMA_H_

#define FX3_SCK_DSCR                          0x00 /* Descriptor Chain Pointer */
#define FX3_SCK_SIZE                          0x04 /* Transfer Size Register */
#define FX3_SCK_COUNT                         0x08 /* Transfer Count Register */
#define FX3_SCK_STATUS                        0x0C /* Socket Status Register */
#define FX3_SCK_INTR                          0x10 /* Socket Interrupt Request Register */
#define FX3_SCK_INTR_MASK                     0x14 /* Socket Interrupt Mask Register */
#define FX3_DSCR_BUFFER                       0x20 /* Descriptor Buffer Base Address Register */
#define FX3_DSCR_SYNC                         0x24 /* Descriptor Synchronization Pointers Register */
#define FX3_DSCR_CHAIN                        0x28 /* Descriptor Chain Pointers Register */
#define FX3_DSCR_SIZE                         0x02C /* Descriptor Size Register */
#define FX3_EVENT                             0x7C /* Event Communication Register */
#define FX3_SCK_INTR0                         0x00 /* Socket Interrupt Request Register */
#define FX3_ADAPTER_STATUS                    0xFC /* Adapter Global Status Fields */
#define FX3_SIB_ID                            0xE0027F00 /* Storage Interface Block ID register */
#define FX3_SIB_POWER                         0xE0027F04 /* SIB Power Control */
#define FX3_SDMMC_CMD_IDX                     0xE0020000 /* SDMMC Command Index */
#define FX3_SDMMC_CMD_ARG0                    0xE0020004 /* SDMMC Command Argument 0 */
#define FX3_SDMMC_CMD_ARG1                    0xE0020008 /* SDMMC Command Argument 1 */
#define FX3_SDMMC_RESP_IDX                    0xE002000C /* SDMMC Response Index */
#define FX3_SDMMC_RESP_REG0                   0xE0020010 /* SDMMC Command Response 0 */
#define FX3_SDMMC_RESP_REG1                   0xE0020014 /* SDMMC Command Response 1 */
#define FX3_SDMMC_RESP_REG2                   0xE0020018 /* SDMMC Command Response 2 */
#define FX3_SDMMC_RESP_REG3                   0xE002001C /* SDMMC Command Response 3 */
#define FX3_SDMMC_RESP_REG4                   0xE0020020 /* SDMMC Command Response 4 */
#define FX3_SDMMC_CMD_RESP_FMT                0xE0020024 /* SDMMC Command Response Format */
#define FX3_SDMMC_BLOCK_COUNT                 0xE0020028 /* SDMMC Block Count */
#define FX3_SDMMC_BLOCK_LEN                   0xE002002C /* SDMMC Block Length */
#define FX3_SDMMC_MODE_CFG                    0xE0020030 /* SDMMC Mode Configuration */
#define FX3_SDMMC_DATA_CFG                    0xE0020034 /* SDMMC Data Configuration */
#define FX3_SDMMC_CS                          0xE0020038 /* SDMMC Command and Status */
#define FX3_SDMMC_STATUS                      0xE002003C /* SDMMC Status */
#define FX3_SDMMC_INTR                        0xE0020040 /* SDMMC Interrupt Status */
#define FX3_SDMMC_INTR_MASK                   0xE0020044 /* SDMMC Interrupt Mask */
#define FX3_SDMMC_NCR                         0xE0020048 /* SDMMC Command Response Timing Register #1 */
#define FX3_SDMMC_NCC_NWR                     0xE002004C /* SDMMC Command Response Timing Register #2 */
#define FX3_SDMMC_NAC                         0xE0020050 /* SDMMC Read Timeout Register */
#define FX3_SDMMC_HW_CTRL                     0xE0020054 /* SDMMC Hardware Control Register */
#define FX3_SDMMC_DLL_CTRL                    0xE0020058 /* SDMMC DLL Control */

#define FX3_SCK_DSCR_DSCR_LOW_SHIFT                      24
#define FX3_SCK_DSCR_DSCR_LOW_BITS                       8
#define FX3_SCK_DSCR_DSCR_LOW_MASK                       (0xffUL << 24)
#define FX3_SCK_DSCR_DSCR_COUNT_SHIFT                    16
#define FX3_SCK_DSCR_DSCR_COUNT_BITS                     8
#define FX3_SCK_DSCR_DSCR_COUNT_MASK                     (0xffUL << 16)
#define FX3_SCK_DSCR_DSCR_NUMBER_SHIFT                   0
#define FX3_SCK_DSCR_DSCR_NUMBER_BITS                    16
#define FX3_SCK_DSCR_DSCR_NUMBER_MASK                    (0xffffUL << 0)

#define FX3_SCK_STATUS_GO_ENABLE                         (1UL << 31)
#define FX3_SCK_STATUS_GO_SUSPEND                        (1UL << 30)
#define FX3_SCK_STATUS_UNIT                              (1UL << 29)
#define FX3_SCK_STATUS_WRAPUP                            (1UL << 28)
#define FX3_SCK_STATUS_SUSP_EOP                          (1UL << 27)
#define FX3_SCK_STATUS_SUSP_TRANS                        (1UL << 26)
#define FX3_SCK_STATUS_SUSP_LAST                         (1UL << 25)
#define FX3_SCK_STATUS_SUSP_PARTIAL                      (1UL << 24)
#define FX3_SCK_STATUS_EN_CONS_EVENTS                    (1UL << 23)
#define FX3_SCK_STATUS_EN_PROD_EVENTS                    (1UL << 22)
#define FX3_SCK_STATUS_TRUNCATE                          (1UL << 21)
#define FX3_SCK_STATUS_ENABLED                           (1UL << 20)
#define FX3_SCK_STATUS_SUSPENDED                         (1UL << 19)
#define FX3_SCK_STATUS_ZLP_RCVD                          (1UL << 18)
#define FX3_SCK_STATUS_STATE_SHIFT                       15
#define FX3_SCK_STATUS_STATE_BITS                        3
#define FX3_SCK_STATUS_STATE_MASK                        (0x7UL << 15)
#define FX3_SCK_STATUS_AVL_ENABLE                        (1UL << 10)
#define FX3_SCK_STATUS_AVL_MIN_SHIFT                     5
#define FX3_SCK_STATUS_AVL_MIN_BITS                      5
#define FX3_SCK_STATUS_AVL_MIN_MASK                      (0x1fUL << 5)
#define FX3_SCK_STATUS_AVL_COUNT_SHIFT                   0
#define FX3_SCK_STATUS_AVL_COUNT_BITS                    5
#define FX3_SCK_STATUS_AVL_COUNT_MASK                    (0x1fUL << 0)

#define FX3_SCK_INTR_LAST_BUF                            (1UL << 9)
#define FX3_SCK_INTR_PARTIAL_BUF                         (1UL << 8)
#define FX3_SCK_INTR_TRANS_DONE                          (1UL << 7)
#define FX3_SCK_INTR_ERROR                               (1UL << 6)
#define FX3_SCK_INTR_SUSPEND                             (1UL << 5)
#define FX3_SCK_INTR_STALL                               (1UL << 4)
#define FX3_SCK_INTR_DSCR_NOT_AVL                        (1UL << 3)
#define FX3_SCK_INTR_DSCR_IS_LOW                         (1UL << 2)
#define FX3_SCK_INTR_CONSUME_EVENT                       (1UL << 1)
#define FX3_SCK_INTR_PRODUCE_EVENT                       (1UL << 0)

#define FX3_SCK_INTR_MASK_LAST_BUF                       (1UL << 9)
#define FX3_SCK_INTR_MASK_PARTIAL_BUF                    (1UL << 8)
#define FX3_SCK_INTR_MASK_TRANS_DONE                     (1UL << 7)
#define FX3_SCK_INTR_MASK_ERROR                          (1UL << 6)
#define FX3_SCK_INTR_MASK_SUSPEND                        (1UL << 5)
#define FX3_SCK_INTR_MASK_STALL                          (1UL << 4)
#define FX3_SCK_INTR_MASK_DSCR_NOT_AVL                   (1UL << 3)
#define FX3_SCK_INTR_MASK_DSCR_IS_LOW                    (1UL << 2)
#define FX3_SCK_INTR_MASK_CONSUME_EVENT                  (1UL << 1)
#define FX3_SCK_INTR_MASK_PRODUCE_EVENT                  (1UL << 0)

#define FX3_DSCR_SYNC_EN_PROD_INT                        (1UL << 31)
#define FX3_DSCR_SYNC_EN_PROD_EVENT                      (1UL << 30)
#define FX3_DSCR_SYNC_PROD_IP_SHIFT                      24
#define FX3_DSCR_SYNC_PROD_IP_BITS                       6
#define FX3_DSCR_SYNC_PROD_IP_MASK                       (0x3fUL << 24)
#define FX3_DSCR_SYNC_PROD_SCK_SHIFT                     16
#define FX3_DSCR_SYNC_PROD_SCK_BITS                      8
#define FX3_DSCR_SYNC_PROD_SCK_MASK                      (0xffUL << 16)
#define FX3_DSCR_SYNC_EN_CONS_INT                        (1UL << 15)
#define FX3_DSCR_SYNC_EN_CONS_EVENT                      (1UL << 14)
#define FX3_DSCR_SYNC_CONS_IP_SHIFT                      8
#define FX3_DSCR_SYNC_CONS_IP_BITS                       6
#define FX3_DSCR_SYNC_CONS_IP_MASK                       (0x3fUL << 8)
#define FX3_DSCR_SYNC_CONS_SCK_SHIFT                     0
#define FX3_DSCR_SYNC_CONS_SCK_BITS                      8
#define FX3_DSCR_SYNC_CONS_SCK_MASK                      (0xffUL << 0)

#define FX3_DSCR_CHAIN_WR_NEXT_DSCR_SHIFT                16
#define FX3_DSCR_CHAIN_WR_NEXT_DSCR_BITS                 16
#define FX3_DSCR_CHAIN_WR_NEXT_DSCR_MASK                 (0xffffUL << 16)
#define FX3_DSCR_CHAIN_RD_NEXT_DSCR_SHIFT                0
#define FX3_DSCR_CHAIN_RD_NEXT_DSCR_BITS                 16
#define FX3_DSCR_CHAIN_RD_NEXT_DSCR_MASK                 (0xffffUL << 0)

#define FX3_DSCR_SIZE_BYTE_COUNT_SHIFT                   16
#define FX3_DSCR_SIZE_BYTE_COUNT_BITS                    16
#define FX3_DSCR_SIZE_BYTE_COUNT_MASK                    (0xffffUL << 16)
#define FX3_DSCR_SIZE_BUFFER_SIZE_SHIFT                  4
#define FX3_DSCR_SIZE_BUFFER_SIZE_BITS                   12
#define FX3_DSCR_SIZE_BUFFER_SIZE_MASK                   (0xfffUL << 4)
#define FX3_DSCR_SIZE_BUFFER_OCCUPIED                    (1UL << 3)
#define FX3_DSCR_SIZE_BUFFER_ERROR                       (1UL << 2)
#define FX3_DSCR_SIZE_EOP                                (1UL << 1)
#define FX3_DSCR_SIZE_MARKER                             (1UL << 0)

#define FX3_EVENT_EVENT_TYPE                             (1UL << 16)
#define FX3_EVENT_ACTIVE_DSCR_SHIFT                      0
#define FX3_EVENT_ACTIVE_DSCR_BITS                       16
#define FX3_EVENT_ACTIVE_DSCR_MASK                       (0xffffUL << 0)

#define FX3_SCK_INTR0_SCKINTR_SHIFT                      0
#define FX3_SCK_INTR0_SCKINTR_BITS                       256
#define FX3_SCK_INTR0_SCKINTR_MASK                       (0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffUL << 0)

#define FX3_ADAPTER_STATUS_WORD_SIZE_SHIFT               22
#define FX3_ADAPTER_STATUS_WORD_SIZE_BITS                2
#define FX3_ADAPTER_STATUS_WORD_SIZE_MASK                (0x3UL << 22)
#define FX3_ADAPTER_STATUS_FQ_SIZE_SHIFT                 16
#define FX3_ADAPTER_STATUS_FQ_SIZE_BITS                  6
#define FX3_ADAPTER_STATUS_FQ_SIZE_MASK                  (0x3fUL << 16)
#define FX3_ADAPTER_STATUS_IG_ONLY_SHIFT                 8
#define FX3_ADAPTER_STATUS_IG_ONLY_BITS                  8
#define FX3_ADAPTER_STATUS_IG_ONLY_MASK                  (0xffUL << 8)
#define FX3_ADAPTER_STATUS_TTL_SOCKETS_SHIFT             0
#define FX3_ADAPTER_STATUS_TTL_SOCKETS_BITS              8
#define FX3_ADAPTER_STATUS_TTL_SOCKETS_MASK              (0xffUL << 0)

#define FX3_SIB_ID_BLOCK_VERSION_SHIFT                   16
#define FX3_SIB_ID_BLOCK_VERSION_BITS                    16
#define FX3_SIB_ID_BLOCK_VERSION_MASK                    (0xffffUL << 16)
#define FX3_SIB_ID_BLOCK_ID_SHIFT                        0
#define FX3_SIB_ID_BLOCK_ID_BITS                         16
#define FX3_SIB_ID_BLOCK_ID_MASK                         (0xffffUL << 0)

#define FX3_SIB_POWER_RESETN                             (1UL << 31)
#define FX3_SIB_POWER_ACTIVE                             (1UL << 0)

#define FX3_SDMMC_CMD_IDX_CMD_SHIFT                      0
#define FX3_SDMMC_CMD_IDX_CMD_BITS                       6
#define FX3_SDMMC_CMD_IDX_CMD_MASK                       (0x3fUL << 0)

#define FX3_SDMMC_RESP_IDX_ST_BIT                        (1UL << 7)
#define FX3_SDMMC_RESP_IDX_TR_BIT                        (1UL << 6)
#define FX3_SDMMC_RESP_IDX_CMD_SHIFT                     0
#define FX3_SDMMC_RESP_IDX_CMD_BITS                      6
#define FX3_SDMMC_RESP_IDX_CMD_MASK                      (0x3fUL << 0)

#define FX3_SDMMC_CMD_RESP_FMT_RESPCRC_START             (1UL << 31)
#define FX3_SDMMC_CMD_RESP_FMT_CORCRC_ODD                (1UL << 30)
#define FX3_SDMMC_CMD_RESP_FMT_R_CRC_EN                  (1UL << 28)
#define FX3_SDMMC_CMD_RESP_FMT_CORCRC                    (1UL << 27)
#define FX3_SDMMC_CMD_RESP_FMT_RESPCONF_SHIFT            16
#define FX3_SDMMC_CMD_RESP_FMT_RESPCONF_BITS             11
#define FX3_SDMMC_CMD_RESP_FMT_RESPCONF_MASK             (0x7ffUL << 16)
#define FX3_SDMMC_CMD_RESP_FMT_CMDFRMT_SHIFT             0
#define FX3_SDMMC_CMD_RESP_FMT_CMDFRMT_BITS              6
#define FX3_SDMMC_CMD_RESP_FMT_CMDFRMT_MASK              (0x3fUL << 0)

#define FX3_SDMMC_MODE_CFG_IDLE_STOP_CLK_EN              (1UL << 31)
#define FX3_SDMMC_MODE_CFG_IDLE_STOP_CLK_DELAY_SHIFT     24
#define FX3_SDMMC_MODE_CFG_IDLE_STOP_CLK_DELAY_BITS      7
#define FX3_SDMMC_MODE_CFG_IDLE_STOP_CLK_DELAY_MASK      (0x7fUL << 24)
#define FX3_SDMMC_MODE_CFG_EXP_BOOT_ACK                  (1UL << 22)
#define FX3_SDMMC_MODE_CFG_BLK_END_STOP_CLK              (1UL << 21)
#define FX3_SDMMC_MODE_CFG_RD_END_STOP_CLK_EN            (1UL << 19)
#define FX3_SDMMC_MODE_CFG_CARD_DETECT_POLARITY          (1UL << 18)
#define FX3_SDMMC_MODE_CFG_WR_STOP_CLK_EN                (1UL << 16)
#define FX3_SDMMC_MODE_CFG_RD_STOP_CLK_EN                (1UL << 15)
#define FX3_SDMMC_MODE_CFG_EN_CMD_COMP                   (1UL << 14)
#define FX3_SDMMC_MODE_CFG_DATABUSWIDTH_SHIFT            12
#define FX3_SDMMC_MODE_CFG_DATABUSWIDTH_BITS             2
#define FX3_SDMMC_MODE_CFG_DATABUSWIDTH_MASK             (0x3UL << 12)
#define FX3_SDMMC_MODE_CFG_MODE_SHIFT                    10
#define FX3_SDMMC_MODE_CFG_MODE_BITS                     2
#define FX3_SDMMC_MODE_CFG_MODE_MASK                     (0x3UL << 10)
#define FX3_SDMMC_MODE_CFG_SIGNALING_SHIFT               6
#define FX3_SDMMC_MODE_CFG_SIGNALING_BITS                4
#define FX3_SDMMC_MODE_CFG_SIGNALING_MASK                (0xfUL << 6)
#define FX3_SDMMC_MODE_CFG_DLL_BYPASS_EN                 (1UL << 5)

#define FX3_SDMMC_DATA_CFG_EXPBUSY                       (1UL << 3)
#define FX3_SDMMC_DATA_CFG_EXPCRCR                       (1UL << 2)
#define FX3_SDMMC_DATA_CFG_CARD_BUSY_DET                 (1UL << 1)
#define FX3_SDMMC_DATA_CFG_RD_CRC_EN                     (1UL << 0)

#define FX3_SDMMC_CS_EOP_EOT                             (1UL << 31)
#define FX3_SDMMC_CS_SOCKET_SHIFT                        24
#define FX3_SDMMC_CS_SOCKET_BITS                         5
#define FX3_SDMMC_CS_SOCKET_MASK                         (0x1fUL << 24)
#define FX3_SDMMC_CS_SDIO_READ_WAIT_EN                   (1UL << 15)
#define FX3_SDMMC_CS_SDMMC_CLK_DIS                       (1UL << 14)
#define FX3_SDMMC_CS_CLR_BOOTCMD                         (1UL << 11)
#define FX3_SDMMC_CS_CLR_RDDCARD                         (1UL << 10)
#define FX3_SDMMC_CS_CLR_WRDCARD                         (1UL << 9)
#define FX3_SDMMC_CS_CLR_SNDCMD                          (1UL << 8)
#define FX3_SDMMC_CS_CMDCOMP_DIS                         (1UL << 7)
#define FX3_SDMMC_CS_BOOTCMD                             (1UL << 6)
#define FX3_SDMMC_CS_RSTCONT                             (1UL << 5)
#define FX3_SDMMC_CS_RDDCARD                             (1UL << 2)
#define FX3_SDMMC_CS_WRDCARD                             (1UL << 1)
#define FX3_SDMMC_CS_SNDCMD                              (1UL << 0)

#define FX3_SDMMC_STATUS_CRC16_EVEN_ERROR                (1UL << 31)
#define FX3_SDMMC_STATUS_CRC16_ODD_ERROR                 (1UL << 30)
#define FX3_SDMMC_STATUS_DATA_SM_BUSY                    (1UL << 28)
#define FX3_SDMMC_STATUS_COMMAND_SM_BUSY                 (1UL << 27)
#define FX3_SDMMC_STATUS_CRCFC_SHIFT                     24
#define FX3_SDMMC_STATUS_CRCFC_BITS                      3
#define FX3_SDMMC_STATUS_CRCFC_MASK                      (0x7UL << 24)
#define FX3_SDMMC_STATUS_RD_END_DATA_ERROR               (1UL << 18)
#define FX3_SDMMC_STATUS_DAT0_STAT                       (1UL << 17)
#define FX3_SDMMC_STATUS_DLL_LOCKED                      (1UL << 16)
#define FX3_SDMMC_STATUS_DLL_LOST_LOCK                   (1UL << 15)
#define FX3_SDMMC_STATUS_BOOT_ACK                        (1UL << 14)
#define FX3_SDMMC_STATUS_CMD_COMP                        (1UL << 13)
#define FX3_SDMMC_STATUS_FIFO_U_DET                      (1UL << 12)
#define FX3_SDMMC_STATUS_FIFO_O_DET                      (1UL << 11)
#define FX3_SDMMC_STATUS_DAT3_STAT                       (1UL << 10)
#define FX3_SDMMC_STATUS_CARD_DETECT                     (1UL << 9)
#define FX3_SDMMC_STATUS_SDIO_INTR                       (1UL << 8)
#define FX3_SDMMC_STATUS_CRC16_ERROR                     (1UL << 7)
#define FX3_SDMMC_STATUS_RD_DATA_TIMEOUT                 (1UL << 6)
#define FX3_SDMMC_STATUS_BLOCKS_RECEIVED                 (1UL << 5)
#define FX3_SDMMC_STATUS_BLOCK_COMP                      (1UL << 4)
#define FX3_SDMMC_STATUS_CRC7_ERROR                      (1UL << 3)
#define FX3_SDMMC_STATUS_RESPTIMEOUT                     (1UL << 2)
#define FX3_SDMMC_STATUS_RCVDRES                         (1UL << 1)
#define FX3_SDMMC_STATUS_CMDSENT                         (1UL << 0)

#define FX3_SDMMC_INTR_RD_END_DATA_ERROR                 (1UL << 18)
#define FX3_SDMMC_INTR_DAT0_OUTOF_BUSY                   (1UL << 17)
#define FX3_SDMMC_INTR_DLL_LOCKED                        (1UL << 16)
#define FX3_SDMMC_INTR_DLL_LOST_LOCK                     (1UL << 15)
#define FX3_SDMMC_INTR_BOOT_ACK                          (1UL << 14)
#define FX3_SDMMC_INTR_CMD_COMP                          (1UL << 13)
#define FX3_SDMMC_INTR_FIFO_U_DET                        (1UL << 12)
#define FX3_SDMMC_INTR_FIFO_O_DET                        (1UL << 11)
#define FX3_SDMMC_INTR_DAT3_CHANGE                       (1UL << 10)
#define FX3_SDMMC_INTR_CARD_DETECT                       (1UL << 9)
#define FX3_SDMMC_INTR_SDIO_INTR                         (1UL << 8)
#define FX3_SDMMC_INTR_CRC16_ERROR                       (1UL << 7)
#define FX3_SDMMC_INTR_RD_DATA_TIMEOUT                   (1UL << 6)
#define FX3_SDMMC_INTR_BLOCKS_RECEIVED                   (1UL << 5)
#define FX3_SDMMC_INTR_BLOCK_COMP                        (1UL << 4)
#define FX3_SDMMC_INTR_CRC7_ERROR                        (1UL << 3)
#define FX3_SDMMC_INTR_RESPTIMEOUT                       (1UL << 2)
#define FX3_SDMMC_INTR_RCVDRES                           (1UL << 1)
#define FX3_SDMMC_INTR_CMDSENT                           (1UL << 0)

#define FX3_SDMMC_INTR_MASK_RD_END_DATA_ERROR            (1UL << 18)
#define FX3_SDMMC_INTR_MASK_DAT0_OUTOF_BUSY              (1UL << 17)
#define FX3_SDMMC_INTR_MASK_DLL_LOCKED                   (1UL << 16)
#define FX3_SDMMC_INTR_MASK_DLL_LOST_LOCK                (1UL << 15)
#define FX3_SDMMC_INTR_MASK_BOOT_ACK                     (1UL << 14)
#define FX3_SDMMC_INTR_MASK_CMD_COMP                     (1UL << 13)
#define FX3_SDMMC_INTR_MASK_FIFO_U_DET                   (1UL << 12)
#define FX3_SDMMC_INTR_MASK_FIFO_O_DET                   (1UL << 11)
#define FX3_SDMMC_INTR_MASK_DAT3_CHANGE                  (1UL << 10)
#define FX3_SDMMC_INTR_MASK_CARD_DETECT                  (1UL << 9)
#define FX3_SDMMC_INTR_MASK_SDIO_INTR                    (1UL << 8)
#define FX3_SDMMC_INTR_MASK_CRC16_ERROR                  (1UL << 7)
#define FX3_SDMMC_INTR_MASK_RD_DATA_TIMEOUT              (1UL << 6)
#define FX3_SDMMC_INTR_MASK_BLOCKS_RECEIVED              (1UL << 5)
#define FX3_SDMMC_INTR_MASK_BLOCK_COMP                   (1UL << 4)
#define FX3_SDMMC_INTR_MASK_CRC7_ERROR                   (1UL << 3)
#define FX3_SDMMC_INTR_MASK_RESPTIMEOUT                  (1UL << 2)
#define FX3_SDMMC_INTR_MASK_RCVDRES                      (1UL << 1)
#define FX3_SDMMC_INTR_MASK_CMDSENT                      (1UL << 0)

#define FX3_SDMMC_NCR_NRC_MIN_SHIFT                      8
#define FX3_SDMMC_NCR_NRC_MIN_BITS                       8
#define FX3_SDMMC_NCR_NRC_MIN_MASK                       (0xffUL << 8)
#define FX3_SDMMC_NCR_NCR_MAX_SHIFT                      0
#define FX3_SDMMC_NCR_NCR_MAX_BITS                       7
#define FX3_SDMMC_NCR_NCR_MAX_MASK                       (0x7fUL << 0)

#define FX3_SDMMC_NCC_NWR_NWR_MIN_SHIFT                  8
#define FX3_SDMMC_NCC_NWR_NWR_MIN_BITS                   8
#define FX3_SDMMC_NCC_NWR_NWR_MIN_MASK                   (0xffUL << 8)
#define FX3_SDMMC_NCC_NWR_NCC_MIN_SHIFT                  0
#define FX3_SDMMC_NCC_NWR_NCC_MIN_BITS                   4
#define FX3_SDMMC_NCC_NWR_NCC_MIN_MASK                   (0xfUL << 0)

#define FX3_SDMMC_NAC_RDTMOUT_SHIFT                      2
#define FX3_SDMMC_NAC_RDTMOUT_BITS                       30
#define FX3_SDMMC_NAC_RDTMOUT_MASK                       (0x3fffffffUL << 2)

#define FX3_SDMMC_HW_CTRL_HW_RESET_EMMC                  (1UL << 0)

#define FX3_SDMMC_DLL_CTRL_DLL_RESET_N                   (1UL << 18)
#define FX3_SDMMC_DLL_CTRL_PIN_CLOCK_PHASE_SEL_SHIFT     11
#define FX3_SDMMC_DLL_CTRL_PIN_CLOCK_PHASE_SEL_BITS      4
#define FX3_SDMMC_DLL_CTRL_PIN_CLOCK_PHASE_SEL_MASK      (0xfUL << 11)
#define FX3_SDMMC_DLL_CTRL_SAMPLE_CMD_PHASE_SEL_SHIFT    7
#define FX3_SDMMC_DLL_CTRL_SAMPLE_CMD_PHASE_SEL_BITS     4
#define FX3_SDMMC_DLL_CTRL_SAMPLE_CMD_PHASE_SEL_MASK     (0xfUL << 7)
#define FX3_SDMMC_DLL_CTRL_SAMPLE_DATA_PHASE_SEL_SHIFT   3
#define FX3_SDMMC_DLL_CTRL_SAMPLE_DATA_PHASE_SEL_BITS    4
#define FX3_SDMMC_DLL_CTRL_SAMPLE_DATA_PHASE_SEL_MASK    (0xfUL << 3)
#define FX3_SDMMC_DLL_CTRL_DLL_STAT                      (1UL << 2)
#define FX3_SDMMC_DLL_CTRL_HIGH_FREQ                     (1UL << 1)
#define FX3_SDMMC_DLL_CTRL_ENABLE                        (1UL << 0)

#endif /* RDB_DMA_H_ */
