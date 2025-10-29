/**************************************************************
* Fecha: 28/10/2025
* Autor: Juan Pablo Motta Talero
* Materia: Sistemas Operativos
* Tema: Paralelización del cálculo de la suma de cuadrados utilizando hilos POSIX (pthread)
*
* Descripción general:
* ------------------------------------------------------------
* Este programa demuestra el uso de hilos POSIX (pthreads) 
* para dividir el trabajo de cálculo computacional costoso en 
* múltiples hilos de ejecución, aplicando el concepto de 
* paralelización. En este caso, se calcula la suma de los 
* cuadrados de los números del 1 al 20, donde cada hilo se 
* encarga de procesar un número y sumar su cuadrado a una 
* variable global compartida.
* Objetivo:
* ------------------------------------------------------------
* - Implementar una solución concurrente que use hilos POSIX.
* - Aplicar sincronización mediante exclusión mutua (mutex)
*   para evitar condiciones de carrera al acceder a variables
*   compartidas.
* Resultado esperado:
* ------------------------------------------------------------
* El programa debe imprimir en pantalla el resultado final de
* la suma de los cuadrados de los números del 1 al 20:
*
*        Sumas cuadradas = 2870

*************************************************************/

#include <stdio.h>      // Para printf()
#include <stdlib.h>     // Para funciones estándar del sistema
#include <stdint.h>     // Para intptr_t
#include <pthread.h>    // Librería POSIX para manejo de hilos
int acumulado = 0;
// Declaración e inicialización del mutex (bloqueo de exclusión mutua)
pthread_mutex_t acumuladoMutex = PTHREAD_MUTEX_INITIALIZER;
/**************************************************************
* Función: cuadrados
* Parámetros: void *x → puntero genérico que representa el número
* Descripción:
*   Cada hilo ejecutará esta función, la cual recibe un número,
*   calcula su cuadrado y lo suma a la variable global "acumulado".
*   La operación de suma está protegida con un mutex para evitar
*   condiciones de carrera entre hilos concurrentes.
*************************************************************/
void *cuadrados(void *x) {
    int xi = (intptr_t)x;  // Conversión segura de puntero a entero
    
    // Bloquear la sección crítica para acceso seguro
    pthread_mutex_lock(&acumuladoMutex);

    // Actualizar la variable compartida
    acumulado += xi * xi;

    // Liberar el mutex para permitir que otros hilos entren
    pthread_mutex_unlock(&acumuladoMutex);

    // Retorno nulo para evitar advertencias del compilador
    return NULL;
}

/**************************************************************
* Función: main
* Descripción:
*   Función principal del programa. Crea 20 hilos, cada uno
*   encargado de calcular el cuadrado de un número entre 1 y 20.
*   Luego espera a que todos los hilos terminen y finalmente
*   imprime la suma total acumulada.
*************************************************************/
int main(int argc, char *argv[]) {
    pthread_t hilos[20];  // Arreglo que almacenará los identificadores de hilo

    // Creación de los 20 hilos
    for (int i = 0; i < 20; i++) {
        pthread_create(&hilos[i], NULL, cuadrados, (void *)(intptr_t)(i + 1));
    }

    // Espera (join) a que todos los hilos terminen su ejecución
    for (int i = 0; i < 20; i++) {
        pthread_join(hilos[i], NULL);
    }

    // Mostrar el resultado final
    printf("Sumas cuadradas = %d\n", acumulado);

    // Liberar los recursos del mutex
    pthread_mutex_destroy(&acumuladoMutex);

    return 0;
}
