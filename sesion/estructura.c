// Barrera Pérez Carlos Tonatihu 1CM2
#include <stdio.h>
struct Punto {
    double x;
    double y;
    double z;
};

struct Dato {
    char a;
    char b;
    char c;
};

typedef struct PilaPuntos {
    struct Punto puntos[100];
    int tope;
} PilaPunto;

typedef struct PilaDatos {
    struct Dato datos[100];
    int tope;
} PilaDato;

void push_punto(PilaPunto *pila, struct Punto *valor);
struct Punto *pop_punto(PilaPunto *pila);

void push_dato(PilaDato *pila, struct Dato *valor);
struct Dato *pop_dato(PilaDato *pila);

void main(){
    // Para tipo punto
    PilaPunto prueba1;
    struct Punto punto1, punto3;
    struct Punto *punto2;
    prueba1.tope = 0;
    unsigned int tope_punto = 0;
    //Datos de prueba
    punto1.x = 1;
    punto1.y = 2;
    punto1.z = 3;

    //Para tipo dato
    PilaDato prueba2;
    struct Dato dato1, dato3;
    struct Dato *dato2;
    prueba2.tope = 0;
    unsigned int tope_dato = 0;

    //Datos de prueba
    dato1.a = 'a';
    dato1.b = 'b';
    dato1.c = 'c';

    printf("Valor de un punto1.z: %lf \n", punto1.z);
    printf("Valor de un dato1.a: %c \n", dato1.a);

    push_punto(&prueba1, &punto1);
    push_dato(&prueba2, &dato1);

    tope_punto = prueba1.tope;
    tope_dato = prueba2.tope;

    printf("Tope del arreglo de puntos: %d \n", tope_punto);
    printf("Tope del arreglo de datos: %d \n", tope_dato);

    printf("Valor de punto1.z en array: %lf \n", prueba1.puntos[tope_punto].z);
    printf("Valor de dato1.a en array: %c \n", prueba2.datos[tope_dato].a);

    punto2 = pop_punto(&prueba1);
    dato2 = pop_dato(&prueba2);

    printf("Retorno del pop punto x: %lf \n", punto2->x);
    printf("Retorno del pop punto y: %lf \n", punto2->y);
    printf("Retorno del pop punto z: %lf \n", punto2->z);

    printf("Retorno del pop dato a: %c \n", dato2->a);
    printf("Retorno del pop dato b: %c \n", dato2->b);
    printf("Retorno del pop dato c: %c \n", dato2->c);

    punto1.x = 10;
    punto1.y = 90;
    punto1.z = 70;

    dato1.a = 'i';
    dato1.b = 'j';
    dato1.c = 'k';

    push_punto(&prueba1, &punto1);
    push_dato(&prueba2, &dato1);

    tope_punto = prueba1.tope;
    tope_dato = prueba2.tope;

    printf("Tope del arreglo de puntos: %d \n", tope_punto);
    printf("Tope del arreglo de datos: %d \n", tope_dato);

    printf("Valor de punto1.z en array: %lf \n", prueba1.puntos[0].z);
    printf("Valor de dato1.a en array: %c \n", prueba2.datos[0].a);

    punto3.x = 666;
    punto3.y = 14;
    punto3.z = 10;

    dato3.a = 'a';
    dato3.b = 'e';
    dato3.c = 'i';

    push_punto(&prueba1, &punto3);
    push_dato(&prueba2, &dato3);

    tope_punto = prueba1.tope;
    tope_dato = prueba2.tope;

    printf("Tope del arreglo de puntos: %d \n", tope_punto);
    printf("Tope del arreglo de datos: %d \n", tope_dato);

    printf("Valor de punto1.z en array: %lf \n", prueba1.puntos[1].z);
    printf("Valor de dato1.a en array: %c \n", prueba2.datos[1].a);

}

struct Punto *pop_punto(PilaPunto *pila){
    struct Punto *aux_punto;
    aux_punto = pila->puntos;
    pila->tope = (pila->tope) - 1;

    return aux_punto;
}

void push_punto(PilaPunto *pila, struct Punto *valor){
    if (pila->tope != 1000) {
        pila->puntos[(pila->tope)].x = valor->x;
        pila->puntos[(pila->tope)].y = valor->y;
        pila->puntos[(pila->tope)].z = valor->z;
        pila->tope = (pila->tope) + 1;
    }
}

// Funciones de la estructura dato
struct Dato *pop_dato(PilaDato *pila){
    struct Dato *aux_dato;
    aux_dato = pila->datos;
    pila->tope = (pila->tope) - 1;

    return aux_dato;
}

void push_dato(PilaDato *pila, struct Dato *valor){
    if (pila->tope != 1000) {
        pila->datos[(pila->tope)].a = valor->a;
        pila->datos[(pila->tope)].b = valor->b;
        pila->datos[(pila->tope)].c = valor->c;
        pila->tope = (pila->tope) + 1;
    }
}
