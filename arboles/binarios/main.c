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
#include <time.h>

int main(int argc, char const *argv[]) {
    struct Arbol *arbol_prueba = NULL;
    int numero = 0;
    int i;
    srand(time(NULL));
    for (i = 0; i<20; i++){
        numero = rand() % 21;
        printf("El numero que se inserta es %d\n", numero);
        insertar(&arbol_prueba, numero);
        mostrar(arbol_prueba);
    }
    for (i = 0; i<3; i++){
        numero = rand() % 21;
        printf("El numero que se busca y se elimina es %d\n", numero);
        if (buscar(arbol_prueba, numero)) {
            printf("El numero: %d fue encontrado\n", numero);
        } else {
            printf("El numero: %d no fue encontrado\n", numero);
        }
        eliminar(&arbol_prueba, 20);
        mostrar(arbol_prueba);
    }
    return 0;
}
