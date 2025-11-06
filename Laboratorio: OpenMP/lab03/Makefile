# ============================================================================
# Makefile para Lab03 - Variables privadas con OpenMP
# ============================================================================
# Compila el programa que demuestra el uso de private en regiones paralelas
# ============================================================================

# Nombre del ejecutable
EXEC = Lab03

# Compilador
CC = gcc

# Banderas de compilación (OpenMP y advertencias)
CFLAGS = -fopenmp -Wall

# Regla principal
all: $(EXEC)

$(EXEC): Lab03.c
	$(CC) $(CFLAGS) Lab03.c -o $(EXEC)

# Regla de limpieza
clean:
	rm -f $(EXEC)
