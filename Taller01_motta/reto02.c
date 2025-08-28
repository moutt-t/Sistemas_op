/** Fecha:27/08/2025
 * Autor: Juan Pablo Motta Talero 
 * Materia: Sistemas Operativos*/
#include <stdio.h>   // printf, perror
#include <stdlib.h>  // malloc, exit
#include <string.h>  // strlen, strcpy

int main() {
    char *q = NULL;

    // Aviso antes de reservar memoria
    printf("Requesting space for \"Goodbye\" \n");

    // Reservamos memoria suficiente para "Goodbye" + '\0'
    q = (char *)malloc(strlen("Goodbye") + 1);

    // Validamos que malloc no haya fallado
    if (!q) {
        perror("Failed to allocate space because");
        exit(1);
    }

    // Mostramos la dirección de memoria reservada
    printf("About to copy \"Goodbye\" to q at address %p \n", (void *)q);

    // Copiamos la cadena a la memoria reservada
    strcpy(q, "Goodbye");

    // Confirmamos y mostramos el contenido
    printf("String copied\n");
    printf("%s \n", q);

    // Liberamos la memoria para evitar fugas
    free(q);

    return 0;
}

