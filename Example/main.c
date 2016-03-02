#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[30];
    char apellido[30];
    int edad;
    char sexo;
    int telefono;
    int condicion;
} Paciente;

FILE *archivo;
Paciente paciente, *apuntador;

void mostrar_menu();
void agregar_elemento();
void mostrar_lista();
void borrar();

int main(){
    int opcion;
    apuntador = &paciente;

    do {
        mostrar_menu();
        fflush(stdin);
        scanf("%d", &opcion);
        switch (opcion) {
            case 1: agregar_elemento();
                break;
            case 2:  borrar();
                break;
            case 3: mostrar_lista();
                break;
            case 4: fclose(archivo);
                exit(0);
                break;
            default: printf("\nOpcion no valida");
                break;
             }
     } while (opcion!='4');

    return 0;
}


void mostrar_menu() {
    printf("\nMenu, escoge una opcion:");
    printf("\n1.-Alta");
    printf("\n2.-Baja");
    printf("\n3.-Mostrar");
    printf("\n4.-Salir\n");
}

void agregar_elemento(){

    archivo = fopen("base.txt", "a");

    if(archivo==NULL){
		printf("\nError en el archivo");
		exit(0);
	} else {
        printf("\nNuevo elemento");

        printf("\nNombre: ");
        scanf("%s", apuntador->nombre);

        printf("\nApellido: ");
        scanf("%s", apuntador->apellido);

        printf("\nEdad: ");
        scanf("%d", &apuntador->edad);

        printf("%s", "Telefono: ");
        scanf("%d", &apuntador->telefono);

        printf("%s", "Condicion: ");
        scanf("%d", &apuntador->condicion);

        printf("\nSexo: ");
        scanf(" %c", &apuntador->sexo);

        fprintf(archivo, "%s,%s,%d,%c,%d,%d \n", apuntador->nombre, apuntador->apellido, apuntador->edad, apuntador->sexo, apuntador->telefono, apuntador->condicion);
    }
    fclose(archivo);
}

void mostrar_lista() {
    const char delimiter[2] = ",";
    char *token;
    char anterior[500];
    char next_text[500];
    int opcion;

    archivo = fopen("base.txt", "r");

    if (archivo==NULL) {
        printf("Error");
        exit(0);
    }

    printf("\nMostrando la lista completa:\n");

    while(feof(archivo) == 0) {
        fgets(next_text, 500, archivo);

        if(strcmp(anterior, next_text) != 0) {
            token = strtok(next_text, delimiter);
            opcion = 0;
            while(token != NULL) {
                if(opcion == 0) {
                    printf("Nombre: %s\n", token);
                } else if(opcion == 1) {
                    printf("Apellido: %s\n", token);
                } else if(opcion == 2) {
                    printf("Edad: %s\n", token);
                } else if(opcion == 3) {
                    printf("Sexo: %s\n", token);
                } else if(opcion == 4) {
                    printf("Telefono: %s\n", token);
                } else if(opcion == 5) {
                    printf("Condicion: %s", token);
                }
                token = strtok(NULL, delimiter);
                opcion++;
            }
            printf("\n***********\n");
        }
        strcpy(anterior, next_text);
    }
    fclose(archivo);
}

void borrar() {
     int linea = 0;
     int i = 1;
     char anterior[500];
     char next_text[500];

     printf("Ingresa el numero de registro a eliminar: ");
     scanf("%d", &linea);
     linea = linea;

     FILE *archivo2;
     archivo2 = fopen("base2.txt", "a"); // Un archivo extra para trabajar en el, al final si se cambia el nombre
     archivo = fopen("base.txt", "r");

    if (archivo==NULL && archivo2==NULL) {
        printf("Error");
        exit(0);
    }

    while(feof(archivo)==0) {
        fgets(next_text, 500, archivo);
        // Si las cadenas son diferentes y la linea es diferente a la elegida se copia al nuevo archivo
        if(strcmp(anterior, next_text) != 0 && i != linea) {
            fprintf(archivo2, "%s",next_text);
        }

        strcpy(anterior, next_text);
        i++;
    }
    // Si no lo borra invertir el  orden de las instrucciones, depende del maldito compilador, computadora o IDE
    fclose(archivo);
    fclose(archivo2);

    remove("base.txt");
    rename("base2.txt", "base.txt");
}
