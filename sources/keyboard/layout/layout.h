#pragma once

#include "configuration.h"
#include "keycode.h"

typedef struct {
    uint8_t type;
    uint8_t value;
} key_t;

extern const key_t layout_1[CONFIG_ROW_COUNT][CONFIG_COL_COUNT];

extern const key_t layout_2[CONFIG_ROW_COUNT][CONFIG_COL_COUNT];

extern const key_t (* const layouts[])[CONFIG_COL_COUNT];
