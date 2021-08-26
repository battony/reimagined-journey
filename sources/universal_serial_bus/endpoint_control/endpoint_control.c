#include "endpoint_control.h"

static volatile uint16_t command;
static volatile uint16_t address;
static volatile uint16_t configuration;
static volatile uint16_t idle;
static volatile uint16_t protocol;
static volatile uint16_t sended;

static void endpoint_control_get_descriptor(const uint8_t* descriptor,
        uint16_t size, uint16_t req_size) {
    uint32_t epnr = USB->EP0R;
    uint32_t send = req_size < size ? req_size : size;

    if (epnr & USB_EP_SETUP)
        sended = 0;

    send -= sended;
    if (send > EP_CONTROL_BUF_MAX)
        send = EP_CONTROL_BUF_MAX;

    if (epnr & USB_EP_CTR_RX) {
        endpoint_set_buffer(
                EP_CONTROL_TX_BUF,
                EP_CONTROL_TX_CNT,
                descriptor + sended, send); 
        endpoint_set_status(&USB->EP0R, USB_EP_RX_VALID | USB_EP_TX_VALID);
        sended += send;
    } else {
        endpoint_set_status(&USB->EP0R, USB_EP_RX_VALID | USB_EP_TX_STALL);
    }
}

static void endpoint_control_set_value(volatile uint16_t* value) {
    if (USB->EP0R & USB_EP_CTR_RX) {
        *value = EP_CONTROL_RX_BUF[1];
        endpoint_set_buffer_zero(EP_CONTROL_TX_CNT);
        endpoint_set_status(&USB->EP0R, USB_EP_RX_VALID | USB_EP_TX_VALID);
    } else {
        endpoint_set_status(&USB->EP0R, USB_EP_RX_VALID | USB_EP_TX_STALL);
    }
}

static void endpoint_control_set_address() {
    uint32_t epnr = USB->EP0R;
    endpoint_control_set_value(&address);

    if (epnr & USB_EP_CTR_TX)
        USB->DADDR |= address;
}

static void endpoint_control_set_configuration() {
    endpoint_control_set_value(&configuration);
}

static void endpoint_control_set_idle() {
    endpoint_control_set_value(&idle);
}

static void endpoint_control_set_protocol() {
    endpoint_control_set_value(&protocol);
}

static void endpoint_control_get_descriptor_standard() {
    uint16_t type = EP_CONTROL_RX_BUF[1];
    uint16_t size = EP_CONTROL_RX_BUF[3];

    const uint8_t* descriptor;
    uint16_t descriptor_size;
    switch (type) {
        case DESC_DEVICE:
            descriptor = descriptor_device;
            descriptor_size = sizeof(descriptor_device);
            break;
        case DESC_DEVICE_QUALFIFER:
            descriptor = descriptor_device_qualifier;
            descriptor_size = sizeof(descriptor_device_qualifier);
            break;
        case DESC_CONFIGURATION:
            descriptor = descriptor_configuration;
            descriptor_size = sizeof(descriptor_configuration);
            break;
        case DESC_STRING:
            descriptor = descriptor_string;
            descriptor_size = sizeof(descriptor_string);
            break;
        case DESC_STRING_MFR:
            descriptor = descriptor_string_manufacturer;
            descriptor_size = sizeof(descriptor_string_manufacturer);
            break;
        case DESC_STRING_PRD:
            descriptor = descriptor_string_product;
            descriptor_size = sizeof(descriptor_string_product);
            break;
        case DESC_STRING_SNU:
            descriptor = descriptor_string_serial_number;
            descriptor_size = sizeof(descriptor_string_serial_number);
            break;
        case DESC_STRING_CNF:
            descriptor = descriptor_string_configuration;
            descriptor_size = sizeof(descriptor_string_configuration);
            break;
        case DESC_REPORT:
            descriptor = descriptor_report;
            descriptor_size = sizeof(descriptor_report);
            break;
        default:
            return;
    }

    endpoint_control_get_descriptor(descriptor, descriptor_size, size);
}

void endpoint_control_reset() {
    USB->EP0R = (USB_EP0R_EA & 0x0);
    USB->EP0R = (USB_EP0R_EA & 0x0) | USB_EP_CONTROL |
                USB_EP_RX_VALID | USB_EP_TX_STALL;
}

void endpoint_control_interrupt() {
    if (USB->EP0R & USB_EP_SETUP)
        command = EP_CONTROL_RX_BUF[0];
    
    void (*handler)();
    switch (command) {
        case EP_CONTROL_GET_DESCRIPTOR_STANDARD:
        case EP_CONTROL_GET_DESCRIPTOR_INTERFACE:
            handler = endpoint_control_get_descriptor_standard;
            break;
        case EP_CONTROL_SET_ADDRESS:
            handler = endpoint_control_set_address;
            break;
        case EP_CONTROL_SET_CONFIGURATION:
            handler = endpoint_control_set_configuration;
            break;
        case EP_CONTROL_SET_IDLE:
            handler = endpoint_control_set_idle;
            break;
        case EP_CONTROL_SET_PROTOCOL:
            handler = endpoint_control_set_protocol;
            break;
        default:
            return;
    }

    handler();
}
