/**************************************************************
* UNIVERSIDAD: Pontificia Universidad Javeriana
* PROGRAMA: Ingeniería de Sistemas
* MATERIA: Sistemas Operativos
* TEMA: Hilos con API POSIX (pthread)
* FECHA: 28/10/2025
* AUTOR: Juan Pablo Motta Talero
*
* DESCRIPCIÓN:
* Este programa demuestra la creación y ejecución concurrente
* de múltiples hilos (threads) utilizando la biblioteca POSIX
* pthread. Cada hilo incrementa una variable global protegida 
* mediante un mutex para evitar condiciones de carrera.
*
* OBJETIVOS:
*  - Comprender la sincronización entre hilos mediante mutex.
*  - Implementar correctamente la creación y gestión de hilos
*    en un entorno concurrente.
*  - Observar cómo varios hilos acceden a una misma variable 
*    compartida sin generar inconsistencias.
*************************************************************/
#include <stdio.h>      
#include <stdlib.h>     
#include <pthread.h>    
#define NTHREADS 10     
/* 
 * Mutex global para controlar el acceso a la variable 'counter'.
 * Evita que múltiples hilos la modifiquen simultáneamente.
 */
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

/* 
 * Variable global compartida entre los hilos.
 * Representa un contador común que se incrementa de forma segura.
 */
int counter = 0;

/**************************************************************
* FUNCIÓN: thread_function
* PARÁMETROS:
*   - void *arg: puntero genérico que contiene el número del hilo.
*
* DESCRIPCIÓN:
*   Función ejecutada por cada hilo. Muestra el número e ID del hilo,
*   bloquea el acceso al contador global mediante un mutex, lo incrementa,
*   y luego libera el bloqueo para permitir que otros hilos accedan.
**************************************************************/
void *thread_function(void *arg) {
    int thread_num = *(int *)(arg); // Conversión del argumento recibido

    printf("Hilo número: %d | ID del hilo: %ld\n", thread_num, pthread_self());

    // Bloqueo del mutex antes de modificar la variable compartida
    pthread_mutex_lock(&mutex1);
    counter++;
    pthread_mutex_unlock(&mutex1);

    pthread_exit(NULL);
}

/*************************************************************
* DESCRIPCIÓN:
*   Crea múltiples hilos, cada uno ejecutando la función 
*   'thread_function'. Espera la finalización de todos los hilos
*   antes de mostrar el valor final del contador compartido.
**************************************************************/
int main() {
    pthread_t thread_id[NTHREADS];   // Identificadores de hilos
    int *thread_args[NTHREADS];      // Argumentos para cada hilo
    int i;

    // Creación de los hilos
    for (i = 0; i < NTHREADS; i++) {
        thread_args[i] = malloc(sizeof(int));  // Asigna memoria para el número del hilo
        *thread_args[i] = i + 1;               // Guarda el número del hilo (1..NTHREADS)

        pthread_create(&thread_id[i], NULL, thread_function, (void *) thread_args[i]);
    }

    // Esperar la finalización de todos los hilos
    for (i = 0; i < NTHREADS; i++) {
        pthread_join(thread_id[i], NULL);
        free(thread_args[i]);  // Libera la memoria reservada
    }

    // Mostrar el resultado final
    printf("Valor final del contador (counter): %d\n", counter);

    // Destruir el mutex antes de terminar
    pthread_mutex_destroy(&mutex1);

    return 0;
}
