#include <stdio.h>
#include "pila.h"

int empty(Pila *pila){
  if(pila->tope ==-1) {
    return 1;
  }
  return 0;
}

int pop(Pila *pila) {
  if(empty(pila)) {
    return 0; // No hay elementos
  }
  return pila->items[(pila->tope)--];
}

void push(Pila *pila, int valor) {
  if(pila->tope == size-1) {
    // No se pueden meter mas cosas
  } else {
    pila->items[++(pila->tope)] = valor;
  }
}
