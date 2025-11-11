#include <stdio.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    int er;
    char nomdir[100], nomfich[100];
    struct stat atr;
    DIR *d;
    struct dirent *rd1;
    time_t fecha;

    printf("Nombre directorio:\n");
    fgets(nomdir, sizeof(nomdir), stdin);

    // Quitar el salto de línea del nombre del directorio
    nomdir[strlen(nomdir) - 1] = '\0';
    fecha = time(&fecha);

    if ((d = opendir(nomdir)) == NULL) {
        printf("No existe ese directorio\n");
        return -1;
    } else {
        while ((rd1 = readdir(d)) != NULL) {
            if ((strcmp(rd1->d_name, ".") != 0) && (strcmp(rd1->d_name, "..") != 0)) {
                strcpy(nomfich, nomdir);
                strcat(nomfich, "/");
                strcat(nomfich, rd1->d_name);

                printf("Fichero: %s\n", nomfich);
                er = stat(nomfich, &atr);
                printf("Modo: %#o\n", atr.st_mode);

                if ((atr.st_mode & 0400) != 0)
                    printf("Permiso R para propietario\n");
                else
                    printf("No permiso R para propietario\n");

                if (S_ISDIR(atr.st_mode))
                    printf("Es un directorio\n");
                if (S_ISREG(atr.st_mode)) {
                    // Ficheros modificados en los últimos 10 días
                    if ((fecha - 10 * 24 * 60 * 60) < atr.st_mtime) {
                        printf("FICHERO: %s\n", rd1->d_name);
                        printf("Fecha de modificación: %s", ctime(&atr.st_mtime));
                        printf("Tiempo en segundos: %ld\n", atr.st_mtime);
                    }
                }
                printf("\n");
            }
        }
        closedir(d);
    }

    return 0;
}
