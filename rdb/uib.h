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

#ifndef RDB_UIB_H_
#define RDB_UIB_H_

#define FX3_UIB_INTR                          0xE0030000 /* USB Interrupt Register */
#define FX3_UIB_INTR_MASK                     0xE0030004 /* USB Interrupt Mask Register */
#define FX3_PHY_CLK_AND_TEST                  0xE0031008 /* USB PHY Clocks and Testability Configuration Register */
#define FX3_PHY_CONF                          0xE003100C /* USB PHY Programmability and Serial Interface Register */
#define FX3_PHY_CHIRP                         0xE0031014 /* USB PHY Chirp Control Register */
#define FX3_DEV_CS                            0xE0031400 /* Device Controller Master Control and Status Register */
#define FX3_DEV_FRAMECNT                      0xE0031404 /* FRAMECNT Register */
#define FX3_DEV_PWR_CS                        0xE0031408 /* Power Management Control and Status Register */
#define FX3_DEV_SETUPDAT                      0xE003140C /* SETUPDAT0/1 Registers */
#define FX3_DEV_TOGGLE                        0xE0031414 /* Data Toggle for Endpoints Register */
#define FX3_DEV_EPI_CS                        0xE0031418 /* IN Endpoint Control and Status Register */
#define FX3_DEV_EPI_XFER_CNT                  0xE0031458 /* IN Endpoint Remaining Transfer Length Register */
#define FX3_DEV_EPO_CS                        0xE0031498 /* OUT Endpoint Control and Status Register */
#define FX3_DEV_EPO_XFER_CNT                  0xE00314D8 /* OUT Endpoint Remaining Transfer Length Register */
#define FX3_DEV_CTRL_INTR_MASK                0xE0031518 /* CONTROL Interrupt Mask Register */
#define FX3_DEV_CTRL_INTR                     0xE003151C /* CONTROL Interrupt Request Register */
#define FX3_DEV_EP_INTR_MASK                  0xE0031520 /* USB EP Interrupt Mask Register */
#define FX3_DEV_EP_INTR                       0xE0031524 /* USB EP Interrupt Request Register */
#define FX3_CHGDET_CTRL                       0xE0031800 /* Charger Detect Control and Configuration Register */
#define FX3_CHGDET_INTR                       0xE0031804 /* Charger Detect Interrupt Register */
#define FX3_CHGDET_INTR_MASK                  0xE0031808 /* Charger Detect Interrupt Mask Register */
#define FX3_OTG_CTRL                          0xE003180C /* OTG Control Register */
#define FX3_OTG_INTR                          0xE0031810 /* OTG Interrupt Register */
#define FX3_OTG_INTR_MASK                     0xE0031814 /* OTG Interrupt Mask Register */
#define FX3_OTG_TIMER                         0xE0031818 /* OTG Timer Register */
#define FX3_EEPM_CS                           0xE0031C00 /* Egress EPM Retry Buffer Status */
#define FX3_IEPM_CS                           0xE0031C04 /* Ingress EPM Control and Status */
#define FX3_IEPM_MULT                         0xE0031C08 /* Ingress EPM MULT Function Control Register */
#define FX3_EEPM_ENDPOINT                     0xE0031C40 /* Egress EPM Retry Buffer Status */
#define FX3_IEPM_ENDPOINT                     0xE0031C80 /* Ingress EPM Per Endpoint Control and Status Register */
#define FX3_IEPM_FIFO                         0xE0031CC0 /* Ingress EPM FIFO Entry Register */
#define FX3_HOST_CS                           0xE0032000 /* Host Controller Command and Status Bits Register */
#define FX3_HOST_EP_INTR                      0xE0032004 /* Host End Point Interrupt Register */
#define FX3_HOST_EP_INTR_MASK                 0xE0032008 /* Host End Point Interrupt Mask Register */
#define FX3_HOST_TOGGLE                       0xE003200C /* Data Toggle for Endpoints Register */
#define FX3_HOST_SHDL_CS                      0xE0032010 /* Scheduler Memory Pointer Register */
#define FX3_HOST_SHDL_SLEEP                   0xE0032014 /* Scheduler Sleep Register */
#define FX3_HOST_RESP_BASE                    0xE0032018 /* Response Base Address Register */
#define FX3_HOST_RESP_CS                      0xE003201C /* Scheduler Response Command and Control Register */
#define FX3_HOST_ACTIVE_EP                    0xE0032020 /* Active Endpoint Register */
#define FX3_OHCI_REVISION                     0xE0032024 /* OHCI Host Controller Revision Number Register */
#define FX3_OHCI_CONTROL                      0xE0032028 /* Host Controller Operating Mode Control Register */
#define FX3_OHCI_COMMAND_STATUS               0xE003202C /* Command and Status Register */
#define FX3_OHCI_INTERRUPT_STATUS             0xE0032030 /* OHCI Host Controller Interrupt Status Register */
#define FX3_OHCI_INTERRUPT_ENABLE             0xE0032034 /* OHCI Interrupt Enable Register */
#define FX3_OHCI_INTERRUPT_DISABLE            0xE0032038 /* OHCI Interrupt Disable Register */
#define FX3_OHCI_FM_INTERVAL                  0xE003203C /* OHCI Frame Control Information Register */
#define FX3_OHCI_FM_REMAINING                 0xE0032040 /* Current Value of Remaining Frame Count Register */
#define FX3_OHCI_FM_NUMBER                    0xE0032044 /* Full Speed Frame Number Register */
#define FX3_OHCI_PERIODIC_START               0xE0032048 /* Periodic Schedule Start Register */
#define FX3_OHCI_LS_THRESHOLD                 0xE003204C /* LSTHRESHOLD Register */
#define FX3_OHCI_RH_PORT_STATUS               0xE0032054 /* Root Hub Port Status Register */
#define FX3_OHCI_EOF                          0xE0032058 /* OHCI End of Frame Times Register */
#define FX3_EHCI_HCCPARAMS                    0xE003205C /* Root Hub Port Status Register */
#define FX3_EHCI_USBCMD                       0xE0032060 /* Root Hub Port Status Register */
#define FX3_EHCI_USBSTS                       0xE0032064 /* Host Controller States and Pending Interrupts Register */
#define FX3_EHCI_USBINTR                      0xE0032068 /* EHCI Interrupt Register */
#define FX3_EHCI_FRINDEX                      0xE003206C /* Frame Index Register */
#define FX3_EHCI_CONFIGFLAG                   0xE0032070 /* Configure Flag Register */
#define FX3_EHCI_PORTSC                       0xE0032074 /* Port Status and Control Register */
#define FX3_EHCI_EOF                          0xE0032078 /* EHCI End of Frame Times Register */
#define FX3_SHDL_CHNG_TYPE                    0xE003207C /* Scheduler Change Type Register */
#define FX3_SHDL_STATE_MACHINE                0xE0032080 /* Scheduler State Machine Register */
#define FX3_SHDL_INTERNAL_STATUS              0xE0032084 /* Scheduler Internal Status Register */
#define FX3_SHDL_OHCI                         0xE0032400 /* Scheduler Memory Register, OHCI Format */
#define FX3_SHDL_EHCI                         0xE0032800 /* Scheduler Memory Register, EHCI Format */
#define FX3_LNK_CONF                          0xE0033000 /* Link Configuration Register */
#define FX3_LNK_INTR                          0xE0033004 /* Link Interrupt Register */
#define FX3_LNK_INTR_MASK                     0xE0033008 /* Link Interrupt Mask Register */
#define FX3_LNK_ERROR_CONF                    0xE003300C /* Link Error Counter Configuration Register */
#define FX3_LNK_ERROR_STATUS                  0xE0033010 /* Link Error Status Register */
#define FX3_LNK_ERROR_COUNT                   0xE0033014 /* Error Counter Register */
#define FX3_LNK_ERROR_COUNT_THRESHOLD         0xE0033018 /* Error Count Threshold Register */
#define FX3_LNK_PHY_CONF                      0xE003301C /* USB 3.0 PHY Configuration Register */
#define FX3_LNK_PHY_MPLL_STATUS               0xE003302C /* USB 3.0 PHY MPLL Status Register */
#define FX3_LNK_PHY_TX_TRIM                   0xE003303C /* USB 3.0 PHY Transmitter, Config Register */
#define FX3_LNK_PHY_ERROR_CONF                0xE0033040 /* PHY Error Counter Configuration Register */
#define FX3_LNK_PHY_ERROR_STATUS              0xE0033044 /* PHY Error Status Register */
#define FX3_LNK_DEVICE_POWER_CONTROL          0xE0033050 /* USB 3.0 Device Power State Control Register */
#define FX3_LNK_LTSSM_STATE                   0xE0033054 /* Link Training Status State Machine (LTSSM) State Register */
#define FX3_LNK_LFPS_OBSERVE                  0xE0033064 /* LFPS Receiver Observability Register */
#define FX3_LNK_COMPLIANCE_PATTERN_0          0xE0033138 /* Compliance Pattern CP0 Register */
#define FX3_LNK_COMPLIANCE_PATTERN_1          0xE003313C /* Compliance Pattern CP1 Register */
#define FX3_LNK_COMPLIANCE_PATTERN_2          0xE0033140 /* Compliance Pattern CP2 Register */
#define FX3_LNK_COMPLIANCE_PATTERN_3          0xE0033144 /* Compliance Pattern CP3 Register */
#define FX3_LNK_COMPLIANCE_PATTERN_4          0xE0033148 /* Compliance Pattern CP4 Register */
#define FX3_LNK_COMPLIANCE_PATTERN_5          0xE003314C /* Compliance Pattern CP5 Register */
#define FX3_LNK_COMPLIANCE_PATTERN_6          0xE0033150 /* Compliance Pattern CP6 Register */
#define FX3_LNK_COMPLIANCE_PATTERN_7          0xE0033154 /* Compliance Pattern CP7 Register */
#define FX3_LNK_COMPLIANCE_PATTERN_8          0xE0033158 /* Compliance Pattern CP8 Register */
#define FX3_PROT_CS                           0xE0033400 /* Protocol Layer Control and Status Register */
#define FX3_PROT_INTR                         0xE0033404 /* Protocol Layer Interrupt Register */
#define FX3_PROT_INTR_MASK                    0xE0033408 /* Protocol Interrupts Mask Register */
#define FX3_PROT_LMP_PORT_CAPABILITY_TIMER    0xE0033418 /* Capability Timer Register */
#define FX3_PROT_LMP_PORT_CONFIGURATION_TIMER 0xE003341C /* Configuration Timer Register */
#define FX3_PROT_FRAMECNT                     0xE0033428 /* Frame Counter Register */
#define FX3_PROT_ITP_TIME                     0xE0033430 /* ITP Time Free Running Counter */
#define FX3_PROT_ITP_TIMESTAMP                0xE0033434 /* ITP Time Stamp Register */
#define FX3_PROT_SETUP_DAT                    0xE0033438 /* Received SETUP Packet Data Register */
#define FX3_PROT_SEQ_NUM                      0xE0033440 /* Sequence Number */
#define FX3_PROT_LMP_RECEIVED                 0xE003345C /* Received Register */
#define FX3_PROT_EP_INTR                      0xE0033474 /* Endpoint Interrupts */
#define FX3_PROT_EP_INTR_MASK                 0xE0033478 /* Endpoint Interrupt Mask */
#define FX3_PROT_EPI_CS1                      0xE0033500 /* SuperSpeed IN Endpoint Control and Status */
#define FX3_PROT_EPI_CS2                      0xE0033540 /* SuperSpeed IN Endpoint Control and Status */
#define FX3_PROT_EPI_UNMAPPED_STREAM          0xE0033580 /* Unmapped Stream Request */
#define FX3_PROT_EPI_MAPPED_STREAM            0xE00335C0 /* Mapped Streams Register */
#define FX3_PROT_EPO_CS1                      0xE0033600 /* SuperSpeed OUT Endpoint Control and Status */
#define FX3_PROT_EPO_CS2                      0xE0033640 /* SuperSpeed OUT Endpoint Control and Status */
#define FX3_PROT_EPO_UNMAPPED_STREAM          0xE0033680 /* Unmapped Stream Request */
#define FX3_PROT_EPO_MAPPED_STREAM            0xE00336C0 /* Mapped Streams Register */
#define FX3_PROT_STREAM_ERROR_DISABLE         0xE0033700 /* Stream Error Disable Register */
#define FX3_PROT_STREAM_ERROR_STATUS          0xE0033704 /* Stream Error Status Register */
#define FX3_UIB_ID                            0xE0037F00 /* Block Identification and Version Number Register */
#define FX3_UIB_POWER                         0xE0037F04 /* Power, Clock, and Reset Control Registers */

#define FX3_UIB_INTR_EPM_URUN_TIMEOUT                    (1UL << 12)
#define FX3_UIB_INTR_EPM_URUN                            (1UL << 11)
#define FX3_UIB_INTR_PROT_EP_INT                         (1UL << 10)
#define FX3_UIB_INTR_PROT_INT                            (1UL << 9)
#define FX3_UIB_INTR_LNK_INT                             (1UL << 8)
#define FX3_UIB_INTR_CHGDET_INT                          (1UL << 7)
#define FX3_UIB_INTR_OTG_INT                             (1UL << 6)
#define FX3_UIB_INTR_DEV_CTL_INT                         (1UL << 5)
#define FX3_UIB_INTR_DEV_EP_INT                          (1UL << 4)
#define FX3_UIB_INTR_OHCI_INT                            (1UL << 3)
#define FX3_UIB_INTR_EHCI_INT                            (1UL << 2)
#define FX3_UIB_INTR_HOST_EP_INT                         (1UL << 1)
#define FX3_UIB_INTR_HOST_INT                            (1UL << 0)

#define FX3_UIB_INTR_MASK_EPM_URUN_TIMEOUT               (1UL << 12)
#define FX3_UIB_INTR_MASK_EPM_URUN                       (1UL << 11)
#define FX3_UIB_INTR_MASK_PROT_EP_INT                    (1UL << 10)
#define FX3_UIB_INTR_MASK_PROT_INT                       (1UL << 9)
#define FX3_UIB_INTR_MASK_LNK_INT                        (1UL << 8)
#define FX3_UIB_INTR_MASK_CHGDET_INT                     (1UL << 7)
#define FX3_UIB_INTR_MASK_OTG_INT                        (1UL << 6)
#define FX3_UIB_INTR_MASK_DEV_CTL_INT                    (1UL << 5)
#define FX3_UIB_INTR_MASK_DEV_EP_INT                     (1UL << 4)
#define FX3_UIB_INTR_MASK_OHCI_INT                       (1UL << 3)
#define FX3_UIB_INTR_MASK_EHCI_INT                       (1UL << 2)
#define FX3_UIB_INTR_MASK_HOST_EP_INT                    (1UL << 1)
#define FX3_UIB_INTR_MASK_HOST_INT                       (1UL << 0)

