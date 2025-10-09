/*******************************************
* Fecha: 08/10/2025
* Autor: Juan Pablo Motta Talero 
* Materia: Sistemas Operativos
* Tema: Uso de la función FORK()
* Descripción: Ejemplo de duplicidad de procesos
*              y comportamiento “caótico” cuando
*              ambos procesos ejecutan código tras el fork.
*******************************************/

#include <unistd.h>   // Necesaria para fork() 
#include <stdio.h>   
#include <stdlib.h>  

/*
 * Función principal.
 * Este programa muestra cómo, tras usar fork(), se crean
 * dos procesos que ejecutan en paralelo las mismas instrucciones,
 * generando salidas entrelazadas en pantalla 
 */
int main (int argc, char *argv[]) {

    // Mensaje inicial del programa antes de crear procesos
    printf("==> Inicio del proceso main o proceso principal <==\n\n");

    // Se crea un nuevo proceso
    // - fork() devuelve 0 al hijo recién creado
    // - fork() devuelve el PID del hijo al proceso padre
    // - fork() devuelve -1 si hay error
    int processID = fork();

    // Verificamos en cuál proceso estamos
    if (processID == 0) {
        // Bloque que se ejecuta únicamente en el proceso hijo
        printf("\t ==> Proceso Hijo recién creado \n");
    } else if (processID > 0) {
        // Bloque que se ejecuta únicamente en el proceso padre
        printf("\t ==> Proceso Padre \n");
    } else {
        // En caso de error al crear el proceso
        perror("Error al crear el proceso con fork");
        exit(EXIT_FAILURE);
    }

    // A partir de aquí, tanto el padre como el hijo ejecutan
    // el mismo código de manera concurrente, produciendo
    // intercalación de líneas en la salida.
    printf("Imprimiendo ... \n");

    // Bucle de impresión para visualizar la ejecución paralela
    for (int i = 0; i < 5; i++) {
        printf("\t\t == %d ==\n", i);
    }

    printf("Fin ... \n");

    return 0;
}
