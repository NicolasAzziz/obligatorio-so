#include <stdio.h>
#include <stddef.h>
#include "my_malloc_manager.h"

int first_fit(unsigned char *bitmap, size_t bitmap_size, size_t units_needed) {
    size_t consecutive_zeros = 0;  // Contador de ceros consecutivos
    size_t start_index = 0;        // Índice de inicio del espacio disponible

    for (size_t i = 0; i < bitmap_size * 8; i++) {
        size_t byte_index = i / 8;  // Índice del byte en el que se encuentra el bit
        size_t bit_offset = i % 8;  // Offset del bit dentro del byte

        if ((bitmap[byte_index] & (1 << (7 - bit_offset))) == 0) { // Verifica si el bit es 0
            consecutive_zeros++;
            if (consecutive_zeros == 1) {
                start_index = i;  // Actualizamos el inicio del espacio disponible
            }
            if (consecutive_zeros == units_needed) {
                // Marcamos los bits necesarios con 1
                for (size_t j = start_index; j < start_index + units_needed; j++) {
                    size_t byte_idx = j / 8;
                    size_t bit_off = j % 8;
                    bitmap[byte_idx] |= (1 << (7 - bit_off));  // Establece el bit a 1
                }
                return start_index; // Retornamos el índice de inicio
            }
        } else {
            consecutive_zeros = 0; // Reiniciamos el contador
        }
    }
    return -1; // No se encontró espacio suficiente
}
