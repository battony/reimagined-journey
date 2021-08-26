#include "effect.h"

void effect_update() {
    DMA1_Channel2->CNDTR = BACKLIGHT_BUFFER_FULL_SIZE;
    DMA1_Channel2->CCR |= DMA_CCR_EN;
}

void effect_set_color(uint32_t pos, uint32_t color) {
    pos *= 24;

    for (uint32_t i = 0; i < 8; i++) {
        backlight_buffer[pos + i + 0x00] = ((color & 0x00FF00) >> 0x08) & 
            (1 << (7 - i)) ? BACKLIGHT_HIGH : BACKLIGHT_LOW;
        backlight_buffer[pos + i + 0x08] = ((color & 0xFF0000) >> 0x10) & 
            (1 << (7 - i)) ? BACKLIGHT_HIGH : BACKLIGHT_LOW;
        backlight_buffer[pos + i + 0x10] = ((color & 0x0000FF) >> 0x00) & 
            (1 << (7 - i)) ? BACKLIGHT_HIGH : BACKLIGHT_LOW;
    }
}
