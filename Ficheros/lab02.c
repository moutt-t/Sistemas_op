/*
 ============================================================================
 Nombre del archivo : Lab02.c
 UNIVERSIDAD        : Pontificia Universidad Javeriana
 PROGRAMA           : Ingeniería de Sistemas
 MATERIA            : Sistemas Operativos
 Autor              : Juan Pablo Motta Talero
 Fecha              : 11/11/2025
 Descripción        : Laboratorio 02 - Análisis de permisos y fechas de modificación de archivos
 ============================================================================
 Objetivo:
     Este programa solicita al usuario el nombre de un directorio y recorre
     todos sus archivos y subdirectorios (excepto "." y ".."). 
     Para cada archivo encontrado, se muestran sus permisos, tipo (archivo o directorio),
     y, en el caso de archivos regulares, se verifica si han sido modificados 
     en los últimos 10 días. Se emplean las funciones `opendir`, `readdir`, `stat` y 
     estructuras del sistema para la manipulación de directorios y atributos de archivos.
 ============================================================================
*/

#include <stdio.h>      
#include <string.h>     
#include <time.h>     
#include <dirent.h>     
#include <fcntl.h>      
#include <unistd.h>     
#include <sys/stat.h>   
#include <sys/types.h>  
int main() {
    int er;                     // Variable para almacenar el resultado de stat()
    char nomdir[100];           // Nombre del directorio introducido por el usuario
    char nomfich[100];          // Ruta completa del archivo actual
    struct stat atr;            // Estructura para los atributos del archivo
    DIR *d;                     // Puntero al directorio
    struct dirent *rd1;         // Estructura que representa cada entrada del directorio
    time_t fecha;               // Variable para almacenar la fecha actual

    // Solicitar al usuario el nombre del directorio
    printf("Nombre directorio:\n");
    fgets(nomdir, sizeof(nomdir), stdin);

    // Eliminar el salto de línea del final del nombre ingresado
    nomdir[strlen(nomdir) - 1] = '\0';

    // Obtener la fecha y hora actuales del sistema
    fecha = time(&fecha);

    // Intentar abrir el directorio ingresado
    if ((d = opendir(nomdir)) == NULL) {
        printf("No existe ese directorio\n");
        return -1;  // Termina el programa si no se puede abrir
    } else {
        // Leer cada entrada del directorio una por una
        while ((rd1 = readdir(d)) != NULL) {
            // Ignorar las entradas especiales "." y ".."
            if ((strcmp(rd1->d_name, ".") != 0) && (strcmp(rd1->d_name, "..") != 0)) {

                // Construir la ruta completa del archivo o subdirectorio
                strcpy(nomfich, nomdir);
                strcat(nomfich, "/");
                strcat(nomfich, rd1->d_name);

                printf("Fichero: %s\n", nomfich);

                // Obtener atributos del archivo
                er = stat(nomfich, &atr);

                // Mostrar el modo (permisos y tipo) en formato octal
                printf("Modo: %#o\n", atr.st_mode);

                // Verificar si el propietario tiene permiso de lectura
                if ((atr.st_mode & 0400) != 0)
                    printf("Permiso R para propietario\n");
                else
                    printf("No permiso R para propietario\n");

                // Determinar si es un directorio
                if (S_ISDIR(atr.st_mode))
                    printf("Es un directorio\n");

                // Determinar si es un archivo regular
                if (S_ISREG(atr.st_mode)) {
                    // Verificar si fue modificado en los últimos 10 días
                    if ((fecha - 10 * 24 * 60 * 60) < atr.st_mtime) {
                        printf("FICHERO: %s\n", rd1->d_name);
                        printf("Fecha de modificación: %s", ctime(&atr.st_mtime));
                        printf("Tiempo en segundos: %ld\n", atr.st_mtime);
                    }
                }

                printf("\n"); // Separador visual entre archivos
            }
        }

        // Cerrar el directorio después de recorrerlo
        closedir(d);
    }

    return 0;
}
