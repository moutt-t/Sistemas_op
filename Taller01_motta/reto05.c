/** Fecha:27/08/2025
 * Autor: Juan Pablo Motta Talero 
 * Materia: Sistemas Operativos*/
#include <stdio.h>    // printf, scanf
#include <stdlib.h>   // malloc, realloc, free

int main() {
    int *ptr, i, n1, n2;

    // Pedir al usuario el tamaño inicial del bloque
    printf("Enter size: ");
    scanf("%d", &n1);

    // Reservar memoria dinámica para n1 enteros
    ptr = (int *)malloc(n1 * sizeof(int));
    if (ptr == NULL) { // Verificar si malloc falló
        printf("Error! memory not allocated.\n");
        return 1;
    }

    // Mostrar las direcciones de memoria asignadas inicialmente
    printf("Addresses of previously allocated memory: ");
    for (i = 0; i < n1; ++i)
        printf("\n\np = %p\n", (void *)(ptr + i));

    // Pedir un nuevo tamaño para redimensionar el bloque
    printf("\n Enter the new size: ");
    scanf("%d", &n2);

    // Redimensionar la memoria usando realloc
    int *tmp = (int *)realloc(ptr, n2 * sizeof(int));
    if (tmp == NULL) { // Verificar si realloc falló
        printf("Error! memory not reallocated.\n");
        free(ptr); // Liberar el bloque original antes de salir
        return 1;
    }
    ptr = tmp; // Actualizar el puntero si realloc fue exitoso

    // Mostrar las direcciones de memoria tras realloc
    printf("Addresses of newly allocated memory: ");
    for (i = 0; i < n2; ++i)
        printf("\n\np = %p\n", (void *)(ptr + i));

    // Liberar la memoria cuando ya no se usa
    free(ptr);

    return 0;
}
