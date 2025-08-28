/** Fecha:27/08/2025
 * Autor: Juan Pablo Motta Talero 
 * Materia: Sistemas Operativos*/
#include <stdio.h>   // Para printf
#include <stdlib.h>  // Para malloc y free

int main() {
    int *ptr;  // Declaramos un puntero a entero

    // Reservamos memoria dinámica para 15 enteros
    ptr = malloc(15 * sizeof(*ptr)); /* a block of 15 integers */

    // Verificamos que la reserva fue exitosa
    if (ptr != NULL) {
        // Asignamos el valor 480 al sexto entero (índice 5, ya que empieza en 0)
        *(ptr + 5) = 480;

        // Mostramos el valor en pantalla
        printf("El sexto entero es: %d\n", *(ptr + 5));

        // Liberamos la memoria reservada para evitar fugas
        free(ptr);
    }

    // Fin del programa
    return 0;
}

