#include <stddef.h>
#include "my_malloc_manager.h"

void* my_malloc(size_t nbytes) {
    // Calcula la cantidad de unidades necesarias, incluyendo el encabezado
    size_t units_needed = (nbytes + sizeof(MemoryChunkHeader) - 1) / UNIT_SIZE + 1;

    // Puntero al primer chunk
    MemoryChunkHeader* current_chunk = first_chunk;

    // Busca un chunk con suficiente espacio
    while (current_chunk != NULL) {
        if (current_chunk->is_large_allocation == 0 && current_chunk->chunk_available_units >= units_needed) {
            // Encontró un chunk con suficiente espacio, utiliza First Fit
            void* allocated_memory = allocate_within_chunk(current_chunk, units_needed);
            if (allocated_memory != NULL) {
                return allocated_memory;
            }
        }
        current_chunk = current_chunk->next;
    }

    // No se encontró un chunk con suficiente espacio, crea uno nuevo
    current_chunk = create_new_chunk(units_needed, 0, first_chunk);
    first_chunk = current_chunk;

    // Utiliza First Fit en el nuevo chunk
    return allocate_within_chunk(current_chunk, units_needed);
}

void* allocate_within_chunk(MemoryChunkHeader* chunk, size_t units_needed) {
    // Puntero al inicio del chunk
    void* chunk_start = (void*)chunk;

    // Puntero a la posición actual dentro del chunk
    void* current_position = chunk_start + sizeof(MemoryChunkHeader);

    // Encuentra el índice de inicio del espacio disponible utilizando First Fit
    int start_index = first_fit((unsigned char*)current_position, chunk->bitmap_size, units_needed);

    if (start_index != -1) {
        // Se encontró espacio adecuado, actualiza el encabezado y retorna el puntero
        MemoryChunkHeader* current_header = (MemoryChunkHeader*)current_position;
        current_header->chunk_available_units = units_needed;

        // Calcula la dirección del espacio alocado
        void* allocated_memory = current_position + start_index * UNIT_SIZE + sizeof(MemoryChunkHeader);

        return allocated_memory;
    }

    // No se encontró espacio adecuado en el chunk
    return NULL;
}
