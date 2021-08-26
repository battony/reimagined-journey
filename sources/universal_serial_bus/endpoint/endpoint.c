#include "endpoint.h"

void endpoint_set_status(volatile uint16_t* ep, uint16_t msk) {
    uint16_t val = *ep;
    *ep = (val & 0x0F0F) | ((val & 0x3030) ^ msk);
}

void endpoint_set_buffer(volatile uint32_t* buffer, volatile uint32_t* count,
        const uint8_t* array, uint16_t size) {
    *count = size;

    uint32_t i, j;
    for (i = 0, j = 0; size > 1; size -= 2, j += 2, i++)
        buffer[i] = (array[j + 1] << 8) | array[j];

    if (size == 1)
        buffer[i] = array[j];
}

void endpoint_set_buffer_zero(volatile uint32_t* count) {
    *count = 0;
}
