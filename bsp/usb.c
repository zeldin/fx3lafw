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

#include <bsp/usb.h>
#include <bsp/regaccess.h>
#include <bsp/dma.h>
#include <bsp/irq.h>
#include <bsp/util.h>
#include <bsp/uart.h>
#include <rdb/gctl.h>
#include <rdb/uib.h>
#include <rdb/uibin.h>
#include <rdb/vic.h>

static const struct Fx3UsbCallbacks *Fx3UsbUserCallbacks = NULL;

static void Fx3UsbGctlCoreIsr(void) __attribute__ ((isr ("IRQ")));
static void Fx3UsbUsbCoreIsr(void) __attribute__ ((isr ("IRQ")));
static void Fx3UsbGctlPowerIsr(void) __attribute__ ((isr ("IRQ")));

static void Fx3UsbWritePhyReg(uint16_t phy_addr, uint16_t phy_val)
{
  if (!(Fx3ReadReg32(FX3_OTG_CTRL) & FX3_OTG_CTRL_SSDEV_ENABLE))
    return;

  Fx3WriteReg32(0xe0033024, phy_addr);
  Fx3WriteReg32(0xe0033024, phy_addr | (1UL << 16));
  while(!(Fx3ReadReg32(0xe0033028) & (1UL << 16)))
    ;
  Fx3WriteReg32(0xe0033024, phy_addr);
  while((Fx3ReadReg32(0xe0033028) & (1UL << 16)))
    ;
  Fx3WriteReg32(0xe0033024, phy_val);
  Fx3WriteReg32(0xe0033024, phy_val | (1UL << 17));
  while(!(Fx3ReadReg32(0xe0033028) & (1UL << 16)))
    ;
  Fx3WriteReg32(0xe0033024, phy_val);
  while((Fx3ReadReg32(0xe0033028) & (1UL << 16)))
    ;
  Fx3WriteReg32(0xe0033024, phy_val | (1UL << 19));
  while(!(Fx3ReadReg32(0xe0033028) & (1UL << 16)))
    ;
  Fx3WriteReg32(0xe0033024, phy_val);
  while((Fx3ReadReg32(0xe0033028) & (1UL << 16)))
    ;
}

static void Fx3UsbConnectSuperSpeed(void)
{
  Fx3WriteReg32(FX3_LNK_PHY_TX_TRIM, 0x0b569011UL);
  Fx3UsbWritePhyReg(0x1006, 0x180);
  Fx3UsbWritePhyReg(0x1024, 0x0080);

  /* Switch EPM clock to USB 3.0 mode */
  Fx3ClearReg32(FX3_GCTL_UIB_CORE_CLK, FX3_GCTL_UIB_CORE_CLK_CLK_EN);
  Fx3UtilDelayUs(5);
  Fx3WriteReg32(FX3_GCTL_UIB_CORE_CLK,
		(1UL << FX3_GCTL_UIB_CORE_CLK_PCLK_SRC_SHIFT) |
		(1UL << FX3_GCTL_UIB_CORE_CLK_EPMCLK_SRC_SHIFT));
  Fx3SetReg32(FX3_GCTL_UIB_CORE_CLK, FX3_GCTL_UIB_CORE_CLK_CLK_EN);
  Fx3UtilDelayUs(5);

  Fx3WriteReg32(FX3_LNK_PHY_CONF,
		FX3_LNK_PHY_CONF_RX_TERMINATION_ENABLE |
		FX3_LNK_PHY_CONF_RX_TERMINATION_OVR_VAL |
		FX3_LNK_PHY_CONF_RX_TERMINATION_OVR |
		(1UL << FX3_LNK_PHY_CONF_PHY_MODE_SHIFT));
  Fx3SetReg32(FX3_OTG_CTRL, FX3_OTG_CTRL_SSEPM_ENABLE);
  
  /* Reset EPM mux */
  Fx3SetReg32(FX3_IEPM_CS,
	      FX3_IEPM_CS_EPM_MUX_RESET |
	      FX3_IEPM_CS_EPM_FLUSH);
  Fx3UtilDelayUs(1);
  Fx3ClearReg32(FX3_IEPM_CS,
		FX3_IEPM_CS_EPM_MUX_RESET |
		FX3_IEPM_CS_EPM_FLUSH);
  Fx3UtilDelayUs(1);

  Fx3UsbWritePhyReg(0x0030, 0x00c0);
  Fx3UsbWritePhyReg(0x1010, 0x0080);
  
  Fx3WriteReg32(FX3_EEPM_ENDPOINT+0,
		(512UL << FX3_EEPM_ENDPOINT_PACKET_SIZE_SHIFT));
  Fx3WriteReg32(FX3_IEPM_ENDPOINT+0,
		(512UL << FX3_IEPM_ENDPOINT_PACKET_SIZE_SHIFT));
}

