#include <stdio.h>
#include <stddef.h>
#include "my_malloc_manager.h"

void clear_bits(Bitmap bitmap, uint16_t start_byte_index, uint16_t start_bit_index, uint16_t qty) {
    if (!bitmap || start_byte_index >= BITMAP_SIZE || qty == 0) {
        // Verificar parámetros inválidos
        return;
    }

    uint16_t byte_index = start_byte_index;
    uint16_t bit_index = start_bit_index;

    while (qty > 0) {
        // Verificar si es necesario cambiar de byte
        if (bit_index >= 8) {
            byte_index++;
            bit_index = 0;
        }

        // Verificar si hemos llegado al final del bitmap
        if (byte_index >= BITMAP_SIZE) {
            break;
        }

        // Marcar el bit como cero
        bitmap[byte_index] &= ~(1 << bit_index);

        bit_index++;
        qty--;
    }
}
