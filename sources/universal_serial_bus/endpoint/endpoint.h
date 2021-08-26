#pragma once

#include "configuration.h"

void endpoint_set_status(volatile uint16_t*, uint16_t);

void endpoint_set_buffer(volatile uint32_t*, volatile uint32_t*,
        const uint8_t*, uint16_t);

void endpoint_set_buffer_zero(volatile uint32_t*);
