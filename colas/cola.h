#ifndef __COLA_H_
#define __COLA_H_
#define size 10

typedef struct Colas {
  int frente, atras;
  int items[size];
} Cola;

int empty(Cola *);
int remove(Cola *);
void insert(Cola *, int);

#endif
