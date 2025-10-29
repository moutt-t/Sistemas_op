/**************************************************************
* Fecha: 28/10/2025
* Autor: Juan Pablo Motta Talero
* Materia: Sistemas Operativos
* Tema: Hilos con API POSIX – Variables de condición y exclusión mutua
*
* Descripción general:
* ------------------------------------------------------------
* Este programa demuestra cómo sincronizar hilos en C utilizando
* la API POSIX (`pthread`), haciendo uso combinado de:
*  - Mutex (exclusión mutua)
*  - Variables de condición (`pthread_cond_t`)
*
* El propósito es garantizar que un hilo no acceda a una variable
* compartida hasta que otro hilo haya terminado de actualizarla,
* evitando así condiciones de carrera o comportamientos indefinidos.
*
* Contexto:
* ------------------------------------------------------------
* En programación concurrente, dos o más hilos pueden ejecutar
* operaciones sobre recursos compartidos. Si no se controla su
* acceso, el resultado puede ser inconsistente.
*************************************************************/

#include <stdio.h>    
#include <stdlib.h>     
#include <stdint.h>
#include <pthread.h>   
#include <stdbool.h>    

pthread_cond_t var_cond = PTHREAD_COND_INITIALIZER;  // Variable de condición
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;   // Mutex para exclusión mutua

int valor = 100;            // Variable compartida entre hilos
bool notificar = false;     // Bandera para controlar la condición

/**************************************************************
* Función: reportar
* ------------------------------------------------------------
* Hilo consumidor: espera hasta recibir la señal de que la
* variable `valor` ha sido actualizada antes de imprimirla.
**************************************************************/
void *reportar(void *nousado) {
    // Bloquea el mutex antes de acceder a variables compartidas
    pthread_mutex_lock(&mutex);

    // Espera mientras la condición "notificar == false" no se cumpla
    while (!notificar) {
        pthread_cond_wait(&var_cond, &mutex);
        // pthread_cond_wait() libera el mutex temporalmente y vuelve
        // a bloquearlo cuando se recibe la señal.
    }

    // Cuando recibe la señal, imprime el valor actualizado
    printf("El valor es: %d\n", valor);

    // Libera el mutex
    pthread_mutex_unlock(&mutex);

    // Fin del hilo
    return NULL;
}

/**************************************************************
* Función: asignar
* ------------------------------------------------------------
* Hilo productor: modifica la variable compartida `valor` y
* notifica al hilo `reportar` que puede continuar.
**************************************************************/
void *asignar(void *nousado) {
    // Actualiza el valor compartido
    valor = 20;

    // Bloquea el mutex antes de modificar la condición
    pthread_mutex_lock(&mutex);

    // Establece la condición y envía la señal
    notificar = true;
    pthread_cond_signal(&var_cond);

    // Libera el mutex para permitir acceso al otro hilo
    pthread_mutex_unlock(&mutex);

    // Fin del hilo
    return NULL;
}

/**************************************************************
* Crea los hilos, los ejecuta y espera su finalización.
* Demuestra la coordinación entre los hilos mediante mutex
* y variables de condición.
**************************************************************/
int main(int argc, char *argv[]) {
    pthread_t reporte, asigne;  // Identificadores de los hilos
    void *nousado;              // Variable para almacenar retornos (no usada)

    // Crear los hilos: primero el que espera, luego el que asigna
    pthread_create(&reporte, NULL, reportar, NULL);
    pthread_create(&asigne, NULL, asignar, NULL);

    // Esperar a que ambos hilos terminen
    pthread_join(reporte, &nousado);
    pthread_join(asigne, &nousado);

    // Destruir los recursos de sincronización
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&var_cond);

    return 0;
}
