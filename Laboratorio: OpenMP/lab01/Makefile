# ============================================================================
# Makefile para Lab01 - Sistemas Operativos
# Compila y ejecuta el programa que usa OpenMP
# ============================================================================

# Nombre del ejecutable
EXEC = Lab01

# Compilador
CC = gcc

# Bandera para OpenMP
CFLAGS = -fopenmp -Wall

# Regla por defecto: compilar
all: $(EXEC)

$(EXEC): Lab01.c
	$(CC) $(CFLAGS) Lab01.c -o $(EXEC)

# Limpieza de archivos compilados
clean:
	rm -f $(EXEC)
