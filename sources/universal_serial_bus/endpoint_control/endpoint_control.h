#pragma once

#include "configuration.h"
#include "descriptor.h"
#include "endpoint.h"

#define EP_CONTROL_TX_BUF                   ((volatile uint32_t*) 0x40006100)
#define EP_CONTROL_TX_CNT                   ((volatile uint32_t*) 0x40006004)
#define EP_CONTROL_RX_BUF                   ((volatile uint32_t*) 0x40006180)
#define EP_CONTROL_RX_CNT                   ((volatile uint32_t*) 0x4000600C)

#define EP_CONTROL_BUF_MAX                  (0x0040)

#define EP_CONTROL_GET_DESCRIPTOR_STANDARD  (0x0680)
#define EP_CONTROL_GET_DESCRIPTOR_INTERFACE (0x0681)
#define EP_CONTROL_SET_ADDRESS              (0x0500)
#define EP_CONTROL_SET_IDLE                 (0x0A21)
#define EP_CONTROL_SET_PROTOCOL             (0x0B21)
#define EP_CONTROL_SET_CONFIGURATION        (0x0900)

void endpoint_control_reset();

void endpoint_control_interrupt();
