#pragma once

#include "configuration.h"

#define EFFECT_ARRAY_LEN (1)

typedef struct {
    void (*update)();
    void (*update_mode)();
} effect_t;

extern const effect_t effect_static;

void effect_update();

void effect_update_mode();

void effect_next();
