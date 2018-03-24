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

#ifndef RDB_GCTL_H_
#define RDB_GCTL_H_

#define FX3_GCTL_CONTROL                      0xE0050000 /* Global control */
#define FX3_GCTL_WAKEUP_EN                    0xE0050004 /* Wakeup Enable Register */
#define FX3_GCTL_WAKEUP_POLARITY              0xE0050008 /* Wakeup Signal Polarity Register */
#define FX3_GCTL_WAKEUP_EVENT                 0xE005000C /* Wakeup Event Register */
#define FX3_GCTL_FREEZE                       0xE0050010 /* I/O Freeze Control Register */
#define FX3_GCTL_WATCHDOG_CS                  0xE0050014 /* Watchdog Timers Command and Control Register */
#define FX3_GCTL_WATCHDOG_TIMER0              0xE0050018 /* Watchdog Timer Value 0 Register */
#define FX3_GCTL_WATCHDOG_TIMER1              0xE005001C /* Watchdog Timer Value 1 Register */
#define FX3_GCTL_IOMATRIX                     0xE0051008 /* I/O Matrix Configuration Register */
#define FX3_GCTL_GPIO_SIMPLE                  0xE005100C /* GPIO Override Configuration Register */
#define FX3_GCTL_GPIO_COMPLEX                 0xE0051014 /* GPIO Override Configuration Register */
#define FX3_GCTL_DS                           0xE005101C /* I/O Drive Strength Configuration Register */
#define FX3_GCTL_WPU_CFG                      0xE0051020 /* I/O Pull-Up Configuration Register */
#define FX3_GCTL_WPD_CFG                      0xE0051028 /* I/O Pull-Down Configuration Register */
#define FX3_GCTL_IOPOWER                      0xE0051030 /* I/O Power Observability Register */
#define FX3_GCTL_IOPOWER_INTR                 0xE0051034 /* I/O Power Change Interrupt Register */
#define FX3_GCTL_IOPOWER_INTR_MASK            0xE0051038 /* I/O Power Change Interrupt Mask Register */
#define FX3_GCTL_SW_INT                       0xE005104C /* Software Interrupt Register */
#define FX3_GCTL_PLL_CFG                      0xE0052000 /* PLL Configuration Register */
#define FX3_GCTL_CPU_CLK_CFG                  0xE0052004 /* CPU and Bus Clock Configuration Register */
#define FX3_GCTL_UIB_CORE_CLK                 0xE0052008 /* UIB Clock Configuration Register */
#define FX3_GCTL_PIB_CORE_CLK                 0xE005200C /* PIB Clock Configuration Register */
#define FX3_GCTL_GPIO_FAST_CLK                0xE0052018 /* GPIO Fast Clock Configuration Register */
#define FX3_GCTL_GPIO_SLOW_CLK                0xE005201C /* GPIO Slow Clock Configuration Register */
#define FX3_GCTL_I2C_CORE_CLK                 0xE0052020 /* I²C Core Clock Configuration Register */
#define FX3_GCTL_UART_CORE_CLK                0xE0052024 /* UART Core Clock Configuration Register */
#define FX3_GCTL_SPI_CORE_CLK                 0xE005202C /* SPI Core Clock Configuration Register */
#define FX3_GCTL_I2S_CORE_CLK                 0xE0052034 /* I2S Core Clock Configuration Register */