#define FX3_PHY_CLK_AND_TEST_ON_DCD                      (1UL << 30)
#define FX3_PHY_CLK_AND_TEST_SUSPEND_N                   (1UL << 29)
#define FX3_PHY_CLK_AND_TEST_RESET                       (1UL << 27)
#define FX3_PHY_CLK_AND_TEST_VDATSRCEEN                  (1UL << 25)
#define FX3_PHY_CLK_AND_TEST_CHGRDET                     (1UL << 24)
#define FX3_PHY_CLK_AND_TEST_CHGRMODE                    (1UL << 23)
#define FX3_PHY_CLK_AND_TEST_CHGRDETEN                   (1UL << 22)
#define FX3_PHY_CLK_AND_TEST_CHGRDETON                   (1UL << 21)
#define FX3_PHY_CLK_AND_TEST_IDDIG                       (1UL << 20)
#define FX3_PHY_CLK_AND_TEST_IDPULLUP                    (1UL << 19)
#define FX3_PHY_CLK_AND_TEST_VLOAD                       (1UL << 4)
#define FX3_PHY_CLK_AND_TEST_ONCLOCK                     (1UL << 1)
#define FX3_PHY_CLK_AND_TEST_DATABUS16_8                 (1UL << 0)

#define FX3_PHY_CONF_PREEMDEPTH                          (1UL << 23)
#define FX3_PHY_CONF_ENPRE                               (1UL << 22)
#define FX3_PHY_CONF_FSRFTSEL_SHIFT                      20
#define FX3_PHY_CONF_FSRFTSEL_BITS                       2
#define FX3_PHY_CONF_FSRFTSEL_MASK                       (0x3UL << 20)
#define FX3_PHY_CONF_LSRFTSEL_SHIFT                      18
#define FX3_PHY_CONF_LSRFTSEL_BITS                       2
#define FX3_PHY_CONF_LSRFTSEL_MASK                       (0x3UL << 18)
#define FX3_PHY_CONF_ICPCTRL_SHIFT                       16
#define FX3_PHY_CONF_ICPCTRL_BITS                        2
#define FX3_PHY_CONF_ICPCTRL_MASK                        (0x3UL << 16)
#define FX3_PHY_CONF_HSTEDVSEL_SHIFT                     14
#define FX3_PHY_CONF_HSTEDVSEL_BITS                      2
#define FX3_PHY_CONF_HSTEDVSEL_MASK                      (0x3UL << 14)
#define FX3_PHY_CONF_FSTUNEVSEL_SHIFT                    11
#define FX3_PHY_CONF_FSTUNEVSEL_BITS                     3
#define FX3_PHY_CONF_FSTUNEVSEL_MASK                     (0x7UL << 11)
#define FX3_PHY_CONF_HSDEDVSEL_SHIFT                     9
#define FX3_PHY_CONF_HSDEDVSEL_BITS                      2
#define FX3_PHY_CONF_HSDEDVSEL_MASK                      (0x3UL << 9)
#define FX3_PHY_CONF_HSDRVSLOPE_SHIFT                    5
#define FX3_PHY_CONF_HSDRVSLOPE_BITS                     4
#define FX3_PHY_CONF_HSDRVSLOPE_MASK                     (0xfUL << 5)
#define FX3_PHY_CONF_HSDRVAMPLITUDE_SHIFT                3
#define FX3_PHY_CONF_HSDRVAMPLITUDE_BITS                 2
#define FX3_PHY_CONF_HSDRVAMPLITUDE_MASK                 (0x3UL << 3)
#define FX3_PHY_CONF_HSDRVTIMINGN_SHIFT                  1
#define FX3_PHY_CONF_HSDRVTIMINGN_BITS                   2
#define FX3_PHY_CONF_HSDRVTIMINGN_MASK                   (0x3UL << 1)
#define FX3_PHY_CONF_HSDRVTIMINGP                        (1UL << 0)

#define FX3_PHY_CHIRP_OVERRIDE_FSM                       (1UL << 30)
#define FX3_PHY_CHIRP_CHIRP_STATE_SHIFT                  0
#define FX3_PHY_CHIRP_CHIRP_STATE_BITS                   5
#define FX3_PHY_CHIRP_CHIRP_STATE_MASK                   (0x1fUL << 0)

#define FX3_DEV_CS_NAKALL                                (1UL << 31)
#define FX3_DEV_CS_SETUP_CLR_BUSY                        (1UL << 26)
#define FX3_DEV_CS_TEST_MODE_SHIFT                       23
#define FX3_DEV_CS_TEST_MODE_BITS                        3
#define FX3_DEV_CS_TEST_MODE_MASK                        (0x7UL << 23)
#define FX3_DEV_CS_DEVICEADDR_SHIFT                      16
#define FX3_DEV_CS_DEVICEADDR_BITS                       7
#define FX3_DEV_CS_DEVICEADDR_MASK                       (0x7fUL << 16)
#define FX3_DEV_CS_COUNT_SHIFT                           8
#define FX3_DEV_CS_COUNT_BITS                            8
#define FX3_DEV_CS_COUNT_MASK                            (0xffUL << 8)
#define FX3_DEV_CS_ERR_LIMIT_SHIFT                       0
#define FX3_DEV_CS_ERR_LIMIT_BITS                        8
#define FX3_DEV_CS_ERR_LIMIT_MASK                        (0xffUL << 0)

#define FX3_DEV_FRAMECNT_FRAMECNT_SHIFT                  3
#define FX3_DEV_FRAMECNT_FRAMECNT_BITS                   11
#define FX3_DEV_FRAMECNT_FRAMECNT_MASK                   (0x7ffUL << 3)
#define FX3_DEV_FRAMECNT_MICROFRAME_SHIFT                0
#define FX3_DEV_FRAMECNT_MICROFRAME_BITS                 3
#define FX3_DEV_FRAMECNT_MICROFRAME_MASK                 (0x7UL << 0)

#define FX3_DEV_PWR_CS_HSM                               (1UL << 7)
#define FX3_DEV_PWR_CS_FORCE_FS                          (1UL << 6)
#define FX3_DEV_PWR_CS_DEV_SUSPEND                       (1UL << 4)
#define FX3_DEV_PWR_CS_DISCON                            (1UL << 3)
#define FX3_DEV_PWR_CS_NOSYNSOF                          (1UL << 2)
#define FX3_DEV_PWR_CS_SIGRSUME                          (1UL << 0)

#define FX3_DEV_SETUPDAT_SETUP_LENGTH_SHIFT              48
#define FX3_DEV_SETUPDAT_SETUP_LENGTH_BITS               16
#define FX3_DEV_SETUPDAT_SETUP_LENGTH_MASK               (0xffffUL << 48)
#define FX3_DEV_SETUPDAT_SETUP_INDEX_SHIFT               32
#define FX3_DEV_SETUPDAT_SETUP_INDEX_BITS                16
#define FX3_DEV_SETUPDAT_SETUP_INDEX_MASK                (0xffffUL << 32)
#define FX3_DEV_SETUPDAT_SETUP_VALUE_SHIFT               16
#define FX3_DEV_SETUPDAT_SETUP_VALUE_BITS                16
#define FX3_DEV_SETUPDAT_SETUP_VALUE_MASK                (0xffffUL << 16)
#define FX3_DEV_SETUPDAT_SETUP_REQUEST_SHIFT             8
#define FX3_DEV_SETUPDAT_SETUP_REQUEST_BITS              8
#define FX3_DEV_SETUPDAT_SETUP_REQUEST_MASK              (0xffUL << 8)
#define FX3_DEV_SETUPDAT_SETUP_REQUEST_TYPE_SHIFT        0
#define FX3_DEV_SETUPDAT_SETUP_REQUEST_TYPE_BITS         8
#define FX3_DEV_SETUPDAT_SETUP_REQUEST_TYPE_MASK         (0xffUL << 0)

#define FX3_DEV_TOGGLE_TOGGLE_VALID                      (1UL << 8)
#define FX3_DEV_TOGGLE_Q                                 (1UL << 7)
#define FX3_DEV_TOGGLE_S                                 (1UL << 6)
#define FX3_DEV_TOGGLE_R                                 (1UL << 5)
#define FX3_DEV_TOGGLE_IO                                (1UL << 4)
#define FX3_DEV_TOGGLE_ENDPOINT_SHIFT                    0
#define FX3_DEV_TOGGLE_ENDPOINT_BITS                     4
#define FX3_DEV_TOGGLE_ENDPOINT_MASK                     (0xfUL << 0)

#define FX3_DEV_EPI_CS_ISOERR_MASK                       (1UL << 31)
#define FX3_DEV_EPI_CS_SHORT_MASK                        (1UL << 30)
#define FX3_DEV_EPI_CS_ZERO_MASK                         (1UL << 29)
#define FX3_DEV_EPI_CS_DONE_MASK                         (1UL << 28)
#define FX3_DEV_EPI_CS_BNAK_MASK                         (1UL << 27)
#define FX3_DEV_EPI_CS_COMMIT_MASK                       (1UL << 26)
#define FX3_DEV_EPI_CS_ISOERR                            (1UL << 23)
#define FX3_DEV_EPI_CS_SHORT                             (1UL << 22)
#define FX3_DEV_EPI_CS_ZERO                              (1UL << 21)
#define FX3_DEV_EPI_CS_DONE                              (1UL << 20)
#define FX3_DEV_EPI_CS_BNAK                              (1UL << 19)
#define FX3_DEV_EPI_CS_COMMIT                            (1UL << 18)
#define FX3_DEV_EPI_CS_STALL                             (1UL << 16)
#define FX3_DEV_EPI_CS_NAK                               (1UL << 15)
#define FX3_DEV_EPI_CS_VALID                             (1UL << 14)
#define FX3_DEV_EPI_CS_ISOINPKS_SHIFT                    12
#define FX3_DEV_EPI_CS_ISOINPKS_BITS                     2
#define FX3_DEV_EPI_CS_ISOINPKS_MASK                     (0x3UL << 12)
#define FX3_DEV_EPI_CS_TYPE_SHIFT                        10
#define FX3_DEV_EPI_CS_TYPE_BITS                         2
#define FX3_DEV_EPI_CS_TYPE_MASK                         (0x3UL << 10)
#define FX3_DEV_EPI_CS_PAYLOAD_SHIFT                     0
#define FX3_DEV_EPI_CS_PAYLOAD_BITS                      10
#define FX3_DEV_EPI_CS_PAYLOAD_MASK                      (0x3ffUL << 0)

#define FX3_DEV_EPI_XFER_CNT_BYTES_REMAINING_SHIFT       0
#define FX3_DEV_EPI_XFER_CNT_BYTES_REMAINING_BITS        24
#define FX3_DEV_EPI_XFER_CNT_BYTES_REMAINING_MASK        (0xffffffUL << 0)

#define FX3_DEV_EPO_CS_ISOERR_MASK                       (1UL << 31)
#define FX3_DEV_EPO_CS_SHORT_MASK                        (1UL << 30)
#define FX3_DEV_EPO_CS_ZERO_MASK                         (1UL << 29)
#define FX3_DEV_EPO_CS_DONE_MASK                         (1UL << 28)
#define FX3_DEV_EPO_CS_BNAK_MASK                         (1UL << 27)
#define FX3_DEV_EPO_CS_COMMIT_MASK                       (1UL << 26)
#define FX3_DEV_EPO_CS_OVF_MASK                          (1UL << 25)
#define FX3_DEV_EPO_CS_ISOERR                            (1UL << 23)
#define FX3_DEV_EPO_CS_SHORT                             (1UL << 22)
#define FX3_DEV_EPO_CS_ZERO                              (1UL << 21)
#define FX3_DEV_EPO_CS_DONE                              (1UL << 20)
#define FX3_DEV_EPO_CS_BNAK                              (1UL << 19)
#define FX3_DEV_EPO_CS_COMMIT                            (1UL << 18)
#define FX3_DEV_EPO_CS_OVF                               (1UL << 17)
#define FX3_DEV_EPO_CS_STALL                             (1UL << 16)
#define FX3_DEV_EPO_CS_NAK                               (1UL << 15)
#define FX3_DEV_EPO_CS_VALID                             (1UL << 14)
#define FX3_DEV_EPO_CS_ISOINPKS_SHIFT                    12
#define FX3_DEV_EPO_CS_ISOINPKS_BITS                     2
#define FX3_DEV_EPO_CS_ISOINPKS_MASK                     (0x3UL << 12)
#define FX3_DEV_EPO_CS_TYPE_SHIFT                        10
#define FX3_DEV_EPO_CS_TYPE_BITS                         2
#define FX3_DEV_EPO_CS_TYPE_MASK                         (0x3UL << 10)
#define FX3_DEV_EPO_CS_PAYLOAD_SHIFT                     0
#define FX3_DEV_EPO_CS_PAYLOAD_BITS                      10
#define FX3_DEV_EPO_CS_PAYLOAD_MASK                      (0x3ffUL << 0)

#define FX3_DEV_EPO_XFER_CNT_BYTES_REMAINING_SHIFT       0
#define FX3_DEV_EPO_XFER_CNT_BYTES_REMAINING_BITS        24
#define FX3_DEV_EPO_XFER_CNT_BYTES_REMAINING_MASK        (0xffffffUL << 0)

#define FX3_DEV_CTRL_INTR_MASK_STATUS_STAGE              (1UL << 11)
#define FX3_DEV_CTRL_INTR_MASK_URESUME                   (1UL << 8)
#define FX3_DEV_CTRL_INTR_MASK_ERRLIMIT                  (1UL << 7)
#define FX3_DEV_CTRL_INTR_MASK_SUDAV                     (1UL << 6)
#define FX3_DEV_CTRL_INTR_MASK_SUTOK                     (1UL << 5)
#define FX3_DEV_CTRL_INTR_MASK_HSGRANT                   (1UL << 4)
#define FX3_DEV_CTRL_INTR_MASK_URESET                    (1UL << 3)
#define FX3_DEV_CTRL_INTR_MASK_SUSP                      (1UL << 2)
#define FX3_DEV_CTRL_INTR_MASK_SOF                       (1UL << 1)

