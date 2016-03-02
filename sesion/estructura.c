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
} PilaPuntos;

void push(PilaPuntos *pila, struct Punto *valor);
struct Punto *pop(PilaPuntos *pila);

void main(){
    PilaPuntos prueba1;
    prueba1.tope = 0;
    struct Punto punto1;
    struct Punto *punto2;
    punto1.x = 1;
    punto1.y = 2;
    punto1.z = 3;

    printf("Valor de un punto1: %lf \n", punto1.z);  
    
    push(&prueba1, &punto1);
    printf("Tope: %d \n", prueba1.tope);
    printf("Valor de un punto1 en array: %lf \n", prueba1.puntos[0].z);  
    punto2 = pop(&prueba1);
    printf("Retorno %lf \n", punto2->x);
    printf("Retorno %lf \n", punto2->y);
    printf("Retorno %lf \n", punto2->z);
    
    punto1.x = 10;
    punto1.y = 90;
    punto1.z = 70;
    push(&prueba1, &punto1);
    
    printf("Valor de un punto1 en array: %lf \n", prueba1.puntos[0].z);  

}

struct Punto *pop(PilaPuntos *pila){
    struct Punto *aux;
    aux = pila->puntos;
    pila->tope = (pila->tope) - 1;
    return aux;
}

void push(PilaPuntos *pila, struct Punto *valor){
    if (pila->tope != 1000) {
        pila->puntos[(pila->tope)].x = valor->x;
        pila->puntos[(pila->tope)].y = valor->y;
        pila->puntos[(pila->tope)].z = valor->z;
        pila->tope = (pila->tope) + 1;
    }
}