#define FX3_GCTL_CONTROL_HARD_RESET_N                    (1UL << 31)
#define FX3_GCTL_CONTROL_CPU_RESET_N                     (1UL << 30)
#define FX3_GCTL_CONTROL_WARM_BOOT                       (1UL << 29)
#define FX3_GCTL_CONTROL_BOOTROM_EN                      (1UL << 28)
#define FX3_GCTL_CONTROL_MAIN_POWER_EN                   (1UL << 26)
#define FX3_GCTL_CONTROL_MAIN_CLOCK_EN                   (1UL << 25)
#define FX3_GCTL_CONTROL_FREEZE_IO                       (1UL << 24)
#define FX3_GCTL_CONTROL_USB_VBAT_EN                     (1UL << 22)
#define FX3_GCTL_CONTROL_USB_POWER_EN                    (1UL << 21)
#define FX3_GCTL_CONTROL_ANALOG_SWITCH                   (1UL << 18)
#define FX3_GCTL_CONTROL_WDT_PROTECT_SHIFT               16
#define FX3_GCTL_CONTROL_WDT_PROTECT_BITS                2
#define FX3_GCTL_CONTROL_WDT_PROTECT_MASK                (0x3UL << 16)
#define FX3_GCTL_CONTROL_NO_SBYWFI                       (1UL << 15)
#define FX3_GCTL_CONTROL_SYSMEM_BIST_EN                  (1UL << 14)
#define FX3_GCTL_CONTROL_WAKEUP_CPU_INT                  (1UL << 12)
#define FX3_GCTL_CONTROL_WAKEUP_AP_INT                   (1UL << 11)
#define FX3_GCTL_CONTROL_RAM_SLEEP                       (1UL << 10)
#define FX3_GCTL_CONTROL_DEBUG_MODE                      (1UL << 9)
#define FX3_GCTL_CONTROL_BOOT_COMPLETE                   (1UL << 8)
#define FX3_GCTL_CONTROL_WAKEUP_CLK                      (1UL << 4)
#define FX3_GCTL_CONTROL_WAKEUP_PWR                      (1UL << 3)
#define FX3_GCTL_CONTROL_WDT_RESET                       (1UL << 2)
#define FX3_GCTL_CONTROL_SW_RESET                        (1UL << 1)
#define FX3_GCTL_CONTROL_POR                             (1UL << 0)

#define FX3_GCTL_WAKEUP_EN_EN_WATCHDOG2                  (1UL << 13)
#define FX3_GCTL_WAKEUP_EN_EN_WATCHDOG1                  (1UL << 12)
#define FX3_GCTL_WAKEUP_EN_EN_UIB_VBUS                   (1UL << 11)
#define FX3_GCTL_WAKEUP_EN_EN_UIB_SSRX                   (1UL << 10)
#define FX3_GCTL_WAKEUP_EN_EN_UIB_OTGID                  (1UL << 9)
#define FX3_GCTL_WAKEUP_EN_EN_UIB_DM                     (1UL << 8)
#define FX3_GCTL_WAKEUP_EN_EN_UIB_DP                     (1UL << 7)
#define FX3_GCTL_WAKEUP_EN_EN_UART_CTS                   (1UL << 6)
#define FX3_GCTL_WAKEUP_EN_EN_GPIO_44                    (1UL << 5)
#define FX3_GCTL_WAKEUP_EN_EN_GPIO_47                    (1UL << 4)
#define FX3_GCTL_WAKEUP_EN_EN_GPIO_34                    (1UL << 3)
#define FX3_GCTL_WAKEUP_EN_EN_PIB_CLK                    (1UL << 2)
#define FX3_GCTL_WAKEUP_EN_EN_PIB_CMD                    (1UL << 1)
#define FX3_GCTL_WAKEUP_EN_EN_PIB_CTRL0                  (1UL << 0)

#define FX3_GCTL_WAKEUP_POLARITY_POL_UIB_VBUS            (1UL << 11)
#define FX3_GCTL_WAKEUP_POLARITY_POL_UIB_DM              (1UL << 8)
#define FX3_GCTL_WAKEUP_POLARITY_POL_UIB_DP              (1UL << 7)
#define FX3_GCTL_WAKEUP_POLARITY_POL_UART_CTS            (1UL << 6)
#define FX3_GCTL_WAKEUP_POLARITY_POL_GPIO_44             (1UL << 5)
#define FX3_GCTL_WAKEUP_POLARITY_POL_GPIO_47             (1UL << 4)
#define FX3_GCTL_WAKEUP_POLARITY_POL_GPIO_34             (1UL << 3)

