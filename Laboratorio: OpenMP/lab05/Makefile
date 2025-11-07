# ============================================================
#  Makefile - Laboratorio 05: Cálculo de sumatorias (función seno)
#  Descripción:
#     Compila el programa Lab05.c usando OpenMP.
#     Permite limpiar archivos intermedios y ejecutar el binario.
# ============================================================

# Nombre del ejecutable
TARGET = lab05

# Compilador
CC = gcc

# Flags de compilación
CFLAGS = -fopenmp -Wall -lm

# Archivo fuente
SRC = lab05.c

# ============================================================
# Reglas principales
# ============================================================

# Compilación del ejecutable
$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS)
	@echo "Compilación completada con éxito."

# Ejecutar el programa con argumentos (por defecto: 4 hilos, 30000 iteraciones)
run: $(TARGET)
	@echo "Ejecutando programa..."
	./$(TARGET) 4 30000

# Limpieza de archivos generados
clean:
	@echo "Limpiando archivos generados..."
	rm -f $(TARGET)
