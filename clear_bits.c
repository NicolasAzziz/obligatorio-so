#include <stdio.h>
#include <stddef.h>
#include "my_malloc_manager.h"

void clear_bits(unsigned char *bitmap, size_t start_index, size_t units_to_free) {
    for (size_t i = start_index; i < start_index + units_to_free; i++) {
        size_t byte_index = i / 8;
        size_t bit_offset = i % 8;
        bitmap[byte_index] &= ~(1 << bit_offset);  // Establece el bit a 0 para liberar el espacio
    }
}
