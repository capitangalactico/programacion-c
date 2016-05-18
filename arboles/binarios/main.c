/*
    Archivo: main.c
    Autor: Carlos Tonatihu Barrera Pérez      Boleta: 2016630023

    Fecha de creación: viernes 07 de mayo de 2016
    Fecha de modificación:

    Descripción:
        En este archivo se realizan las pruebas de la libreria arbol.h

    Estructuras de Datos - ESCOM-IPN 2016
*/

#include <stdio.h>
#include "arbol.h"

int main(int argc, char const *argv[]) {
    struct Arbol *arbol_vacio = NULL;
    mostrar(arbol_vacio);
    insertar(&arbol_vacio, 1);
    insertar(&arbol_vacio, 2);
    insertar(&arbol_vacio, 0);
    insertar(&arbol_vacio, -2);
    insertar(&arbol_vacio, -1);
    insertar(&arbol_vacio, -3);
    mostrar(arbol_vacio);
    return 0;
}
