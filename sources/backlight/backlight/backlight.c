#include "backlight.h"

static volatile uint16_t backlight_buffer[BACKLIGHT_BUFFER_COUNT][BACKLIGHT_BUFFER_FULL_LEN];

static volatile uint8_t backlight_buffer_id;

static volatile uint16_t* backlight_get_buffer() {
    return backlight_buffer[backlight_buffer_id];
}

static uint16_t backlight_get_color(uint8_t is_enable) {
    return is_enable ? BACKLIGHT_HIGH : BACKLIGHT_LOW;
}

void interrupt_dma_1_ch_2() {
    DMA1->IFCR          = DMA_IFCR_CGIF2;
    DMA1_Channel2->CCR &= ~DMA_CCR_EN;
}

void interrupt_tim_2() {
    TIM2->SR &= ~TIM_SR_UIF;

    if (++backlight_buffer_id == BACKLIGHT_BUFFER_COUNT)
        backlight_buffer_id = 0;

    for (uint32_t i = 0; i < CONFIG_LED_COUNT; i++)
        backlight_set_color(i, 0x0F0503);

    DMA1_Channel2->CMAR  = ((uint32_t) backlight_get_buffer());
    DMA1_Channel2->CNDTR = BACKLIGHT_BUFFER_FULL_LEN;
    DMA1_Channel2->CCR  |= DMA_CCR_EN;
}

void backlight_set_color(uint32_t position, uint32_t color) {
    volatile uint16_t* buffer = backlight_get_buffer() + BACKLIGHT_SKIP;
    position *= BACKLIGHT_COLOR;

    uint32_t color_r = (color & 0xFF0000) >> 0x10;
    uint32_t color_g = (color & 0x00FF00) >> 0x08;
    uint32_t color_b = (color & 0x0000FF) >> 0x00;

    for (uint32_t i = 0, j = 128; i < 8; i++, j >>= 1) {
        buffer[position + i + 0x00] = backlight_get_color(color_g & j);
        buffer[position + i + 0x08] = backlight_get_color(color_r & j);
        buffer[position + i + 0x10] = backlight_get_color(color_b & j);
    }
}
