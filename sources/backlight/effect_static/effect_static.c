#include "effect_static.h"

#define EFFECT_STATIC_MODE_COUNT (4)

const effect_t effect_static = {
    .update      = effect_static_update,
    .update_mode = effect_static_update_mode,
};

static const uint32_t effect_static_modes[EFFECT_STATIC_MODE_COUNT] = {
    0x000000, 0x702818, 0x287018, 0x3A3A3A,
};

static volatile uint8_t effect_static_mode_id;

void effect_static_update() {
    uint32_t color = effect_static_modes[effect_static_mode_id];
    for (uint32_t i = 0; i < CONFIG_LED_COUNT; i++)
        backlight_set_color(i, color);
}

void effect_static_update_mode() {
    uint8_t id = effect_static_mode_id;
    if (++id == EFFECT_STATIC_MODE_COUNT)
        id = 0;
    effect_static_mode_id = id;
}