#define FX3_DEV_CTRL_INTR_STATUS_STAGE                   (1UL << 11)
#define FX3_DEV_CTRL_INTR_URESUME                        (1UL << 8)
#define FX3_DEV_CTRL_INTR_ERRLIMIT                       (1UL << 7)
#define FX3_DEV_CTRL_INTR_SUDAV                          (1UL << 6)
#define FX3_DEV_CTRL_INTR_SUTOK                          (1UL << 5)
#define FX3_DEV_CTRL_INTR_HSGRANT                        (1UL << 4)
#define FX3_DEV_CTRL_INTR_URESET                         (1UL << 3)
#define FX3_DEV_CTRL_INTR_SUSP                           (1UL << 2)
#define FX3_DEV_CTRL_INTR_SOF                            (1UL << 1)

#define FX3_DEV_EP_INTR_MASK_EP_OUT_SHIFT                16
#define FX3_DEV_EP_INTR_MASK_EP_OUT_BITS                 16
#define FX3_DEV_EP_INTR_MASK_EP_OUT_MASK                 (0xffffUL << 16)
#define FX3_DEV_EP_INTR_MASK_EP_IN_SHIFT                 0
#define FX3_DEV_EP_INTR_MASK_EP_IN_BITS                  16
#define FX3_DEV_EP_INTR_MASK_EP_IN_MASK                  (0xffffUL << 0)

#define FX3_DEV_EP_INTR_EP_OUT_SHIFT                     16
#define FX3_DEV_EP_INTR_EP_OUT_BITS                      16
#define FX3_DEV_EP_INTR_EP_OUT_MASK                      (0xffffUL << 16)
#define FX3_DEV_EP_INTR_EP_IN_SHIFT                      0
#define FX3_DEV_EP_INTR_EP_IN_BITS                       16
#define FX3_DEV_EP_INTR_EP_IN_MASK                       (0xffffUL << 0)

#define FX3_CHGDET_CTRL_PHY_CHARGER_DETECT_EN            (1UL << 31)
#define FX3_CHGDET_CTRL_ACA_RTRIM_SHIFT                  24
#define FX3_CHGDET_CTRL_ACA_RTRIM_BITS                   3
#define FX3_CHGDET_CTRL_ACA_RTRIM_MASK                   (0x7UL << 24)
#define FX3_CHGDET_CTRL_ACA_ADC_OUT_SHIFT                16
#define FX3_CHGDET_CTRL_ACA_ADC_OUT_BITS                 8
#define FX3_CHGDET_CTRL_ACA_ADC_OUT_MASK                 (0xffUL << 16)
#define FX3_CHGDET_CTRL_CARKIT                           (1UL << 14)
#define FX3_CHGDET_CTRL_ACA_CONN_MODE                    (1UL << 13)
#define FX3_CHGDET_CTRL_ACA_ENABLE                       (1UL << 12)
#define FX3_CHGDET_CTRL_ACA_OTG_ID_VALUE_SHIFT           9
#define FX3_CHGDET_CTRL_ACA_OTG_ID_VALUE_BITS            3
#define FX3_CHGDET_CTRL_ACA_OTG_ID_VALUE_MASK            (0x7UL << 9)
#define FX3_CHGDET_CTRL_ACA_RTRIM_OVERRIDE               (1UL << 5)
#define FX3_CHGDET_CTRL_ACA_POLL_INTERVAL_SHIFT          1
#define FX3_CHGDET_CTRL_ACA_POLL_INTERVAL_BITS           4
#define FX3_CHGDET_CTRL_ACA_POLL_INTERVAL_MASK           (0xfUL << 1)
#define FX3_CHGDET_CTRL_PHY_CHG_DETECTED                 (1UL << 0)

#define FX3_CHGDET_INTR_CHG_DET_CHANGE                   (1UL << 1)
#define FX3_CHGDET_INTR_OTG_ID_CHANGE                    (1UL << 0)

#define FX3_CHGDET_INTR_MASK_CHG_DET_CHANGE              (1UL << 1)
#define FX3_CHGDET_INTR_MASK_OTG_ID_CHANGE               (1UL << 0)

#define FX3_OTG_CTRL_SSEPM_ENABLE                        (1UL << 15)
#define FX3_OTG_CTRL_SSDEV_ENABLE                        (1UL << 14)
#define FX3_OTG_CTRL_DEV_ENABLE                          (1UL << 13)
#define FX3_OTG_CTRL_HOST_ENABLE                         (1UL << 12)
#define FX3_OTG_CTRL_B_END_SESS                          (1UL << 11)
#define FX3_OTG_CTRL_B_SESS_VALID                        (1UL << 10)
#define FX3_OTG_CTRL_A_SESS_VALID                        (1UL << 9)
#define FX3_OTG_CTRL_DSCHG_VBUS                          (1UL << 8)
#define FX3_OTG_CTRL_CHG_VBUS                            (1UL << 7)
#define FX3_OTG_CTRL_VBUS_VALID                          (1UL << 6)
#define FX3_OTG_CTRL_DM                                  (1UL << 5)
#define FX3_OTG_CTRL_DP                                  (1UL << 4)
#define FX3_OTG_CTRL_DP_PD_EN                            (1UL << 3)
#define FX3_OTG_CTRL_DM_PD_EN                            (1UL << 2)
#define FX3_OTG_CTRL_DP_PU_EN                            (1UL << 1)
#define FX3_OTG_CTRL_OTG_ENABLE                          (1UL << 0)

#define FX3_OTG_INTR_OTG_TIMER_TIMEOUT                   (1UL << 5)
#define FX3_OTG_INTR_SRP_VBUS_INT                        (1UL << 4)
#define FX3_OTG_INTR_SRP_DP_INT                          (1UL << 3)
#define FX3_OTG_INTR_B_END_SESS_INT                      (1UL << 2)
#define FX3_OTG_INTR_B_SESS_VALID_INT                    (1UL << 1)
#define FX3_OTG_INTR_A_SESS_VALID_INT                    (1UL << 0)

#define FX3_OTG_INTR_MASK_OTG_TIMER_TIMEOUT              (1UL << 5)
#define FX3_OTG_INTR_MASK_SRP_VBUS_INT                   (1UL << 4)
#define FX3_OTG_INTR_MASK_SRP_DP_INT                     (1UL << 3)
#define FX3_OTG_INTR_MASK_B_END_SESS_INT                 (1UL << 2)
#define FX3_OTG_INTR_MASK_B_SESS_VALID_INT               (1UL << 1)
#define FX3_OTG_INTR_MASK_A_SESS_VALID_INT               (1UL << 0)

#define FX3_EEPM_CS_EG_EPNUM_SHIFT                       28
#define FX3_EEPM_CS_EG_EPNUM_BITS                        4
#define FX3_EEPM_CS_EG_EPNUM_MASK                        (0xfUL << 28)
#define FX3_EEPM_CS_URUN_EP_NUM_SHIFT                    18
#define FX3_EEPM_CS_URUN_EP_NUM_BITS                     4
#define FX3_EEPM_CS_URUN_EP_NUM_MASK                     (0xfUL << 18)
#define FX3_EEPM_CS_URUN_REPAIR_TIMEOUT_EN               (1UL << 17)
#define FX3_EEPM_CS_URUN_REPAIR_EN                       (1UL << 16)
#define FX3_EEPM_CS_VALID_PACKETS_SHIFT                  0
#define FX3_EEPM_CS_VALID_PACKETS_BITS                   16
#define FX3_EEPM_CS_VALID_PACKETS_MASK                   (0xffffUL << 0)

#define FX3_IEPM_CS_EPM_MUX_RESET                        (1UL << 29)
#define FX3_IEPM_CS_EPM_FLUSH                            (1UL << 28)
#define FX3_IEPM_CS_WRITE_PTR_SHIFT                      16
#define FX3_IEPM_CS_WRITE_PTR_BITS                       12
#define FX3_IEPM_CS_WRITE_PTR_MASK                       (0xfffUL << 16)
#define FX3_IEPM_CS_READ_PTR_SHIFT                       0
#define FX3_IEPM_CS_READ_PTR_BITS                        12
#define FX3_IEPM_CS_READ_PTR_MASK                        (0xfffUL << 0)

#define FX3_IEPM_MULT_MULT_THRSHOLD_SHIFT                15
#define FX3_IEPM_MULT_MULT_THRSHOLD_BITS                 11
#define FX3_IEPM_MULT_MULT_THRSHOLD_MASK                 (0x7ffUL << 15)
#define FX3_IEPM_MULT_MULT_EN_SHIFT                      0
#define FX3_IEPM_MULT_MULT_EN_BITS                       15
#define FX3_IEPM_MULT_MULT_EN_MASK                       (0x7fffUL << 0)

#define FX3_EEPM_ENDPOINT_SOCKET_FLUSH                   (1UL << 31)
#define FX3_EEPM_ENDPOINT_EEPM_EP_READY                  (1UL << 30)
#define FX3_EEPM_ENDPOINT_ZLP                            (1UL << 27)
#define FX3_EEPM_ENDPOINT_EEPM_BYTE_COUNT_SHIFT          11
#define FX3_EEPM_ENDPOINT_EEPM_BYTE_COUNT_BITS           16
#define FX3_EEPM_ENDPOINT_EEPM_BYTE_COUNT_MASK           (0xffffUL << 11)
#define FX3_EEPM_ENDPOINT_PACKET_SIZE_SHIFT              0
#define FX3_EEPM_ENDPOINT_PACKET_SIZE_BITS               11
#define FX3_EEPM_ENDPOINT_PACKET_SIZE_MASK               (0x7ffUL << 0)

#define FX3_IEPM_ENDPOINT_SOCKET_FLUSH                   (1UL << 31)
#define FX3_IEPM_ENDPOINT_EOT_EOP                        (1UL << 30)
#define FX3_IEPM_ENDPOINT_EP_READY                       (1UL << 22)
#define FX3_IEPM_ENDPOINT_NUM_IN_PACKETS_SHIFT           11
#define FX3_IEPM_ENDPOINT_NUM_IN_PACKETS_BITS            11
#define FX3_IEPM_ENDPOINT_NUM_IN_PACKETS_MASK            (0x7ffUL << 11)
#define FX3_IEPM_ENDPOINT_PACKET_SIZE_SHIFT              0
#define FX3_IEPM_ENDPOINT_PACKET_SIZE_BITS               11
#define FX3_IEPM_ENDPOINT_PACKET_SIZE_MASK               (0x7ffUL << 0)

#define FX3_IEPM_FIFO_EP_VALID                           (1UL << 16)
#define FX3_IEPM_FIFO_IN_EPNUM_SHIFT                     12
#define FX3_IEPM_FIFO_IN_EPNUM_BITS                      4
#define FX3_IEPM_FIFO_IN_EPNUM_MASK                      (0xfUL << 12)
#define FX3_IEPM_FIFO_EOT                                (1UL << 11)
#define FX3_IEPM_FIFO_BYTES_SHIFT                        0
#define FX3_IEPM_FIFO_BYTES_BITS                         11
#define FX3_IEPM_FIFO_BYTES_MASK                         (0x7ffUL << 0)

#define FX3_HOST_CS_DEACTIVATE_ON_IN_EP_SHORT_PKT        (1UL << 24)
#define FX3_HOST_CS_DISABLE_EHCI_HOSTERR                 (1UL << 23)
#define FX3_HOST_CS_FRAME_FIT_OFFSET_SHIFT               8
#define FX3_HOST_CS_FRAME_FIT_OFFSET_BITS                15
#define FX3_HOST_CS_FRAME_FIT_OFFSET_MASK                (0x7fffUL << 8)
#define FX3_HOST_CS_DEV_ADDR_SHIFT                       0
#define FX3_HOST_CS_DEV_ADDR_BITS                        7
#define FX3_HOST_CS_DEV_ADDR_MASK                        (0x7fUL << 0)

#define FX3_HOST_EP_INTR_EPI_IRQ_TOP_SHIFT               16
#define FX3_HOST_EP_INTR_EPI_IRQ_TOP_BITS                16
#define FX3_HOST_EP_INTR_EPI_IRQ_TOP_MASK                (0xffffUL << 16)
#define FX3_HOST_EP_INTR_EPO_IRQ_TOP_SHIFT               0
#define FX3_HOST_EP_INTR_EPO_IRQ_TOP_BITS                16
#define FX3_HOST_EP_INTR_EPO_IRQ_TOP_MASK                (0xffffUL << 0)

#define FX3_HOST_EP_INTR_MASK_EPI_IRQ_MASK_SHIFT         16
#define FX3_HOST_EP_INTR_MASK_EPI_IRQ_MASK_BITS          16
#define FX3_HOST_EP_INTR_MASK_EPI_IRQ_MASK_MASK          (0xffffUL << 16)
#define FX3_HOST_EP_INTR_MASK_EPO_IRQ_MASK_SHIFT         0
#define FX3_HOST_EP_INTR_MASK_EPO_IRQ_MASK_BITS          16
#define FX3_HOST_EP_INTR_MASK_EPO_IRQ_MASK_MASK          (0xffffUL << 0)

#define FX3_HOST_TOGGLE_VALID                            (1UL << 8)
#define FX3_HOST_TOGGLE_Q                                (1UL << 7)
#define FX3_HOST_TOGGLE_S                                (1UL << 6)
#define FX3_HOST_TOGGLE_R                                (1UL << 5)
#define FX3_HOST_TOGGLE_IO                               (1UL << 4)
#define FX3_HOST_TOGGLE_ENDPOINT_SHIFT                   0
#define FX3_HOST_TOGGLE_ENDPOINT_BITS                    4
#define FX3_HOST_TOGGLE_ENDPOINT_MASK                    (0xfUL << 0)

