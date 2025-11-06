/*
 ============================================================================
 Nombre del archivo : Lab02.c
 Autor              : Juan Pablo Motta Talero 
 Fecha              : 6/11/2025
 Descripción        : Laboratorio 02 - Introducción a OpenMP
 ============================================================================
 Este programa demuestra el uso básico de OpenMP para la creación de hilos
 en paralelo. El usuario debe proporcionar como argumento el número de hilos
 con los cuales se desea ejecutar el programa. Cada hilo imprimirá un mensaje
 indicando su número dentro del equipo de ejecución.

 Compilación:
     gcc -fopenmp Lab02.c -o Lab02
 ============================================================================
*/

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    // Verificación de argumentos
    if (argc != 2) {
        printf("ERROR\n\tUso: ./Lab01 numHilos\n");
        exit(0);
    }

    // Conversión del argumento a entero
    int numHilos = atoi(argv[1]);

    // Obtener la cantidad máxima de hilos disponibles
    int maxHilos = omp_get_max_threads();
    printf("OpenMP ejecutando en cores = %d hilos disponibles\n", maxHilos);

    // Establecer el número de hilos a utilizar
    omp_set_num_threads(numHilos);

    // Región paralela: cada hilo imprime su identificador
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        printf("Hola mundo desde el thread %d\n", id);
    }

    return 0;
}
