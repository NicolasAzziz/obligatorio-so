// my_malloc_manager.h

#ifndef MY_ALLOC_MANAGER_H // prevent multiple includes
#define MY_ALLOC_MANAGER_H 1
// Standard includes
#include <errno.h>  // for errno
#include <error.h>  // for error handling of system calls: man 3 error
#include <stddef.h> // for size_t
#include <stdio.h>  // for I/O functions
#include <stdlib.h> // for EXIT_FAILURE
#include <string.h> // for string manipulation functions
#include <stdint.h>    // for uint16_t

// #define BITMAP_SIZE 16 // in bytes
#define BITMAP_SIZE (uint16_t)16 // in bytes
#define UNIT_SIZE (uint16_t)16   // minimum unit to assign, in bytes
#define UNITS_PER_CHUNK (uint16_t)(BITMAP_SIZE * 8)

typedef unsigned char *Bitmap;

typedef struct MemoryChunkHeader // All chunks have this header
{
    uint16_t id;                    // id of the chunk, useful for debugging
    uint16_t is_large_allocation;   // Flag to indicate if this is for a single large allocation
    uint16_t chunk_total_units;     // Size of the memory block in units
    uint16_t chunk_available_units; // How many units are available
    Bitmap bitmap;                  // Pointer to the bitmap for this chunk, NULL if is_large_allocation
    uint16_t bitmap_size;           // Size of bitmap in bytes, 0 if is_large_allocation
    struct MemoryChunkHeader *next; // Pointer to the next MemoryChunkHeader, NULL if last one
} MemoryChunkHeader;

typedef struct AllocationHeader // All malloc calls have a this header located before the returned address
{
    uint16_t nunits;    // number of units
    uint16_t bit_index; // offset from the MemoryChunkHeader struct
} AllocationHeader;
 
// Funciones
extern int first_fit(unsigned char *bitmap, size_t bitmap_size, size_t units_needed);
extern void print_bitmap(unsigned char *bitmap, size_t bitmap_size);
extern void clear_bits(unsigned char *bitmap, size_t start_index, size_t units_to_free);
void set_or_clear_bits(int set, Bitmap bitmap, uint16_t start_byte_index, uint16_t start_bit_index, uint16_t qty);
// extern void set_or_clear_bits(int set, unsigned char *bitmap, size_t bitmap_size, size_t units_to_modify);


#endif // MY_ALLOC_MANAGER_H