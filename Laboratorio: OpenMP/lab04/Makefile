# ============================================================================
# Makefile para Lab04 - Variables privadas en regiones paralelas
# ============================================================================
# Compila el programa que demuestra la independencia de variables privadas
# ============================================================================

# Nombre del ejecutable
EXEC = lab04

# Compilador
CC = gcc

# Banderas de compilación (OpenMP y advertencias)
CFLAGS = -fopenmp -Wall

# Regla principal
all: $(EXEC)

$(EXEC): Lab04.c
	$(CC) $(CFLAGS) lab04.c -o $(EXEC)

# Regla de limpieza
clean:
	rm -f $(EXEC)
