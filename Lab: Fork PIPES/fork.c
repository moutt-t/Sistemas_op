/****************************************
* Fecha: 07/10/2025
* Autor: Carolina Ujueta
* Materia: Sistemas Operativos
* Tema: Uso de la función FORK()
*****************************************/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
	printf("==> Inicio del proceso main o proceso principal <==\n\n");
	int processID = fork();

	if(processID>0){
		printf("\t ==>Proceso Padre con ID %d \n", getpid());
	} else {
		printf("\t ==>Proceso Hijo con ID %d \n", getpid());
	}

	printf("A partir de aqui es el proceso main o proceso principal \n");
	return 0;
}
