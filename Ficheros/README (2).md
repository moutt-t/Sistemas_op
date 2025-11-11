# 🧪 Laboratorios de Sistemas Operativos - Pontificia Universidad Javeriana

## 👨‍💻 Autor
**Nombre:** Juan Pablo Motta Talero  
**Programa:** Ingeniería de Sistemas  
**Materia:** Sistemas Operativos  
**Fecha:** 6 de noviembre de 2025  

---

## 📘 Descripción general
Este proyecto contiene dos laboratorios implementados en **lenguaje C**, enfocados en el manejo de **directorios, archivos y atributos del sistema operativo**.  
Cada laboratorio aplica funciones del sistema UNIX/Linux como `opendir`, `readdir`, `stat`, y utiliza estructuras como `dirent` y `stat` para explorar y analizar archivos.

---

## 📂 Contenido del proyecto

| Elemento | Descripción |
|-----------|--------------|
| `Lab01.c` | Recorre un directorio y muestra el nombre y tamaño de cada archivo regular. |
| `Lab02.c` | Analiza permisos, tipo y fecha de modificación de los archivos en un directorio. |
| `Makefile` | Archivo para compilar, ejecutar y limpiar los laboratorios. |
| `prueba/` | Carpeta de prueba con un archivo `hola.txt` para verificar el funcionamiento. |
| `README.md` | Documento explicativo del proyecto. |

---

## 🧱 Estructura de carpetas

```
📁 Proyecto-Sistemas-Operativos/
│
├── Lab01.c
├── Lab02.c
├── Makefile
├── README.md
└── prueba/
    └── hola.txt
```

---

## ⚙️ Requisitos previos
Antes de compilar o ejecutar los laboratorios, asegúrate de tener:
- Sistema operativo **Linux** o **macOS**.
- Compilador **GCC** instalado.
- Herramienta **make** disponible en el sistema.

Puedes verificarlo con:
```bash
gcc --version
make --version
```

---

## 🏗️ Compilación

Para compilar **ambos laboratorios**:
```bash
make
```

Esto generará los ejecutables:
```
lab01
lab02
```

También puedes compilar individualmente:
```bash
make lab01   # Solo compila Lab01
make lab02   # Solo compila Lab02
```

---

## ▶️ Ejecución

### 🧩 **Ejecutar el Laboratorio 01**
```bash
make run1
```
O manualmente:
```bash
./lab01
```

Cuando el programa solicite el nombre del directorio, escribe:
```
prueba
```

**Resultado esperado:**
El programa mostrará el archivo `hola.txt` con su tamaño en bytes.

**Ejemplo de salida:**
```
Introduzca el Nombre de un Directorio: prueba
Nombre: hola.txt   | Tamaño: 12 bytes
```

---

### 🧠 **Ejecutar el Laboratorio 02**
```bash
make run2
```
O manualmente:
```bash
./lab02
```

Cuando se solicite el nombre del directorio, escribe:
```
prueba
```

**Resultado esperado:**
El programa analizará el archivo `hola.txt` e imprimirá:
- Sus permisos.
- Si es un archivo regular.
- Fecha de última modificación.
- Si fue modificado en los últimos 10 días.

**Ejemplo de salida:**
```
Nombre directorio:
prueba
Fichero: prueba/hola.txt
Modo: 0100644
Permiso R para propietario
Es un fichero regular
FICHERO: hola.txt
Fecha de modificación: Tue Nov 11 14:35:02 2025
Tiempo en segundos: 1731335702
```

---

## 📁 Carpeta de prueba

La carpeta **`prueba/`** contiene el archivo de texto `hola.txt`, utilizado para verificar que los programas leen correctamente los archivos del sistema.

**Contenido de `hola.txt`:**
```
Hola mundo desde Sistemas Operativos!
```

Puedes modificarlo o agregar más archivos a esta carpeta para probar el comportamiento de los programas con diferentes datos.

---

## 🧹 Limpieza y recompilación

Eliminar los ejecutables:
```bash
make clean
```

Limpiar y recompilar todo:
```bash
make rebuild
```

---

## 🧠 Conceptos aplicados

### **Lab01**
- Lectura de directorios con `opendir()` y `readdir()`.
- Uso de `stat()` para obtener tamaño de archivos.
- Concatenación de rutas con `strcat()` y `strcpy()`.

### **Lab02**
- Verificación de permisos con `st_mode`.
- Detección de tipo de archivo (`S_ISDIR`, `S_ISREG`).
- Comparación de fechas (`st_mtime`, `time()`).
- Cálculo de archivos modificados en los últimos 10 días.

---

## 🏁 Conclusión
Estos laboratorios permiten comprender el manejo de directorios y archivos desde el lenguaje C en un entorno UNIX/Linux.  
Además, refuerzan la aplicación de funciones del sistema operativo, la manipulación de estructuras y el control de permisos y tiempos en archivos reales.

---

## 📚 Créditos
**Autor:** Juan Pablo Motta Talero  
**Pontificia Universidad Javeriana**  
**Ingeniería de Sistemas – 2025**
