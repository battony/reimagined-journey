#pragma once

#include "configuration.h"

#define BACKLIGHT_LOW              (22)
#define BACKLIGHT_HIGH             (68)

#define BACKLIGHT_COLOR            (24)
#define BACKLIGHT_SKIP             (BACKLIGHT_COLOR)

#define BACKLIGHT_BUFFER_COUNT     (2)
#define BACKLIGHT_BUFFER_LEN       (BACKLIGHT_COLOR * CONFIG_LED_COUNT)
#define BACKLIGHT_BUFFER_FULL_LEN  (BACKLIGHT_BUFFER_LEN + 2 * BACKLIGHT_SKIP) 

void backlight_set_color(uint32_t, uint32_t);
