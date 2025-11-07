# Laboratorio OpenMP

Este repositorio contiene una serie de laboratorios enfocados en el uso de **OpenMP** para la paralelización de programas en lenguaje **C**.  
Cada laboratorio aborda un concepto diferente de programación paralela, desde las directivas básicas hasta optimizaciones más avanzadas.

---

##  Estructura del proyecto
Laboratorio_ OpenMP/
├── lab01/
│ ├── lab01.c
│ └── Makefile
├── lab02/
│ ├── lab02.c
│ └── Makefile
├── lab03/
│ ├── lab03.c
│ └── Makefile
├── lab04/
│ ├── lab04.c
│ └── Makefile
└── lab05/
├── lab05.c
└── Makefile

Cada carpeta contiene el código fuente (`.c`) y un `Makefile` para su compilación.

---

Compilación y ejecución

Para compilar y ejecutar cualquier laboratorio, entra en su carpeta correspondiente.
Por ejemplo, para el laboratorio 1: 
cd lab01
make
./lab01

Puedes limpiar los archivos compilados con:
make clean

Contenido de los laboratorios

| Laboratorio | Archivo principal | Descripción                                                              |
| ----------- | ----------------- | ------------------------------------------------------------------------ |
| **lab01**   | `lab01.c`         | Introducción a OpenMP: uso de directivas básicas `#pragma omp parallel`. |
| **lab02**   | `lab02.c`         | Control de número de hilos y regiones paralelas.                         |
| **lab03**   | `lab03.c`         | Reducciones y sincronización de variables compartidas.                   |
| **lab04**   | `lab04.c`         | Uso de secciones críticas y `atomic`.                                    |
| **lab05**   | `lab05.c`         | Ejemplo completo con optimización del rendimiento.                       |

Conceptos cubiertos

Paralelización con #pragma omp parallel

Variables privadas y compartidas

Reducciones (reduction)

Control de número de hilos

Secciones críticas (critical) y atómicas (atomic)

Balanceo de carga y eficiencia
