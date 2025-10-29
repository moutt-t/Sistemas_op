/**************************************************************
* UNIVERSIDAD: Pontificia Universidad Javeriana
* PROGRAMA: Ingeniería de Sistemas
* MATERIA: Sistemas Operativos
* TEMA: Paralelización del cálculo de la suma de cuadrados con hilos (POSIX Threads)
* FECHA: 28/10/2025
* AUTOR: Juan Pablo Motta Talero
*
* DESCRIPCIÓN GENERAL:
* Suponga que la operación de cálculo de cuadrados es altamente
* costosa en términos computacionales. Este programa aplica el 
* concepto de paralelización dividiendo la carga de trabajo entre 
* múltiples hilos (threads), cada uno encargado de calcular el 
* cuadrado de un número y acumularlo en una variable global.
*
* OBJETIVOS:
*  - Comprender cómo paralelizar operaciones matemáticas simples.
*  - Utilizar hilos POSIX para dividir una tarea en partes concurrentes.
*  - Aplicar exclusión mutua con mutex para evitar condiciones de carrera
*    durante la actualización de variables compartidas.
*************************************************************/
#include <stdio.h>      
#include <stdlib.h>     
#include <stdint.h>     
#include <pthread.h>    
int acumulado = 0;                       // Variable compartida
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex para exclusión mutua

/**************************************************************
* FUNCIÓN: cuadrados
*
* PARÁMETROS:
*   - void *x : número entero (convertido a puntero) cuyo cuadrado se calculará
*
* DESCRIPCIÓN:
*   Cada hilo toma un número, calcula su cuadrado y lo agrega
*   al valor global 'acumulado'. Para evitar condiciones de carrera
*   al modificar la variable compartida, se utiliza un mutex.
**************************************************************/
void *cuadrados(void *x) {
    int xi = (intptr_t)x;        // Conversión segura del puntero a entero
    int cuadrado = xi * xi;

    // Protección de la sección crítica
    pthread_mutex_lock(&mutex);
    acumulado += cuadrado;
    pthread_mutex_unlock(&mutex);

    printf("Hilo %ld → número: %d, cuadrado: %d, acumulado parcial: %d\n",
           pthread_self(), xi, cuadrado, acumulado);

    pthread_exit(NULL);
}

/**************************************************************
* FUNCIÓN PRINCIPAL: main
*
* DESCRIPCIÓN:
*   Crea 20 hilos, cada uno encargado de calcular el cuadrado
*   de un número del 1 al 20. Posteriormente espera que todos los
*   hilos finalicen y muestra el resultado total acumulado.
**************************************************************/
int main(int argc, char *argv[]) {
    pthread_t hilos[20];   // Identificadores de hilos
    int total_hilos = 20;

    printf("=== Cálculo paralelo de la suma de cuadrados ===\n");

    // Creación de hilos
    for (int i = 0; i < total_hilos; i++) {
        pthread_create(&hilos[i], NULL, cuadrados, (void *)(intptr_t)(i + 1));
    }

    // Esperar a que todos los hilos terminen
    for (int i = 0; i < total_hilos; i++) {
        pthread_join(hilos[i], NULL);
    }

    printf("\n✅ Resultado final: Suma de cuadrados = %d\n", acumulado);

    // Liberar recursos del mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}
