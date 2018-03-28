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

#ifndef BSP_USB_H_
#define BSP_USB_H_

#include <stdint.h>

#define FX3_USB_REQTYPE_DIR_MASK    0x80
#define FX3_USB_REQTYPE_OUT         0x00
#define FX3_USB_REQTYPE_IN          0x80

#define FX3_USB_REQTYPE_TYPE_MASK   0x60
#define FX3_USB_REQTYPE_TYPE_STD    0x00
#define FX3_USB_REQTYPE_TYPE_CLASS  0x20
#define FX3_USB_REQTYPE_TYPE_VENDOR 0x40

#define FX3_USB_REQTYPE_TGT_MASK    0x1F
#define FX3_USB_REQTYPE_TGT_DEVICE  0x00
#define FX3_USB_REQTYPE_TGT_INTERFC 0x01
#define FX3_USB_REQTYPE_TGT_EP      0x02
#define FX3_USB_REQTYPE_TGT_OTHER   0x03

#define FX3_USB_STD_REQUEST_GET_STATUS        0x00
#define FX3_USB_STD_REQUEST_CLEAR_FEATURE     0x01
#define FX3_USB_STD_REQUEST_SET_FEATURE       0x03
#define FX3_USB_STD_REQUEST_SET_ADDRESS       0x05
#define FX3_USB_STD_REQUEST_GET_DESCRIPTOR    0x06
#define FX3_USB_STD_REQUEST_SET_DESCRIPTOR    0x07
#define FX3_USB_STD_REQUEST_GET_CONFIGURATION 0x08
#define FX3_USB_STD_REQUEST_SET_CONFIGURATION 0x09
#define FX3_USB_STD_REQUEST_GET_INTERFACE     0x0A
#define FX3_USB_STD_REQUEST_SET_INTERFACE     0x0B
#define FX3_USB_STD_REQUEST_SYNCH_FRAME       0x0C

#define FX3_USB_DESCRIPTOR_DEVICE             0x01
#define FX3_USB_DESCRIPTOR_CONFIGURATION      0x02
#define FX3_USB_DESCRIPTOR_STRING             0x03
#define FX3_USB_DESCRIPTOR_INTERFACE          0x04
#define FX3_USB_DESCRIPTOR_ENDPOINT           0x05
#define FX3_USB_DESCRIPTOR_DEVICE_QUALIFIER   0x06
#define FX3_USB_DESCRIPTOR_OTHER_SPEED_CONFIG 0x07
#define FX3_USB_DESCRIPTOR_INTERFACE_POWER    0x08
#define FX3_USB_DESCRIPTOR_OTG                0x09
#define FX3_USB_DESCRIPTOR_DEBUG              0x0A
#define FX3_USB_DESCRIPTOR_INTERFACE_ASSOC    0x0B
#define FX3_USB_DESCRIPTOR_BOS                0x0F
#define FX3_USB_DESCRIPTOR_DEV_CAPABILITY     0x10
#define FX3_USB_DESCRIPTOR_SS_EP_COMPANION    0x30

struct Fx3UsbCallbacks {
  void (*sutok)(uint8_t request_type, uint8_t request, uint16_t value,
		uint16_t index, uint16_t length);
};

extern void Fx3UsbInit(const struct Fx3UsbCallbacks *callbacks);
extern void Fx3UsbConnect(void);
extern void Fx3UsbStallEp0(void);
extern void Fx3UsbUnstallEp0(void);
extern void Fx3UsbDmaDataOut(uint8_t ep, volatile void *buffer,
			     uint16_t length);
extern void Fx3UsbDmaDataIn(uint8_t ep, const volatile void *buffer,
			    uint16_t length);

#endif /* BSP_USB_H_ */
