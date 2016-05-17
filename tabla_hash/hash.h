/*
    Archivo: hash.h
    Autor: Carlos Tonatihu Barrera Pérez      Boleta: 2016630023

    Fecha de creación: viernes 29 de abril de 2016
    Fecha de modificación: domingo 1 de mayo de 2016

    Descripción:
        Este archivo es la cabecera de la biblioteca 'hash' que mediante una funcion hash almacena las palabras de un archivo .txt en una tabla

    Estructuras de Datos - ESCOM-IPN 2016
*/

#ifndef __HASH__
#define __HASH__

#include <stdio.h>
#include <stdlib.h>

typedef struct Letras {
  char elemento;
  struct Letras *siguiente;
} Letra;

typedef struct Palabras{
  Letra *inicio;
  Letra *fin;
} Palabra;

typedef struct ListaPalabras {
    Palabra palabra;
    struct ListaPalabras *siguiente;
} ListaPalabras;

typedef struct Cubetas {
    ListaPalabras *primero;
    ListaPalabras *ultimo;
} Cubeta;

typedef struct Tablas {
    Cubeta array_cubetas[32];
} Tabla;

void mostrar_contenido(FILE *);
void iniciar_tabla_hash(Tabla *);
void iniciar_palabra(Palabra *);
int validar_letra(int);
void guardar_letra(Palabra *, char);
void almacenar_palabra(Tabla *, Palabra *, int *);
void guardar_palabra(Tabla *, Palabra *, int);
int funcion_hash(int);
void mostar_tabla(Tabla *);

#endif