static void Fx3UsbEnablePhy(void)
{
  Fx3WriteReg32(FX3_OTG_INTR, ~0UL);
  Fx3WriteReg32(FX3_LNK_INTR, ~0UL);
  Fx3WriteReg32(FX3_LNK_INTR_MASK,
		FX3_LNK_INTR_MASK_LTSSM_RESET |
		FX3_LNK_INTR_MASK_LTSSM_DISCONNECT |
		FX3_LNK_INTR_MASK_LTSSM_CONNECT |
		FX3_LNK_INTR_MASK_LGO_U3 |
		FX3_LNK_INTR_MASK_LTSSM_STATE_CHG);
  Fx3WriteReg32(FX3_PROT_EP_INTR_MASK, 0);
  Fx3WriteReg32(FX3_PROT_INTR, ~0UL);
  Fx3WriteReg32(FX3_PROT_INTR_MASK,
		FX3_PROT_INTR_MASK_STATUS_STAGE |
		FX3_PROT_INTR_MASK_SUTOK_EN |
		FX3_PROT_INTR_MASK_TIMEOUT_PORT_CFG_EN |
		FX3_PROT_INTR_MASK_TIMEOUT_PORT_CAP_EN |
		FX3_PROT_INTR_MASK_LMP_PORT_CFG_EN |
		FX3_PROT_INTR_MASK_LMP_PORT_CAP_EN |
		FX3_PROT_INTR_MASK_LMP_RCV_EN);
  Fx3WriteReg32(FX3_DEV_CTRL_INTR, ~0UL);
  Fx3WriteReg32(FX3_DEV_CTRL_INTR_MASK,
		FX3_DEV_CTRL_INTR_MASK_URESUME |
		FX3_DEV_CTRL_INTR_MASK_SUDAV |
		FX3_DEV_CTRL_INTR_MASK_HSGRANT |
		FX3_DEV_CTRL_INTR_MASK_URESET |
		FX3_DEV_CTRL_INTR_MASK_SUSP);
  Fx3WriteReg32(FX3_DEV_EP_INTR, ~0UL);
  Fx3WriteReg32(FX3_DEV_EP_INTR_MASK, 0);
  Fx3WriteReg32(FX3_UIB_INTR_MASK,
		FX3_UIB_INTR_MASK_PROT_INT |
		FX3_UIB_INTR_MASK_LNK_INT |
		FX3_UIB_INTR_MASK_DEV_CTL_INT);
  Fx3WriteReg32(FX3_VIC_INT_ENABLE, (1UL << FX3_IRQ_USB_CORE));
  Fx3SetReg32(FX3_GCTL_CONTROL, FX3_GCTL_CONTROL_USB_POWER_EN);

  /* Setup LNK for superspeed */
  Fx3WriteReg32(FX3_LNK_DEVICE_POWER_CONTROL,
		FX3_LNK_DEVICE_POWER_CONTROL_AUTO_U2 |
		FX3_LNK_DEVICE_POWER_CONTROL_AUTO_U1);
  Fx3WriteReg32(0xe003309c, 10000);
  Fx3WriteReg32(0xe0033080, 10000);
  Fx3WriteReg32(0xe0033084, 0x00fa004b);
  Fx3WriteReg32(0xe00330c4, 0x00000177);
  Fx3WriteReg32(0xe0033078, 0x58);
  Fx3WriteReg32(FX3_PROT_LMP_PORT_CAPABILITY_TIMER, 2312);
  Fx3WriteReg32(FX3_PROT_LMP_PORT_CONFIGURATION_TIMER, 2312);
  Fx3SetReg32(FX3_LNK_COMPLIANCE_PATTERN_8,
	      FX3_LNK_COMPLIANCE_PATTERN_8_LFPS);
  Fx3WriteReg32(FX3_LNK_PHY_CONF,
		FX3_LNK_PHY_CONF_RX_TERMINATION_OVR |
		(1UL << FX3_LNK_PHY_CONF_PHY_MODE_SHIFT));
  uint32_t old_int_enable = Fx3ReadReg32(FX3_VIC_INT_ENABLE);
  Fx3WriteReg32(FX3_VIC_INT_CLEAR, ~0UL);
  Fx3ClearReg32(FX3_GCTL_UIB_CORE_CLK, FX3_GCTL_UIB_CORE_CLK_CLK_EN);
  Fx3UtilDelayUs(5);
  Fx3WriteReg32(FX3_GCTL_UIB_CORE_CLK,
		(2UL << FX3_GCTL_UIB_CORE_CLK_PCLK_SRC_SHIFT) |
		(2UL << FX3_GCTL_UIB_CORE_CLK_EPMCLK_SRC_SHIFT));
  Fx3SetReg32(FX3_GCTL_UIB_CORE_CLK, FX3_GCTL_UIB_CORE_CLK_CLK_EN);
  Fx3UtilDelayUs(5);
  Fx3WriteReg32(FX3_LNK_LTSSM_STATE,
		(0UL << FX3_LNK_LTSSM_STATE_LTSSM_OVERRIDE_VALUE_SHIFT) |
		FX3_LNK_LTSSM_STATE_LTSSM_OVERRIDE_EN);
  Fx3SetReg32(FX3_OTG_CTRL, FX3_OTG_CTRL_SSDEV_ENABLE);
  Fx3UtilDelayUs(100);
  Fx3SetField32(FX3_LNK_CONF, EPM_FIRST_DELAY, 15UL);
  Fx3SetReg32(FX3_LNK_CONF, FX3_LNK_CONF_LDN_DETECTION);
  Fx3WriteReg32(FX3_LNK_PHY_MPLL_STATUS,
		FX3_LNK_PHY_MPLL_STATUS_REF_SSP_EN |
		(136UL << FX3_LNK_PHY_MPLL_STATUS_SSC_REF_CLK_SEL_SHIFT) |
		(0UL << FX3_LNK_PHY_MPLL_STATUS_SSC_RANGE_SHIFT) |
		FX3_LNK_PHY_MPLL_STATUS_SSC_EN |
		(3UL << FX3_LNK_PHY_MPLL_STATUS_MPLL_MULTIPLIER_SHIFT));
  Fx3UsbWritePhyReg(0x30, 0xc0);
  Fx3ClearReg32(FX3_LNK_LTSSM_STATE, FX3_LNK_LTSSM_STATE_LTSSM_OVERRIDE_EN);
  Fx3WriteReg32(FX3_LNK_PHY_CONF,
		FX3_LNK_PHY_CONF_RX_TERMINATION_ENABLE |
		FX3_LNK_PHY_CONF_RX_TERMINATION_OVR_VAL |
		FX3_LNK_PHY_CONF_RX_TERMINATION_OVR |
		(1UL << FX3_LNK_PHY_CONF_PHY_MODE_SHIFT));
  Fx3UtilDelayUs(100);
  Fx3WriteReg32(FX3_GCTL_UIB_CORE_CLK,
		FX3_GCTL_UIB_CORE_CLK_CLK_EN |
		(1UL << FX3_GCTL_UIB_CORE_CLK_PCLK_SRC_SHIFT) |
		(1UL << FX3_GCTL_UIB_CORE_CLK_EPMCLK_SRC_SHIFT));
  Fx3WriteReg32(FX3_VIC_INT_ENABLE, old_int_enable);
}