#define FX3_HOST_SHDL_CS_ASYNC_SHDL_STATUS               (1UL << 19)
#define FX3_HOST_SHDL_CS_PERI_SHDL_STATUS                (1UL << 18)
#define FX3_HOST_SHDL_CS_PERI_SHDL_CHNG                  (1UL << 17)
#define FX3_HOST_SHDL_CS_ASYNC_SHDL_CHNG                 (1UL << 16)
#define FX3_HOST_SHDL_CS_BULK_CNTRL_PTR1_SHIFT           8
#define FX3_HOST_SHDL_CS_BULK_CNTRL_PTR1_BITS            8
#define FX3_HOST_SHDL_CS_BULK_CNTRL_PTR1_MASK            (0xffUL << 8)
#define FX3_HOST_SHDL_CS_BULK_CNTRL_PTR0_SHIFT           0
#define FX3_HOST_SHDL_CS_BULK_CNTRL_PTR0_BITS            8
#define FX3_HOST_SHDL_CS_BULK_CNTRL_PTR0_MASK            (0xffUL << 0)

#define FX3_HOST_SHDL_SLEEP_ASYNC_SLEEP_TIMMER_SHIFT     1
#define FX3_HOST_SHDL_SLEEP_ASYNC_SLEEP_TIMMER_BITS      9
#define FX3_HOST_SHDL_SLEEP_ASYNC_SLEEP_TIMMER_MASK      (0x1ffUL << 1)
#define FX3_HOST_SHDL_SLEEP_ASYNC_SLEEP_EN               (1UL << 0)

#define FX3_HOST_RESP_CS_LIM_ERROR                       (1UL << 31)
#define FX3_HOST_RESP_CS_WR_RESP_COND                    (1UL << 24)
#define FX3_HOST_RESP_CS_WR_PTR_SHIFT                    16
#define FX3_HOST_RESP_CS_WR_PTR_BITS                     8
#define FX3_HOST_RESP_CS_WR_PTR_MASK                     (0xffUL << 16)
#define FX3_HOST_RESP_CS_LIMIT_SHIFT                     8
#define FX3_HOST_RESP_CS_LIMIT_BITS                      8
#define FX3_HOST_RESP_CS_LIMIT_MASK                      (0xffUL << 8)
#define FX3_HOST_RESP_CS_MAX_ENTRY_SHIFT                 0
#define FX3_HOST_RESP_CS_MAX_ENTRY_BITS                  8
#define FX3_HOST_RESP_CS_MAX_ENTRY_MASK                  (0xffUL << 0)

#define FX3_HOST_ACTIVE_EP_IN_EP_ACTIVE_SHIFT            16
#define FX3_HOST_ACTIVE_EP_IN_EP_ACTIVE_BITS             16
#define FX3_HOST_ACTIVE_EP_IN_EP_ACTIVE_MASK             (0xffffUL << 16)
#define FX3_HOST_ACTIVE_EP_OUT_EP_ACTIVE_SHIFT           0
#define FX3_HOST_ACTIVE_EP_OUT_EP_ACTIVE_BITS            16
#define FX3_HOST_ACTIVE_EP_OUT_EP_ACTIVE_MASK            (0xffffUL << 0)

#define FX3_OHCI_REVISION_REV_SHIFT                      0
#define FX3_OHCI_REVISION_REV_BITS                       8
#define FX3_OHCI_REVISION_REV_MASK                       (0xffUL << 0)

#define FX3_OHCI_CONTROL_HCFS_SHIFT                      6
#define FX3_OHCI_CONTROL_HCFS_BITS                       2
#define FX3_OHCI_CONTROL_HCFS_MASK                       (0x3UL << 6)
#define FX3_OHCI_CONTROL_BLE                             (1UL << 5)
#define FX3_OHCI_CONTROL_CLE                             (1UL << 4)
#define FX3_OHCI_CONTROL_IE                              (1UL << 3)
#define FX3_OHCI_CONTROL_PLE                             (1UL << 2)

#define FX3_OHCI_COMMAND_STATUS_HC_HALTED                (1UL << 19)
#define FX3_OHCI_COMMAND_STATUS_RS                       (1UL << 18)
#define FX3_OHCI_COMMAND_STATUS_SOC_SHIFT                16
#define FX3_OHCI_COMMAND_STATUS_SOC_BITS                 2
#define FX3_OHCI_COMMAND_STATUS_SOC_MASK                 (0x3UL << 16)

#define FX3_OHCI_INTERRUPT_STATUS_RHSC                   (1UL << 6)
#define FX3_OHCI_INTERRUPT_STATUS_FNO                    (1UL << 5)
#define FX3_OHCI_INTERRUPT_STATUS_RD                     (1UL << 3)
#define FX3_OHCI_INTERRUPT_STATUS_SF                     (1UL << 2)
#define FX3_OHCI_INTERRUPT_STATUS_SO                     (1UL << 0)

#define FX3_OHCI_INTERRUPT_ENABLE_MIE                    (1UL << 31)
#define FX3_OHCI_INTERRUPT_ENABLE_RHSC                   (1UL << 6)
#define FX3_OHCI_INTERRUPT_ENABLE_FNO                    (1UL << 5)
#define FX3_OHCI_INTERRUPT_ENABLE_RD                     (1UL << 3)
#define FX3_OHCI_INTERRUPT_ENABLE_SF                     (1UL << 2)
#define FX3_OHCI_INTERRUPT_ENABLE_SO                     (1UL << 0)

#define FX3_OHCI_INTERRUPT_DISABLE_MIE                   (1UL << 31)
#define FX3_OHCI_INTERRUPT_DISABLE_RHSC                  (1UL << 6)
#define FX3_OHCI_INTERRUPT_DISABLE_FNO                   (1UL << 5)
#define FX3_OHCI_INTERRUPT_DISABLE_RD                    (1UL << 3)
#define FX3_OHCI_INTERRUPT_DISABLE_SF                    (1UL << 2)
#define FX3_OHCI_INTERRUPT_DISABLE_SO                    (1UL << 0)

#define FX3_OHCI_FM_INTERVAL_FIT                         (1UL << 31)
#define FX3_OHCI_FM_INTERVAL_FSMPS_SHIFT                 16
#define FX3_OHCI_FM_INTERVAL_FSMPS_BITS                  15
#define FX3_OHCI_FM_INTERVAL_FSMPS_MASK                  (0x7fffUL << 16)
#define FX3_OHCI_FM_INTERVAL_FI_SHIFT                    0
#define FX3_OHCI_FM_INTERVAL_FI_BITS                     15
#define FX3_OHCI_FM_INTERVAL_FI_MASK                     (0x7fffUL << 0)

#define FX3_OHCI_FM_REMAINING_FRT                        (1UL << 31)
#define FX3_OHCI_FM_REMAINING_FR_SHIFT                   0
#define FX3_OHCI_FM_REMAINING_FR_BITS                    15
#define FX3_OHCI_FM_REMAINING_FR_MASK                    (0x7fffUL << 0)

#define FX3_OHCI_FM_NUMBER_FN_SHIFT                      0
#define FX3_OHCI_FM_NUMBER_FN_BITS                       16
#define FX3_OHCI_FM_NUMBER_FN_MASK                       (0xffffUL << 0)

#define FX3_OHCI_PERIODIC_START_PS_SHIFT                 0
#define FX3_OHCI_PERIODIC_START_PS_BITS                  16
#define FX3_OHCI_PERIODIC_START_PS_MASK                  (0xffffUL << 0)

#define FX3_OHCI_LS_THRESHOLD_LST_SHIFT                  0
#define FX3_OHCI_LS_THRESHOLD_LST_BITS                   12
#define FX3_OHCI_LS_THRESHOLD_LST_MASK                   (0xfffUL << 0)

#define FX3_OHCI_RH_PORT_STATUS_PORT_RESUME_FW           (1UL << 31)
#define FX3_OHCI_RH_PORT_STATUS_PRSC                     (1UL << 20)
#define FX3_OHCI_RH_PORT_STATUS_PSSC                     (1UL << 18)
#define FX3_OHCI_RH_PORT_STATUS_PESC                     (1UL << 17)
#define FX3_OHCI_RH_PORT_STATUS_CSC                      (1UL << 16)

#define FX3_OHCI_EOF_EOF2_SHIFT                          16
#define FX3_OHCI_EOF_EOF2_BITS                           16
#define FX3_OHCI_EOF_EOF2_MASK                           (0xffffUL << 16)
#define FX3_OHCI_EOF_EOF1_SHIFT                          0
#define FX3_OHCI_EOF_EOF1_BITS                           16
#define FX3_OHCI_EOF_EOF1_MASK                           (0xffffUL << 0)

#define FX3_EHCI_HCCPARAMS_ISO_SHDL_THR_SHIFT            4
#define FX3_EHCI_HCCPARAMS_ISO_SHDL_THR_BITS             4
#define FX3_EHCI_HCCPARAMS_ISO_SHDL_THR_MASK             (0xfUL << 4)
#define FX3_EHCI_HCCPARAMS_ASYNC_PARK_CAP                (1UL << 2)
#define FX3_EHCI_HCCPARAMS_ADDR_64_BIT_CAP               (1UL << 0)

#define FX3_EHCI_USBCMD_INT_THRESHOLD_CTRL_SHIFT         16
#define FX3_EHCI_USBCMD_INT_THRESHOLD_CTRL_BITS          8
#define FX3_EHCI_USBCMD_INT_THRESHOLD_CTRL_MASK          (0xffUL << 16)
#define FX3_EHCI_USBCMD_ASYNC_SHDL_PRK_EN                (1UL << 11)
#define FX3_EHCI_USBCMD_ASYNC_SHDL_PRK_CNT_SHIFT         8
#define FX3_EHCI_USBCMD_ASYNC_SHDL_PRK_CNT_BITS          2
#define FX3_EHCI_USBCMD_ASYNC_SHDL_PRK_CNT_MASK          (0x3UL << 8)
#define FX3_EHCI_USBCMD_ASYNC_SHDL_EN                    (1UL << 5)
#define FX3_EHCI_USBCMD_PER_SHDL_EN                      (1UL << 4)
#define FX3_EHCI_USBCMD_RS                               (1UL << 0)

#define FX3_EHCI_USBSTS_ASYNC_SHDL_ST                    (1UL << 15)
#define FX3_EHCI_USBSTS_PER_SHDL_ST                      (1UL << 14)
#define FX3_EHCI_USBSTS_RECLAMATION                      (1UL << 13)
#define FX3_EHCI_USBSTS_HC_HALTED                        (1UL << 12)
#define FX3_EHCI_USBSTS_HOST_SYS_ERR                     (1UL << 4)
#define FX3_EHCI_USBSTS_PORT_CHNG_DET                    (1UL << 2)
#define FX3_EHCI_USBSTS_USBERRINT                        (1UL << 1)
#define FX3_EHCI_USBSTS_USBINT                           (1UL << 0)

#define FX3_EHCI_USBINTR_HOST_SYS_ERR_IE                 (1UL << 4)
#define FX3_EHCI_USBINTR_PORT_CHANGE_DET_IE              (1UL << 2)
#define FX3_EHCI_USBINTR_USBERRINT_IE                    (1UL << 1)
#define FX3_EHCI_USBINTR_USBINT_IE                       (1UL << 0)

#define FX3_EHCI_FRINDEX_FRINDEX_SHIFT                   0
#define FX3_EHCI_FRINDEX_FRINDEX_BITS                    14
#define FX3_EHCI_FRINDEX_FRINDEX_MASK                    (0x3fffUL << 0)

#define FX3_EHCI_CONFIGFLAG_CF                           (1UL << 0)

#define FX3_EHCI_PORTSC_PORT_RESET_FW                    (1UL << 31)
#define FX3_EHCI_PORTSC_PORT_RESUME_HW                   (1UL << 30)
#define FX3_EHCI_PORTSC_PORT_OWNER                       (1UL << 13)
#define FX3_EHCI_PORTSC_EHCI_LINE_STATE_SHIFT            10
#define FX3_EHCI_PORTSC_EHCI_LINE_STATE_BITS             2
#define FX3_EHCI_PORTSC_EHCI_LINE_STATE_MASK             (0x3UL << 10)
#define FX3_EHCI_PORTSC_PORT_RESET                       (1UL << 8)
#define FX3_EHCI_PORTSC_PORT_SUSPEND                     (1UL << 7)
#define FX3_EHCI_PORTSC_F_PORT_RESUME                    (1UL << 6)
#define FX3_EHCI_PORTSC_PORT_EN_C                        (1UL << 3)
#define FX3_EHCI_PORTSC_PORT_EN                          (1UL << 2)
#define FX3_EHCI_PORTSC_PORT_CONNECT_C                   (1UL << 1)
#define FX3_EHCI_PORTSC_PORT_CONNECT                     (1UL << 0)

#define FX3_EHCI_EOF_EOF2_SHIFT                          16
#define FX3_EHCI_EOF_EOF2_BITS                           16
#define FX3_EHCI_EOF_EOF2_MASK                           (0xffffUL << 16)
#define FX3_EHCI_EOF_EOF1_SHIFT                          0
#define FX3_EHCI_EOF_EOF1_BITS                           16
#define FX3_EHCI_EOF_EOF1_MASK                           (0xffffUL << 0)

#define FX3_SHDL_CHNG_TYPE_EOF2_SHIFT                    16
#define FX3_SHDL_CHNG_TYPE_EOF2_BITS                     16
#define FX3_SHDL_CHNG_TYPE_EOF2_MASK                     (0xffffUL << 16)
#define FX3_SHDL_CHNG_TYPE_EOF1_SHIFT                    0
#define FX3_SHDL_CHNG_TYPE_EOF1_BITS                     16
#define FX3_SHDL_CHNG_TYPE_EOF1_MASK                     (0xffffUL << 0)

#define FX3_SHDL_STATE_MACHINE_WAIT_EOF                  (1UL << 18)
#define FX3_SHDL_STATE_MACHINE_WAIT_SHDL_EN              (1UL << 17)
#define FX3_SHDL_STATE_MACHINE_SCRATCH_WRITE2            (1UL << 16)
#define FX3_SHDL_STATE_MACHINE_SCRATCH_WRITE1            (1UL << 15)
#define FX3_SHDL_STATE_MACHINE_SHDL_WRITE                (1UL << 14)
#define FX3_SHDL_STATE_MACHINE_LAST_EVAL                 (1UL << 13)
#define FX3_SHDL_STATE_MACHINE_WAIT_TP_STUPD             (1UL << 12)
#define FX3_SHDL_STATE_MACHINE_EXECUTE                   (1UL << 11)
#define FX3_SHDL_STATE_MACHINE_ASYNC_SLEEP               (1UL << 10)
#define FX3_SHDL_STATE_MACHINE_FIRST_EVAL                (1UL << 9)
#define FX3_SHDL_STATE_MACHINE_READ_EP0_1                (1UL << 8)
#define FX3_SHDL_STATE_MACHINE_READ_EP0_0                (1UL << 7)
#define FX3_SHDL_STATE_MACHINE_LOAD_SHDL_MEM             (1UL << 6)
#define FX3_SHDL_STATE_MACHINE_SCRATCH_READ2             (1UL << 5)
#define FX3_SHDL_STATE_MACHINE_SCRATCH_READ1             (1UL << 4)
#define FX3_SHDL_STATE_MACHINE_SCRATCH_READ0             (1UL << 3)
#define FX3_SHDL_STATE_MACHINE_FETCH                     (1UL << 2)
#define FX3_SHDL_STATE_MACHINE_LOAD_PTR                  (1UL << 1)
#define FX3_SHDL_STATE_MACHINE_IDLE                      (1UL << 0)

