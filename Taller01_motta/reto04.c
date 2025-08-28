/** Fecha:27/08/2025
 * Autor: Juan Pablo Motta Talero 
 * Materia: Sistemas Operativos*/
#include <stdio.h>   // printf, scanf
#include <stdlib.h>  // calloc, free, exit

int main() {
    int n, i, *ptr, sum = 0;

    // Pedir la cantidad de elementos
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Reservar memoria dinámica para n enteros, inicializados en 0
    ptr = (int*) calloc(n, sizeof(int));
    if (ptr == NULL) {
        printf("Error! memory not allocated.");
        exit(0);
    }

    // Leer los elementos uno por uno, mostrando el índice
    for (i = 0; i < n; ++i) {
        printf("Enter elements %d :", i + 1);
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }

    // Mostrar la suma calculada
    printf("Sum = %d\n", sum);

    // Liberar memoria
    free(ptr);

    return 0;
}
