#include <stdio.h>
#include <stddef.h>
#include "my_malloc_manager.h"

void set_or_clear_bits(int set, Bitmap bitmap, uint16_t start_byte_index, uint16_t start_bit_index, uint16_t qty)
{
    unsigned char mask; // Se crea una mascara para indentificar el bit dentro del byte
    uint16_t byte_index, bit_index;
 
    // Se recorren los bits a partir del start_byte_index
    for (byte_index = start_byte_index; qty > 0; byte_index ++){
        mask = 0x80 >> start_bit_index;
 
        for (bit_index = start_bit_index; qty > 0 && bit_index < 8; bit_index++, qty--) {
            if (set) {
                bitmap[byte_index] |= mask; //Ajusta el bit a 1
            } else {
                bitmap[byte_index] &= ~mask; //Ajusta el bit a 0
            }
            mask >>= 1; // La mascara cambia al siguiente bit
           
        }
        start_bit_index = 0; //Resetea start_byte_index para el proximo byte
    }
}