#define FX3_GCTL_WAKEUP_EVENT_EV_WATCHDOG2               (1UL << 13)
#define FX3_GCTL_WAKEUP_EVENT_EV_WATCHDOG1               (1UL << 12)
#define FX3_GCTL_WAKEUP_EVENT_EV_UIB_VBUS                (1UL << 11)
#define FX3_GCTL_WAKEUP_EVENT_EV_UIB_SSRX                (1UL << 10)
#define FX3_GCTL_WAKEUP_EVENT_EV_UIB_OTGID               (1UL << 9)
#define FX3_GCTL_WAKEUP_EVENT_EV_UIB_DM                  (1UL << 8)
#define FX3_GCTL_WAKEUP_EVENT_EV_UIB_DP                  (1UL << 7)
#define FX3_GCTL_WAKEUP_EVENT_EV_UART_CTS                (1UL << 6)
#define FX3_GCTL_WAKEUP_EVENT_EV_GPIO_44                 (1UL << 5)
#define FX3_GCTL_WAKEUP_EVENT_EV_GPIO_47                 (1UL << 4)
#define FX3_GCTL_WAKEUP_EVENT_EV_GPIO_34                 (1UL << 3)
#define FX3_GCTL_WAKEUP_EVENT_EV_PIB_CLK                 (1UL << 2)
#define FX3_GCTL_WAKEUP_EVENT_EV_PIB_CMD                 (1UL << 1)
#define FX3_GCTL_WAKEUP_EVENT_EV_PIB_CTRL0               (1UL << 0)

#define FX3_GCTL_FREEZE_VIO4IO_FRZ_SHIFT                 6
#define FX3_GCTL_FREEZE_VIO4IO_FRZ_BITS                  2
#define FX3_GCTL_FREEZE_VIO4IO_FRZ_MASK                  (0x3UL << 6)
#define FX3_GCTL_FREEZE_VIO3IO_FRZ_SHIFT                 4
#define FX3_GCTL_FREEZE_VIO3IO_FRZ_BITS                  2
#define FX3_GCTL_FREEZE_VIO3IO_FRZ_MASK                  (0x3UL << 4)
#define FX3_GCTL_FREEZE_VIO2IO_FRZ_SHIFT                 2
#define FX3_GCTL_FREEZE_VIO2IO_FRZ_BITS                  2
#define FX3_GCTL_FREEZE_VIO2IO_FRZ_MASK                  (0x3UL << 2)
#define FX3_GCTL_FREEZE_VIO1IO_FRZ_SHIFT                 0
#define FX3_GCTL_FREEZE_VIO1IO_FRZ_BITS                  2
#define FX3_GCTL_FREEZE_VIO1IO_FRZ_MASK                  (0x3UL << 0)

#define FX3_GCTL_WATCHDOG_CS_BACKUP_CLK                  (1UL << 31)
#define FX3_GCTL_WATCHDOG_CS_BACKUP_DIVIDER_SHIFT        16
#define FX3_GCTL_WATCHDOG_CS_BACKUP_DIVIDER_BITS         15
#define FX3_GCTL_WATCHDOG_CS_BACKUP_DIVIDER_MASK         (0x7fffUL << 16)
#define FX3_GCTL_WATCHDOG_CS_BITS1_SHIFT                 11
#define FX3_GCTL_WATCHDOG_CS_BITS1_BITS                  5
#define FX3_GCTL_WATCHDOG_CS_BITS1_MASK                  (0x1fUL << 11)
#define FX3_GCTL_WATCHDOG_CS_INTR1                       (1UL << 10)
#define FX3_GCTL_WATCHDOG_CS_MODE1_SHIFT                 8
#define FX3_GCTL_WATCHDOG_CS_MODE1_BITS                  2
#define FX3_GCTL_WATCHDOG_CS_MODE1_MASK                  (0x3UL << 8)
#define FX3_GCTL_WATCHDOG_CS_BITS0_SHIFT                 3
#define FX3_GCTL_WATCHDOG_CS_BITS0_BITS                  5
#define FX3_GCTL_WATCHDOG_CS_BITS0_MASK                  (0x1fUL << 3)
#define FX3_GCTL_WATCHDOG_CS_INTR0                       (1UL << 2)
#define FX3_GCTL_WATCHDOG_CS_MODE0_SHIFT                 0
#define FX3_GCTL_WATCHDOG_CS_MODE0_BITS                  2
#define FX3_GCTL_WATCHDOG_CS_MODE0_MASK                  (0x3UL << 0)

#define FX3_GCTL_IOMATRIX_S1CFG_SHIFT                    8
#define FX3_GCTL_IOMATRIX_S1CFG_BITS                     3
#define FX3_GCTL_IOMATRIX_S1CFG_MASK                     (0x7UL << 8)
#define FX3_GCTL_IOMATRIX_S0CFG                          (1UL << 4)
#define FX3_GCTL_IOMATRIX_CARKIT                         (1UL << 1)