#define FX3_SHDL_INTERNAL_STATUS_TP_EPM_OVERRUN          (1UL << 17)
#define FX3_SHDL_INTERNAL_STATUS_TP_EPM_UNDERRUN         (1UL << 16)
#define FX3_SHDL_INTERNAL_STATUS_TP_TIMEOUT              (1UL << 15)
#define FX3_SHDL_INTERNAL_STATUS_TP_PID_ERROR            (1UL << 14)
#define FX3_SHDL_INTERNAL_STATUS_TP_BABBLE               (1UL << 13)
#define FX3_SHDL_INTERNAL_STATUS_TP_PORT_ERROR           (1UL << 12)
#define FX3_SHDL_INTERNAL_STATUS_TP_PHY_ERROR            (1UL << 11)
#define FX3_SHDL_INTERNAL_STATUS_TP_CRC16_ERROR          (1UL << 10)
#define FX3_SHDL_INTERNAL_STATUS_TP_DT_MISMATCH          (1UL << 9)
#define FX3_SHDL_INTERNAL_STATUS_TP_STALL                (1UL << 8)
#define FX3_SHDL_INTERNAL_STATUS_TP_NYET                 (1UL << 7)
#define FX3_SHDL_INTERNAL_STATUS_TP_NAK                  (1UL << 6)
#define FX3_SHDL_INTERNAL_STATUS_TP_ACK                  (1UL << 5)
#define FX3_SHDL_INTERNAL_STATUS_EP0_IN                  (1UL << 4)
#define FX3_SHDL_INTERNAL_STATUS_EP0_OUT                 (1UL << 3)
#define FX3_SHDL_INTERNAL_STATUS_EP0_SETUP               (1UL << 2)
#define FX3_SHDL_INTERNAL_STATUS_FRAME_FIT               (1UL << 1)
#define FX3_SHDL_INTERNAL_STATUS_EP_DONE                 (1UL << 0)

#define FX3_SHDL_OHCI_SHDL_NOT_USED_SHIFT                96
#define FX3_SHDL_OHCI_SHDL_NOT_USED_BITS                 32
#define FX3_SHDL_OHCI_SHDL_NOT_USED_MASK                 (0xffffffffUL << 96)
#define FX3_SHDL_OHCI_IOC_RATE_SHIFT                     81
#define FX3_SHDL_OHCI_IOC_RATE_BITS                      8
#define FX3_SHDL_OHCI_IOC_RATE_MASK                      (0xffUL << 81)
#define FX3_SHDL_OHCI_TRNS_MODE                          (1UL << 80)
#define FX3_SHDL_OHCI_TOTAL_BYTE_COUNT_SHIFT             64
#define FX3_SHDL_OHCI_TOTAL_BYTE_COUNT_BITS              16
#define FX3_SHDL_OHCI_TOTAL_BYTE_COUNT_MASK              (0xffffUL << 64)
#define FX3_SHDL_OHCI_EP0_CODE_SHIFT                     62
#define FX3_SHDL_OHCI_EP0_CODE_BITS                      2
#define FX3_SHDL_OHCI_EP0_CODE_MASK                      (0x3UL << 62)
#define FX3_SHDL_OHCI_BYPASS_ERROR                       (1UL << 61)
#define FX3_SHDL_OHCI_MMULT_SHIFT                        59
#define FX3_SHDL_OHCI_MMULT_BITS                         2
#define FX3_SHDL_OHCI_MMULT_MASK                         (0x3UL << 59)
#define FX3_SHDL_OHCI_RESP_RATE_SHIFT                    51
#define FX3_SHDL_OHCI_RESP_RATE_BITS                     8
#define FX3_SHDL_OHCI_RESP_RATE_MASK                     (0xffUL << 51)
#define FX3_SHDL_OHCI_POLLING_RATE_SHIFT                 43
#define FX3_SHDL_OHCI_POLLING_RATE_BITS                  8
#define FX3_SHDL_OHCI_POLLING_RATE_MASK                  (0xffUL << 43)
#define FX3_SHDL_OHCI_MAX_PKT_SIZE_SHIFT                 32
#define FX3_SHDL_OHCI_MAX_PKT_SIZE_BITS                  11
#define FX3_SHDL_OHCI_MAX_PKT_SIZE_MASK                  (0x7ffUL << 32)
#define FX3_SHDL_OHCI_UFRAME_SMASK_SHIFT                 24
#define FX3_SHDL_OHCI_UFRAME_SMASK_BITS                  8
#define FX3_SHDL_OHCI_UFRAME_SMASK_MASK                  (0xffUL << 24)
#define FX3_SHDL_OHCI_PING                               (1UL << 23)
#define FX3_SHDL_OHCI_RL_SHIFT                           19
#define FX3_SHDL_OHCI_RL_BITS                            4
#define FX3_SHDL_OHCI_RL_MASK                            (0xfUL << 19)
#define FX3_SHDL_OHCI_MULT_SHIFT                         17
#define FX3_SHDL_OHCI_MULT_BITS                          2
#define FX3_SHDL_OHCI_MULT_MASK                          (0x3UL << 17)
#define FX3_SHDL_OHCI_ISO_EPM                            (1UL << 16)
#define FX3_SHDL_OHCI_CERR_SHIFT                         14
#define FX3_SHDL_OHCI_CERR_BITS                          2
#define FX3_SHDL_OHCI_CERR_MASK                          (0x3UL << 14)
#define FX3_SHDL_OHCI_NAK_CNT_SHIFT                      10
#define FX3_SHDL_OHCI_NAK_CNT_BITS                       4
#define FX3_SHDL_OHCI_NAK_CNT_MASK                       (0xfUL << 10)
#define FX3_SHDL_OHCI_HALT                               (1UL << 9)
#define FX3_SHDL_OHCI_T                                  (1UL << 8)
#define FX3_SHDL_OHCI_ZPLEN                              (1UL << 7)
#define FX3_SHDL_OHCI_EPT_SHIFT                          5
#define FX3_SHDL_OHCI_EPT_BITS                           2
#define FX3_SHDL_OHCI_EPT_MASK                           (0x3UL << 5)
#define FX3_SHDL_OHCI_EPND_SHIFT                         0
#define FX3_SHDL_OHCI_EPND_BITS                          5
#define FX3_SHDL_OHCI_EPND_MASK                          (0x1fUL << 0)

#define FX3_SHDL_EHCI_SHDL_NOT_USED_SHIFT                96
#define FX3_SHDL_EHCI_SHDL_NOT_USED_BITS                 32
#define FX3_SHDL_EHCI_SHDL_NOT_USED_MASK                 (0xffffffffUL << 96)
#define FX3_SHDL_EHCI_IOC_RATE_SHIFT                     81
#define FX3_SHDL_EHCI_IOC_RATE_BITS                      8
#define FX3_SHDL_EHCI_IOC_RATE_MASK                      (0xffUL << 81)
#define FX3_SHDL_EHCI_TRNS_MODE                          (1UL << 80)
#define FX3_SHDL_EHCI_TOTAL_BYTE_COUNT_SHIFT             64
#define FX3_SHDL_EHCI_TOTAL_BYTE_COUNT_BITS              16
#define FX3_SHDL_EHCI_TOTAL_BYTE_COUNT_MASK              (0xffffUL << 64)
#define FX3_SHDL_EHCI_EP0_CODE_SHIFT                     62
#define FX3_SHDL_EHCI_EP0_CODE_BITS                      2
#define FX3_SHDL_EHCI_EP0_CODE_MASK                      (0x3UL << 62)
#define FX3_SHDL_EHCI_BYPASS_ERROR                       (1UL << 61)
#define FX3_SHDL_EHCI_MMULT_SHIFT                        59
#define FX3_SHDL_EHCI_MMULT_BITS                         2
#define FX3_SHDL_EHCI_MMULT_MASK                         (0x3UL << 59)
#define FX3_SHDL_EHCI_RESP_RATE_SHIFT                    51
#define FX3_SHDL_EHCI_RESP_RATE_BITS                     8
#define FX3_SHDL_EHCI_RESP_RATE_MASK                     (0xffUL << 51)
#define FX3_SHDL_EHCI_POLLING_RATE_SHIFT                 43
#define FX3_SHDL_EHCI_POLLING_RATE_BITS                  8
#define FX3_SHDL_EHCI_POLLING_RATE_MASK                  (0xffUL << 43)
#define FX3_SHDL_EHCI_MAX_PKT_SIZE_SHIFT                 32
#define FX3_SHDL_EHCI_MAX_PKT_SIZE_BITS                  11
#define FX3_SHDL_EHCI_MAX_PKT_SIZE_MASK                  (0x7ffUL << 32)
#define FX3_SHDL_EHCI_UFRAME_SMASK_SHIFT                 24
#define FX3_SHDL_EHCI_UFRAME_SMASK_BITS                  8
#define FX3_SHDL_EHCI_UFRAME_SMASK_MASK                  (0xffUL << 24)
#define FX3_SHDL_EHCI_PING                               (1UL << 23)
#define FX3_SHDL_EHCI_RL_SHIFT                           19
#define FX3_SHDL_EHCI_RL_BITS                            4
#define FX3_SHDL_EHCI_RL_MASK                            (0xfUL << 19)
#define FX3_SHDL_EHCI_MULT_SHIFT                         17
#define FX3_SHDL_EHCI_MULT_BITS                          2
#define FX3_SHDL_EHCI_MULT_MASK                          (0x3UL << 17)
#define FX3_SHDL_EHCI_ISO_EPM                            (1UL << 16)
#define FX3_SHDL_EHCI_CERR_SHIFT                         14
#define FX3_SHDL_EHCI_CERR_BITS                          2
#define FX3_SHDL_EHCI_CERR_MASK                          (0x3UL << 14)
#define FX3_SHDL_EHCI_NAK_CNT_SHIFT                      10
#define FX3_SHDL_EHCI_NAK_CNT_BITS                       4
#define FX3_SHDL_EHCI_NAK_CNT_MASK                       (0xfUL << 10)
#define FX3_SHDL_EHCI_HALT                               (1UL << 9)
#define FX3_SHDL_EHCI_T                                  (1UL << 8)
#define FX3_SHDL_EHCI_ZPLEN                              (1UL << 7)
#define FX3_SHDL_EHCI_EPT_SHIFT                          5
#define FX3_SHDL_EHCI_EPT_BITS                           2
#define FX3_SHDL_EHCI_EPT_MASK                           (0x3UL << 5)
#define FX3_SHDL_EHCI_EPND_SHIFT                         0
#define FX3_SHDL_EHCI_EPND_BITS                          5
#define FX3_SHDL_EHCI_EPND_MASK                          (0x1fUL << 0)

#define FX3_LNK_CONF_EPM_FIRST_DELAY_SHIFT               12
#define FX3_LNK_CONF_EPM_FIRST_DELAY_BITS                4
#define FX3_LNK_CONF_EPM_FIRST_DELAY_MASK                (0xfUL << 12)
#define FX3_LNK_CONF_CREDIT_ADV_HOLDOFF                  (1UL << 10)
#define FX3_LNK_CONF_LDN_DETECTION                       (1UL << 9)
#define FX3_LNK_CONF_FORCE_POWER_PRESENT                 (1UL << 8)
#define FX3_LNK_CONF_LCW_IGNORE_RSVD                     (1UL << 6)

#define FX3_LNK_INTR_LTSSM_RESET                         (1UL << 17)
#define FX3_LNK_INTR_LTSSM_DISCONNECT                    (1UL << 16)
#define FX3_LNK_INTR_LTSSM_CONNECT                       (1UL << 15)
#define FX3_LNK_INTR_U2_INACTIVITY_TIMEOUT               (1UL << 14)
#define FX3_LNK_INTR_PHY_ERROR                           (1UL << 13)
#define FX3_LNK_INTR_LINK_ERROR                          (1UL << 12)
#define FX3_LNK_INTR_BAD_LCW                             (1UL << 11)
#define FX3_LNK_INTR_LPMA                                (1UL << 10)
#define FX3_LNK_INTR_LXU                                 (1UL << 9)
#define FX3_LNK_INTR_LAU                                 (1UL << 8)
#define FX3_LNK_INTR_LGO_U3                              (1UL << 7)
#define FX3_LNK_INTR_LGO_U2                              (1UL << 6)
#define FX3_LNK_INTR_LGO_U1                              (1UL << 5)
#define FX3_LNK_INTR_LCRD                                (1UL << 4)
#define FX3_LNK_INTR_LBAD                                (1UL << 3)
#define FX3_LNK_INTR_LRTY                                (1UL << 2)
#define FX3_LNK_INTR_LGOOD                               (1UL << 1)
#define FX3_LNK_INTR_LTSSM_STATE_CHG                     (1UL << 0)

#define FX3_LNK_INTR_MASK_LTSSM_RESET                    (1UL << 17)
#define FX3_LNK_INTR_MASK_LTSSM_DISCONNECT               (1UL << 16)
#define FX3_LNK_INTR_MASK_LTSSM_CONNECT                  (1UL << 15)
#define FX3_LNK_INTR_MASK_U2_INACTIVITY_TIMEOUT          (1UL << 14)
#define FX3_LNK_INTR_MASK_PHY_ERROR                      (1UL << 13)
#define FX3_LNK_INTR_MASK_LINK_ERROR                     (1UL << 12)
#define FX3_LNK_INTR_MASK_BAD_LCW                        (1UL << 11)
#define FX3_LNK_INTR_MASK_LPMA                           (1UL << 10)
#define FX3_LNK_INTR_MASK_LXU                            (1UL << 9)
#define FX3_LNK_INTR_MASK_LAU                            (1UL << 8)
#define FX3_LNK_INTR_MASK_LGO_U3                         (1UL << 7)
#define FX3_LNK_INTR_MASK_LGO_U2                         (1UL << 6)
#define FX3_LNK_INTR_MASK_LGO_U1                         (1UL << 5)
#define FX3_LNK_INTR_MASK_LCRD                           (1UL << 4)
#define FX3_LNK_INTR_MASK_LBAD                           (1UL << 3)
#define FX3_LNK_INTR_MASK_LRTY                           (1UL << 2)
#define FX3_LNK_INTR_MASK_LGOOD                          (1UL << 1)
#define FX3_LNK_INTR_MASK_LTSSM_STATE_CHG                (1UL << 0)

