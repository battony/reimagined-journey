#include "initialization.h"

extern void infinity();

static void initialization_peryphery() {
    RCC->APB2ENR = RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN |
                   RCC_APB2ENR_AFIOEN | RCC_APB2ENR_TIM1EN;
    RCC->APB1ENR = RCC_APB1ENR_TIM2EN | RCC_APB1ENR_TIM3EN |
                   RCC_APB1ENR_USBEN;
    RCC->AHBENR  = RCC_AHBENR_DMA1EN;
}

static void initialization_clock() {
    RCC->CR    |= RCC_CR_HSEON;
    RCC->CFGR  |= RCC_CFGR_PLLMULL6 | RCC_CFGR_PLLSRC | RCC_CFGR_USBPRE |
                  RCC_CFGR_PPRE1_DIV2 | RCC_CFGR_ADCPRE_DIV6;
    FLASH->ACR |= FLASH_ACR_LATENCY_1;
    while (!(RCC->CR & RCC_CR_HSERDY));
    RCC->CR    |= RCC_CR_PLLON;
    while (!(RCC->CR & RCC_CR_PLLRDY));
    RCC->CFGR  |= RCC_CFGR_SW_PLL;
}

static void initialization_endpoint_control() {
    INIT_EP_0_TX_BUF = 0x0080;
    INIT_EP_0_TX_CNT = 0x0000;
    INIT_EP_0_RX_BUF = 0x00C0;
    INIT_EP_0_RX_CNT = 0x8400;
}

static void initialization_endpoint_keyboard() {
    INIT_EP_1_TX_BUF = 0x0100;
    INIT_EP_1_TX_CNT = 0x0000;
    INIT_EP_1_RX_BUF = 0x0140;
    INIT_EP_1_RX_CNT = 0x8400;
}

static void initialization_usb() {
    initialization_endpoint_control();
    initialization_endpoint_keyboard();

    USB->CNTR  = USB_CNTR_RESETM | USB_CNTR_CTRM;
    USB->DADDR = USB_DADDR_EF;
}

static void initialization_pin() {
    AFIO->MAPR = AFIO_MAPR_SWJ_CFG_JTAGDISABLE;

    GPIOA->CRL = 0x88888338;
    GPIOA->CRH = 0x84444348;
    GPIOA->ODR = 0x00000000;

    GPIOB->CRL = 0x8888833B;
    GPIOB->CRH = 0x33344488;
    GPIOB->ODR = 0x00000002;
}

static void initialization_backlight() {
    TIM2->PSC  = 7199;
    TIM2->ARR  = 332;
    TIM2->EGR  = TIM_EGR_UG;
    TIM2->DIER = TIM_DIER_UIE;
    TIM2->CR1  = TIM_CR1_CEN;

    TIM3->PSC   = 0;
    TIM3->CCR3  = 0;
    TIM3->ARR   = 89;
    TIM3->CCER  = TIM_CCER_CC3E;
    TIM3->CCMR2 = TIM_CCMR2_OC3PE | TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2;
    TIM3->EGR   = TIM_EGR_UG;
    TIM3->DIER  = TIM_DIER_CC3DE;
    TIM3->CR2   = TIM_CR2_CCDS;
    TIM3->CR1   = TIM_CR1_CEN;

    DMA1_Channel2->CCR  = DMA_CCR_MSIZE_0 | DMA_CCR_MINC | DMA_CCR_DIR |
                          DMA_CCR_PSIZE_0 | DMA_CCR_TCIE;
    DMA1_Channel2->CPAR = ((uint32_t) &TIM3->CCR3);
}

static void initialization_keyboard() {
    TIM1->PSC  = 7199;
    TIM1->ARR  = 9;
    TIM1->EGR  = TIM_EGR_UG;
    TIM1->DIER = TIM_DIER_UIE;
    TIM1->CR1  = TIM_CR1_CEN;
}

static void initialization_nvic() {
    NVIC->IP[INIT_NVIC_IP_USB]      = INIT_NVIC_PRIORITY_15;
    NVIC->ISER[INIT_NVIC_PG_USB]   |= INIT_NVIC_IS_USB;

    NVIC->IP[INIT_NVIC_IP_TIM_1]    = INIT_NVIC_PRIORITY_14;
    NVIC->ISER[INIT_NVIC_PG_TIM_1] |= INIT_NVIC_IS_TIM_1;

    NVIC->IP[INIT_NVIC_IP_DMA_2]    = INIT_NVIC_PRIORITY_13;
    NVIC->ISER[INIT_NVIC_PG_DMA_2] |= INIT_NVIC_IS_DMA_2;

    NVIC->IP[INIT_NVIC_IP_TIM_2]    = INIT_NVIC_PRIORITY_13;
    NVIC->ISER[INIT_NVIC_PG_TIM_2] |= INIT_NVIC_IS_TIM_2;
}

static void initialization_sleep() {
   // DBGMCU->CR |= DBGMCU_CR_DBG_SLEEP;
   // SCB->SCR   |= SCB_SCR_SLEEPONEXIT_Msk;
   // asm volatile ("wfi");

   infinity();
}

void main() {
    initialization_peryphery();
    initialization_clock();
    initialization_pin();
    initialization_keyboard();
    initialization_backlight();
    initialization_usb();
    initialization_nvic();
    initialization_sleep();
}
