/*
    Archivo: arbol.c
    Autor: Carlos Tonatihu Barrera Pérez      Boleta: 2016630023

    Fecha de creación: viernes 07 de mayo de 2016
    Fecha de modificación:

    Descripción:
        Este archivo se encuentra el codigo de las funciones de 'arbol.h'

    Estructuras de Datos - ESCOM-IPN 2016
*/

#include "arbol.h"
/*
si el valor es menor al elemento lo manda a la izq y a la derecha en caso contrario
*/
int insertar(struct Arbol **arbol, int valor) {
    struct Arbol *arbol_nuevo = NULL;

    if (*arbol == NULL) {
        crearArbol(&arbol_nuevo);
        arbol_nuevo->elemento = valor;
        *arbol = arbol_nuevo;
    }

    crearArbol(&arbol_nuevo);
    arbol_nuevo->elemento = valor;

    if (valor < ((*arbol)->elemento)) {
        if((*arbol)->izquierda != NULL) {
            insertar(&((*arbol)->izquierda), valor);
        }
        (*arbol)->izquierda = arbol_nuevo;
    } else {
        if((*arbol)->derecha != NULL) {
            insertar(&((*arbol)->derecha), valor);
        }
        (*arbol)->derecha = arbol_nuevo;
    }
    return 1;
}

int crearArbol(struct Arbol **nuevo) {
    struct Arbol *auxiliar = NULL;
    auxiliar = (struct Arbol*)malloc(sizeof(struct Arbol));

    if (auxiliar == NULL) {
        return -1;
    }

    auxiliar->izquierda = NULL;
    auxiliar->derecha = NULL;
    *nuevo = auxiliar;
    return 1;
}
