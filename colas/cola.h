#ifndef __COLA_H_
#define __COLA_H_
#define size 10

typedef struct Colas {
  int frente, atras;
  int items[size];
} Cola;

int empty(Cola *);
void init(Cola *);
int quitar(Cola *);
void insert(Cola *, int);
int full(Cola *cola);

#endif
