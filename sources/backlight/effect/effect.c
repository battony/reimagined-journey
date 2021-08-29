#include "effect.h"

volatile uint32_t effect_buffer[CONFIG_LED_COUNT];

static const effect_t * const effect_array[EFFECT_ARRAY_LEN] = {
    &effect_static,
    &effect_pressed,
};

static volatile uint8_t effect_id;

void effect_update() {
    const effect_t* effect = effect_array[effect_id];
    if (effect->update)
        effect->update();
}

void effect_update_mode() {
    const effect_t* effect = effect_array[effect_id];
    if (effect->update_mode)
        effect->update_mode();
}

void effect_update_keyboard(
        volatile uint8_t keyboard[CONFIG_ROW_COUNT][CONFIG_COL_COUNT]) {
    const effect_t* effect = effect_array[effect_id];
    if (effect->update_keyboard)
        effect->update_keyboard(keyboard);
}

void effect_next() {
    uint8_t id = effect_id;
    if (++id == EFFECT_ARRAY_LEN)
        id = 0;
    effect_id = id;

    const effect_t* effect = effect_array[effect_id];
    if (effect->init)
        effect->init();
}
