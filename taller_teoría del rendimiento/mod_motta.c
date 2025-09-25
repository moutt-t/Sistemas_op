/**
 * Fecha:24/09/2025
 * Autor: Juan Pablo Motta Talero
 * Materia: Sistemas Operativos
 * Tema: Teoría del rendimiento
 * Objetivo: Hacer una metodología para la implementación de la multiplicación de matrices. 
*************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "modulo.h"
int main(int argc, char *argv[]) {
    // Se mira que el usuari ingrese los dos argumento, la dimencion de la matriz y los hilos 
    if(argc <= 2){
        printf("Numero de argumentos incorrectos\n");
        printf("\n\tUso: ejecutable.exe DIM\n");
        return -1; 
    }

    int N = (int) atof(argv[1]);

    // se mira que el argumento no sea 0 
    if(N <= 0){
        printf("\nValores deben ser mayores que cero\n");
        return -1; 
    };

    // Reserva dinámica de memoria para las matrices con calloc
    mA = (double *) malloc(N * N * sizeof(double));
    mB = (double *) malloc(N * N * sizeof(double));
    mC = (double *) calloc(N * N, sizeof(double));

    /** Se inicializan las matrices mA y mB **/
    iniMatriz(N, mA, mB);

    // Se imprimen las matrices iniciales si N < 9 (la función lo valida)
    imprMatrices(N, mA);
    imprMatrices(N, mB);

    InicioMuestra();
    // multiplicación de matrices 
    multimatrizclasica(mA, mB, mC, N);

    // Marca de tiempo final y cálculo del tiempo de ejecución
    FinMuestra();

    //imprime la matriz resultante 
    imprMatrices(N, mC);

    printf("\n\tFin del programa.............!\n");

    // Se libera la memoria reservada
    free(mA);
    free(mB);
    free(mC);

    return 0; 
}
