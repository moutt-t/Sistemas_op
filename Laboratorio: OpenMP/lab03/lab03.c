/*
 ============================================================================
 Nombre del archivo : Lab03.c
 UNIVERSIDAD        : Pontificia Universidad Javeriana
 PROGRAMA           : Ingeniería de Sistemas
 MATERIA            : Sistemas Operativos
 Autor              : Juan Pablo Motta Talero
 Fecha              : 6/11/2025
 Descripción        : Laboratorio 03 - Variables privadas y paralelismo con OpenMP
 ============================================================================
 Objetivo:
     Este laboratorio demuestra el uso de las cláusulas `private` dentro
     de una región paralela `for` en OpenMP. Se observa cómo las variables
     locales a cada hilo no interfieren entre sí, y cómo las variables
     compartidas mantienen su valor fuera de la región paralela.

 Compilación:
     gcc -fopenmp Lab03.c -o Lab03
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

    // Región paralela con bucle for
    // 'i' y 'a' se declaran privadas: cada hilo tiene su propia copia
    #pragma omp parallel for private(i) firstprivate(a)
    for (i = 0; i < N; i++) {
        b = a + i;   // Cálculo local dentro de cada hilo
    }

    // 'b' al final tomará un valor de alguna de las iteraciones
    printf("a = %d, b = %d (Se espera a = 50, b = 1049)\n", a, b);

    return 0;
}
