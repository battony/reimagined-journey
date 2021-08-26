#pragma once

#include "configuration.h"
#include "effect.h"

#define BACKLIGHT_LOW              (22)
#define BACKLIGHT_HIGH             (58)

#define BACKLIGHT_SKIP             (24)

#define BACKLIGHT_BUFFER_SIZE      (24 * CONFIG_LED_COUNT)
#define BACKLIGHT_BUFFER_FULL_SIZE (BACKLIGHT_BUFFER_SIZE + 2 * BACKLIGHT_SKIP) 

extern volatile uint16_t backlight_full[BACKLIGHT_BUFFER_FULL_SIZE];

extern volatile uint16_t * const backlight_buffer;
