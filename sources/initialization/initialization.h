#pragma once

#include "configuration.h"

#define INIT_NVIC_PRIORITY_15 (0x00)
#define INIT_NVIC_PRIORITY_14 (0x10)
#define INIT_NVIC_PRIORITY_13 (0x20)
#define INIT_NVIC_PRIORITY_12 (0x30)
#define INIT_NVIC_PRIORITY_11 (0x40)
#define INIT_NVIC_PRIORITY_10 (0x50)
#define INIT_NVIC_PRIORITY_09 (0x60)
#define INIT_NVIC_PRIORITY_08 (0x70)
#define INIT_NVIC_PRIORITY_07 (0x80)
#define INIT_NVIC_PRIORITY_06 (0x90)
#define INIT_NVIC_PRIORITY_05 (0xA0)
#define INIT_NVIC_PRIORITY_04 (0xB0)
#define INIT_NVIC_PRIORITY_03 (0xC0)
#define INIT_NVIC_PRIORITY_02 (0xD0)
#define INIT_NVIC_PRIORITY_01 (0xE0)
#define INIT_NVIC_PRIORITY_00 (0xF0)

#define INIT_NVIC_IP_USB      (20)
#define INIT_NVIC_IS_USB      (1 << 20)
#define INIT_NVIC_PG_USB      (0)

#define INIT_NVIC_IP_TIM_1    (25)
#define INIT_NVIC_IS_TIM_1    (1 << 25)
#define INIT_NVIC_PG_TIM_1    (0)

#define INIT_NVIC_IP_DMA_2    (12)
#define INIT_NVIC_IS_DMA_2    (1 << 12)
#define INIT_NVIC_PG_DMA_2    (0)

#define INIT_NVIC_IP_TIM_2    (28)
#define INIT_NVIC_IS_TIM_2    (1 << 28)
#define INIT_NVIC_PG_TIM_2    (0)

#define INIT_EP_0_TX_BUF      (*(volatile uint32_t*) 0x40006000)
#define INIT_EP_0_TX_CNT      (*(volatile uint32_t*) 0x40006004)
#define INIT_EP_0_RX_BUF      (*(volatile uint32_t*) 0x40006008)
#define INIT_EP_0_RX_CNT      (*(volatile uint32_t*) 0x4000600C)

#define INIT_EP_1_TX_BUF      (*(volatile uint32_t*) 0x40006010)
#define INIT_EP_1_TX_CNT      (*(volatile uint32_t*) 0x40006014)
#define INIT_EP_1_RX_BUF      (*(volatile uint32_t*) 0x40006018)
#define INIT_EP_1_RX_CNT      (*(volatile uint32_t*) 0x4000601C)
