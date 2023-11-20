# obligatorio-so
Obligatorio - Sistemas Operativos 2023


Funcion Clear_bits


void clear_bits(unsigned char *bitmap, size_t start_index, size_t units_to_free);


Esta función establece a 0 los bits específicos en el bitmap.
Comienza desde el índice start_index y se extiende hasta start_index + units_to_free - 1.
Utiliza operaciones de máscara para lograr esta tarea.


Parámetros:
- bitmap: Puntero al array de bytes que representa el bitmap.
- start_index: Índice del primer bit a establecer a 0.
- units_to_free: Número de bits que se establecerán a 0.


Ejemplo de uso


unsigned char my_bitmap[8] = {255, 255, 255, 255, 255, 255, 255, 255};
clear_bits(my_bitmap, 10, 5);  // Establecer a 0 los bits del índice 10 al 14


--------------------------------------------------------------


Función first_fit


Esta función busca un espacio contiguo en un mapa de bits representado como un array de bytes.
El objetivo es encontrar un espacio consecutivo de bits con el tamaño especificado y marcar esos bits como ocupados.


int first_fit(unsigned char *bitmap, size_t bitmap_size, size_t units_needed);


Parámetros
-bitmap: Puntero al array de bytes que representa el mapa de bits.
-bitmap_size: Tamaño del mapa de bits en bytes.
-units_needed: Número de bits consecutivos necesarios.


Retorno
La función devuelve el índice del primer bit del espacio contiguo si se encuentra; de lo contrario, devuelve -1.


Ejemplo de Uso
unsigned char mi_mapa_bits[8] = {0};  // Inicializando un mapa de bits con todos los ceros
int indice = first_fit(mi_mapa_bits, 8, 3);  // Buscar espacio para 3 bits consecutivos


Notas
-La función utiliza un contador para rastrear los ceros consecutivos.
-Itera a través de cada bit del mapa de bits.
-Marca los bits consecutivos necesarios como ocupados.
-Devuelve el índice del primer bit del espacio contiguo si se encuentra.
-Devuelve -1 si no se encuentra un espacio suficiente.


--------------------------------------------------------------


Función set_or_clear_bits


void set_or_clear_bits(int set, Bitmap bitmap, uint16_t start_byte_index, uint16_t start_bit_index, uint16_t qty);


Esta función está diseñada para establecer o limpiar bits dentro de un mapa de bits representado como un array de bytes.
La operación comienza desde un índice específico de byte y bit y se extiende por una cantidad dada.


Parámetros
-set: Un entero que indica la acción a realizar. Si set es 1, establece los bits en 1; si es 0, establece los bits en 0.
-bitmap: Puntero al array de bytes que representa el mapa de bits.
-start_byte_index: Índice del byte de inicio.
-start_bit_index: Índice del bit de inicio dentro del byte de inicio.
-qty: Número de bits que se establecerán o limpiarán.


Ejemplo de uso


unsigned char mi_mapa_bits[8] = {0};  // Inicializando un mapa de bits con todos los ceros
set_or_clear_bits(1, mi_mapa_bits, 1, 2, 5);  // Establecer 5 bits comenzando desde el byte 1, bit 2 a 1


Nota


-La función utiliza una máscara para identificar el bit dentro del byte.
-Itera a través de los bits comenzando desde start_byte_index y start_bit_index.
-El parámetro set determina si se establecerán los bits en 1 (set = 1) o 0 (set = 0).
-La función ajusta la máscara para cada posición de bit.
-qty representa la cantidad de bits que se establecerán o limpiarán.
-La función reinicia start_bit_index para cada nuevo byte.


--------------------------------------------------------------


Main


Este es un programa de ejemplo que utiliza las funciones first_fit, clear_bits y set_or_clear_bits proporcionadas en el archivo my_malloc_manager.h.
El programa ilustra cómo trabajar con un mapa de bits, encontrar espacio, liberar espacio y establecer o borrar bits en el mapa.


Descripción del Programa
- Inicialización del Bitmap: Se crea un array bitmap de tamaño BITMAP_SIZE e inicializado con ceros.
- Espacio con first_fit: Se utiliza la función first_fit para encontrar un espacio consecutivo de bits. Si se encuentra, se imprime el índice y se marca el espacio como ocupado.
- Liberación con clear_bits: Se utiliza la función clear_bits para liberar un espacio de bits a partir del índice obtenido anteriormente. Se imprime el estado actual del bitmap después de la liberación.
- Set y Clear con set_or_clear_bits: Se utilizan las funciones set_or_clear_bits para establecer y borrar bits en el bitmap. Se imprime el estado del bitmap después de cada operación.


Para ejecutar el programa, simplemente compílelo con el siguiente comando:


gcc -o example_program example_program.c my_malloc_manager.c
./example_program


Notas.
Asegúrese de tener correctamente definidas las funciones y constantes necesarias en my_malloc_manager.h.


--------------------------------------------------------------