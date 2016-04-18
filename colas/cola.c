#include <stdio.h>
#include "cola.h"

int empty(Cola *cola) {
  if(cola->frente == cola->atras) {
    return 1;
  }
  return 0;
}

void insert(Cola *cola, int x){
  if(cola->atras == size-1) {
    cola->atras = 0;
  } else {
    (cola->atras)++;
  }
  if(cola->atras == cola->frente) {
    //No se puede agregar mas
  }
  cola->items[cola->atras] = x;
}
int remove(Cola *cola) {
  if(empty(cola)){
    //esta vacia
    return(0);
  }
  if(cola->frente == size-1) {
    cola->frente == 0;
  } else {
    (cola->frente)++;
  }
  return cola->items[cola->frente];
}

int full(Cola *cola) {
  if(cola->atras == size - 1) {
    if(cola->adelante == 0) {
      return 1;
    }
  }
  if((cola->atras)+1 == cola->adelante) {
    return 1;
  }
  return 0;
}
