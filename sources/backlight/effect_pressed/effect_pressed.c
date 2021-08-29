#include "effect_pressed.h"

const effect_t effect_pressed = {
    .init            = effect_pressed_init,
    .update          = effect_pressed_update,
    .update_mode     = NULL,
    .update_keyboard = effect_pressed_update_keyboard,
};

void effect_pressed_init() {
    for (uint32_t i = 0; i < CONFIG_LED_COUNT; i++)
        effect_buffer[i] = 0;
}

void effect_pressed_update() {
    for (uint32_t i = 0; i < CONFIG_LED_COUNT; i++) {
        uint32_t color = effect_buffer[i];
        effect_buffer[i] = color ? color - 1 : 0;

        color = color | (color << 0x10);
        backlight_set_color(i, color);
    }
}

void effect_pressed_update_keyboard(
        volatile uint8_t keyboard[CONFIG_ROW_COUNT][CONFIG_COL_COUNT]) {
    for (uint32_t i = 0; i < CONFIG_ROW_COUNT; i++)
        for (uint32_t j = 0; j < CONFIG_COL_COUNT; j++)
            if (keyboard[i][j])
                effect_buffer[led_matrix[i][j].index] = 60;
}
