#include <stdio.h>
#include <stdlib.h>
#include "ligada.h"

void init(Ligada *lista) {
  lista->primero = NULL;
}

void recorrer(Ligada *lista) {
  //vacia
  recursivo(lista->primero);
}

void recursivo(Nodo *nodo) {
  if(nodo->siguiente != NULL){
    printf("%d\n", nodo->dato);
    recursivo(nodo->siguiente);
  }
}

void insertar_inicio(Ligada *lista, int valor) {
  Nodo *temporal = NULL;
  temporal = (Nodo *) malloc(sizeof(Nodo));
  if(temporal == NULL)
    return;

  temporal->dato = valor;
  temporal->siguiente = lista->primero;
  lista->primero = temporal;
}

void insertar_final(Ligada *lista, int valor) {
  //vacia
  Nodo *final = lista->primero;
  while(final->siguiente != NULL) {
    final = final->siguiente;
  }
  // Se puede hacer sin usar el temporal con solo final->siguiente en su lugar
  Nodo *temporal = NULL;
  temporal = (Nodo *) malloc(sizeof(Nodo));
  if (temporal == NULL)
    return;

  temporal->dato = valor;
  temporal->siguiente = NULL;
  final->siguiente = temporal;
}
