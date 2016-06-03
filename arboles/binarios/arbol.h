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
// Puedo hacerlo mas facil y guardar al padre, si esta balanceado ese arbol y su altura
struct Arbol{
    int elemento;
    struct Arbol *derecha;
    struct Arbol *izquierda;
};
/*funciones principales*/
int insertar(struct Arbol **, int);
int crear_arbol(struct Arbol **, int);
void mostrar(struct Arbol *);
int buscar(struct Arbol *, int);
int eliminar();
/*funciones auxiliares*/
int calcular_altura(struct Arbol *);
int altura_total(struct Arbol *);
int calcular_balance();
/*no*/
int rotar_izquierda(struct Arbol **);
int rotar_derecha(struct Arbol **);
// guardamos la parte izq
// guardamos la parte derecha de la izq
// esa parte derecha ahora es la raiz
// la parte izq de nuestra anterior raiz es ka derecha de la izq
int doble_rotacion_derecha();
//Primero una izq en el hijo y despues una derecha en el padre
int doble_rotacion_izq();
//primero una derecha en el hijo y despues una izq en el padre


#endif
