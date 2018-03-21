
#include <bsp/gctl.h>
#include <bsp/gpio.h>
#include <bsp/uart.h>
#include <bsp/util.h>

int main(void)
{
  Fx3GctlInitClock();
  *(volatile uint32_t *)(void *)0x400020e8 = 0;
  Fx3GctlInitIoMatrix(FX3_GCTL_ALTFUNC_GPIF32BIT_UART_I2S);
  Fx3UartInit(115200, FX3_UART_NO_PARITY, FX3_UART_1_STOP_BIT);
  Fx3UartTxString("\nGood moaning!\n");
  Fx3UartTxFlush();

  Fx3GpioSetupSimple(54,
		     FX3_GPIO_SIMPLE_ENABLE |
		     FX3_GPIO_SIMPLE_DRIVE_HI_EN |
		     FX3_GPIO_SIMPLE_DRIVE_LO_EN);
  for(;;) {
    Fx3GpioSetOutputValue(54, 1);
    Fx3UtilDelayUs(500000);
    Fx3GpioSetOutputValue(54, 0);
    Fx3UtilDelayUs(500000);
  }
}
