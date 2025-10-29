/**************************************************************
* UNIVERSIDAD: Pontificia Universidad Javeriana
* PROGRAMA: Ingeniería de Sistemas
* MATERIA: Sistemas Operativos
* TEMA: POSIX Threads (pthreads) - Implementación básica
* FECHA: 28/10/2025
* AUTOR: Juan Pablo Motta Talero
* DESCRIPCIÓN:
* Este programa demuestra el uso de hilos en C utilizando la
* biblioteca POSIX Threads (pthread). Se crean dos hilos
* independientes que ejecutan una función común encargada de
* imprimir un mensaje en pantalla. 
* OBJETIVO:
* - Comprender la creación, ejecución y finalización de hilos
*   (threads) en entornos POSIX.
* - Observar cómo múltiples hilos pueden ejecutarse de forma
*   concurrente dentro de un mismo proceso.
*************************************************************/
#include <stdio.h>  
#include <stdlib.h>    
#include <pthread.h>    
/**************************************************************
* FUNCIÓN: print_message_function
* PARÁMETROS:
*   - void *ptr : puntero genérico que recibirá el mensaje
*                 (convertido a tipo char*)
**************************************************************/
void *print_message_function(void *ptr) {
    char *message;
    message = (char *) ptr;    // Conversión del puntero genérico
    printf("%s \n", message);  // Imprime el mensaje del hilo
    pthread_exit(NULL);        // Finaliza el hilo de forma segura
}

/**************************************************************
* DESCRIPCIÓN:
*   Crea dos hilos independientes que ejecutan la misma función
*   (print_message_function), pero con diferentes mensajes.
*   Posteriormente imprime los códigos de retorno de la creación
*   de cada hilo.
*
**************************************************************/
int main() {
    pthread_t thread1, thread2;     // Identificadores de los hilos
    char *message1 = "Mensaje del hilo 1";
    char *message2 = "Mensaje del hilo 2";
    int iret1, iret2;

    /* Creación de los hilos */
    iret1 = pthread_create(&thread1, NULL, print_message_function, (void*) message1);
    iret2 = pthread_create(&thread2, NULL, print_message_function, (void*) message2);

    /* Verificación del resultado de la creación */
    printf("Creación del hilo 1, código de retorno: %d\n", iret1);
    printf("Creación del hilo 2, código de retorno: %d\n", iret2);

    /* Esperar la finalización de ambos hilos */
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Ejecución de ambos hilos finalizada.\n");
    return 0;
}
