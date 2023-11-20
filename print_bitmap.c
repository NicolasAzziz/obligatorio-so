#include <stdio.h>
#include <stddef.h>

void print_bitmap(unsigned char *bitmap, size_t bitmap_size_in_bytes)
{
    for (size_t i = 0; i < bitmap_size_in_bytes; ++i) {
        for (int j = 7; j >= 0; --j) {
            printf("%d", (bitmap[i] >> j) & 1);
        }
        printf(" ");
    }
    printf("\n");
}

// void print_bitmap(unsigned char *bitmap, size_t bitmap_size) {
//     for (size_t i = 0; i < bitmap_size; i++) {
//         unsigned char byte = bitmap[i];
        
//         if (byte == 1) {
//             for (int j = 0; j <= 7; j++) {
//                 printf("1");
//             }
//         } else {
//             for (int j = 0; j <= 7; j++) {
//                 if (byte & (1 << j)) {
//                     printf("1");
//                 } else {
//                     printf("0");
//                 }
//             }
//         }

//         if (i < bitmap_size - 1) {
//             printf(" ");
//         }
//     }
//     printf(".\n");
// }
