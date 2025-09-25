/**
 * Fecha:24/09/2025
 * Autor: Juan Pablo Motta Talero
 * Materia: Sistemas Operativos
 * Tema: Teoría del rendimiento
 * Objetivo: Hacer una metodología para la implementación de la multiplicación de matrices. 
*************************************************************************************/
#ifndef MODULO_H
#define MODULO_H

//se define las variables globales 
extern double *mA, *mB, *mC;
extern struct timeval ini, fin;
// La función para tomar el tiempo 
void InicioMuestra();
//la funcion Imprime el tiempo que tarda en la pantalla
void FinMuestra();

// La función es la que llena las matrices con los valores 
void iniMatriz(int n, double *m1, double *m2);

// la función imprime la matriz llena en la pantalla 
void imprMatrices(int n, double *matriz);

// La función multiplica las matrices A y B 
void multimatrizclasica(double *mA, double *mB, double *mC, int N);
 

#endif
