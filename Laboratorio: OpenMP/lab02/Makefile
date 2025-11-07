# ============================================================================
# Makefile para Lab02 - Sistemas Operativos
# Compila y ejecuta el programa que usa OpenMP
# ============================================================================

# Nombre del ejecutable
EXEC = lab02

# Compilador
CC = gcc

# Bandera para OpenMP
CFLAGS = -fopenmp -Wall

# Regla por defecto: compilar
all: $(EXEC)

$(EXEC): Lab02.c
	$(CC) $(CFLAGS) lab02.c -o $(EXEC)

# Limpieza de archivos compilados
clean:
	rm -f $(EXEC)
