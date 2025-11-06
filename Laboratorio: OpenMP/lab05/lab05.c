/*
 ============================================================================
 Nombre del archivo : Lab05.c
 UNIVERSIDAD: Pontificia Universidad Javeriana
 PROGRAMA: Ingeniería de Sistemas
 MATERIA: Sistemas Operativos
 AUTOR: Juan Pablo Motta Talero
 FECHA: 06/11/2025
 DESCRIPCIÓN:
    Laboratorio - Cálculo de sumatorias con la función seno usando OpenMP.
    Este programa calcula la sumatoria de sin(x) para una cantidad de
    iteraciones definida por el usuario, distribuyendo la carga entre
    múltiples hilos (threads) y midiendo el tiempo total de ejecución.
  COMPILACIÓN:
  gcc -fopenmp Lab05.c -o Lab05 -lm
  EJECUCIÓN:
  ./Lab05 4 30000
 ============================================================================
 */

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MIN(x, y) (((x) < (y)) ? (x) : (y))

// ------------------------------------------------------------
// Función que calcula una sumatoria parcial de senos
// ------------------------------------------------------------
double funcion(int i) {
    int j, inicio = i * (i + 1) / 2, fin = inicio + 1;
    double valor = 0;

    for (j = inicio; j < fin; j++) {
        valor += sin(j);
    }

    return valor;
}

// ------------------------------------------------------------
// Función principal
// ------------------------------------------------------------
int main(int argc, char *argv[]) {

    // Verificación de argumentos
    if (argc != 3) {
        printf("Uso: %s <num_hilos> <num_iteraciones>\n", argv[0]);
        return 1;
    }

    // Lectura de parámetros desde la línea de comandos
    int num_hilos = atoi(argv[1]);
    int n = atoi(argv[2]);

    double suma = 0.0;
    double tiempo_inicio, tiempo_fin;

    // Configurar número de hilos
    omp_set_num_threads(num_hilos);

    // Medir tiempo de inicio
    tiempo_inicio = omp_get_wtime();

    // Región paralela con reducción
    #pragma omp parallel
    {
        int threads = omp_get_num_threads();

        #pragma omp master
        printf("Número de Hilos: %d\n", threads);

        #pragma omp for reduction(+:suma)
        for (int i = 0; i <= n; i++) {
            suma += funcion(i);
        }
    }

    // Medir tiempo final
    tiempo_fin = omp_get_wtime();

    // Calcular duración
    double tiempo_total = tiempo_fin - tiempo_inicio;

    // Mostrar resultados
    printf("\n=====================================\n");
    printf("Cantidad de iteraciones: %d\n", n);
    printf("Número de hilos usados:  %d\n", num_hilos);
    printf("La sumatoria total es:   %.4f\n", suma);
    printf("Tiempo total de ejecución: %.6f segundos\n", tiempo_total);
    printf("=====================================\n");

    return 0;
}