#define FX3_GCTL_GPIO_SIMPLE_OVERRIDE_SHIFT              0
#define FX3_GCTL_GPIO_SIMPLE_OVERRIDE_BITS               61
#define FX3_GCTL_GPIO_SIMPLE_OVERRIDE_MASK               (0x1fffffffffffffffUL << 0)

#define FX3_GCTL_GPIO_COMPLEX_OVERRIDE_SHIFT             0
#define FX3_GCTL_GPIO_COMPLEX_OVERRIDE_BITS              61
#define FX3_GCTL_GPIO_COMPLEX_OVERRIDE_MASK              (0x1fffffffffffffffUL << 0)

#define FX3_GCTL_DS_I2CDS_G_SHIFT                        18
#define FX3_GCTL_DS_I2CDS_G_BITS                         2
#define FX3_GCTL_DS_I2CDS_G_MASK                         (0x3UL << 18)
#define FX3_GCTL_DS_S1LDS_G_SHIFT                        16
#define FX3_GCTL_DS_S1LDS_G_BITS                         2
#define FX3_GCTL_DS_S1LDS_G_MASK                         (0x3UL << 16)
#define FX3_GCTL_DS_S1DS_G_SHIFT                         14
#define FX3_GCTL_DS_S1DS_G_BITS                          2
#define FX3_GCTL_DS_S1DS_G_MASK                          (0x3UL << 14)
#define FX3_GCTL_DS_S0DS_G_SHIFT                         12
#define FX3_GCTL_DS_S0DS_G_BITS                          2
#define FX3_GCTL_DS_S0DS_G_MASK                          (0x3UL << 12)
#define FX3_GCTL_DS_PDS_G_SHIFT                          10
#define FX3_GCTL_DS_PDS_G_BITS                           2
#define FX3_GCTL_DS_PDS_G_MASK                           (0x3UL << 10)
#define FX3_GCTL_DS_I2CDS_SHIFT                          8
#define FX3_GCTL_DS_I2CDS_BITS                           2
#define FX3_GCTL_DS_I2CDS_MASK                           (0x3UL << 8)
#define FX3_GCTL_DS_S1LDS_SHIFT                          6
#define FX3_GCTL_DS_S1LDS_BITS                           2
#define FX3_GCTL_DS_S1LDS_MASK                           (0x3UL << 6)
#define FX3_GCTL_DS_S1DS_SHIFT                           4
#define FX3_GCTL_DS_S1DS_BITS                            2
#define FX3_GCTL_DS_S1DS_MASK                            (0x3UL << 4)
#define FX3_GCTL_DS_S0DS_SHIFT                           2
#define FX3_GCTL_DS_S0DS_BITS                            2
#define FX3_GCTL_DS_S0DS_MASK                            (0x3UL << 2)
#define FX3_GCTL_DS_PDS_SHIFT                            0
#define FX3_GCTL_DS_PDS_BITS                             2
#define FX3_GCTL_DS_PDS_MASK                             (0x3UL << 0)

#define FX3_GCTL_WPU_CFG_WPU_SHIFT                       0
#define FX3_GCTL_WPU_CFG_WPU_BITS                        60
#define FX3_GCTL_WPU_CFG_WPU_MASK                        (0xfffffffffffffffUL << 0)

#define FX3_GCTL_WPD_CFG_WPD_SHIFT                       0
#define FX3_GCTL_WPD_CFG_WPD_BITS                        60
#define FX3_GCTL_WPD_CFG_WPD_MASK                        (0xfffffffffffffffUL << 0)

