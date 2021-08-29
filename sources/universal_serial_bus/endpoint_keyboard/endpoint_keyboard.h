#pragma once

#include "configuration.h"
#include "endpoint.h"

#define EP_KEYBOARD_TX_BUF  ((volatile uint32_t*) 0x40006200)
#define EP_KEYBOARD_TX_CNT  ((volatile uint32_t*) 0x40006014)
#define EP_KEYBOARD_RX_BUF  ((volatile uint32_t*) 0x40006280)
#define EP_KEYBOARD_RX_CNT  ((volatile uint32_t*) 0x4000601C)

#define EP_KEYBOARD_BUF_MAX (0x0040)

void endpoint_keyboard_reset();

void endpoint_keyboard_interrupt();

void endpoint_keyboard_send_report(const uint8_t[EP_KEYBOARD_BUF_MAX]);
