#include "endpoint_keyboard.h"

static volatile uint8_t endpoint_keyboard_is_sending;

void endpoint_keyboard_send_report(const uint8_t array[EP_KEYBOARD_BUF_MAX]) {
    if (endpoint_keyboard_is_sending) return;
    endpoint_keyboard_is_sending = 1;

    endpoint_set_buffer(
            EP_KEYBOARD_TX_BUF,
            EP_KEYBOARD_TX_CNT,
            array, EP_KEYBOARD_BUF_MAX);
    endpoint_set_status(&USB->EP1R, USB_EP_RX_STALL | USB_EP_TX_VALID);
}

void endpoint_keyboard_reset() {
    endpoint_keyboard_is_sending = 0;

    USB->EP1R = (USB_EP1R_EA & 0x1);
    USB->EP1R = (USB_EP1R_EA & 0x1) | USB_EP_INTERRUPT |
                USB_EP_RX_STALL | USB_EP_TX_NAK;
}

void endpoint_keyboard_interrupt() {
    endpoint_keyboard_is_sending = 0;

    endpoint_set_status(&USB->EP1R, USB_EP_RX_STALL | USB_EP_TX_NAK);
}