#define FX3_LNK_ERROR_CONF_CREDIT_ADV_LGO_EN             (1UL << 14)
#define FX3_LNK_ERROR_CONF_CREDIT_ADV_HP_EN              (1UL << 13)
#define FX3_LNK_ERROR_CONF_CREDIT_ADV_TIMEOUT_EN         (1UL << 12)
#define FX3_LNK_ERROR_CONF_HDR_ADV_LGO_EN                (1UL << 11)
#define FX3_LNK_ERROR_CONF_HDR_ADV_LCRD_EN               (1UL << 10)
#define FX3_LNK_ERROR_CONF_HDR_ADV_HP_EN                 (1UL << 9)
#define FX3_LNK_ERROR_CONF_HDR_ADV_TIMEOUT_EN            (1UL << 8)
#define FX3_LNK_ERROR_CONF_TX_SEQ_NUM_ERR_EN             (1UL << 7)
#define FX3_LNK_ERROR_CONF_PM_LC_TIMEOUT_EN              (1UL << 6)
#define FX3_LNK_ERROR_CONF_CREDIT_HP_TIMEOUT_EN          (1UL << 5)
#define FX3_LNK_ERROR_CONF_MISSING_LCRD_EN               (1UL << 4)
#define FX3_LNK_ERROR_CONF_MISSING_LGOOD_EN              (1UL << 3)
#define FX3_LNK_ERROR_CONF_RX_HP_FAIL_EN                 (1UL << 2)
#define FX3_LNK_ERROR_CONF_RX_SEQ_NUM_ERR_EN             (1UL << 1)
#define FX3_LNK_ERROR_CONF_HP_TIMEOUT_EN                 (1UL << 0)

#define FX3_LNK_ERROR_STATUS_CREDIT_ADV_LGO_EV           (1UL << 14)
#define FX3_LNK_ERROR_STATUS_CREDIT_ADV_HP_EV            (1UL << 13)
#define FX3_LNK_ERROR_STATUS_CREDIT_ADV_TIMEOUT_EV       (1UL << 12)
#define FX3_LNK_ERROR_STATUS_HDR_ADV_LGO_EV              (1UL << 11)
#define FX3_LNK_ERROR_STATUS_HDR_ADV_LCRD_EV             (1UL << 10)
#define FX3_LNK_ERROR_STATUS_HDR_ADV_HP_EV               (1UL << 9)
#define FX3_LNK_ERROR_STATUS_HDR_ADV_TIMEOUT_EV          (1UL << 8)
#define FX3_LNK_ERROR_STATUS_TX_SEQ_NUM_ERR_EV           (1UL << 7)
#define FX3_LNK_ERROR_STATUS_PM_LC_TIMEOUT_EV            (1UL << 6)
#define FX3_LNK_ERROR_STATUS_CREDIT_HP_TIMEOUT_EV        (1UL << 5)
#define FX3_LNK_ERROR_STATUS_MISSING_LCRD_EV             (1UL << 4)
#define FX3_LNK_ERROR_STATUS_MISSING_LGOOD_EV            (1UL << 3)
#define FX3_LNK_ERROR_STATUS_RX_HP_FAIL_EV               (1UL << 2)
#define FX3_LNK_ERROR_STATUS_RX_SEQ_NUM_ERR_EV           (1UL << 1)
#define FX3_LNK_ERROR_STATUS_HP_TIMEOUT_EV               (1UL << 0)

#define FX3_LNK_ERROR_COUNT_PHY_ERROR_COUNT_SHIFT        16
#define FX3_LNK_ERROR_COUNT_PHY_ERROR_COUNT_BITS         16
#define FX3_LNK_ERROR_COUNT_PHY_ERROR_COUNT_MASK         (0xffffUL << 16)
#define FX3_LNK_ERROR_COUNT_LINK_ERROR_COUNT_SHIFT       0
#define FX3_LNK_ERROR_COUNT_LINK_ERROR_COUNT_BITS        16
#define FX3_LNK_ERROR_COUNT_LINK_ERROR_COUNT_MASK        (0xffffUL << 0)

#define FX3_LNK_ERROR_COUNT_THRESHOLD_PHY_ERROR_THRESHOLD_SHIFT 16
#define FX3_LNK_ERROR_COUNT_THRESHOLD_PHY_ERROR_THRESHOLD_BITS  16
#define FX3_LNK_ERROR_COUNT_THRESHOLD_PHY_ERROR_THRESHOLD_MASK  (0xffffUL << 16)
#define FX3_LNK_ERROR_COUNT_THRESHOLD_LINK_ERROR_THRESHOLD_SHIFT 0
#define FX3_LNK_ERROR_COUNT_THRESHOLD_LINK_ERROR_THRESHOLD_BITS  16
#define FX3_LNK_ERROR_COUNT_THRESHOLD_LINK_ERROR_THRESHOLD_MASK  (0xffffUL << 0)

#define FX3_LNK_PHY_CONF_RX_TERMINATION_ENABLE           (1UL << 31)
#define FX3_LNK_PHY_CONF_RX_TERMINATION_OVR_VAL          (1UL << 30)
#define FX3_LNK_PHY_CONF_RX_TERMINATION_OVR              (1UL << 29)
#define FX3_LNK_PHY_CONF_PHY_MODE_SHIFT                  0
#define FX3_LNK_PHY_CONF_PHY_MODE_BITS                   2
#define FX3_LNK_PHY_CONF_PHY_MODE_MASK                   (0x3UL << 0)

#define FX3_LNK_PHY_MPLL_STATUS_REF_CLKREQ_N             (1UL << 23)
#define FX3_LNK_PHY_MPLL_STATUS_REF_CLKDIV2              (1UL << 22)
#define FX3_LNK_PHY_MPLL_STATUS_REF_SSP_EN               (1UL << 21)
#define FX3_LNK_PHY_MPLL_STATUS_SSC_REF_CLK_SEL_SHIFT    13
#define FX3_LNK_PHY_MPLL_STATUS_SSC_REF_CLK_SEL_BITS     8
#define FX3_LNK_PHY_MPLL_STATUS_SSC_REF_CLK_SEL_MASK     (0xffUL << 13)
#define FX3_LNK_PHY_MPLL_STATUS_SSC_RANGE_SHIFT          11
#define FX3_LNK_PHY_MPLL_STATUS_SSC_RANGE_BITS           2
#define FX3_LNK_PHY_MPLL_STATUS_SSC_RANGE_MASK           (0x3UL << 11)
#define FX3_LNK_PHY_MPLL_STATUS_SSC_EN                   (1UL << 10)
#define FX3_LNK_PHY_MPLL_STATUS_MPLL_MULTIPLIER_SHIFT    3
#define FX3_LNK_PHY_MPLL_STATUS_MPLL_MULTIPLIER_BITS     7
#define FX3_LNK_PHY_MPLL_STATUS_MPLL_MULTIPLIER_MASK     (0x7fUL << 3)

#define FX3_LNK_PHY_TX_TRIM_PCS_TX_SWING_LOW_SHIFT       21
#define FX3_LNK_PHY_TX_TRIM_PCS_TX_SWING_LOW_BITS        7
#define FX3_LNK_PHY_TX_TRIM_PCS_TX_SWING_LOW_MASK        (0x7fUL << 21)
#define FX3_LNK_PHY_TX_TRIM_PCS_TX_SWING_FULL_SHIFT      14
#define FX3_LNK_PHY_TX_TRIM_PCS_TX_SWING_FULL_BITS       7
#define FX3_LNK_PHY_TX_TRIM_PCS_TX_SWING_FULL_MASK       (0x7fUL << 14)
#define FX3_LNK_PHY_TX_TRIM_PCS_TX_DEEMPH_6DB_SHIFT      7
#define FX3_LNK_PHY_TX_TRIM_PCS_TX_DEEMPH_6DB_BITS       6
#define FX3_LNK_PHY_TX_TRIM_PCS_TX_DEEMPH_6DB_MASK       (0x3fUL << 7)
#define FX3_LNK_PHY_TX_TRIM_PCS_TX_DEEMPH_3P5DB_SHIFT    0
#define FX3_LNK_PHY_TX_TRIM_PCS_TX_DEEMPH_3P5DB_BITS     6
#define FX3_LNK_PHY_TX_TRIM_PCS_TX_DEEMPH_3P5DB_MASK     (0x3fUL << 0)

#define FX3_LNK_PHY_ERROR_CONF_PHY_LOCK_EN               (1UL << 8)
#define FX3_LNK_PHY_ERROR_CONF_TRAINING_ERROR_EN         (1UL << 7)
#define FX3_LNK_PHY_ERROR_CONF_RX_ERROR_CRC32_EN         (1UL << 6)
#define FX3_LNK_PHY_ERROR_CONF_RX_ERROR_CRC16_EN         (1UL << 5)
#define FX3_LNK_PHY_ERROR_CONF_RX_ERROR_CRC5_EN          (1UL << 4)
#define FX3_LNK_PHY_ERROR_CONF_PHY_ERROR_DISPARITY_EN       (1UL << 3)
#define FX3_LNK_PHY_ERROR_CONF_PHY_ERROR_EB_UND_EN       (1UL << 2)
#define FX3_LNK_PHY_ERROR_CONF_PHY_ERROR_EB_OVR_EN       (1UL << 1)
#define FX3_LNK_PHY_ERROR_CONF_PHY_ERROR_DECODE_EN       (1UL << 0)

#define FX3_LNK_PHY_ERROR_STATUS_PHY_LOCK_EV             (1UL << 8)
#define FX3_LNK_PHY_ERROR_STATUS_TRAINING_ERROR_EV       (1UL << 7)
#define FX3_LNK_PHY_ERROR_STATUS_RX_ERROR_CRC32_EV       (1UL << 6)
#define FX3_LNK_PHY_ERROR_STATUS_RX_ERROR_CRC16_EV       (1UL << 5)
#define FX3_LNK_PHY_ERROR_STATUS_RX_ERROR_CRC5_EV        (1UL << 4)
#define FX3_LNK_PHY_ERROR_STATUS_PHY_ERROR_DISPARITY_EV       (1UL << 3)
#define FX3_LNK_PHY_ERROR_STATUS_PHY_ERROR_EB_UND_EV       (1UL << 2)
#define FX3_LNK_PHY_ERROR_STATUS_PHY_ERROR_EB_OVR_EV       (1UL << 1)
#define FX3_LNK_PHY_ERROR_STATUS_PHY_ERROR_DECODE_EV       (1UL << 0)

#define FX3_LNK_DEVICE_POWER_CONTROL_YES_U2              (1UL << 31)
#define FX3_LNK_DEVICE_POWER_CONTROL_YES_U1              (1UL << 30)
#define FX3_LNK_DEVICE_POWER_CONTROL_NO_U2               (1UL << 29)
#define FX3_LNK_DEVICE_POWER_CONTROL_NO_U1               (1UL << 28)
#define FX3_LNK_DEVICE_POWER_CONTROL_AUTO_U2             (1UL << 27)
#define FX3_LNK_DEVICE_POWER_CONTROL_AUTO_U1             (1UL << 26)
#define FX3_LNK_DEVICE_POWER_CONTROL_EXIT_LP             (1UL << 9)
#define FX3_LNK_DEVICE_POWER_CONTROL_TX_LXU              (1UL << 8)
#define FX3_LNK_DEVICE_POWER_CONTROL_TX_LAU              (1UL << 7)
#define FX3_LNK_DEVICE_POWER_CONTROL_RX_U3               (1UL << 6)
#define FX3_LNK_DEVICE_POWER_CONTROL_RX_U2               (1UL << 5)
#define FX3_LNK_DEVICE_POWER_CONTROL_RX_U1               (1UL << 4)
#define FX3_LNK_DEVICE_POWER_CONTROL_TX_U3               (1UL << 2)
#define FX3_LNK_DEVICE_POWER_CONTROL_TX_U2               (1UL << 1)
#define FX3_LNK_DEVICE_POWER_CONTROL_TX_U1               (1UL << 0)

#define FX3_LNK_LTSSM_STATE_LTSSM_STATE_SHIFT            0
#define FX3_LNK_LTSSM_STATE_LTSSM_STATE_BITS             6
#define FX3_LNK_LTSSM_STATE_LTSSM_STATE_MASK             (0x3fUL << 0)
#define FX3_LNK_LTSSM_STATE_LTSSM_OVERRIDE_VALUE_SHIFT   6
#define FX3_LNK_LTSSM_STATE_LTSSM_OVERRIDE_VALUE_BITS    6
#define FX3_LNK_LTSSM_STATE_LTSSM_OVERRIDE_VALUE_MASK    (0x3fUL << 6)
#define FX3_LNK_LTSSM_STATE_LTSSM_OVERRIDE_EN            (1UL << 12)
#define FX3_LNK_LTSSM_STATE_LTSSM_OVERRIDE_GO            (1UL << 13)
#define FX3_LNK_LTSSM_STATE_LOOPBACK_MASTER              (1UL << 14)
#define FX3_LNK_LTSSM_STATE_DISABLE_SCRAMBLING           (1UL << 15)
#define FX3_LNK_LTSSM_STATE_LOOPBACK_ERROR               (1UL << 16)
#define FX3_LNK_LTSSM_STATE_LOOPBACK_GOOD                (1UL << 17)
#define FX3_LNK_LTSSM_STATE_LTSSM_FREEZE                 (1UL << 31)