#define FX3_GCTL_IOPOWER_REG_BYPASS_EN                   (1UL << 21)
#define FX3_GCTL_IOPOWER_REG_CARKIT_EN                   (1UL << 20)
#define FX3_GCTL_IOPOWER_REG_CARKIT_SEL_SHIFT            18
#define FX3_GCTL_IOPOWER_REG_CARKIT_SEL_BITS             2
#define FX3_GCTL_IOPOWER_REG_CARKIT_SEL_MASK             (0x3UL << 18)
#define FX3_GCTL_IOPOWER_USB_REGULATOR_TRIM_SHIFT        16
#define FX3_GCTL_IOPOWER_USB_REGULATOR_TRIM_BITS         2
#define FX3_GCTL_IOPOWER_USB_REGULATOR_TRIM_MASK         (0x3UL << 16)
#define FX3_GCTL_IOPOWER_USB_POWER_GOOD                  (1UL << 13)
#define FX3_GCTL_IOPOWER_VBUS_TH                         (1UL << 12)
#define FX3_GCTL_IOPOWER_VBAT                            (1UL << 11)
#define FX3_GCTL_IOPOWER_VBUS                            (1UL << 10)
#define FX3_GCTL_IOPOWER_USB25REG                        (1UL << 9)
#define FX3_GCTL_IOPOWER_USB33REG                        (1UL << 8)
#define FX3_GCTL_IOPOWER_VIO5                            (1UL << 7)
#define FX3_GCTL_IOPOWER_CVDDQ                           (1UL << 6)
#define FX3_GCTL_IOPOWER_EFVDDQ                          (1UL << 5)
#define FX3_GCTL_IOPOWER_VIO4                            (1UL << 4)
#define FX3_GCTL_IOPOWER_VIO3                            (1UL << 3)
#define FX3_GCTL_IOPOWER_VIO2                            (1UL << 2)
#define FX3_GCTL_IOPOWER_VIO1                            (1UL << 0)

#define FX3_GCTL_IOPOWER_INTR_USB_POWER_GOOD             (1UL << 13)
#define FX3_GCTL_IOPOWER_INTR_VBUS_TH                    (1UL << 12)
#define FX3_GCTL_IOPOWER_INTR_VBAT                       (1UL << 11)
#define FX3_GCTL_IOPOWER_INTR_VBUS                       (1UL << 10)
#define FX3_GCTL_IOPOWER_INTR_USB25REG                   (1UL << 9)
#define FX3_GCTL_IOPOWER_INTR_USB33REG                   (1UL << 8)
#define FX3_GCTL_IOPOWER_INTR_VIO5                       (1UL << 7)
#define FX3_GCTL_IOPOWER_INTR_CVDDQ                      (1UL << 6)
#define FX3_GCTL_IOPOWER_INTR_EFVDDQ                     (1UL << 5)
#define FX3_GCTL_IOPOWER_INTR_VIO4                       (1UL << 4)
#define FX3_GCTL_IOPOWER_INTR_VIO3                       (1UL << 3)
#define FX3_GCTL_IOPOWER_INTR_VIO2                       (1UL << 2)
#define FX3_GCTL_IOPOWER_INTR_VIO1                       (1UL << 0)

#define FX3_GCTL_IOPOWER_INTR_MASK_USB_POWER_GOOD        (1UL << 13)
#define FX3_GCTL_IOPOWER_INTR_MASK_VBUS_TH               (1UL << 12)
#define FX3_GCTL_IOPOWER_INTR_MASK_VBAT                  (1UL << 11)
#define FX3_GCTL_IOPOWER_INTR_MASK_VBUS                  (1UL << 10)
#define FX3_GCTL_IOPOWER_INTR_MASK_USB25REG              (1UL << 9)
#define FX3_GCTL_IOPOWER_INTR_MASK_USB33REG              (1UL << 8)
#define FX3_GCTL_IOPOWER_INTR_MASK_VIO5                  (1UL << 7)
#define FX3_GCTL_IOPOWER_INTR_MASK_CVDDQ                 (1UL << 6)
#define FX3_GCTL_IOPOWER_INTR_MASK_EFVDDQ                (1UL << 5)
#define FX3_GCTL_IOPOWER_INTR_MASK_VIO4                  (1UL << 4)
#define FX3_GCTL_IOPOWER_INTR_MASK_VIO3                  (1UL << 3)
#define FX3_GCTL_IOPOWER_INTR_MASK_VIO2                  (1UL << 2)
#define FX3_GCTL_IOPOWER_INTR_MASK_VIO1                  (1UL << 0)

#define FX3_GCTL_SW_INT_SWINT                            (1UL << 31)
#define FX3_GCTL_SW_INT_ARGUMENT_SHIFT                   0
#define FX3_GCTL_SW_INT_ARGUMENT_BITS                    31
#define FX3_GCTL_SW_INT_ARGUMENT_MASK                    (0x7fffffffUL << 0)

