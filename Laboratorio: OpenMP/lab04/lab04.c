/*
 ============================================================================
 Nombre del archivo : Lab04.c
 UNIVERSIDAD        : Pontificia Universidad Javeriana
 PROGRAMA           : Ingeniería de Sistemas
 MATERIA            : Sistemas Operativos
 Autor              : Juan Pablo Motta Talero
 Fecha              : 6/11/2025
 Descripción        : Laboratorio 04 - Variables privadas en regiones paralelas
 ===========================================================================
 Objetivo:
     Este laboratorio extiende el uso de la directiva `private` de OpenMP 
     aplicándola a todas las variables involucradas en el bucle paralelo.
     De esta forma, cada hilo mantiene sus propias copias independientes 
     de `i`, `a` y `b`, evitando condiciones de carrera y comportamientos 
     indeterminados.

 Compilación:
     gcc -fopenmp Lab04.c -o Lab04
 ============================================================================
*/

#include <omp.h>    // Header necesario para invocar la API de OpenMP
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;                  // Variable de control del bucle
    const int N = 1000;     // Límite superior del bucle
    int a = 50;             // Variable base
    int b = 0;              // Variable resultado

    // Región paralela: todas las variables se declaran privadas
    #pragma omp parallel for private(i) private(a) private(b)
    for (i = 0; i < N; i++) {
        b = a + i;   // Cada hilo tiene su propia versión de a, b e i
    }

    // Fuera de la región paralela se imprime el valor original de a y b
    printf("a = %d, b = %d (Se espera a = 50, b = 1049)\n", a, b);

    return 0;
}