void Fx3UsbConnect(void)
{
  Fx3WriteReg32(FX3_GCTL_IOPOWER_INTR, ~0UL);
  Fx3WriteReg32(FX3_GCTL_IOPOWER_INTR_MASK, FX3_GCTL_IOPOWER_INTR_MASK_VBUS);
  Fx3WriteReg32(FX3_VIC_INT_ENABLE, (1UL << FX3_IRQ_GCTL_POWER));
  if (Fx3ReadReg32(FX3_GCTL_IOPOWER) & FX3_GCTL_IOPOWER_VBUS) {
    Fx3UartTxString("VBUS POWER!\n");
    Fx3UsbEnablePhy();
  }
}

void Fx3UsbStallEp0(void)
{
  Fx3UartTxString("STALL EP0!\n");
  
  Fx3SetReg32(FX3_PROT_EPI_CS1+0, FX3_PROT_EPI_CS1_STALL);
  Fx3SetReg32(FX3_PROT_EPO_CS1+0, FX3_PROT_EPO_CS1_STALL);
  Fx3UtilDelayUs(1);
  Fx3SetReg32(FX3_PROT_CS, FX3_PROT_CS_SETUP_CLR_BUSY);
}

void Fx3UsbUnstallEp0(void)
{
  Fx3ClearReg32(FX3_PROT_EPI_CS1+0, FX3_PROT_EPI_CS1_STALL);
  Fx3ClearReg32(FX3_PROT_EPO_CS1+0, FX3_PROT_EPO_CS1_STALL);
  Fx3UtilDelayUs(1);
  Fx3SetReg32(FX3_PROT_CS, FX3_PROT_CS_SETUP_CLR_BUSY);
}

