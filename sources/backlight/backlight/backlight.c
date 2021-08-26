#include "backlight.h"

volatile uint16_t backlight_full[BACKLIGHT_BUFFER_FULL_SIZE];

volatile uint16_t * const backlight_buffer = backlight_full + BACKLIGHT_SKIP;

void interrupt_dma_1_ch_2() {
    DMA1->IFCR = DMA_IFCR_CGIF2;
    DMA1_Channel2->CCR &= ~DMA_CCR_EN;
}

void interrupt_tim_2() {
    TIM2->SR &= ~TIM_SR_UIF;

    for (uint32_t i = 0; i < CONFIG_LED_COUNT; i++)
        effect_set_color(i, 0xF05030);

    effect_update();
}
