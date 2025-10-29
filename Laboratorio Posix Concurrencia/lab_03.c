/**************************************************************
* UNIVERSIDAD: Pontificia Universidad Javeriana
* PROGRAMA: Ingeniería de Sistemas
* MATERIA: Sistemas Operativos
* TEMA: Exclusión mutua y sincronización con mutex y variables
*       de condición (POSIX Threads)
* FECHA: 28/10/2025
* AUTOR: Juan Pablo Motta Talero
*
* DESCRIPCIÓN GENERAL:
* Este programa demuestra el uso combinado de mecanismos de
* exclusión mutua (mutex) y sincronización (variables de condición)
* en la API POSIX. Dos hilos (threads) acceden y modifican una
* variable global compartida llamada “count”, pero lo hacen de
* manera controlada para evitar conflictos y comportamientos
* indeterminados.
*
* OBJETIVOS:
*  - Implementar exclusión mutua mediante pthread_mutex.
*  - Utilizar variables de condición (pthread_cond) para coordinar
*    la ejecución entre hilos.
*  - Comprender cómo evitar condiciones de carrera y mantener
*    sincronización entre múltiples hilos que comparten datos.
*************************************************************/

#include <stdio.h>     
#include <stdlib.h>     
#include <pthread.h>    

pthread_mutex_t count_mutex      = PTHREAD_MUTEX_INITIALIZER;  // Protege el acceso a 'count'
pthread_mutex_t condition_mutex  = PTHREAD_MUTEX_INITIALIZER;  // Protege la variable de condición
pthread_cond_t  condition_cond   = PTHREAD_COND_INITIALIZER;   // Variable de condición

int count = 0;  // Contador global compartido

// Límites de control para el comportamiento de los hilos
#define COUNT_DONE  15   // Valor máximo del contador antes de detener el programa
#define COUNT_HALT1  4   // Primer umbral de pausa
#define COUNT_HALT2 11   // Segundo umbral de pausa

/**************************************************************
* DESCRIPCIÓN:
*   Este hilo incrementa el contador global 'count' mientras
*   su valor NO se encuentre dentro del rango [COUNT_HALT1, COUNT_HALT2].
*   Si el contador está dentro de este rango, el hilo se suspende
*   utilizando la variable de condición 'condition_cond'.
*
*   Una vez que otro hilo (count02) envía una señal, este hilo
*   se reanuda y continúa su ejecución.
**************************************************************/
void *count01(void *arg) {
    for (;;) {
        // Bloquea el mutex asociado a la condición
        pthread_mutex_lock(&condition_mutex);

        // Si el contador está entre los umbrales, el hilo espera
        while (count >= COUNT_HALT1 && count <= COUNT_HALT2) {
            pthread_cond_wait(&condition_cond, &condition_mutex);
        }
        // Libera el mutex de la condición
        pthread_mutex_unlock(&condition_mutex);

        // Bloquea el mutex principal antes de modificar el contador
        pthread_mutex_lock(&count_mutex);
        count++;
        printf("Hilo 1 → Contador incrementado a: %d\n", count);
        pthread_mutex_unlock(&count_mutex);

        // Termina cuando se alcanza el valor máximo
        if (count >= COUNT_DONE) {
            pthread_exit(NULL);
        }
    }
}

/**************************************************************
* FUNCIÓN: count02
* DESCRIPCIÓN:
*   Este hilo también incrementa el contador global 'count', pero
*   además tiene la función de "reactivar" al hilo 1 cuando el
*   contador sale del rango de pausa [COUNT_HALT1, COUNT_HALT2].
*   En otras palabras, este hilo es responsable de emitir señales
*   a la variable de condición cuando corresponde.
**************************************************************/
void *count02(void *arg) {
    for (;;) {
        // Bloquea el mutex asociado a la condición
        pthread_mutex_lock(&condition_mutex);

        // Si el contador está fuera del rango de pausa, envía señal
        if (count < COUNT_HALT1 || count > COUNT_HALT2) {
            pthread_cond_signal(&condition_cond);
        }

        // Libera el mutex de la condición
        pthread_mutex_unlock(&condition_mutex);

        // Bloquea el mutex principal antes de modificar el contador
        pthread_mutex_lock(&count_mutex);
        count++;
        printf("Hilo 2 → Contador incrementado a: %d\n", count);
        pthread_mutex_unlock(&count_mutex);

        // Termina cuando se alcanza el valor máximo
        if (count >= COUNT_DONE) {
            pthread_exit(NULL);
        }
    }
}

/**************************************************************
* DESCRIPCIÓN:
*   Crea dos hilos (count01 y count02) que trabajan sobre una
*   variable compartida 'count' con exclusión mutua y sincronización.
*   Espera a que ambos hilos finalicen antes de terminar el programa.
**************************************************************/
int main() {
    pthread_t thread1, thread2;

    // Creación de los hilos
    pthread_create(&thread1, NULL, count01, NULL);
    pthread_create(&thread2, NULL, count02, NULL);

    // Esperar a que ambos hilos finalicen
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("\nEjecución finalizada. Valor total del contador: %d\n", count);

    // Liberar recursos
    pthread_mutex_destroy(&count_mutex);
    pthread_mutex_destroy(&condition_mutex);
    pthread_cond_destroy(&condition_cond);

    return 0;
}
