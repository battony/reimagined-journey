#include "keyboard.h"

const uint32_t rows[CONFIG_ROW_COUNT] = {
    0x8000 << 0x00, 0x4000 << 0x00, 0x2000 << 0x00, 0x0004 << 0x00,
};

const uint32_t cols[CONFIG_COL_COUNT] = {
    0x0008 << 0x00, 0x0010 << 0x00, 0x0020 << 0x00, 0x0040 << 0x00,
    0x0080 << 0x00, 0x0100 << 0x00, 0x8000 << 0x00, 0x0008 << 0x10,
    0x0010 << 0x10, 0x0020 << 0x10, 0x0040 << 0x10, 0x0080 << 0x10,
    0x0100 << 0x10, 0x0200 << 0x10,
};

void interrupt_tim_1_up() {
    TIM1->SR &= ~TIM_SR_UIF;

    uint8_t position = 1;
    uint8_t keycodes[EP_KEYBOARD_BUF_MAX];
    for (uint32_t i = 0; i < EP_KEYBOARD_BUF_MAX; i++)
        keycodes[i] = 0;

    for (uint32_t i = 0; i < CONFIG_ROW_COUNT; i++) {
        GPIOB->BSRR = (0xE004 << 0x10) | rows[i];

        for (volatile uint32_t j = 0; j < 10; j++);

        uint32_t gpio = (GPIOB->IDR << 0x10) | GPIOA->IDR;
        for (uint32_t j = 0; j < CONFIG_COL_COUNT; j++) {
            if (gpio & cols[j]) {
                key_t key = layouts[0][i][j];
                switch (key.type) {
                    case KEYTYPE_STANDARD:
                        keycodes[position++] = key.value;
                        break;
                    case KEYTYPE_MODIFIER:
                        keycodes[0] |= key.value;
                        break;
                }
            }
        }
    }

    endpoint_keyboard_send_report(keycodes);
}
