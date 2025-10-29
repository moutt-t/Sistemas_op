/*********************************************************************************************
 * Pontificia Universidad Javeriana
 * Materia: Sistemas Operativos
 * Docente: J. Corredor, PhD
 * Autor: Juan Pablo Motta Talero
 * Fecha: 28/10/2025
 * Tema: POSIX para la creación de hilos concurrentes
 *
 * Descripción:
 * -------------------------------------------------------------------------------------------
 * Este programa demuestra el uso de hilos POSIX para el procesamiento concurrente de datos.
 * En particular, se busca el valor máximo dentro de un vector de números enteros utilizando
 * varios hilos que procesan distintos segmentos del vector en paralelo.
 *
 * El vector de datos se lee desde un archivo de texto, cuyo formato es:
 *     <n>         → número de elementos
 *     <x1> <x2> <x3> ... <xn> → elementos del vector
 *
 * Ejemplo de uso:
 *     ./maximo datos.txt 4
 *
 * donde "4" representa el número de hilos que se crearán.
 * Cada hilo busca el máximo parcial en una sección del vector, y luego el hilo principal
 * combina los resultados para obtener el máximo global.
 *********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//------------------------------------------------------------
// Estructura de parámetros a pasar a cada hilo
//------------------------------------------------------------
typedef struct {
    int inicio;       // Índice inicial del segmento
    int fin;          // Índice final (no inclusivo)
    int *vector;      // Puntero al vector de datos
    int maxparcial;   // Resultado parcial (máximo local)
} param_H;

//------------------------------------------------------------
// Función ejecutada por cada hilo: busca el máximo parcial
//------------------------------------------------------------
void *buscarMax(void *parametro) {
    param_H *args = (param_H *)parametro;
    args->maxparcial = args->vector[args->inicio];

    for (int i = args->inicio + 1; i < args->fin; i++) {
        if (args->vector[i] > args->maxparcial)
            args->maxparcial = args->vector[i];
    }

    pthread_exit(NULL);
    return NULL;
}

//------------------------------------------------------------
// Función que gestiona la creación de hilos y obtiene el máximo global
//------------------------------------------------------------
int maximoValor(int *vector, int n, int nhilos) {
    pthread_t hilos[nhilos];
    param_H parametros[nhilos];

    int tam_segmento = n / nhilos;
    int resto = n % nhilos;
    int inicio = 0;

    // Crear los hilos y asignar sus rangos
    for (int i = 0; i < nhilos; i++) {
        parametros[i].inicio = inicio;
        parametros[i].fin = inicio + tam_segmento + (i < resto ? 1 : 0);
        parametros[i].vector = vector;

        pthread_create(&hilos[i], NULL, buscarMax, &parametros[i]);
        inicio = parametros[i].fin;
    }

    // Esperar a que terminen los hilos
    for (int i = 0; i < nhilos; i++) {
        pthread_join(hilos[i], NULL);
    }

    // Calcular el máximo global
    int max_global = parametros[0].maxparcial;
    for (int i = 1; i < nhilos; i++) {
        if (parametros[i].maxparcial > max_global)
            max_global = parametros[i].maxparcial;
    }

    return max_global;
}

//------------------------------------------------------------
// Función principal
//------------------------------------------------------------
int main(int argc, char *argv[]) {
    FILE *fichero;
    int n, nhilos, ret;
    int *vec;

    if (argc != 3) {
        fprintf(stderr, "Uso correcto: %s <archivo> <num_hilos>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fichero = fopen(argv[1], "r");
    if (fichero == NULL) {
        perror("No se puede abrir el archivo");
        exit(EXIT_FAILURE);
    }

    if (fscanf(fichero, "%d", &n) != 1) {
        fprintf(stderr, "Error al leer tamaño del vector\n");
        fclose(fichero);
        exit(EXIT_FAILURE);
    }

    nhilos = atoi(argv[2]);
    if (nhilos <= 0 || nhilos > n) {
        fprintf(stderr, "Número de hilos inválido\n");
        fclose(fichero);
        exit(EXIT_FAILURE);
    }

    vec = malloc(sizeof(int) * n);
    if (vec == NULL) {
        fprintf(stderr, "Error al reservar memoria\n");
        fclose(fichero);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        if (fscanf(fichero, "%d", &vec[i]) != 1) {
            fprintf(stderr, "Error al leer elemento %d\n", i);
            free(vec);
            fclose(fichero);
            exit(EXIT_FAILURE);
        }
    }

    fclose(fichero);

    int maximo = maximoValor(vec, n, nhilos);
    printf("Máximo encontrado: %d\n", maximo);

    free(vec);
    return 0;
}