#define FX3_LNK_LFPS_OBSERVE_POLLING_LFPS_SENT_SHIFT     20
#define FX3_LNK_LFPS_OBSERVE_POLLING_LFPS_SENT_BITS      4
#define FX3_LNK_LFPS_OBSERVE_POLLING_LFPS_SENT_MASK      (0xfUL << 20)
#define FX3_LNK_LFPS_OBSERVE_POLLING_LFPS_RCVD_SHIFT     16
#define FX3_LNK_LFPS_OBSERVE_POLLING_LFPS_RCVD_BITS      4
#define FX3_LNK_LFPS_OBSERVE_POLLING_LFPS_RCVD_MASK      (0xfUL << 16)
#define FX3_LNK_LFPS_OBSERVE_LOOPBACK_DET                (1UL << 6)
#define FX3_LNK_LFPS_OBSERVE_U3_EXIT_DET                 (1UL << 5)
#define FX3_LNK_LFPS_OBSERVE_U2_EXIT_DET                 (1UL << 4)
#define FX3_LNK_LFPS_OBSERVE_U1_EXIT_DET                 (1UL << 3)
#define FX3_LNK_LFPS_OBSERVE_RESET_DET                   (1UL << 2)
#define FX3_LNK_LFPS_OBSERVE_PING_DET                    (1UL << 1)
#define FX3_LNK_LFPS_OBSERVE_POLLING_DET                 (1UL << 0)

#define FX3_LNK_COMPLIANCE_PATTERN_0_TXONESZEROS         (1UL << 12)
#define FX3_LNK_COMPLIANCE_PATTERN_0_LFPS                (1UL << 11)
#define FX3_LNK_COMPLIANCE_PATTERN_0_DEEMPHASIS          (1UL << 10)
#define FX3_LNK_COMPLIANCE_PATTERN_0_SCRAMBLED           (1UL << 9)
#define FX3_LNK_COMPLIANCE_PATTERN_0_K_D                 (1UL << 8)
#define FX3_LNK_COMPLIANCE_PATTERN_0_CP_SHIFT            0
#define FX3_LNK_COMPLIANCE_PATTERN_0_CP_BITS             8
#define FX3_LNK_COMPLIANCE_PATTERN_0_CP_MASK             (0xffUL << 0)

#define FX3_LNK_COMPLIANCE_PATTERN_1_TXONESZEROS         (1UL << 12)
#define FX3_LNK_COMPLIANCE_PATTERN_1_LFPS                (1UL << 11)
#define FX3_LNK_COMPLIANCE_PATTERN_1_DEEMPHASIS          (1UL << 10)
#define FX3_LNK_COMPLIANCE_PATTERN_1_SCRAMBLED           (1UL << 9)
#define FX3_LNK_COMPLIANCE_PATTERN_1_K_D                 (1UL << 8)
#define FX3_LNK_COMPLIANCE_PATTERN_1_CP_SHIFT            0
#define FX3_LNK_COMPLIANCE_PATTERN_1_CP_BITS             8
#define FX3_LNK_COMPLIANCE_PATTERN_1_CP_MASK             (0xffUL << 0)

#define FX3_LNK_COMPLIANCE_PATTERN_2_TXONESZEROS         (1UL << 12)
#define FX3_LNK_COMPLIANCE_PATTERN_2_LFPS                (1UL << 11)
#define FX3_LNK_COMPLIANCE_PATTERN_2_DEEMPHASIS          (1UL << 10)
#define FX3_LNK_COMPLIANCE_PATTERN_2_SCRAMBLED           (1UL << 9)
#define FX3_LNK_COMPLIANCE_PATTERN_2_K_D                 (1UL << 8)
#define FX3_LNK_COMPLIANCE_PATTERN_2_CP_SHIFT            0
#define FX3_LNK_COMPLIANCE_PATTERN_2_CP_BITS             8
#define FX3_LNK_COMPLIANCE_PATTERN_2_CP_MASK             (0xffUL << 0)

#define FX3_LNK_COMPLIANCE_PATTERN_3_TXONESZEROS         (1UL << 12)
#define FX3_LNK_COMPLIANCE_PATTERN_3_LFPS                (1UL << 11)
#define FX3_LNK_COMPLIANCE_PATTERN_3_DEEMPHASIS          (1UL << 10)
#define FX3_LNK_COMPLIANCE_PATTERN_3_SCRAMBLED           (1UL << 9)
#define FX3_LNK_COMPLIANCE_PATTERN_3_K_D                 (1UL << 8)
#define FX3_LNK_COMPLIANCE_PATTERN_3_CP_SHIFT            0
#define FX3_LNK_COMPLIANCE_PATTERN_3_CP_BITS             8
#define FX3_LNK_COMPLIANCE_PATTERN_3_CP_MASK             (0xffUL << 0)

#define FX3_LNK_COMPLIANCE_PATTERN_4_TXONESZEROS         (1UL << 12)
#define FX3_LNK_COMPLIANCE_PATTERN_4_LFPS                (1UL << 11)
#define FX3_LNK_COMPLIANCE_PATTERN_4_DEEMPHASIS          (1UL << 10)
#define FX3_LNK_COMPLIANCE_PATTERN_4_SCRAMBLED           (1UL << 9)
#define FX3_LNK_COMPLIANCE_PATTERN_4_K_D                 (1UL << 8)
#define FX3_LNK_COMPLIANCE_PATTERN_4_CP_SHIFT            0
#define FX3_LNK_COMPLIANCE_PATTERN_4_CP_BITS             8
#define FX3_LNK_COMPLIANCE_PATTERN_4_CP_MASK             (0xffUL << 0)

#define FX3_LNK_COMPLIANCE_PATTERN_5_TXONESZEROS         (1UL << 12)
#define FX3_LNK_COMPLIANCE_PATTERN_5_LFPS                (1UL << 11)
#define FX3_LNK_COMPLIANCE_PATTERN_5_DEEMPHASIS          (1UL << 10)
#define FX3_LNK_COMPLIANCE_PATTERN_5_SCRAMBLED           (1UL << 9)
#define FX3_LNK_COMPLIANCE_PATTERN_5_K_D                 (1UL << 8)
#define FX3_LNK_COMPLIANCE_PATTERN_5_CP_SHIFT            0
#define FX3_LNK_COMPLIANCE_PATTERN_5_CP_BITS             8
#define FX3_LNK_COMPLIANCE_PATTERN_5_CP_MASK             (0xffUL << 0)

#define FX3_LNK_COMPLIANCE_PATTERN_6_TXONESZEROS         (1UL << 12)
#define FX3_LNK_COMPLIANCE_PATTERN_6_LFPS                (1UL << 11)
#define FX3_LNK_COMPLIANCE_PATTERN_6_DEEMPHASIS          (1UL << 10)
#define FX3_LNK_COMPLIANCE_PATTERN_6_SCRAMBLED           (1UL << 9)
#define FX3_LNK_COMPLIANCE_PATTERN_6_K_D                 (1UL << 8)
#define FX3_LNK_COMPLIANCE_PATTERN_6_CP_SHIFT            0
#define FX3_LNK_COMPLIANCE_PATTERN_6_CP_BITS             8
#define FX3_LNK_COMPLIANCE_PATTERN_6_CP_MASK             (0xffUL << 0)

#define FX3_LNK_COMPLIANCE_PATTERN_7_TXONESZEROS         (1UL << 12)
#define FX3_LNK_COMPLIANCE_PATTERN_7_LFPS                (1UL << 11)
#define FX3_LNK_COMPLIANCE_PATTERN_7_DEEMPHASIS          (1UL << 10)
#define FX3_LNK_COMPLIANCE_PATTERN_7_SCRAMBLED           (1UL << 9)
#define FX3_LNK_COMPLIANCE_PATTERN_7_K_D                 (1UL << 8)
#define FX3_LNK_COMPLIANCE_PATTERN_7_CP_SHIFT            0
#define FX3_LNK_COMPLIANCE_PATTERN_7_CP_BITS             8
#define FX3_LNK_COMPLIANCE_PATTERN_7_CP_MASK             (0xffUL << 0)

#define FX3_LNK_COMPLIANCE_PATTERN_8_TXONESZEROS         (1UL << 12)
#define FX3_LNK_COMPLIANCE_PATTERN_8_LFPS                (1UL << 11)
#define FX3_LNK_COMPLIANCE_PATTERN_8_DEEMPHASIS          (1UL << 10)
#define FX3_LNK_COMPLIANCE_PATTERN_8_SCRAMBLED           (1UL << 9)
#define FX3_LNK_COMPLIANCE_PATTERN_8_K_D                 (1UL << 8)
#define FX3_LNK_COMPLIANCE_PATTERN_8_CP_SHIFT            0
#define FX3_LNK_COMPLIANCE_PATTERN_8_CP_BITS             8
#define FX3_LNK_COMPLIANCE_PATTERN_8_CP_MASK             (0xffUL << 0)

#define FX3_PROT_CS_MULT_TIMER_SHIFT                     27
#define FX3_PROT_CS_MULT_TIMER_BITS                      5
#define FX3_PROT_CS_MULT_TIMER_MASK                      (0x1fUL << 27)
#define FX3_PROT_CS_DISABLE_IDLE_DET                     (1UL << 26)
#define FX3_PROT_CS_SEQ_NUM_CONFIG                       (1UL << 25)
#define FX3_PROT_CS_PROT_HOST_RESET_RESP                 (1UL << 24)
#define FX3_PROT_CS_TP_THRESHOLD_SHIFT                   18
#define FX3_PROT_CS_TP_THRESHOLD_BITS                    6
#define FX3_PROT_CS_TP_THRESHOLD_MASK                    (0x3fUL << 18)
#define FX3_PROT_CS_NRDY_ALL                             (1UL << 17)
#define FX3_PROT_CS_SETUP_CLR_BUSY                       (1UL << 16)
#define FX3_PROT_CS_DEVICEADDR_SHIFT                     0
#define FX3_PROT_CS_DEVICEADDR_BITS                      7
#define FX3_PROT_CS_DEVICEADDR_MASK                      (0x7fUL << 0)

#define FX3_PROT_INTR_SET_ADDR0_EV                       (1UL << 15)
#define FX3_PROT_INTR_EP0_STALLED_EV                     (1UL << 14)
#define FX3_PROT_INTR_LMP_INVALID_PORT_CFG_EV            (1UL << 13)
#define FX3_PROT_INTR_LMP_INVALID_PORT_CAP_EV            (1UL << 12)
#define FX3_PROT_INTR_STATUS_STAGE                       (1UL << 11)
#define FX3_PROT_INTR_HOST_ERR_EV                        (1UL << 10)
#define FX3_PROT_INTR_SUTOK_EV                           (1UL << 9)
#define FX3_PROT_INTR_ITP_EV                             (1UL << 8)
#define FX3_PROT_INTR_TIMEOUT_HOST_ACK_EV                (1UL << 7)
#define FX3_PROT_INTR_TIMEOUT_PING_EV                    (1UL << 6)
#define FX3_PROT_INTR_TIMEOUT_PORT_CFG_EV                (1UL << 5)
#define FX3_PROT_INTR_TIMEOUT_PORT_CAP_EV                (1UL << 4)
#define FX3_PROT_INTR_LMP_PORT_CFG_EV                    (1UL << 3)
#define FX3_PROT_INTR_LMP_PORT_CAP_EV                    (1UL << 2)
#define FX3_PROT_INTR_LMP_UNKNOWN_EV                     (1UL << 1)
#define FX3_PROT_INTR_LMP_RCV_EV                         (1UL << 0)

#define FX3_PROT_INTR_MASK_SET_ADDR0_EN                  (1UL << 15)
#define FX3_PROT_INTR_MASK_EP0_STALLED_EN                (1UL << 14)
#define FX3_PROT_INTR_MASK_LMP_INVALID_PORT_CFG_EN       (1UL << 13)
#define FX3_PROT_INTR_MASK_LMP_INVALID_PORT_CAP_EN       (1UL << 12)
#define FX3_PROT_INTR_MASK_STATUS_STAGE                  (1UL << 11)
#define FX3_PROT_INTR_MASK_HOST_ERR_EN                   (1UL << 10)
#define FX3_PROT_INTR_MASK_SUTOK_EN                      (1UL << 9)
#define FX3_PROT_INTR_MASK_ITP_EN                        (1UL << 8)
#define FX3_PROT_INTR_MASK_TIMEOUT_HOST_ACK_EN           (1UL << 7)
#define FX3_PROT_INTR_MASK_TIMEOUT_PING_EN               (1UL << 6)
#define FX3_PROT_INTR_MASK_TIMEOUT_PORT_CFG_EN           (1UL << 5)
#define FX3_PROT_INTR_MASK_TIMEOUT_PORT_CAP_EN           (1UL << 4)
#define FX3_PROT_INTR_MASK_LMP_PORT_CFG_EN               (1UL << 3)
#define FX3_PROT_INTR_MASK_LMP_PORT_CAP_EN               (1UL << 2)
#define FX3_PROT_INTR_MASK_LMP_UNKNOWN_EN                (1UL << 1)
#define FX3_PROT_INTR_MASK_LMP_RCV_EN                    (1UL << 0)

#define FX3_PROT_FRAMECNT_DELTA_SHIFT                    14
#define FX3_PROT_FRAMECNT_DELTA_BITS                     13
#define FX3_PROT_FRAMECNT_DELTA_MASK                     (0x1fffUL << 14)
#define FX3_PROT_FRAMECNT_SS_MICROFRAME_SHIFT            0
#define FX3_PROT_FRAMECNT_SS_MICROFRAME_BITS             14
#define FX3_PROT_FRAMECNT_SS_MICROFRAME_MASK             (0x3fffUL << 0)

#define FX3_PROT_ITP_TIME_COUNTER24_SHIFT                0
#define FX3_PROT_ITP_TIME_COUNTER24_BITS                 24
#define FX3_PROT_ITP_TIME_COUNTER24_MASK                 (0xffffffUL << 0)

#define FX3_PROT_ITP_TIMESTAMP_MICROFRAME_LSB_SHIFT      24
#define FX3_PROT_ITP_TIMESTAMP_MICROFRAME_LSB_BITS       8
#define FX3_PROT_ITP_TIMESTAMP_MICROFRAME_LSB_MASK       (0xffUL << 24)
#define FX3_PROT_ITP_TIMESTAMP_TIMESTAMP_SHIFT           0
#define FX3_PROT_ITP_TIMESTAMP_TIMESTAMP_BITS            24
#define FX3_PROT_ITP_TIMESTAMP_TIMESTAMP_MASK            (0xffffffUL << 0)

