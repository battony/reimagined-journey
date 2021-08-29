#include "keyboard.h"

static const uint32_t keyboard_rows[CONFIG_ROW_COUNT] = {
    0x8000 << 0x00, 0x4000 << 0x00, 0x2000 << 0x00, 0x0004 << 0x00,
};

static const uint32_t keyboard_cols[CONFIG_COL_COUNT] = {
    0x0008 << 0x00, 0x0010 << 0x00, 0x0020 << 0x00, 0x0040 << 0x00,
    0x0080 << 0x00, 0x0100 << 0x00, 0x8000 << 0x00, 0x0008 << 0x10,
    0x0010 << 0x10, 0x0020 << 0x10, 0x0040 << 0x10, 0x0080 << 0x10,
    0x0100 << 0x10, 0x0200 << 0x10,
};

static volatile uint8_t keyboard_down[CONFIG_ROW_COUNT][CONFIG_COL_COUNT];

static volatile uint8_t keyboard_fall[CONFIG_ROW_COUNT][CONFIG_COL_COUNT];

static volatile uint8_t keyboard_layout_id;

void interrupt_tim_1_up() {
    TIM1->SR &= ~TIM_SR_UIF;

    uint8_t position = 1;
    uint8_t keycodes[EP_KEYBOARD_BUF_MAX];
    for (uint32_t i = 0; i < EP_KEYBOARD_BUF_MAX; i++)
        keycodes[i] = 0;

    for (uint32_t i = 0; i < CONFIG_ROW_COUNT; i++) {
        GPIOB->BSRR = (0xE004 << 0x10) | keyboard_rows[i];

        for (volatile uint32_t j = 0; j < 10; j++);

        uint32_t gpio = (GPIOB->IDR << 0x10) | GPIOA->IDR;
        for (uint32_t j = 0; j < CONFIG_COL_COUNT; j++) {
            uint8_t is_down = (gpio & keyboard_cols[j]) != 0;
            keyboard_fall[i][j] = !keyboard_down[i][j] && is_down;
            keyboard_down[i][j] = is_down;
        }
    }

    uint8_t layout_id = keyboard_layout_id;
    for (uint32_t i = 0; i < CONFIG_ROW_COUNT; i++) {
        for (uint32_t j = 0; j < CONFIG_COL_COUNT; j++) {
            key_t key = layouts[keyboard_layout_id][i][j];
            if (keyboard_down[i][j] && key.type == KEYCODE_TYPE_LAYOUT_HOLD) 
                layout_id = key.value;
        }
    }

    for (uint32_t i = 0; i < CONFIG_ROW_COUNT; i++) {
        for (uint32_t j = 0; j < CONFIG_COL_COUNT; j++) {
            key_t key = layouts[layout_id][i][j];
            if (keyboard_fall[i][j] && key.type == KEYCODE_TYPE_LAYOUT_PRESS) 
                keyboard_layout_id = layout_id = key.value;
        }
    }

    for (uint32_t i = 0; i < CONFIG_ROW_COUNT; i++) {
        for (uint32_t j = 0; j < CONFIG_COL_COUNT; j++) {
            key_t key = layouts[layout_id][i][j];

            if (keyboard_down[i][j]) {
                switch (key.type) {
                    case KEYCODE_TYPE_STANDARD:
                        keycodes[position++] = key.value;
                        break;
                    case KEYCODE_TYPE_MODIFIER:
                        keycodes[0] |= key.value;
                        break;
                }
            }

            if (keyboard_fall[i][j]) {
                switch (key.type) {
                    case KEYCODE_TYPE_BACKLIGHT_MODE:
                        effect_update_mode();
                        break;
                    case KEYCODE_TYPE_BACKLIGHT_EFFECT:
                        effect_next();
                        break;
                }
            }
        }
    }

    endpoint_keyboard_send_report(keycodes);
}
