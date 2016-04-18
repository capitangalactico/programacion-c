#ifndef __PILA_H_
#define __PILA_H_
#define size 10

typedef struct Pilas {
  int tope;
  int items[size];
} Pila;

int empty(Pila *);
int pop(Pila *);
void push(Pila *, int);

#endif
