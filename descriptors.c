#include <stdint.h>
#include <stddef.h>
#include <bsp/uart.h>
#include <bsp/usb.h>

#include "descriptors.h"

static const struct __attribute__((packed)) {
  uint8_t length, descriptor_type;
  uint16_t usb_version;
  uint8_t device_class, sub_class, protocol, max_packet_size;
  uint16_t vendor, product, dev_version;
  uint8_t manuf_index, product_index, serial_index, num_configurations;
} highspeed_device_descriptor = {
  .length = sizeof(highspeed_device_descriptor),
  .descriptor_type = FX3_USB_DESCRIPTOR_DEVICE,
  .usb_version = 0x0200,
  .device_class = 0xff,
  .sub_class = 0xff,
  .protocol = 0xff,
  .max_packet_size = 64 /* 2^9 */,
  .vendor = 0x04b4,
  .product = 0x00f3,
  .dev_version = 0x0001,
  .manuf_index = 1,
  .product_index = 2,
  .serial_index = 3,
  .num_configurations = 1
};

static const struct __attribute__((packed)) {
  uint8_t length, descriptor_type;
  uint16_t usb_version;
  uint8_t device_class, sub_class, protocol, max_packet_size;
  uint16_t vendor, product, dev_version;
  uint8_t manuf_index, product_index, serial_index, num_configurations;
} superspeed_device_descriptor = {
  .length = sizeof(superspeed_device_descriptor),
  .descriptor_type = FX3_USB_DESCRIPTOR_DEVICE,
  .usb_version = 0x0300,
  .device_class = 0xff,
  .sub_class = 0xff,
  .protocol = 0xff,
  .max_packet_size = 9 /* 2^9 */,
  .vendor = 0x04b4,
  .product = 0x00f3,
  .dev_version = 0x0001,
  .manuf_index = 1,
  .product_index = 2,
  .serial_index = 3,
  .num_configurations = 1
};

static const struct __attribute__((packed)) {
  struct __attribute__((packed)) {
    uint8_t length, descriptor_type;
    uint16_t total_length;
    uint8_t num_interfaces, configuration_value, configuration_string;
    uint8_t attributes, max_power;
  } configuration;
  struct __attribute__((packed)) {
    uint8_t length, descriptor_type;
    uint8_t interface_number, alternate_setting, num_endpoints;
    uint8_t interface_class, interface_subclass, interface_protocol;
    uint8_t interface_string;
  } interfaces[1];
  struct __attribute__((packed)) {
    uint8_t length, descriptor_type;
    uint8_t endpoint_address, attributes;
    uint16_t max_packet_size;
    uint8_t interval;
  } endpoints[1];
  struct __attribute__((packed)) {
    uint8_t length, descriptor_type;
    uint8_t max_burst, max_streams;
    uint16_t service_interval;
  } companions[1];
} superspeed_configuration_descriptor = {
  .configuration = {
      .length = sizeof(superspeed_configuration_descriptor.configuration),
      .descriptor_type = FX3_USB_DESCRIPTOR_CONFIGURATION,
      .total_length = sizeof(superspeed_configuration_descriptor),
      .num_interfaces = 1,
      .configuration_value = 1,
      .configuration_string = 0,
      .attributes = 0x80,
      .max_power = 100/2
    },
  .interfaces[0] = {
     .length = sizeof(superspeed_configuration_descriptor.interfaces[0]),
     .descriptor_type = FX3_USB_DESCRIPTOR_INTERFACE,
     .interface_number = 0,
     .alternate_setting = 0,
     .num_endpoints = 1,
     .interface_class = 0xff,
     .interface_subclass = 0xff,
     .interface_protocol = 0xff,
     .interface_string = 0
   },
  .endpoints[0] = {
     .length = sizeof(superspeed_configuration_descriptor.endpoints[0]),
     .descriptor_type = FX3_USB_DESCRIPTOR_ENDPOINT,
     .endpoint_address = 0x82,
     .attributes = 2 /* Bulk */,
     .max_packet_size = 1024,
     .interval = 0
   },
  .companions[0] = {
     .length = sizeof(superspeed_configuration_descriptor.companions[0]),
     .descriptor_type = FX3_USB_DESCRIPTOR_SS_EP_COMPANION,
     .max_burst = 0,
     .max_streams = 0,
     .service_interval = 0
   },
};

static const struct __attribute__((packed)) {
  struct __attribute__((packed)) {
    uint8_t length, descriptor_type;
    uint16_t total_length;
    uint8_t num_capability_descriptors;
  } bos;
  struct __attribute__((packed)) {
    uint8_t length, descriptor_type;
    uint8_t usb_version;
    uint32_t features;
  } usb2_caps;
  struct __attribute__((packed)) {
    uint8_t length, descriptor_type;
    uint8_t usb_version;
    uint8_t dev_features;
    uint16_t speeds;
    uint8_t functionality;
    uint8_t u1_exit_latency;
    uint16_t u2_exit_latency;
  } usb3_caps;
} bos_descriptor = {
  .bos = {
      .length = sizeof(bos_descriptor.bos),
      .descriptor_type = FX3_USB_DESCRIPTOR_BOS,
      .total_length = sizeof(bos_descriptor),
      .num_capability_descriptors = 2
    },
  .usb2_caps = {
      .length = sizeof(bos_descriptor.usb2_caps),
      .descriptor_type = FX3_USB_DESCRIPTOR_DEV_CAPABILITY,
      .usb_version = 2,
      .features = 2 /* LPM support */
   },
  .usb3_caps = {
      .length = sizeof(bos_descriptor.usb3_caps),
      .descriptor_type = FX3_USB_DESCRIPTOR_DEV_CAPABILITY,
      .usb_version = 3,
      .dev_features = 0,
      .speeds = 0xe /* SS, HS, FS */,
      .functionality = 3,
      .u1_exit_latency = 0,
      .u2_exit_latency = 0
   },
};

static const uint16_t * const string_descriptors[] = {
  [0] = u"\x0304" "\x0409", /* US english only */
  [1] = u"\x030e" "sigrok",
  [2] = u"\x0310" "fx3lafw",
  [3] = u"\x0312" "12345678",
};

const void *GetDescriptor(uint8_t descriptor_type, uint8_t descriptor_no, Fx3UsbSpeed_t s)
{
  switch(descriptor_type) {
  case FX3_USB_DESCRIPTOR_DEVICE:
    if (descriptor_no == 0){
       if (s == FX3_USB_SUPER_SPEED)
         return &superspeed_device_descriptor;
       return &highspeed_device_descriptor;
     } else
        break;
  case FX3_USB_DESCRIPTOR_CONFIGURATION:
    if (descriptor_no == 0)
      return &superspeed_configuration_descriptor;
    break;
  case FX3_USB_DESCRIPTOR_STRING:
    if (descriptor_no < sizeof(string_descriptors)/sizeof(string_descriptors[0]))
      return string_descriptors[descriptor_no];
    break;
  case FX3_USB_DESCRIPTOR_BOS:
    if (descriptor_no == 0)
      return &bos_descriptor;
    break;
  }
  return NULL;
}

