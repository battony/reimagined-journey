#include "universal_serial_bus.h"

static void (* const universal_serial_bus_interrupt[])() = {
    endpoint_control_interrupt,
    endpoint_keyboard_interrupt,
};

static void universal_serial_bus_clear_flag(uint32_t flag) {
    USB->ISTR = ~flag;
}

static void universal_serial_bus_switch_endpoint(uint32_t epid) {
    universal_serial_bus_interrupt[epid]();
}

static void universal_serial_bus_reset() {
    endpoint_control_reset();
    endpoint_keyboard_reset();

    USB->DADDR = USB_DADDR_EF;
}

void interrupt_usb_lp_can_1_rx_0() {
    uint32_t istr = USB->ISTR;
    uint32_t epid = istr & USB_ISTR_EP_ID;

    if (istr & USB_ISTR_RESET) {
        universal_serial_bus_reset();
        universal_serial_bus_clear_flag(USB_ISTR_RESET);
    } else if (istr & USB_ISTR_CTR) {
        universal_serial_bus_switch_endpoint(epid);
    }
}
