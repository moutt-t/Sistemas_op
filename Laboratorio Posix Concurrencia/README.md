# Laboratorios de Programación Concurrente en C (POSIX Threads)

**Universidad:** Pontificia Universidad Javeriana  
**Programa:** Ingeniería de Sistemas  
**Materia:** Sistemas Operativos  
**Autor:** Juan Pablo Motta Talero  
**Fecha:** 28/10/2025  

---

## Descripción general

Este proyecto recopila **nueve laboratorios en lenguaje C** diseñados para comprender los fundamentos de la **programación concurrente** utilizando **hilos POSIX (pthreads)**.

Cada práctica aborda un concepto distinto: desde la creación básica de hilos hasta la sincronización avanzada mediante **mutex** y **variables de condición**.

El objetivo general es aprender a **controlar la ejecución concurrente** y **evitar condiciones de carrera** al acceder a recursos compartidos en sistemas multitarea.

---

## Estructura del proyecto

```
├── lab_01.c  → Introducción a pthreads
├── lab_02.c  → Sincronización con mutex
├── lab_03.c  → Mutex + variables de condición
├── lab_04.c  → Ejemplo de condiciones de carrera
├── lab_05.c  → Paralelización: suma de cuadrados
├── lab_06.c  → Versión optimizada del lab_05
├── lab_07.c  → Variables de condición (no sincronizado)
├── lab_08.c  → Variables de condición (sincronizado)
└── lab_09.c  → Búsqueda del máximo con hilos
```

---

## Contenido de cada laboratorio

| Nº | Archivo | Tema principal | Conceptos clave |
|----|----------|----------------|----------------|
| **1** | `lab_01.c` | Introducción a pthreads | Creación y ejecución de dos hilos simples. |
| **2** | `lab_02.c` | Sincronización con mutex | Uso de `pthread_mutex_t` para proteger un contador global. |
| **3** | `lab_03.c` | Mutex y variables de condición | Coordinación entre dos hilos usando `pthread_cond_t`. |
| **4** | `lab_04.c` | Condiciones de carrera | Demostración de acceso concurrente sin exclusión mutua. |
| **5** | `lab_05.c` | Paralelización matemática | Suma de cuadrados de 1 a 20 con mutex. |
| **6** | `lab_06.c` | Optimización del lab_05 | Misma lógica con documentación y resultado esperado `2870`. |
| **7** | `lab_07.c` | Variables de condición (sin señalización) | Ejemplo sin sincronización (comentado). |
| **8** | `lab_08.c` | Variables de condición (sincronizado) | Versión correcta con `pthread_cond_signal`. |
| **9** | `lab_09.c` | Procesamiento concurrente de archivos | Búsqueda del valor máximo en un vector dividido entre hilos. |

---

## Resultados esperados (resumen)

| Laboratorio | Resultado clave |
|--------------|-----------------|
| **Lab 01** | Mensajes impresos desde dos hilos. |
| **Lab 02** | `Valor final del contador = 10`. |
| **Lab 03** | Ejecución sincronizada con pausa controlada. |
| **Lab 04** | Valor final inconsistente de `counter` (demuestra la condición de carrera). |
| **Lab 05–06** | Suma de cuadrados = **2870**. |
| **Lab 08** | “El valor es: 20” (sin conflictos). |
| **Lab 09** | Muestra el **máximo global** del vector. |

---

##  Conceptos abordados

- **Hilos POSIX (`pthread_create`, `pthread_join`)**
- **Exclusión mutua (`pthread_mutex_t`)**
- **Variables de condición (`pthread_cond_t`)**
- **Sincronización entre hilos**
- **Evitar condiciones de carrera**
- **Paralelización de tareas**
- **Procesamiento concurrente de archivos**

---

##  Conclusiones

- Los **hilos POSIX** permiten ejecutar múltiples tareas en paralelo dentro del mismo proceso.
- Es fundamental aplicar **mecanismos de sincronización** (mutex y condition variables) para garantizar la **consistencia de datos**.
- La paralelización mejora el **rendimiento** en cálculos intensivos, pero requiere control cuidadoso del acceso compartido.
- El manejo correcto de la **exclusión mutua** y la **señalización** es esencial en sistemas operativos multitarea.

---
  