void Fx3UsbDmaDataOut(uint8_t ep, volatile void *buffer, uint16_t length)
{
  uint16_t d = Fx3DmaAllocateDescriptor();
  Fx3DmaSimpleTransferWrite(FX3_UIBIN_DMA_SCK(ep), d, buffer, length);
  Fx3DmaFreeDescriptor(d);
}

void Fx3UsbDmaDataIn(uint8_t ep, const volatile void *buffer, uint16_t length)
{
  uint16_t d = Fx3DmaAllocateDescriptor();
  Fx3DmaSimpleTransferRead(FX3_UIB_DMA_SCK(ep), d, buffer, length);
  Fx3DmaFreeDescriptor(d);
}

static void Fx3UsbUsbCoreIsr(void)
{
  uint32_t req = Fx3ReadReg32(FX3_UIB_INTR) & Fx3ReadReg32(FX3_UIB_INTR_MASK);
  Fx3WriteReg32(FX3_UIB_INTR, req);

  Fx3UartTxString("Fx3UsbUsbCoreIsr\n");
  if (req & FX3_UIB_INTR_PROT_INT) {
    Fx3UartTxString("  PROT\n");
    uint32_t prot_req =
      Fx3ReadReg32(FX3_PROT_INTR) & Fx3ReadReg32(FX3_PROT_INTR_MASK);
    Fx3WriteReg32(FX3_PROT_INTR, prot_req);

    if (prot_req & FX3_PROT_INTR_STATUS_STAGE) {
      Fx3UartTxString("    STATUS_STAGE\n");
    }
    if (prot_req & FX3_PROT_INTR_SUTOK_EV) {
      Fx3UartTxString("    SUTOK_EV\n");
      Fx3WriteReg32(FX3_PROT_EPO_CS1 + 0, FX3_PROT_EPO_CS1_VALID);
      Fx3WriteReg32(FX3_PROT_EPI_CS1 + 0, FX3_PROT_EPI_CS1_VALID);

      Fx3DmaAbortSocket(FX3_UIB_DMA_SCK(0));
      Fx3DmaAbortSocket(FX3_UIBIN_DMA_SCK(0));
      Fx3SetReg32(FX3_EEPM_ENDPOINT, FX3_EEPM_ENDPOINT_SOCKET_FLUSH);
      Fx3UtilDelayUs(10);
      Fx3ClearReg32(FX3_EEPM_ENDPOINT, FX3_EEPM_ENDPOINT_SOCKET_FLUSH);
 
      uint32_t sudat0 = Fx3ReadReg32(FX3_PROT_SETUP_DAT+0);
      uint32_t sudat1 = Fx3ReadReg32(FX3_PROT_SETUP_DAT+4);
      uint8_t req_type = sudat0 >> FX3_PROT_SETUP_DAT_SETUP_REQUEST_TYPE_SHIFT;
      uint16_t length = sudat1 >> (FX3_PROT_SETUP_DAT_SETUP_LENGTH_SHIFT - 32);
      if ((req_type & FX3_USB_REQTYPE_DIR_MASK) == FX3_USB_REQTYPE_IN)
	/* IN transfer */
	Fx3WriteReg32(FX3_DEV_EPI_XFER_CNT, length);
      else
	/* OUT transfer */
	Fx3WriteReg32(FX3_DEV_EPO_XFER_CNT, length);
      (*Fx3UsbUserCallbacks->sutok)
	(req_type, sudat0 >> FX3_PROT_SETUP_DAT_SETUP_REQUEST_SHIFT,
	 sudat0 >> FX3_PROT_SETUP_DAT_SETUP_VALUE_SHIFT,
	 sudat1 >> (FX3_PROT_SETUP_DAT_SETUP_INDEX_SHIFT - 32),
	 length);
    }
    if (prot_req & FX3_PROT_INTR_TIMEOUT_PORT_CFG_EV) {
      Fx3UartTxString("    TIMEOUT_PORT_CFG_EV\n");
    }
    if (prot_req & FX3_PROT_INTR_TIMEOUT_PORT_CAP_EV) {
      Fx3UartTxString("    TIMEOUT_PORT_CAP_EV\n");
    }
    if (prot_req & FX3_PROT_INTR_LMP_PORT_CFG_EV) {
      Fx3UartTxString("    LMP_PORT_CFG_EV\n");
      /* Disable timeout */
      Fx3WriteReg32(FX3_PROT_LMP_PORT_CONFIGURATION_TIMER, 0x80008000UL);
      Fx3WriteReg32(FX3_PROT_INTR, FX3_PROT_INTR_TIMEOUT_PORT_CFG_EV);
    }
    if (prot_req & FX3_PROT_INTR_LMP_PORT_CAP_EV) {
      Fx3UartTxString("    LMP_PORT_CAP_EV\n");
      /* Disable timeout */
      Fx3WriteReg32(FX3_PROT_LMP_PORT_CAPABILITY_TIMER, 0x80008000UL);
      Fx3WriteReg32(FX3_PROT_INTR, FX3_PROT_INTR_TIMEOUT_PORT_CAP_EV);
    }
    if (prot_req & FX3_PROT_INTR_LMP_RCV_EV) {
      Fx3UartTxString("    LMP_RCV_EV\n");
    }
  }
  if (req & FX3_UIB_INTR_LNK_INT) {
    Fx3UartTxString("  LNK\n");
    uint32_t lnk_req =
      Fx3ReadReg32(FX3_LNK_INTR) & Fx3ReadReg32(FX3_LNK_INTR_MASK);
    Fx3WriteReg32(FX3_LNK_INTR, lnk_req);

    if (lnk_req & FX3_LNK_INTR_LTSSM_RESET) {
      Fx3UartTxString("    LTSSM_RESET\n");
    }
    if (lnk_req & FX3_LNK_INTR_LTSSM_DISCONNECT) {
      Fx3UartTxString("    LTSSM_DISCONNECT\n");
    }
    if (lnk_req & FX3_LNK_INTR_LTSSM_CONNECT) {
      Fx3UartTxString("    LTSSM_CONNECT\n");
      Fx3UsbConnectSuperSpeed();
    }
    if (lnk_req & FX3_LNK_INTR_LGO_U3) {
      Fx3UartTxString("    LGO_U3\n");
    }
    if (lnk_req & FX3_LNK_INTR_LTSSM_STATE_CHG) {
      Fx3UartTxString("    LTSSM_STATE_CHG %u\n");
    }
  }
  if (req & FX3_UIB_INTR_DEV_CTL_INT) {
    Fx3UartTxString("  DEV_CTL\n");
    uint32_t dev_ctrl_req =
      Fx3ReadReg32(FX3_DEV_CTRL_INTR) & Fx3ReadReg32(FX3_DEV_CTRL_INTR_MASK);
    Fx3WriteReg32(FX3_DEV_CTRL_INTR, dev_ctrl_req);
  }

  Fx3WriteReg32(FX3_VIC_ADDRESS, 0);
}  

