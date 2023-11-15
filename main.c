#include "my_malloc_manager.h"
#include <stdint.h>
#include <stdio.h>

int main() {
    unsigned char bitmap[BITMAP_SIZE] = {0};
    size_t units_needed = 30;
    size_t units_to_free = 10;
    
    printf("\n");
    printf("Bitmap inicial\n");
    print_bitmap(bitmap, BITMAP_SIZE);
    printf("\n");

    int index = first_fit(bitmap, BITMAP_SIZE, units_needed);

    if (index != -1) {
        printf("Espacio de %zu bits encontrado a partir del índice %d\n", units_needed, index);
        print_bitmap(bitmap, BITMAP_SIZE);
        printf("\n");

        clear_bits(bitmap, index, units_to_free);
        printf("Espacio de %zu bits liberado con funcion CLEAR_BITS a partir del índice %d\n", units_to_free, index);
        print_bitmap(bitmap, BITMAP_SIZE);
        printf("\n");
    } else {
        printf("No se encontró espacio suficiente para la cantidad de bits necesarios.\n");
        printf("\n");
    }

    uint16_t start_byte_index = 8;
    uint16_t start_bit_index = 3;
    uint16_t qty = 8;
    
    set_or_clear_bits(1, bitmap, start_byte_index, start_bit_index, qty);
    // set_or_clear_bits(1, bitmap, BITMAP_SIZE, units_needed);
    // printf("Espacio de %" PRIu16 " bits encontrado\n", qty);
    printf("SET_OR_CLEAR_BITS SET = 1\n");
    print_bitmap(bitmap, BITMAP_SIZE);
    printf("\n");

    set_or_clear_bits(0, bitmap, start_byte_index, start_bit_index, qty);
    //set_or_clear_bits(0, bitmap, BITMAP_SIZE, units_to_free);
    // printf("Espacio de %zu bits liberado con funcion SET_OR_CLEAR_BITS\n", qty);
    printf("SET_OR_CLEAR_BITS SET = 0\n");
    print_bitmap(bitmap, BITMAP_SIZE);
    printf("\n");


    return 0;
}
