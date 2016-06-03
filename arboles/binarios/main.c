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
    struct Arbol *arbol_prueba = NULL;
    mostrar(arbol_prueba);
    insertar(&arbol_prueba, 20);
    insertar(&arbol_prueba, 30);
    insertar(&arbol_prueba, 10);
    insertar(&arbol_prueba, 40);
    insertar(&arbol_prueba, 25);
    insertar(&arbol_prueba, 0);
    insertar(&arbol_prueba, 15);
    insertar(&arbol_prueba, 17);
    insertar(&arbol_prueba, 5);
    insertar(&arbol_prueba, -10);
    insertar(&arbol_prueba, -20);

    mostrar(arbol_prueba);
    printf("Encontro: %d\n", buscar(arbol_prueba, 1));
    printf("Altura: %d\n", altura_total(arbol_prueba));
    rotar_derecha(&arbol_prueba);
    mostrar(arbol_prueba);
    return 0;
}