#define FX3_GCTL_PLL_CFG_PLL_LOCK                        (1UL << 19)
#define FX3_GCTL_PLL_CFG_FSLC_SHIFT                      16
#define FX3_GCTL_PLL_CFG_FSLC_BITS                       3
#define FX3_GCTL_PLL_CFG_FSLC_MASK                       (0x7UL << 16)
#define FX3_GCTL_PLL_CFG_CP_CFG_SHIFT                    12
#define FX3_GCTL_PLL_CFG_CP_CFG_BITS                     2
#define FX3_GCTL_PLL_CFG_CP_CFG_MASK                     (0x3UL << 12)
#define FX3_GCTL_PLL_CFG_REFDIV                          (1UL << 8)
#define FX3_GCTL_PLL_CFG_OUTDIV_SHIFT                    6
#define FX3_GCTL_PLL_CFG_OUTDIV_BITS                     2
#define FX3_GCTL_PLL_CFG_OUTDIV_MASK                     (0x3UL << 6)
#define FX3_GCTL_PLL_CFG_FBDIV_SHIFT                     0
#define FX3_GCTL_PLL_CFG_FBDIV_BITS                      6
#define FX3_GCTL_PLL_CFG_FBDIV_MASK                      (0x3fUL << 0)

#define FX3_GCTL_CPU_CLK_CFG_MMIO_DIV_SHIFT              12
#define FX3_GCTL_CPU_CLK_CFG_MMIO_DIV_BITS               4
#define FX3_GCTL_CPU_CLK_CFG_MMIO_DIV_MASK               (0xfUL << 12)
#define FX3_GCTL_CPU_CLK_CFG_DMA_DIV_SHIFT               8
#define FX3_GCTL_CPU_CLK_CFG_DMA_DIV_BITS                4
#define FX3_GCTL_CPU_CLK_CFG_DMA_DIV_MASK                (0xfUL << 8)
#define FX3_GCTL_CPU_CLK_CFG_SRC_SHIFT                   4
#define FX3_GCTL_CPU_CLK_CFG_SRC_BITS                    2
#define FX3_GCTL_CPU_CLK_CFG_SRC_MASK                    (0x3UL << 4)
#define FX3_GCTL_CPU_CLK_CFG_CPU_DIV_SHIFT               0
#define FX3_GCTL_CPU_CLK_CFG_CPU_DIV_BITS                4
#define FX3_GCTL_CPU_CLK_CFG_CPU_DIV_MASK                (0xfUL << 0)

#define FX3_GCTL_UIB_CORE_CLK_CLK_EN                     (1UL << 31)
#define FX3_GCTL_UIB_CORE_CLK_PCLK_SRC_SHIFT             2
#define FX3_GCTL_UIB_CORE_CLK_PCLK_SRC_BITS              2
#define FX3_GCTL_UIB_CORE_CLK_PCLK_SRC_MASK              (0x3UL << 2)
#define FX3_GCTL_UIB_CORE_CLK_EPMCLK_SRC_SHIFT           0
#define FX3_GCTL_UIB_CORE_CLK_EPMCLK_SRC_BITS            2
#define FX3_GCTL_UIB_CORE_CLK_EPMCLK_SRC_MASK            (0x3UL << 0)

#define FX3_GCTL_PIB_CORE_CLK_CLK_EN                     (1UL << 31)
#define FX3_GCTL_PIB_CORE_CLK_SRC_SHIFT                  11
#define FX3_GCTL_PIB_CORE_CLK_SRC_BITS                   2
#define FX3_GCTL_PIB_CORE_CLK_SRC_MASK                   (0x3UL << 11)
#define FX3_GCTL_PIB_CORE_CLK_HALFDIV                    (1UL << 10)
#define FX3_GCTL_PIB_CORE_CLK_DIV_SHIFT                  0
#define FX3_GCTL_PIB_CORE_CLK_DIV_BITS                   10
#define FX3_GCTL_PIB_CORE_CLK_DIV_MASK                   (0x3ffUL << 0)

