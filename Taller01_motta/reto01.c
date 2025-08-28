/** Fecha:27/08/2025
 * Autor: Juan Pablo Motta Talero 
 * Materia: Sistemas Operativos*/
//* Programa de demostración de manejo de memoria dinámica en C.
#include <stdio.h>   // printf
#include <string.h>  // strcpy
#include <stdlib.h>  // malloc, free

int main() {
    /*
     * p y q son punteros a char. Se usarán para almacenar cadenas copiadas con strcpy.
     * Inicialmente no apuntan a memoria válida para escritura; por eso reservamos memoria.
     */
    char *p;
    char *q = NULL;

    /*
     * Reserva de memoria dinámica.
     * Elegimos 100 bytes para cada puntero como tamaño suficiente para las cadenas usadas. */
    p = (char *)malloc(100 * sizeof(char));
    q = (char *)malloc(100 * sizeof(char));

    /* * Comprobación de errores: si malloc falla, devuelve NULL.   */
    if (p == NULL || q == NULL) {
        printf("Error reservando memoria\n");
        /* Si uno de los malloc falló y el otro no, liberamos el que sí reservó. */
        free(p);
        free(q);
        return 1;
    }

    /*
     * Imprimimos la dirección que contiene 'p'.
     * Se usa el especificador %p para direcciones de memoria.    */
    printf("Address of p = %p\n", (void *)p);

    /*
     * Copiamos una cadena literal a la memoria apuntada por 'p'.  */
    strcpy(p, "Hello, I'm the best in Operating Systems!!!");
 /*     * Mostramos el contenido recién copiado en 'p'.
     */
    printf("%s\n", p);
    /*
     * Mensaje informativo previo a copiar en 'q' (manteniendo exactamente el texto pedido).
     */
    printf("About to copy \"Goodbye\" to q\n");
    /*
     * Copiamos "Goodbye" a la memoria apuntada por 'q'.
     * Igual que con 'p', 'q' ya apunta a un bloque de 100 bytes, por lo que es seguro.
     */
    strcpy(q, "Goodbye");
    /*
     * Confirmamos la copia y luego imprimimos el contenido de 'q'.
     */
    printf("String copied\n");
    printf("%s\n", q);

    /*
     * Liberamos la memoria dinámica reservada para evitar fugas (memory leaks).*/
    free(p);
    free(q);
    /*
     * Retorno exitoso.
     */
    return 0;
}



