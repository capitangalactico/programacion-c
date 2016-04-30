#ifndef __HASH__
#define __HASH__

typedef struct Letras {
  char elemento;
  struct Letras *siguiente;
} Letra;

typedef struct Palabras{
  Letra *inicio;
  Letra *fin;
} Palabra;

typedef struct ListaPalabras {
    Palabra palabra;
    struct ListaPalabras *siguiente;
} ListaPalabras;

typedef struct Cubetas {
    ListaPalabras *primero;
    ListaPalabras *ultimo;
} Cubeta;

typedef struct Tablas {
    Cubeta array_cubetas[32];
} Tabla;

void mostrar_contenido(FILE *);
void guardar_letra(Palabra *, char);
void guardar_palabra(Tabla *, Palabra *, int);
void iniciar_palabra(Palabra *);
void iniciar_tabla_hash(Tabla *);
int funcion_hash(int);
void mostar_tabla(Tabla *);

#endif
