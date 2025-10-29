/**************************************************************
* UNIVERSIDAD: Pontificia Universidad Javeriana
* PROGRAMA: Ingeniería de Sistemas
* MATERIA: Sistemas Operativos
* TEMA: Verificación de ejecución concurrente con hilos (mutex lock/unlock)
* FECHA: 28/10/2025
* AUTOR: Juan Pablo Motta Talero
*
* DESCRIPCIÓN GENERAL:
* Este programa demuestra cómo varios hilos pueden ejecutarse de manera
* concurrente y modificar una variable global compartida. El ejemplo muestra
* que, sin el uso de mecanismos de exclusión mutua (como mutex), se pueden
* generar condiciones de carrera al acceder o modificar recursos comunes.
*
* OBJETIVOS:
*  - Comprender la creación y sincronización básica de hilos con POSIX Threads.
*  - Observar los efectos de la ejecución concurrente sobre variables globales.
*  - Preparar el escenario para aplicar exclusión mutua (mutex lock/unlock)
*    en futuras versiones del programa.
*************************************************************/
#include <stdio.h>    
#include <stdlib.h>    
#include <pthread.h>   
#include <string.h>     

pthread_t tid[3];   // Arreglo de identificadores de hilos
int counter = 0;    // Variable compartida entre los hilos

/**************************************************************
* FUNCIÓN: compute
*
* PARÁMETROS:
*   - void *arg : No se usa en este ejemplo (puntero genérico)
*
* DESCRIPCIÓN:
*   Cada hilo ejecuta esta función. Incrementa una variable global
*   compartida ('counter') y simula una carga de trabajo mediante un
*   ciclo grande. Se imprime un mensaje al inicio y al final de la
*   ejecución de cada hilo.
**************************************************************/
void* compute(void *arg) {
    unsigned long i = 0;

    counter += 1;  // Modificación de variable compartida (sin protección)
    printf("\n🟢 Job %d ha iniciado (Thread ID: %ld)\n", counter, pthread_self());

    // Simulación de trabajo pesado (delay artificial)
    for (i = 0; i < (0xFFFFFFF); i++);

    printf("\n🔵 Job %d ha finalizado (Thread ID: %ld)\n", counter, pthread_self());

    return NULL;
}

/**************************************************************
* FUNCIÓN PRINCIPAL: main
*
* DESCRIPCIÓN:
*   Crea tres hilos que ejecutan la función 'compute'. Verifica si
*   la creación de cada hilo fue exitosa e informa mediante mensajes
*   en consola. Luego espera (join) la finalización de los tres hilos
*   antes de terminar el programa.
**************************************************************/
int main(void) {
    int i = 0;
    int error;

    printf("=== Inicio del programa de verificación con hilos POSIX ===\n");

    // Creación de tres hilos
    while (i < 3) {
        error = pthread_create(&(tid[i]), NULL, &compute, NULL);

        if (error != 0) {
            printf("\n❌ No se pudo crear el hilo %d : [%s]\n", i + 1, strerror(error));
        } else {
            printf("\n✅ Hilo %d creado exitosamente (ID: %ld)\n", i + 1, tid[i]);
        }

        i++;
    }

    // Esperar a que los tres hilos terminen su ejecución
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_join(tid[2], NULL); // Se corrigió el índice: antes era 3 (fuera de rango)

    printf("\n=== Todos los hilos han finalizado ===\n");
    printf("Valor final de 'counter': %d\n", counter);

    return 0;
}
