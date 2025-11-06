/*
 ============================================================================
 Nombre del archivo : Lab01.c
 UNIVERSIDAD        : Pontificia Universidad Javeriana
 PROGRAMA           : Ingeniería de Sistemas
 MATERIA            : Sistemas Operativos
 Autor              : Juan Pablo Motta Talero
 Fecha              : 6/11/2025
 Descripción        : Laboratorio 01 - Introducción a OpenMP
 ============================================================================
 Objetivo:
     Este laboratorio tiene como propósito introducir el uso de la librería 
     OpenMP para la creación de secciones paralelas y la ejecución de tareas 
     concurrentes en múltiples hilos. El programa muestra la cantidad de hilos 
     disponibles y ejecuta un bloque de código en paralelo, donde cada hilo 
     imprime su identificador.

 Compilación:
     gcc -fopenmp Lab01.c -o Lab01
 ============================================================================
*/

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Mostrar la cantidad máxima de hilos disponibles
    printf("OpenMP ejecutando con %d hilos\n", omp_get_max_threads());

    // Región paralela: cada hilo imprime su número de identificación
    #pragma omp parallel
    {
        int id = omp_get_thread_num();  // Identificador del hilo
        printf("Hello World desde el thread %d\n", id);
    }

    return 0;
}

