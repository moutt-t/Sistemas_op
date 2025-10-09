/****************************************
* Fecha: 08/10/2025
* Autor: Juan Pablo Motta Talero 
* Materia: Sistemas Operativos
* Tema: Usos de la función FORK()
*****************************************/

#include <unistd.h>   // Biblioteca necesaria para usar fork() y getpid()
#include <stdio.h>    
#include <stdlib.h>   

/*
 * Función principal del programa.
 * Demuestra el uso básico de fork(), que se utiliza para crear procesos hijos.
 * Cada vez que se llama a fork(), el proceso actual se duplica:
*/
int main (int argc, char *argv[]) {

    // Mensaje inicial indicando que el programa ha comenzado.
    printf("==> Inicio del proceso main o proceso principal <==\n\n");

    // Se crea un nuevo proceso. fork() devuelve:
    //  - >0 en el proceso padre (el valor es el PID del hijo)
    //  - 0 en el proceso hijo
    //  - -1 en caso de error
    int processID = fork();

    // Verificamos si estamos en el proceso padre o hijo
    if (processID > 0) {
        // Este bloque se ejecuta solo en el proceso padre
        printf("\t ==> Proceso Padre con ID %d \n", getpid());
    } else if (processID == 0) {
        // Este bloque se ejecuta solo en el proceso hijo
        printf("\t ==> Proceso Hijo con ID %d \n", getpid());
    } else {
        // En caso de error al crear el proceso
        perror("Error al crear el proceso con fork");
        exit(EXIT_FAILURE);
    }

    // Este mensaje será mostrado tanto por el padre como por el hijo,
    // ya que después del fork, ambos procesos continúan ejecutando desde aquí.
    printf("A partir de aqui es el proceso main o proceso principal \n");

    return 0;
}
