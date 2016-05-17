/*
    Archivo: arbol.h
    Autor: Carlos Tonatihu Barrera Pérez      Boleta: 2016630023

    Fecha de creación: viernes 07 de mayo de 2016
    Fecha de modificación:

    Descripción:
        Este archivo es la cabecera de la biblioteca 'arbol' donde se especifican las funciones basicas de un arbol binario

    Estructuras de Datos - ESCOM-IPN 2016
*/

#ifndef __ARBOL__
#define __ARBOL__

#include <stdio.h>
#include <stdlib.h>

struct Arbol{
    int elemento;
    struct Arbol *derecha;
    struct Arbol *izquierda;
};

int insertar(struct Arbol **, int);
int crearArbol(struct Arbol **);
void mostrar(struct Arbol *);
int buscar(struct Arbol *, int);
int eliminar();
/*recuersivas*/
int carlcular_altura();
int calcular_balance();
/*no*/
int rot_izq();
int rot_der();
int doble_rot();

#endif
