# ============================================================================
# Makefile para Lab01 - Introducción a OpenMP
# ============================================================================
# Compila el programa que ejecuta hilos en paralelo usando OpenMP
# ============================================================================

# Nombre del ejecutable
EXEC = lab01

# Compilador
CC = gcc

# Banderas para OpenMP
CFLAGS = -fopenmp -Wall

# Regla por defecto: compilar el programa
all: $(EXEC)

$(EXEC): lab01.c
	$(CC) $(CFLAGS) lab01.c -o $(EXEC)

# Regla de limpieza
clean:
	rm -f $(EXEC)
