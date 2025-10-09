/*******************************************
* Fecha: 08/10/2025
* Autor: Juan Pabl Motta Talero
* Materia: Sistemas Operativos
* Tema: Uso de la función FORK()
* Descripción: Ejemplo de comunicación entre procesos
*              mediante tuberías (pipes). El proceso padre
*              envía un mensaje al hijo después de crear la tubería.
*******************************************/

#include <unistd.h>   // Para fork()
#include <stdio.h>  
#include <stdlib.h>   
#include <string.h>  

/*
 * Función principal.
 * Crea una tubería (pipe) que permite la comunicación unidireccional
 * entre el proceso padre y el hijo. Luego, usa fork() para crear el hijo.
 * El padre envía un mensaje por la tubería, y el hijo lo lee.
 */
int main (int argc, char *argv[]) {

    // Mensaje inicial informativo
    printf("==> Inicio del proceso main o proceso principal <==\n\n");

    // Se declara un arreglo de 2 enteros para almacenar los descriptores de la tubería
    // pipefd[0] -> extremo de lectura
    // pipefd[1] -> extremo de escritura
    int pipefd[2];
    pid_t procesoHIJO_PID;

    // Crear la tubería. Devuelve -1 en caso de error
    if (pipe(pipefd) == -1) {
        perror("PIPE");        
        exit(EXIT_FAILURE);    
    }

    // Crear el proceso hijo
    procesoHIJO_PID = fork();
    if (procesoHIJO_PID == -1) {
        perror("FORK");
        exit(EXIT_FAILURE);
    }

    // === PROCESO HIJO ===
    if (procesoHIJO_PID == 0) {
        // Cerrar el extremo de escritura, ya que el hijo solo leerá
        close(pipefd[1]);

        char mensaje[100];   // Buffer para almacenar el mensaje recibido
        int lecturaBYTES;

        // Leer datos enviados por el padre desde el pipe
        lecturaBYTES = read(pipefd[0], mensaje, sizeof(mensaje));
        if (lecturaBYTES == -1) {
            perror("LECTURA!!");
            exit(EXIT_FAILURE);
        }

        // Mostrar el mensaje recibido
        // %*.s imprime exactamente 'lecturaBYTES' caracteres
        printf("\t Proceso HIJO: Recibe mensaje PADRE %*.s \n", lecturaBYTES, mensaje);

        // Cerrar el extremo de lectura
        close(pipefd[0]);

    // === PROCESO PADRE ===
    } else {
        // Cerrar el extremo de lectura, ya que el padre solo escribe
        close(pipefd[0]);

        // Mensaje que se enviará al hijo
        char mensajeP[] = "Holi, bienvenido a OP";
        int escribirBYTES;

        // Escribir el mensaje en el pipe
        escribirBYTES = write(pipefd[1], mensajeP, strlen(mensajeP));
        if (escribirBYTES == -1) {
            perror("ESCRITURA");
            exit(EXIT_FAILURE);
        }

        // Cerrar el extremo de escritura después de enviar
        close(pipefd[1]);
    }

    return 0;
}
