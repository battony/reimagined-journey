#pragma once

#include "configuration.h"

#define EFFECT_ARRAY_LEN (2)

typedef struct {
    void (*init)();
    void (*update)();
    void (*update_mode)();
    void (*update_keyboard)(volatile uint8_t[CONFIG_ROW_COUNT][CONFIG_COL_COUNT]);
} effect_t;

extern const effect_t effect_static;

extern const effect_t effect_pressed;

extern volatile uint32_t effect_buffer[CONFIG_LED_COUNT];

void effect_update();

void effect_update_mode();

void effect_update_keyboard(volatile uint8_t[CONFIG_ROW_COUNT][CONFIG_COL_COUNT]);

void effect_next();