static void Fx3UsbGctlCoreIsr(void)
{
  uint32_t req = Fx3ReadReg32(FX3_GCTL_WAKEUP_EVENT) & Fx3ReadReg32(FX3_GCTL_WAKEUP_EN);
  Fx3WriteReg32(FX3_GCTL_WAKEUP_EVENT, req);

  Fx3UartTxString("Fx3UsbGctlCoreIsr\n");

  Fx3WriteReg32(FX3_VIC_ADDRESS, 0);
}

static void Fx3UsbGctlPowerIsr(void)
{
  uint32_t req = Fx3ReadReg32(FX3_GCTL_IOPOWER_INTR) & Fx3ReadReg32(FX3_GCTL_IOPOWER_INTR_MASK);
  Fx3WriteReg32(FX3_GCTL_IOPOWER_INTR, req);

  Fx3UartTxString("Fx3UsbGctlPowerIsr\n");

  if (req & FX3_GCTL_IOPOWER_INTR_VBUS) {
    Fx3UartTxString("  VBUS\n");
  }

  Fx3WriteReg32(FX3_VIC_ADDRESS, 0);
}

void Fx3UsbInit(const struct Fx3UsbCallbacks *callbacks)
{
  Fx3UsbUserCallbacks = callbacks;

  /* Select bus clock */
  Fx3ClearReg32(FX3_GCTL_UIB_CORE_CLK, FX3_GCTL_UIB_CORE_CLK_CLK_EN);
  Fx3UtilDelayUs(5);
  Fx3WriteReg32(FX3_GCTL_UIB_CORE_CLK,
		(2UL << FX3_GCTL_UIB_CORE_CLK_PCLK_SRC_SHIFT) |
		(2UL << FX3_GCTL_UIB_CORE_CLK_EPMCLK_SRC_SHIFT));
  Fx3SetReg32(FX3_GCTL_UIB_CORE_CLK, FX3_GCTL_UIB_CORE_CLK_CLK_EN);
  Fx3UtilDelayUs(5);

  Fx3WriteReg32(FX3_GCTL_CONTROL,
		FX3_GCTL_CONTROL_HARD_RESET_N |
		FX3_GCTL_CONTROL_CPU_RESET_N |
		FX3_GCTL_CONTROL_BOOTROM_EN |
		(1UL<<27) |
		FX3_GCTL_CONTROL_MAIN_POWER_EN |
		FX3_GCTL_CONTROL_MAIN_CLOCK_EN |
		FX3_GCTL_CONTROL_WAKEUP_CPU_INT |
		FX3_GCTL_CONTROL_WAKEUP_CLK |
		FX3_GCTL_CONTROL_POR);

  /* Reset USB */
  Fx3ClearReg32(FX3_UIB_POWER, FX3_UIB_POWER_RESETN);
  Fx3UtilDelayUs(50);
  Fx3SetReg32(FX3_UIB_POWER, FX3_UIB_POWER_RESETN);
  Fx3UtilDelayUs(100);
  while((Fx3ReadReg32(FX3_UIB_POWER) & FX3_UIB_POWER_ACTIVE) == 0)
    ;

  Fx3WriteReg32(FX3_OTG_CTRL, 0);

  Fx3WriteReg32(FX3_PHY_CLK_AND_TEST,
		(1UL<<31) |
		FX3_PHY_CLK_AND_TEST_SUSPEND_N |
		FX3_PHY_CLK_AND_TEST_VLOAD |
		FX3_PHY_CLK_AND_TEST_DATABUS16_8);
  Fx3SetReg32(FX3_DEV_PWR_CS, FX3_DEV_PWR_CS_DISCON);
  Fx3WriteReg32(FX3_GCTL_WAKEUP_EN, 0);
  Fx3WriteReg32(FX3_GCTL_WAKEUP_POLARITY, 0);
  Fx3WriteReg32(FX3_LNK_PHY_CONF,
		FX3_LNK_PHY_CONF_RX_TERMINATION_ENABLE |
		FX3_LNK_PHY_CONF_RX_TERMINATION_OVR_VAL |
		FX3_LNK_PHY_CONF_RX_TERMINATION_OVR |
		(1UL << FX3_LNK_PHY_CONF_PHY_MODE_SHIFT));
  Fx3WriteReg32(FX3_LNK_ERROR_CONF, ~0UL);
  Fx3WriteReg32(FX3_LNK_INTR, ~0UL);
  Fx3WriteReg32(FX3_LNK_INTR_MASK,
		FX3_LNK_INTR_MASK_LTSSM_RESET |
		FX3_LNK_INTR_MASK_LTSSM_DISCONNECT |
		FX3_LNK_INTR_MASK_LTSSM_CONNECT |
		FX3_LNK_INTR_MASK_LGO_U3 |
		FX3_LNK_INTR_MASK_LTSSM_STATE_CHG);
  Fx3WriteReg32(FX3_PROT_EP_INTR_MASK, 0);
  Fx3WriteReg32(FX3_PROT_INTR, ~0UL);
  Fx3WriteReg32(FX3_PROT_INTR_MASK,
		FX3_PROT_INTR_MASK_STATUS_STAGE |
		FX3_PROT_INTR_MASK_SUTOK_EN |
		FX3_PROT_INTR_MASK_TIMEOUT_PORT_CFG_EN |
		FX3_PROT_INTR_MASK_TIMEOUT_PORT_CAP_EN |
		FX3_PROT_INTR_MASK_LMP_PORT_CFG_EN |
		FX3_PROT_INTR_MASK_LMP_PORT_CAP_EN |
		FX3_PROT_INTR_MASK_LMP_RCV_EN);

  Fx3WriteReg32(FX3_PHY_CONF,
		FX3_PHY_CONF_PREEMDEPTH |
		FX3_PHY_CONF_ENPRE |
		(1UL << FX3_PHY_CONF_FSRFTSEL_SHIFT) |
		(1UL << FX3_PHY_CONF_LSRFTSEL_SHIFT) |
		(2UL << FX3_PHY_CONF_HSTEDVSEL_SHIFT) |
		(4UL << FX3_PHY_CONF_FSTUNEVSEL_SHIFT) |
		(2UL << FX3_PHY_CONF_HSDEDVSEL_SHIFT) |
		(4UL << FX3_PHY_CONF_HSDRVSLOPE_SHIFT));

  Fx3WriteReg32(FX3_DEV_CTRL_INTR, ~0UL);
  Fx3WriteReg32(FX3_DEV_CTRL_INTR_MASK,
		FX3_DEV_CTRL_INTR_MASK_URESUME |
		FX3_DEV_CTRL_INTR_MASK_SUDAV |
		FX3_DEV_CTRL_INTR_MASK_HSGRANT |
		FX3_DEV_CTRL_INTR_MASK_URESET |
		FX3_DEV_CTRL_INTR_MASK_SUSP);
  Fx3WriteReg32(FX3_DEV_EP_INTR, ~0UL);
  Fx3WriteReg32(FX3_DEV_EP_INTR_MASK, 0);

  /* USB3 EP0 valid as control */
  Fx3WriteReg32(FX3_PROT_EPO_CS1+0, FX3_PROT_EPO_CS1_VALID);
  Fx3WriteReg32(FX3_PROT_EPI_CS1+0, FX3_PROT_EPI_CS1_VALID);
  Fx3WriteReg32(FX3_PROT_EPO_CS2+0,
		(16UL << FX3_PROT_EPO_CS2_ISOINPKS_SHIFT) |
		(3UL << FX3_PROT_EPO_CS2_TYPE_SHIFT));
  Fx3WriteReg32(FX3_PROT_EPI_CS2+0,
		(16UL << FX3_PROT_EPI_CS2_ISOINPKS_SHIFT) |
		(3UL << FX3_PROT_EPI_CS2_TYPE_SHIFT));

  /* USB2 EP0 valid as control */
  Fx3WriteReg32(FX3_DEV_EPI_CS+0,
		FX3_DEV_EPI_CS_VALID |
		(0UL << FX3_DEV_EPI_CS_TYPE_SHIFT) |
		(64UL << FX3_DEV_EPI_CS_PAYLOAD_SHIFT));
  Fx3WriteReg32(FX3_DEV_EPO_CS+0,
		FX3_DEV_EPO_CS_VALID |
		(0UL << FX3_DEV_EPO_CS_TYPE_SHIFT) |
		(64UL << FX3_DEV_EPO_CS_PAYLOAD_SHIFT));

  /* Endpoint manager settings for EP0 */
  Fx3WriteReg32(FX3_EEPM_ENDPOINT+0,
		(64UL << FX3_EEPM_ENDPOINT_PACKET_SIZE_SHIFT));
  Fx3WriteReg32(FX3_IEPM_ENDPOINT+0,
		(64UL << FX3_IEPM_ENDPOINT_PACKET_SIZE_SHIFT));

  /* Invalidate all other EPs */
  unsigned i;
  for (i=1; i<16; i++) {
    Fx3ClearReg32(FX3_DEV_EPO_CS + (i<<2), FX3_DEV_EPO_CS_VALID);
    Fx3WriteReg32(FX3_PROT_EPO_CS1 + (i<<2), 0);
    Fx3ClearReg32(FX3_DEV_EPI_CS + (i<<2), FX3_DEV_EPI_CS_VALID);
    Fx3WriteReg32(FX3_PROT_EPI_CS1 + (i<<2), 0);
  }

  Fx3WriteReg32(FX3_UIB_INTR_MASK, 0);

  /* Configure vectored interrupt controller */
  Fx3WriteReg32(FX3_VIC_VEC_ADDRESS + (FX3_IRQ_GCTL_CORE<<2), Fx3UsbGctlCoreIsr);
  Fx3WriteReg32(FX3_VIC_VEC_ADDRESS + (FX3_IRQ_USB_CORE<<2), Fx3UsbUsbCoreIsr);
  Fx3WriteReg32(FX3_VIC_VEC_ADDRESS + (FX3_IRQ_GCTL_POWER<<2), Fx3UsbGctlPowerIsr);
  Fx3WriteReg32(FX3_VIC_INT_CLEAR,
		(1UL << FX3_IRQ_GCTL_POWER) | (1UL << FX3_IRQ_USB_CORE) | (1UL << FX3_IRQ_GCTL_CORE));
}

