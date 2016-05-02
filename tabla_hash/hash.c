#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

Tabla tabla_hash;

void mostrar_conetenido(FILE *file) {
    char letra = ' ';
    Palabra aux_palabra;
    int suma = 0;
    iniciar_palabra(&aux_palabra);
    iniciar_tabla_hash(&tabla_hash);
    while (feof(file) == 0) {
        letra = fgetc(file);
        //Metodo que valide
        if(validar_letra(letra)) {
            suma += letra;
            guardar_letra(&aux_palabra, letra);
        } else {
            almacenar_palabra(&tabla_hash, &aux_palabra, &suma);
        }
        if(feof(file) != 0){
            almacenar_palabra(&tabla_hash, &aux_palabra, &suma);
        }
    }
    mostar_tabla(&tabla_hash);
}

void iniciar_palabra(Palabra *palabra) {
    palabra->inicio = NULL;
    palabra->fin = NULL;
    palabra = NULL;
}

void iniciar_tabla_hash(Tabla *tabla) {
    int i = 0;
    while (i<32) {
        tabla->array_cubetas[i].primero = NULL;
        tabla->array_cubetas[i].ultimo = NULL;
        i++;
    }
    tabla = NULL;
}

int validar_letra(int letra_ascii) {
    // Mayusculas
    if(letra_ascii>64 && letra_ascii<91)
        return 1;
    // Minusculas
    if(letra_ascii>96 && letra_ascii<123)
        return 1;
    // Acentos
    if(letra_ascii>129 && letra_ascii<166)
        return 1;
    // E con acento
    if(letra_ascii==130)
        return 1;

    return 0;
}

void guardar_letra(Palabra *palabra, char letra_caracter) {
    Letra *aux_letra = NULL;
    aux_letra = (Letra*) malloc(sizeof(Letra));

    if (aux_letra == NULL)
        exit(0); //Sin memoria

    aux_letra->elemento = letra_caracter;
    aux_letra->siguiente = NULL;

    if(palabra->inicio == NULL) {
        palabra->inicio = aux_letra;
    } else {
        palabra->fin->siguiente = aux_letra;
    }
    palabra->fin = aux_letra;

}

void almacenar_palabra(Tabla *tabla, Palabra *palabra, int *suma) {
    guardar_palabra(tabla, palabra, *suma);
    iniciar_palabra(palabra);
    *suma = 0;
}

void guardar_palabra(Tabla *tabla, Palabra *palabra, int suma) {
    if(suma == 0)
        return; // Evita guardar "palabras" si detecta algo que no es una letra
    int indice = funcion_hash(suma);
    ListaPalabras *aux_lista = NULL;
    aux_lista = (ListaPalabras*) malloc(sizeof(ListaPalabras));
    aux_lista->siguiente = NULL;
    if(aux_lista == NULL)
        exit(0);

    aux_lista->palabra = *palabra;
    aux_lista->siguiente = NULL;

    if ((tabla->array_cubetas[indice]).primero == NULL) {
        tabla->array_cubetas[indice].primero = aux_lista;
    } else {
        tabla->array_cubetas[indice].ultimo->siguiente = aux_lista;
    }
    tabla->array_cubetas[indice].ultimo = aux_lista;
}

int funcion_hash(int suma) {
    return (suma%32);
}

void mostar_tabla(Tabla *tabla) {
    int i;
    int contador = 0;
    Palabra aux_palabra;
    ListaPalabras *aux_lista;
    Letra *aux_letra;
    for(i = 0; i<32; i++) {
        aux_lista = tabla->array_cubetas[i].primero; //indices
        printf("\n--------Cubeta %d--------\n", i);
        while(aux_lista != NULL){
            contador++;
            if(contador<4) {
                aux_palabra = aux_lista->palabra;
                aux_letra = aux_palabra.inicio; // Imprimir la palabra
                printf("-");
                while(aux_letra != NULL) {
                    printf("%c", aux_letra->elemento);
                    aux_letra = aux_letra->siguiente;
                }
                printf("\n");
            }
            aux_lista = aux_lista->siguiente;
        }
        printf("Numero de palabras encontradas: %d\n", contador);
        contador = 0;
    }
}