#define FX3_PROT_SETUP_DAT_SETUP_LENGTH_SHIFT            48
#define FX3_PROT_SETUP_DAT_SETUP_LENGTH_BITS             16
#define FX3_PROT_SETUP_DAT_SETUP_LENGTH_MASK             (0xffffUL << 48)
#define FX3_PROT_SETUP_DAT_SETUP_INDEX_SHIFT             32
#define FX3_PROT_SETUP_DAT_SETUP_INDEX_BITS              16
#define FX3_PROT_SETUP_DAT_SETUP_INDEX_MASK              (0xffffUL << 32)
#define FX3_PROT_SETUP_DAT_SETUP_VALUE_SHIFT             16
#define FX3_PROT_SETUP_DAT_SETUP_VALUE_BITS              16
#define FX3_PROT_SETUP_DAT_SETUP_VALUE_MASK              (0xffffUL << 16)
#define FX3_PROT_SETUP_DAT_SETUP_REQUEST_SHIFT           8
#define FX3_PROT_SETUP_DAT_SETUP_REQUEST_BITS            8
#define FX3_PROT_SETUP_DAT_SETUP_REQUEST_MASK            (0xffUL << 8)
#define FX3_PROT_SETUP_DAT_SETUP_REQUEST_TYPE_SHIFT      0
#define FX3_PROT_SETUP_DAT_SETUP_REQUEST_TYPE_BITS       8
#define FX3_PROT_SETUP_DAT_SETUP_REQUEST_TYPE_MASK       (0xffUL << 0)

#define FX3_PROT_SEQ_NUM_SEQ_VALID                       (1UL << 31)
#define FX3_PROT_SEQ_NUM_COMMAND                         (1UL << 30)
#define FX3_PROT_SEQ_NUM_LAST_COMMITTED_SHIFT            16
#define FX3_PROT_SEQ_NUM_LAST_COMMITTED_BITS             5
#define FX3_PROT_SEQ_NUM_LAST_COMMITTED_MASK             (0x1fUL << 16)
#define FX3_PROT_SEQ_NUM_SEQUENCE_NUMBER_SHIFT           8
#define FX3_PROT_SEQ_NUM_SEQUENCE_NUMBER_BITS            5
#define FX3_PROT_SEQ_NUM_SEQUENCE_NUMBER_MASK            (0x1fUL << 8)
#define FX3_PROT_SEQ_NUM_DIR                             (1UL << 4)
#define FX3_PROT_SEQ_NUM_ENDPOINT_SHIFT                  0
#define FX3_PROT_SEQ_NUM_ENDPOINT_BITS                   4
#define FX3_PROT_SEQ_NUM_ENDPOINT_MASK                   (0xfUL << 0)

#define FX3_PROT_EP_INTR_EP_OUT_SHIFT                    16
#define FX3_PROT_EP_INTR_EP_OUT_BITS                     16
#define FX3_PROT_EP_INTR_EP_OUT_MASK                     (0xffffUL << 16)
#define FX3_PROT_EP_INTR_EP_IN_SHIFT                     0
#define FX3_PROT_EP_INTR_EP_IN_BITS                      16
#define FX3_PROT_EP_INTR_EP_IN_MASK                      (0xffffUL << 0)

#define FX3_PROT_EP_INTR_MASK_EP_OUT_SHIFT               16
#define FX3_PROT_EP_INTR_MASK_EP_OUT_BITS                16
#define FX3_PROT_EP_INTR_MASK_EP_OUT_MASK                (0xffffUL << 16)
#define FX3_PROT_EP_INTR_MASK_EP_IN_SHIFT                0
#define FX3_PROT_EP_INTR_MASK_EP_IN_BITS                 16
#define FX3_PROT_EP_INTR_MASK_EP_IN_MASK                 (0xffffUL << 0)

#define FX3_PROT_EPI_CS1_FIRST_ACK_NUMP_0_MASK           (1UL << 29)
#define FX3_PROT_EPI_CS1_STREAM_ERROR_MASK               (1UL << 28)
#define FX3_PROT_EPI_CS1_DBTERM_MASK                     (1UL << 27)
#define FX3_PROT_EPI_CS1_HBTERM_MASK                     (1UL << 26)
#define FX3_PROT_EPI_CS1_OOSERR_MASK                     (1UL << 25)
#define FX3_PROT_EPI_CS1_SHORT_MASK                      (1UL << 24)
#define FX3_PROT_EPI_CS1_ZERO_MASK                       (1UL << 23)
#define FX3_PROT_EPI_CS1_STREAMNRDY_MASK                 (1UL << 22)
#define FX3_PROT_EPI_CS1_FLOWCONTROL_MASK                (1UL << 21)
#define FX3_PROT_EPI_CS1_RETRY_MASK                      (1UL << 20)
#define FX3_PROT_EPI_CS1_COMMIT_MASK                     (1UL << 19)
#define FX3_PROT_EPI_CS1_FIRST_ACK_NUMP_0                (1UL << 18)
#define FX3_PROT_EPI_CS1_STREAM_ERROR                    (1UL << 17)
#define FX3_PROT_EPI_CS1_DBTERM                          (1UL << 16)
#define FX3_PROT_EPI_CS1_HBTERM                          (1UL << 15)
#define FX3_PROT_EPI_CS1_OOSERR                          (1UL << 14)
#define FX3_PROT_EPI_CS1_SHORT                           (1UL << 13)
#define FX3_PROT_EPI_CS1_ZERO                            (1UL << 12)
#define FX3_PROT_EPI_CS1_STREAMNRDY                      (1UL << 11)
#define FX3_PROT_EPI_CS1_FLOWCONTROL                     (1UL << 10)
#define FX3_PROT_EPI_CS1_RETRY                           (1UL << 9)
#define FX3_PROT_EPI_CS1_COMMIT                          (1UL << 8)
#define FX3_PROT_EPI_CS1_STREAM_ERROR_STALL_EN           (1UL << 5)
#define FX3_PROT_EPI_CS1_EP_RESET                        (1UL << 4)
#define FX3_PROT_EPI_CS1_STREAM_EN                       (1UL << 3)
#define FX3_PROT_EPI_CS1_STALL                           (1UL << 2)
#define FX3_PROT_EPI_CS1_NRDY                            (1UL << 1)
#define FX3_PROT_EPI_CS1_VALID                           (1UL << 0)

#define FX3_PROT_EPI_CS2_BTERM_NUMP_SHIFT                12
#define FX3_PROT_EPI_CS2_BTERM_NUMP_BITS                 5
#define FX3_PROT_EPI_CS2_BTERM_NUMP_MASK                 (0x1fUL << 12)
#define FX3_PROT_EPI_CS2_MAXBURST_SHIFT                  8
#define FX3_PROT_EPI_CS2_MAXBURST_BITS                   4
#define FX3_PROT_EPI_CS2_MAXBURST_MASK                   (0xfUL << 8)
#define FX3_PROT_EPI_CS2_ISOINPKS_SHIFT                  2
#define FX3_PROT_EPI_CS2_ISOINPKS_BITS                   6
#define FX3_PROT_EPI_CS2_ISOINPKS_MASK                   (0x3fUL << 2)
#define FX3_PROT_EPI_CS2_TYPE_SHIFT                      0
#define FX3_PROT_EPI_CS2_TYPE_BITS                       2
#define FX3_PROT_EPI_CS2_TYPE_MASK                       (0x3UL << 0)

#define FX3_PROT_EPI_UNMAPPED_STREAM_SPSM_STATE_SHIFT    16
#define FX3_PROT_EPI_UNMAPPED_STREAM_SPSM_STATE_BITS     4
#define FX3_PROT_EPI_UNMAPPED_STREAM_SPSM_STATE_MASK     (0xfUL << 16)
#define FX3_PROT_EPI_UNMAPPED_STREAM_STREAM_ID_SHIFT     0
#define FX3_PROT_EPI_UNMAPPED_STREAM_STREAM_ID_BITS      16
#define FX3_PROT_EPI_UNMAPPED_STREAM_STREAM_ID_MASK      (0xffffUL << 0)

#define FX3_PROT_EPI_MAPPED_STREAM_ENABLE                (1UL << 31)
#define FX3_PROT_EPI_MAPPED_STREAM_UNMAP                 (1UL << 30)
#define FX3_PROT_EPI_MAPPED_STREAM_UNMAPPED              (1UL << 29)
#define FX3_PROT_EPI_MAPPED_STREAM_EP_NUMBER_SHIFT       16
#define FX3_PROT_EPI_MAPPED_STREAM_EP_NUMBER_BITS        4
#define FX3_PROT_EPI_MAPPED_STREAM_EP_NUMBER_MASK        (0xfUL << 16)
#define FX3_PROT_EPI_MAPPED_STREAM_STREAM_ID_SHIFT       0
#define FX3_PROT_EPI_MAPPED_STREAM_STREAM_ID_BITS        16
#define FX3_PROT_EPI_MAPPED_STREAM_STREAM_ID_MASK        (0xffffUL << 0)

#define FX3_PROT_EPO_CS1_FIRST_ACK_NUMP_0_MASK           (1UL << 29)
#define FX3_PROT_EPO_CS1_STREAM_ERROR_MASK               (1UL << 28)
#define FX3_PROT_EPO_CS1_DBTERM_MASK                     (1UL << 27)
#define FX3_PROT_EPO_CS1_HBTERM_MASK                     (1UL << 26)
#define FX3_PROT_EPO_CS1_OOSERR_MASK                     (1UL << 25)
#define FX3_PROT_EPO_CS1_SHORT_MASK                      (1UL << 24)
#define FX3_PROT_EPO_CS1_ZERO_MASK                       (1UL << 23)
#define FX3_PROT_EPO_CS1_STREAMNRDY_MASK                 (1UL << 22)
#define FX3_PROT_EPO_CS1_FLOWCONTROL_MASK                (1UL << 21)
#define FX3_PROT_EPO_CS1_RETRY_MASK                      (1UL << 20)
#define FX3_PROT_EPO_CS1_COMMIT_MASK                     (1UL << 19)
#define FX3_PROT_EPO_CS1_FIRST_ACK_NUMP_0                (1UL << 18)
#define FX3_PROT_EPO_CS1_STREAM_ERROR                    (1UL << 17)
#define FX3_PROT_EPO_CS1_DBTERM                          (1UL << 16)
#define FX3_PROT_EPO_CS1_HBTERM                          (1UL << 15)
#define FX3_PROT_EPO_CS1_OOSERR                          (1UL << 14)
#define FX3_PROT_EPO_CS1_SHORT                           (1UL << 13)
#define FX3_PROT_EPO_CS1_ZERO                            (1UL << 12)
#define FX3_PROT_EPO_CS1_STREAMNRDY                      (1UL << 11)
#define FX3_PROT_EPO_CS1_FLOWCONTROL                     (1UL << 10)
#define FX3_PROT_EPO_CS1_RETRY                           (1UL << 9)
#define FX3_PROT_EPO_CS1_COMMIT                          (1UL << 8)
#define FX3_PROT_EPO_CS1_STREAM_ERROR_STALL_EN           (1UL << 5)
#define FX3_PROT_EPO_CS1_EP_RESET                        (1UL << 4)
#define FX3_PROT_EPO_CS1_STREAM_EN                       (1UL << 3)
#define FX3_PROT_EPO_CS1_STALL                           (1UL << 2)
#define FX3_PROT_EPO_CS1_NRDY                            (1UL << 1)
#define FX3_PROT_EPO_CS1_VALID                           (1UL << 0)

#define FX3_PROT_EPO_CS2_MAXBURST_SHIFT                  8
#define FX3_PROT_EPO_CS2_MAXBURST_BITS                   4
#define FX3_PROT_EPO_CS2_MAXBURST_MASK                   (0xfUL << 8)
#define FX3_PROT_EPO_CS2_ISOINPKS_SHIFT                  2
#define FX3_PROT_EPO_CS2_ISOINPKS_BITS                   6
#define FX3_PROT_EPO_CS2_ISOINPKS_MASK                   (0x3fUL << 2)
#define FX3_PROT_EPO_CS2_TYPE_SHIFT                      0
#define FX3_PROT_EPO_CS2_TYPE_BITS                       2
#define FX3_PROT_EPO_CS2_TYPE_MASK                       (0x3UL << 0)

#define FX3_PROT_EPO_UNMAPPED_STREAM_SPSM_STATE_SHIFT    16
#define FX3_PROT_EPO_UNMAPPED_STREAM_SPSM_STATE_BITS     4
#define FX3_PROT_EPO_UNMAPPED_STREAM_SPSM_STATE_MASK     (0xfUL << 16)
#define FX3_PROT_EPO_UNMAPPED_STREAM_STREAM_ID_SHIFT     0
#define FX3_PROT_EPO_UNMAPPED_STREAM_STREAM_ID_BITS      16
#define FX3_PROT_EPO_UNMAPPED_STREAM_STREAM_ID_MASK      (0xffffUL << 0)

#define FX3_PROT_EPO_MAPPED_STREAM_ENABLE                (1UL << 31)
#define FX3_PROT_EPO_MAPPED_STREAM_UNMAP                 (1UL << 30)
#define FX3_PROT_EPO_MAPPED_STREAM_UNMAPPED              (1UL << 29)
#define FX3_PROT_EPO_MAPPED_STREAM_EP_NUMBER_SHIFT       16
#define FX3_PROT_EPO_MAPPED_STREAM_EP_NUMBER_BITS        4
#define FX3_PROT_EPO_MAPPED_STREAM_EP_NUMBER_MASK        (0xfUL << 16)
#define FX3_PROT_EPO_MAPPED_STREAM_STREAM_ID_SHIFT       0
#define FX3_PROT_EPO_MAPPED_STREAM_STREAM_ID_BITS        16
#define FX3_PROT_EPO_MAPPED_STREAM_STREAM_ID_MASK        (0xffffUL << 0)

#define FX3_UIB_ID_BLOCK_VERSION_SHIFT                   16
#define FX3_UIB_ID_BLOCK_VERSION_BITS                    16
#define FX3_UIB_ID_BLOCK_VERSION_MASK                    (0xffffUL << 16)
#define FX3_UIB_ID_BLOCK_ID_SHIFT                        0
#define FX3_UIB_ID_BLOCK_ID_BITS                         16
#define FX3_UIB_ID_BLOCK_ID_MASK                         (0xffffUL << 0)

#define FX3_UIB_POWER_RESETN                             (1UL << 31)
#define FX3_UIB_POWER_ACTIVE                             (1UL << 0)

#endif /* RDB_UIB_H_ */
