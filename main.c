#include "my_malloc_manager.h"
#include <stdint.h>

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

    units_needed = 20;
    units_to_free = 10;

    set_or_clear_bits(1, bitmap, BITMAP_SIZE, units_needed);
    printf("Espacio de %zu bits encontrado\n", units_needed);
    print_bitmap(bitmap, BITMAP_SIZE);
    printf("\n");

    set_or_clear_bits(0, bitmap, BITMAP_SIZE, units_to_free);
    printf("Espacio de %zu bits liberado con funcion SET_OR_CLEAR_BITS\n", units_to_free);
    print_bitmap(bitmap, BITMAP_SIZE);
    printf("\n");


    return 0;
}
