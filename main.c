#include "my_malloc_manager.h"

#define BITMAP_SIZE 16

int main() {
    unsigned char bitmap[BITMAP_SIZE] = {0};
    
    printf("\n");
    printf("Bitmap inicial\n");
    print_bitmap(bitmap, BITMAP_SIZE);
    printf("\n");

    size_t units_needed = 30;

    int index = first_fit(bitmap, BITMAP_SIZE, units_needed);

    if (index != -1) {
        printf("Espacio de %zu bits encontrado a partir del índice %d\n", units_needed, index);
        print_bitmap(bitmap, BITMAP_SIZE);
        printf("\n");
    } else {
        printf("No se encontró espacio suficiente para la cantidad de bits necesarios.\n");
        printf("\n");
    }

    return 0;
}
