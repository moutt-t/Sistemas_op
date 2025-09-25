/**
 * Fecha:24/09/2025
 * Autor: Juan Pablo Motta Talero
 * Materia: Sistemas Operativos
 * Tema: Teoría del rendimiento
 * Objetivo: Hacer una metodología para la implementación de la multiplicación de matrices. 
*************************************************************************************/
#include <stdio.h>     
#include <stdlib.h>     
#include <sys/time.h>   
#include "modulo.h"     

// Variables globales 
double *mA, *mB, *mC;
struct timeval ini, fin;

//  toma el tiempo inicial

void InicioMuestra(){
	gettimeofday(&ini, (void *)0);   
}

// la funcion Imprime el tiempo que tarda en la pantalla

void FinMuestra(){
	gettimeofday(&fin, (void *)0);   
	fin.tv_usec -= ini.tv_usec;     
	fin.tv_sec  -= ini.tv_sec;       
	double tiempo = (double)(fin.tv_sec*1000000 + fin.tv_usec); 
	printf("%9.0f \n", tiempo);      
}


// La función es la que llena las matrices con los valores 

void iniMatriz(int n, double *m1, double *m2){
   	for(int i=0; i<n*n; i++){
	        m1[i] = i*2.3 + 1.3;
	        m2[i] = i*2.3;
	}
}

// la función imprime la matriz llena en la pantalla 

void imprMatrices(int n, double *matriz){
    if(n<9){
        printf("\n#######################################################\n");
   	for(int i=0; i<n*n; i++){
                if(i%n==0) printf("\n");    
	        printf(" %f ", matriz[i]);     
        }
    } else {
        printf("\n#######################################################\n");
    }
}

// La función multiplica las matrices A y B 
void multimatrizclasica(double *mA, double *mB, double *mC, int N) {
    for (int i = 0; i < N; i++) {           
        for (int j = 0; j < N; j++) {     
            double sumaTemp = 0.0;          
            double *pA = mA + i * N;       
            double *pB = mB + j;           
            for (int k = 0; k < N; k++, pA++, pB += N) {
                // Multiplica elemento de fila por elemento de columna
                sumaTemp += (*pA) * (*pB);
            }
            mC[j + i * N] = sumaTemp;
        }
    }
}
