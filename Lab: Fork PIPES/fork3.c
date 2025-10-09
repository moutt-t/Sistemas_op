/*******************************************
* Fecha: 07/10/2025
* Autor: Carolina Ujueta
* Materia: Sistemas Operativos
* Tema: Uso de la función FORK()
* Duplicidad de procesos y caos en creación
*******************************************/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]) {
        printf("==> Inicio del proceso main o proceso principal <==\n\n");
        int pipefd[2];
	pid_t procesoHIJO_PID;

        if(pipe(pipefd) == -1){
		perror("PIPE");
		exit(EXIT_FAILURE);
	}

	procesoHIJO_PID = fork();
	if(procesoHIJO_PID == -1){
                perror("FORK");
		exit(EXIT_FAILURE);
	}

	if(procesoHIJO_PID == 0){
		close(pipefd[1]);
		char mensaje[100];
		int lecturaBYTES;
		lecturaBYTES = read(pipefd[0], mensaje, sizeof(mensaje));
		if(lecturaBYTES == -1){
                	perror("LECTURA!!");
                	exit(EXIT_FAILURE);
        }
        printf("\t Proceso HIJO: Recibe mensaje PADRE %*.s \n", lecturaBYTES, mensaje);
	close(pipefd[0]);
	} else {
		close(pipefd[0]);
		char mensajeP[]= "Holi, bienvenido a OP";
		int escribirBYTES;
		escribirBYTES = write(pipefd[1], mensajeP, strlen(mensajeP));
		if(escribirBYTES == -1){
			perror("ESCRITURA");
			exit(EXIT_FAILURE);
		}
		close(pipefd[1]);
	}
	return 0;
}
