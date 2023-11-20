#include "my_malloc_manager.h"
#include <stdint.h>
#include <stdio.h>

int main() {
    size_t units_needed = 30;
    
    MemoryChunkHeader* nextChunk = NULL;
    units_needed = 10;
    int is_large_allocation = 0;

    MemoryChunkHeader* allocated_memory = create_new_chunk(units_needed, is_large_allocation, nextChunk);
    // Obtén la dirección de memoria
    printf("La dirección de memoria a la que apunta allocated_memory es: %p\n", allocated_memory);
    printf("\n");

    Bitmap bitmap = allocated_memory->bitmap;

    // unsigned char bitmap[BITMAP_SIZE] = {0};

    uint16_t start_byte_index = 2;
    uint16_t start_bit_index = 3;
    uint16_t qty = 8;
    
    printf("\n");
    printf("Bitmap inicial\n");
    print_bitmap(bitmap, BITMAP_SIZE);
    printf("\n");

    int index = first_fit(bitmap, BITMAP_SIZE, units_needed);

    if (index != -1) {
        printf("Espacio de %zu bits encontrado a partir del índice %d\n", units_needed, index);
        print_bitmap(bitmap, BITMAP_SIZE);
        printf("\n");

    } else {
        printf("No se encontró espacio suficiente para la cantidad de bits necesarios.\n");
        printf("\n");
    }

    // clear_bits(bitmap, start_byte_index, start_bit_index, qty);
    // printf("CLEAR_BITS\n");
    // print_bitmap(bitmap, BITMAP_SIZE);
    // printf("\n");
    
    
    set_or_clear_bits(0, bitmap, start_byte_index, start_bit_index, qty);
    printf("SET_OR_CLEAR_BITS SET = 0 a partir del byte %hd\n", start_byte_index);
    print_bitmap(bitmap, BITMAP_SIZE);
    printf("\n");
    
    start_byte_index = 4;
    start_bit_index = 3;
    qty = 8;

    set_or_clear_bits(1, bitmap, start_byte_index, start_bit_index, qty);
    printf("SET_OR_CLEAR_BITS SET = 1\n");
    print_bitmap(bitmap, BITMAP_SIZE);
    printf("\n");



    return 0;
}
