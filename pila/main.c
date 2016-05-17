#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main(void) {
  Pila pila;
  pila.tope=-1;
  printf("Empty %d\n", empty(&pila));
  push(&pila, 1);
  printf("Pop %d\n", pop(&pila));
  printf("Empty %d\n", empty(&pila));
  return 0;
}
