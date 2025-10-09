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

int main (int argc, char *argv[]) {
        printf("==> Inicio del proceso main o proceso principal <==\n\n");
        int processID = fork();

        if(processID==0){
                printf("\t ==>Proceso Hijo recien creado \n");
        } else {
                printf("\t ==>Proceso padre \n");
        }

        printf("Imprimiendo ... \n");
	for(int i=0; i<5; i++){
		printf("\t\t == %d ==\n", i);
	}
	printf("Fin ... \n");
        return 0;
}

