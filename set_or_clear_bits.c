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



// void set_or_clear_bits(int set, unsigned char *bitmap, size_t bitmap_size, size_t units_to_modify) {
//     size_t consecutive_zeros = 0;
//     size_t start_index = 0;
//     size_t units_modified = 0;

//     for (size_t i = 0; i < bitmap_size * 8; i++) {
//         size_t byte_index = i / 8;
//         size_t bit_offset = i % 8;

//         if (set == 1) {
//             // Establecer bits en 1
//             if ((bitmap[byte_index] & (1 << bit_offset)) == 0) {
//                 consecutive_zeros++;
//                 if (consecutive_zeros == 1) {
//                     start_index = i;
//                 }
//                 if (consecutive_zeros == units_to_modify) {
//                     for (size_t j = start_index; j < start_index + units_to_modify; j++) {
//                         size_t byte_idx = j / 8;
//                         size_t bit_off = j % 8;
//                         bitmap[byte_idx] |= (1 << bit_off);
//                         units_modified++;
//                     }
//                     if (units_modified == units_to_modify) {
//                         return;
//                     }
//                 }
//             } else {
//                 consecutive_zeros = 0;
//             }
//         } else if (set == 0) {
//             // Establecer bits en 0
//             if ((bitmap[byte_index] & (1 << bit_offset)) != 0) {
//                 consecutive_zeros++;
//                 if (consecutive_zeros == 1) {
//                     start_index = i;
//                 }
//                 if (consecutive_zeros == units_to_modify) {
//                     for (size_t j = start_index; j < start_index + units_to_modify; j++) {
//                         size_t byte_idx = j / 8;
//                         size_t bit_off = j % 8;
//                         bitmap[byte_idx] &= ~(1 << bit_off);
//                         units_modified++;
//                     }
//                     if (units_modified == units_to_modify) {
//                         return;
//                     }
//                 }
//             } else {
//                 consecutive_zeros = 0;
//             }
//         }
//     }
// }
