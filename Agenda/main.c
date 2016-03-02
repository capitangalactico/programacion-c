#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nombre[20];
    char telefono[12];
    struct Agenda *siguiente;
} Agenda;

Agenda *primero, *ultimo;

void mostrar_menu();
void anadir_elemento();
void mostrar_lista();
void borrar_elemento();

int main() {
    int opcion;

    primero = (struct Agenda *) NULL;
    ultimo = (struct Agenda *) NULL;
    do {
        mostrar_menu();
        scanf("%d", &opcion);
        switch (opcion) {
            case 1: anadir_elemento();
                break;
            case 2: borrar_elemento();
                break;
            case 3: mostrar_lista();
                break;
            case 4: exit(0);
                break;
            default: printf("Opcion no valida\n");
                break;
        }
     } while (opcion!='4');
    return 0;
}

 void mostrar_menu() {
      printf("\nMenu:\n\n");
      printf("1.-Agregar elementos\n");
      printf("2.-Borrar elementos\n");
      printf("3.-Mostrar lista\n");
      printf("4.-Salir\n");
      printf("Escoge una opcion: ");

      fflush(stdout);
 }

void anadir_elemento() {
    Agenda *nuevo;

    nuevo = (Agenda *) malloc (sizeof(Agenda));
    if (nuevo==NULL)
        printf("No hay memoria duh!\n");

    printf("\nNuevo elemento:\n");
    fflush(stdin);
    printf("Nombre: ");
    gets(nuevo->nombre);

    printf("Telefono: ");
    gets(nuevo->telefono);

    nuevo->siguiente = NULL;

    if (primero==NULL) {
        printf("Primer elemento\n");
        primero = nuevo;
        ultimo = nuevo;
    }
    else {
        ultimo->siguiente = nuevo;
        ultimo = nuevo;
    }
}

void mostrar_lista() {
    Agenda *auxiliar;
    int i = 0;
    auxiliar = primero;
    printf("\nMostrando la lista completa:\n");

    while (auxiliar!=NULL) {
        printf("Nombre: %s, Telefono: %s\n", auxiliar->nombre, auxiliar->telefono);
        auxiliar = auxiliar->siguiente;
        i++;
    }
    if (i==0)
        printf("\nLista vacia\n");
}

void borrar_elemento() {
    Agenda *auxiliar;
    auxiliar = primero;
    primero = primero->siguiente;
    auxiliar = NULL;
    printf("\nBorrado el primer elemento\n");
}
