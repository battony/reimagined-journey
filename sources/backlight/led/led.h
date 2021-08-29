#pragma once

#include "configuration.h"

typedef struct {
    uint32_t index;
    uint32_t x;
    uint32_t y;
} led_t;

extern const led_t led_matrix[CONFIG_ROW_COUNT][CONFIG_COL_COUNT];
