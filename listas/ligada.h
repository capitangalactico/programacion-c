#ifndef __LIGADA_H_
#define __LIGADA_H_

struct Nodos {
  int dato;
  struct Nodos *siguiente;
};

typedef struct Nodos Nodo;

typedef struct Ligadas {
  Nodo *primero;
} Ligada;

void init(Ligada *);
void recorrer(Ligada *);
void recursivo(Nodo *);
void insertar_inicio(Ligada *, int);
void insertar_final(Ligada *lista, int valor);

#endif
