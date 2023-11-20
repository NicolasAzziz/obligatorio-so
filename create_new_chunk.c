#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <error.h>
#include "my_malloc_manager.h"

uint16_t chunk_current_id = 0;

void* create_new_chunk(uint16_t units_needed, int is_large_allocation, MemoryChunkHeader *next) {

    if (is_large_allocation != 0) {
        fprintf(stderr, "Error: is_large_allocation debe ser 0.\n");
        exit(EXIT_FAILURE);
    }

    // Calcula el tamaño total en unidades
    // uint16_t total_units_to_mmap = units_needed + 1; // +1 para el encabezado

    // If is_large_allocation, add the units needed for the MemoryChunkHeader structure
    uint16_t total_units_to_mmap = is_large_allocation ? units_needed + STRUCT_UNITS : UNITS_PER_CHUNK;

    // Utiliza mmap para asignar memoria
    void* mem = mmap(NULL, total_units_to_mmap * UNIT_SIZE, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    if (mem == MAP_FAILED) {
        perror("Error en el mapeo de memoria");
        exit(EXIT_FAILURE);
    }

    // Configuracion del encabezado en la memoria asignada
    MemoryChunkHeader* header = (MemoryChunkHeader*)mem;
    header->id = chunk_current_id++;
    header->is_large_allocation = 0;
    header->chunk_total_units = units_needed;
    header->chunk_available_units = units_needed;
    header->bitmap = (Bitmap)((char*)mem + UNIT_SIZE*STRUCT_UNITS);
    header->bitmap_size = BITMAP_SIZE;
    header->next = next;

    return header;
}