#define FX3_GCTL_GPIO_FAST_CLK_CLK_EN                    (1UL << 31)
#define FX3_GCTL_GPIO_FAST_CLK_SIMPLE_SHIFT              7
#define FX3_GCTL_GPIO_FAST_CLK_SIMPLE_BITS               2
#define FX3_GCTL_GPIO_FAST_CLK_SIMPLE_MASK               (0x3UL << 7)
#define FX3_GCTL_GPIO_FAST_CLK_SRC_SHIFT                 5
#define FX3_GCTL_GPIO_FAST_CLK_SRC_BITS                  2
#define FX3_GCTL_GPIO_FAST_CLK_SRC_MASK                  (0x3UL << 5)
#define FX3_GCTL_GPIO_FAST_CLK_HALFDIV                   (1UL << 4)
#define FX3_GCTL_GPIO_FAST_CLK_DIV_SHIFT                 0
#define FX3_GCTL_GPIO_FAST_CLK_DIV_BITS                  4
#define FX3_GCTL_GPIO_FAST_CLK_DIV_MASK                  (0xfUL << 0)

#define FX3_GCTL_GPIO_SLOW_CLK_CLK_EN                    (1UL << 31)
#define FX3_GCTL_GPIO_SLOW_CLK_DIV_SHIFT                 0
#define FX3_GCTL_GPIO_SLOW_CLK_DIV_BITS                  6
#define FX3_GCTL_GPIO_SLOW_CLK_DIV_MASK                  (0x3fUL << 0)

#define FX3_GCTL_I2C_CORE_CLK_CLK_EN                     (1UL << 31)
#define FX3_GCTL_I2C_CORE_CLK_SRC_SHIFT                  13
#define FX3_GCTL_I2C_CORE_CLK_SRC_BITS                   2
#define FX3_GCTL_I2C_CORE_CLK_SRC_MASK                   (0x3UL << 13)
#define FX3_GCTL_I2C_CORE_CLK_HALFDIV                    (1UL << 12)
#define FX3_GCTL_I2C_CORE_CLK_DIV_SHIFT                  0
#define FX3_GCTL_I2C_CORE_CLK_DIV_BITS                   12
#define FX3_GCTL_I2C_CORE_CLK_DIV_MASK                   (0xfffUL << 0)

#define FX3_GCTL_UART_CORE_CLK_CLK_EN                    (1UL << 31)
#define FX3_GCTL_UART_CORE_CLK_SRC_SHIFT                 17
#define FX3_GCTL_UART_CORE_CLK_SRC_BITS                  2
#define FX3_GCTL_UART_CORE_CLK_SRC_MASK                  (0x3UL << 17)
#define FX3_GCTL_UART_CORE_CLK_HALFDIV                   (1UL << 16)
#define FX3_GCTL_UART_CORE_CLK_DIV_SHIFT                 0
#define FX3_GCTL_UART_CORE_CLK_DIV_BITS                  16
#define FX3_GCTL_UART_CORE_CLK_DIV_MASK                  (0xffffUL << 0)

#define FX3_GCTL_SPI_CORE_CLK_CLK_EN                     (1UL << 31)
#define FX3_GCTL_SPI_CORE_CLK_SRC_SHIFT                  17
#define FX3_GCTL_SPI_CORE_CLK_SRC_BITS                   2
#define FX3_GCTL_SPI_CORE_CLK_SRC_MASK                   (0x3UL << 17)
#define FX3_GCTL_SPI_CORE_CLK_HALFDIV                    (1UL << 16)
#define FX3_GCTL_SPI_CORE_CLK_DIV_SHIFT                  0
#define FX3_GCTL_SPI_CORE_CLK_DIV_BITS                   16
#define FX3_GCTL_SPI_CORE_CLK_DIV_MASK                   (0xffffUL << 0)

#define FX3_GCTL_I2S_CORE_CLK_CLK_EN                     (1UL << 31)
#define FX3_GCTL_I2S_CORE_CLK_MCLK_IN                    (1UL << 30)
#define FX3_GCTL_I2S_CORE_CLK_SRC_SHIFT                  16
#define FX3_GCTL_I2S_CORE_CLK_SRC_BITS                   2
#define FX3_GCTL_I2S_CORE_CLK_SRC_MASK                   (0x3UL << 16)
#define FX3_GCTL_I2S_CORE_CLK_HALFDIV                    (1UL << 15)
#define FX3_GCTL_I2S_CORE_CLK_DIV_SHIFT                  0
#define FX3_GCTL_I2S_CORE_CLK_DIV_BITS                   15
#define FX3_GCTL_I2S_CORE_CLK_DIV_MASK                   (0x7fffUL << 0)

#endif /* RDB_GCTL_H_ */
