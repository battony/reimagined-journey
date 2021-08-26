#include "endpoint_keyboard.h"

static volatile uint16_t is_now_sending;

void endpoint_keyboard_send_report(const uint8_t* array) {
    if (is_now_sending) return;
    is_now_sending = 1;
    endpoint_set_buffer(
            EP_KEYBOARD_TX_BUF,
            EP_KEYBOARD_TX_CNT,
            array, EP_KEYBOARD_BUF_MAX);
    endpoint_set_status(&USB->EP1R, USB_EP_RX_STALL | USB_EP_TX_VALID);
}

void endpoint_keyboard_reset() {
    is_now_sending = 0;
    USB->EP1R = (USB_EP1R_EA & 0x1);
    USB->EP1R = (USB_EP1R_EA & 0x1) | USB_EP_INTERRUPT |
                USB_EP_RX_STALL | USB_EP_TX_NAK;
}

void endpoint_keyboard_interrupt() {
    is_now_sending = 0;
    endpoint_set_status(&USB->EP1R, USB_EP_RX_STALL | USB_EP_TX_NAK);
}
