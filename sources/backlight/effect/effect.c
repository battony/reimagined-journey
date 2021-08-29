#include "effect.h"

static const effect_t * const effect_array[EFFECT_ARRAY_LEN] = {
    &effect_static,
};

static volatile uint8_t effect_id;

void effect_update() {
   effect_array[effect_id]->update();
}

void effect_update_mode() {
   effect_array[effect_id]->update_mode();
}

void effect_next() {
    uint8_t id = effect_id;
    if (++id == EFFECT_ARRAY_LEN)
        id = 0;
    effect_id = id;
}
