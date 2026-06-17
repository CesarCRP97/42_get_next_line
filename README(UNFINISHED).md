*Este proyecto ha sido creado como parte del currículo de 42 por crubio-p.*

## Description

## Instructions

## Resources



# Explicacion de Alberto:

## Meta
- Leer la siguiente línea
- No tener leaks
- No perder el residuo al leer la siguietne línea
- Proteger los mallocs

## Conceptos

### FD - FILE DESCRIPTOR
- Valor int asignado por open()
- Hace referencia al file que has abierto
- Investiga --> ulimit -Sn

### Read()
- Función que lee N = BUFFER_SIZE caracteres del FD y lo guarda
- Puede fallar?
- Siempre lee hacia delante

### RESIDUE
- Qué define una línea??.
- Read() lo lee todo, no para en '\n'.
- El residue guarda todos los caracteres extra que read() lee tras '\n'.

### Variable Estática
- Variable que permanece aunque finalice la función.

## Pasos

0. PROTEGE LOS VALORES DE TU FD Y TU BUFFER_SIZE
1. COMPRUEBA SI TU RESIDUE CONTIENE UNA LÍNEA COMPLETA
2. LEE TANTOS BUFFER_SIZE COMO SEA NECESARIO PARA TENER LA NUEVA LÍNEA Y AÑADELOS AL RESIDUO 
3. REPITE EL PASO 1
