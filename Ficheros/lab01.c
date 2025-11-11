/*
 ============================================================================
 Nombre del archivo : Lab01.c
 UNIVERSIDAD        : Pontificia Universidad Javeriana
 PROGRAMA           : Ingeniería de Sistemas
 MATERIA            : Sistemas Operativos
 Autor              : Juan Pablo Motta Talero
 Fecha              : 6/11/2025
 Descripción        : Laboratorio 01 - Manejo de directorios en C
 ============================================================================
 Objetivo:
     Este programa solicita al usuario el nombre de un directorio y muestra 
     en pantalla todos los archivos regulares (no subdirectorios) que contiene, 
     junto con su tamaño en bytes. Se emplean las funciones de la librería 
     estándar de manejo de directorios (dirent.h) y de la estructura stat 
     para obtener información sobre los archivos.
 ============================================================================
*/

#include <stdio.h>      
#include <stdlib.h>     
#include <string.h>    
#include <dirent.h>    
#include <sys/stat.h>   
#include <unistd.h>     

int main() {
    DIR *d;                     // Puntero al directorio
    char nomdir[90];            // Nombre del directorio introducido por el usuario
    char nomfich[90];           // Ruta completa del archivo actual
    struct stat datos;          // Estructura para guardar información del archivo
    struct dirent *direc;       // Estructura para leer cada entrada del directorio

    // Solicita al usuario el nombre de un directorio
    printf("Introduzca el Nombre de un Directorio: ");
    fgets(nomdir, sizeof(nomdir), stdin);

    // Eliminamos el salto de línea '\n' del final de la cadena
    nomdir[strlen(nomdir) - 1] = '\0';

    // Intentamos abrir el directorio indicado
    if ((d = opendir(nomdir)) == NULL) {
        printf("El directorio no existe\n");
        return -1;  // Finaliza el programa si no se puede abrir
    }

    // Recorremos todas las entradas dentro del directorio
    while ((direc = readdir(d)) != NULL) {
        // Construimos la ruta completa del archivo o subdirectorio
        strcpy(nomfich, nomdir);
        strcat(nomfich, "/");
        strcat(nomfich, direc->d_name);

        // Obtenemos información del archivo usando stat()
        stat(nomfich, &datos);

        // Verificamos si la entrada es un archivo regular
        if (S_ISREG(datos.st_mode))
            printf("Nombre: %s\t| Tamaño: %ld bytes\n", direc->d_name, datos.st_size);
    } // Fin del while

    // Cerramos el directorio
    closedir(d);

    return 0;
}
