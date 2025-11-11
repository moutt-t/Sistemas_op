# ============================================================================
# Nombre del archivo : Makefile
# UNIVERSIDAD        : Pontificia Universidad Javeriana
# PROGRAMA           : Ingeniería de Sistemas
# MATERIA            : Sistemas Operativos
# Autor              : Juan Pablo Motta Talero
# Fecha              : 6/11/2025
# Descripción        : Makefile para compilar los laboratorios Lab01.c y Lab02.c
# ============================================================================
# Este Makefile permite compilar de forma independiente o conjunta los dos
# laboratorios. Incluye reglas para compilación, ejecución, limpieza y recompilación.
# ============================================================================

# Compilador
CC = gcc

# Opciones de compilación
# -Wall   : muestra todas las advertencias
# -Wextra : muestra advertencias adicionales
# -O2     : nivel medio de optimización
# -std=c11: usa el estándar C11
CFLAGS = -Wall -Wextra -O2 -std=c11

# Archivos fuente
SRC1 = lab01.c
SRC2 = lab02.c

# Ejecutables resultantes
OUT1 = lab01
OUT2 = lab02

# ============================================================================
# Reglas principales
# ============================================================================

# Regla por defecto: compila ambos laboratorios
all: $(OUT1) $(OUT2)

# Compilación de lab01
$(OUT1): $(SRC1)
	@echo "Compilando $(SRC1)..."
	$(CC) $(CFLAGS) $(SRC1) -o $(OUT1)
	@echo ">>> Ejecutable generado: $(OUT1)"

# Compilación de lab02
$(OUT2): $(SRC2)
	@echo "Compilando $(SRC2)..."
	$(CC) $(CFLAGS) $(SRC2) -o $(OUT2)
	@echo ">>> Ejecutable generado: $(OUT2)"

# ============================================================================
# Reglas adicionales
# ============================================================================

# Ejecutar lab01
run1: $(OUT1)
	@echo "Ejecutando lab01..."
	./$(OUT1)

# Ejecutar lab02
run2: $(OUT2)
	@echo "Ejecutando lab02..."
	./$(OUT2)

# Limpiar archivos compilados
clean:
	@echo "Eliminando ejecutables..."
	rm -f $(OUT1) $(OUT2)
	@echo "Limpieza completada."

# Recompilar desde cero
rebuild: clean all

# ============================================================================
# Fin del Makefile
# ============================================================================