void Fx3UsbEnableInEndpoint(uint8_t ep, Fx3UsbEndpointType_t type, uint16_t pktsize)
{
  static const uint8_t usb2_type_map[] = {
    [FX3_USB_EP_ISOCHRONOUS] = 1,
    [FX3_USB_EP_INTERRUPT] = 3,
    [FX3_USB_EP_BULK] = 2,
    [FX3_USB_EP_CONTROL] = 0,
  };

  /* USB3 EP valid */
  Fx3WriteReg32(FX3_PROT_EPI_CS1+(ep<<2), FX3_PROT_EPI_CS1_VALID);
  Fx3WriteReg32(FX3_PROT_EPI_CS2+(ep<<2),
		(16UL << FX3_PROT_EPI_CS2_ISOINPKS_SHIFT) |
		((type << FX3_PROT_EPI_CS2_TYPE_SHIFT) & FX3_PROT_EPI_CS2_TYPE_MASK));

  /* USB2 EP valid */
  Fx3WriteReg32(FX3_DEV_EPI_CS+(ep<<2),
		FX3_DEV_EPI_CS_VALID |
		(usb2_type_map[type&3] << FX3_DEV_EPI_CS_TYPE_SHIFT) |
		((pktsize << FX3_DEV_EPI_CS_PAYLOAD_SHIFT) & FX3_DEV_EPI_CS_PAYLOAD_MASK));

  /* Endpoint manager settings for EP */
  Fx3WriteReg32(FX3_EEPM_ENDPOINT+(ep<<2),
		(pktsize << FX3_EEPM_ENDPOINT_PACKET_SIZE_SHIFT)
		& FX3_EEPM_ENDPOINT_PACKET_SIZE_MASK);
}

void Fx3UsbFlushInEndpoint(uint8_t ep)
{
  Fx3SetReg32(FX3_EEPM_ENDPOINT+(ep<<2), FX3_EEPM_ENDPOINT_SOCKET_FLUSH);
  Fx3UtilDelayUs(5);
  Fx3ClearReg32(FX3_EEPM_ENDPOINT+(ep<<2), FX3_EEPM_ENDPOINT_SOCKET_FLUSH);
}
