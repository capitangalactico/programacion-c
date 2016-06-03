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
    if(arbol == NULL) {
        return -1; //No existe
    }
    int existe_arbol_nuevo = crear_arbol(&arbol_nuevo, valor);
    if(existe_arbol_nuevo==-1) {
        return -1; // No existe
    }
    if (*arbol == NULL) {
        *arbol = arbol_nuevo;
    } else if (valor < ((*arbol)->elemento)) {
        insertar(&((*arbol)->izquierda), valor);
    } else if (valor > ((*arbol)->elemento)) {
        insertar(&((*arbol)->derecha), valor);
    } else if(valor == ((*arbol)->elemento)){
        return 0; // repetido
    }
    return 1;
}

int crear_arbol(struct Arbol **nuevo, int valor) {
    struct Arbol *auxiliar = NULL;
    auxiliar = (struct Arbol*)malloc(sizeof(struct Arbol));
    if (auxiliar == NULL) {
        return -1;
    }
    auxiliar->izquierda = NULL;
    auxiliar->derecha = NULL;
    auxiliar->elemento = valor;
    *nuevo = auxiliar;
    return 1;
}

void mostrar(struct Arbol *un_arbol){
    if(un_arbol == NULL) {
        return;
    }
    printf("%d ", un_arbol->elemento);
    mostrar(un_arbol->derecha);
    mostrar(un_arbol->izquierda);

}
int buscar(struct Arbol *un_arbol, int dato){
    if(un_arbol==NULL){
        return 0;
    }
    if(dato==un_arbol->elemento){
        return 1;
    }
    if(dato > un_arbol->elemento){
        return buscar(un_arbol->derecha, dato);
    } else {
        return buscar(un_arbol->izquierda, dato);
    }
    return 0;
}

int calcular_altura(struct Arbol *arbol){
    if (arbol == NULL){
        return 0;
    }
    int altura_izquierda = calcular_altura(arbol->izquierda);
    int altura_derecha = calcular_altura(arbol->derecha);

    if (altura_derecha > altura_izquierda){
        return altura_derecha + 1;
    } else {
        return altura_izquierda + 1;
    }
}
int altura_total(struct Arbol *arbol) {
    return calcular_altura(arbol) -1;
}

int rotar_derecha(struct Arbol **arbol) {
    if(arbol == NULL) {
        return -1;
    }
    struct Arbol *sub_arbol_izquierdo = (*arbol)->izquierda;
    struct Arbol *sub_arbol_izquierdo_derecho = sub_arbol_izquierdo->derecha;
    (*arbol)->izquierda = sub_arbol_izquierdo_derecho;
    sub_arbol_izquierdo->derecha = *arbol;
    *arbol = sub_arbol_izquierdo;
    return 1;
}

int rotar_izquierda(struct Arbol **arbol) {
    if(arbol == NULL) {
        return -1;
    }
    struct Arbol *sub_arbol_derecho = (*arbol)->derecha;
    struct Arbol *sub_arbol_derecho_izquierdo = sub_arbol_derecho->izquierda;
    (*arbol)->derecha = sub_arbol_derecho_izquierdo;
    sub_arbol_derecho->izquierda = *arbol;
    *arbol = sub_arbol_derecho;
    return 1;
}
