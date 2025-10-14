Proyecto: Comunicación Cliente-Servidor con FIFO en C
Descripción general

Este proyecto implementa un sistema de comunicación bidireccional entre dos procesos (cliente y servidor) usando un FIFO (named pipe) ubicado en /tmp/fifo_twoway.

El cliente envía cadenas de texto.

El servidor recibe las cadenas, las invierte, y las devuelve al cliente.

Cuando el cliente envía la palabra "end", ambos programas finalizan la comunicación y cierran el FIFO.
