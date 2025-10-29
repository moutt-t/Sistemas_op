/**************************************************************
* Fecha: 28/10/2025
* Autor: Juan Pablo Motta Talero 
* Materia: Sistemas Operativos
* Tema: Hilos con API POSIX - Variables de condición y exclusión mutua
* Descripción general:
* ------------------------------------------------------------
* Este programa ilustra el uso de mecanismos de sincronización 
* en la programación concurrente con hilos POSIX (pthreads). 
* En particular, se utilizan:
*  - Variables de condición (`pthread_cond_t`)
*  - Mutex (exclusión mutua con `pthread_mutex_t`)
*
* El objetivo es demostrar cómo un hilo puede esperar una 
* condición específica antes de continuar su ejecución, y 
* cómo otro hilo puede "notificar" o "despertar" al primero 
* cuando dicha condición se cumple.
*

* Objetivo de aprendizaje:
* ------------------------------------------------------------
* - Comprender el uso conjunto de `pthread_mutex` y `pthread_cond`.
* - Observar la diferencia entre ejecución sincronizada y no sincronizada.
* - Analizar posibles condiciones de carrera.
*************************************************************/

#include <stdio.h>      // Para printf()
#include <stdlib.h>     // Para exit(), NULL, etc.
#include <stdint.h>     // Para intptr_t si se requiere conversión segura
#include <pthread.h>    // Librería POSIX de manejo de hilos
#include <stdbool.h>    // Para tipo booleano (true/false)

// Declaración de la variable de condición y el mutex
pthread_cond_t var_cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Variables compartidas
int valor = 100;
bool notificar = false;

/**************************************************************
* Función: reportar
* Descripción:
*   Este hilo imprime el valor actual de la variable global `valor`.
*   En la versión sincronizada (comentada), espera hasta que otro 
*   hilo le indique mediante una variable de condición que puede 
*   continuar su ejecución.
*************************************************************/
void *reportar(void *nousado) {
    /*
    // Bloquear el mutex antes de verificar la condición
    pthread_mutex_lock(&mutex);

    // Esperar hasta que 'notificar' sea true
    while (!notificar) {
        pthread_cond_wait(&var_cond, &mutex);
    }

    // Una vez señalizado, imprimir el valor
    printf("El valor es: %d\n", valor);

    // Liberar el mutex
    pthread_mutex_unlock(&mutex);
    */

    // Versión sin sincronización (demostrativa)
    printf("El valor es: %d\n", valor);

    return NULL;  // Previene advertencias del compilador
}

/**************************************************************
* Función: asignar
* Descripción:
*   Este hilo modifica el valor de la variable compartida `valor`.
*   En la versión sincronizada, también se encarga de notificar 
*   al hilo "reportar" que ya puede continuar.
*************************************************************/
void *asignar(void *nousado) {
    valor = 20;

    /*
    // Bloquear el mutex antes de cambiar la variable de estado
    pthread_mutex_lock(&mutex);

    notificar = true;

    // Enviar la señal al hilo que está esperando la condición
    pthread_cond_signal(&var_cond);

    // Liberar el mutex
    pthread_mutex_unlock(&mutex);
    */

    return NULL;  // Previene advertencias del compilador
}

/**************************************************************
* Función principal: main
* Descripción:
*   Crea los dos hilos y espera su finalización.
*   Este flujo demuestra cómo los hilos interactúan con variables 
*   compartidas, y cómo la falta de sincronización puede causar 
*   resultados impredecibles.
*************************************************************/
int main(int argc, char *argv[]) {
    pthread_t reporte, asigne;

    // Creación de los hilos
    pthread_create(&reporte, NULL, reportar, NULL);
    pthread_create(&asigne, NULL, asignar, NULL);

    // Esperar a que ambos hilos terminen
    void *nousado;
    pthread_join(reporte, &nousado);
    pthread_join(asigne, &nousado);

    // Liberar los recursos
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&var_cond);

    return 0;
}
