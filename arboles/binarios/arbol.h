/*
    Archivo: arbol.h
    Autor: Carlos Tonatihu Barrera Pérez      Boleta: 2016630023

    Fecha de creación: viernes 07 de mayo de 2016
    Fecha de modificación: sabado 04 de junio de 2016

    Descripción:
        Este archivo es la cabecera de la biblioteca 'arbol' donde se especifican las funciones basicas de un arbol binario como son:
        - Insertar
        - Mostrar
        - Buscar
        - Eliminar

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
/*funciones principales*/
int insertar(struct Arbol **, int);
void mostrar(struct Arbol *);
int buscar(struct Arbol *, int);
int eliminar(struct Arbol **, int);
/*funciones auxiliares*/
int calcular_altura(struct Arbol *);
int crear_arbol(struct Arbol **, int);
int balancear_arbol(struct Arbol **);
int calcular_balance(struct Arbol *);
int rotar_izquierda(struct Arbol **);
int rotar_derecha(struct Arbol **);
int recordenar_arbol(struct Arbol **, struct Arbol **);
// guardamos la parte izq
// guardamos la parte derecha de la izq
// esa parte derecha ahora es la izquierda de la raiz
// la  parte derecha de la izq es la raiz
// la raiz ahora es la izq
int rotar_doble_derecha(struct Arbol **);
//Primero una izq en el hijo y despues una derecha en el padre
int rotar_doble_izquierda(struct Arbol **);
//primero una derecha en el hijo y despues una izq en el padre

#endif
