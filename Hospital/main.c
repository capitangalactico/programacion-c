#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUMBER 1

typedef struct {
    char nombre[30];
    char apellido[30];
    int edad;
    char sexo;
    int telefono;
    int condicion;

} Paciente;

void alta(paciente hospitalArray[NUMBER]);
void imprime(paciente hospitalArray[NUMBER]);
void printPorcentaje(paciente hospitalArray[NUMBER]);
void printCategorias(paciente hospitalArray[NUMBER]);
void printTelefonos(paciente hospitalArray[NUMBER]);


int main()
{
    printf("*****Ingresa cosas magicas*****\n");
    paciente hospitalArray[NUMBER];
    alta(hospitalArray);
    imprime(hospitalArray);
    int continuar = 1;
    char opcion = 'd';
    while(continuar) {
        printf("\nQue quieres hacer?\n");
        printf("\ta)Porcentaje de hombres y mujeres\n");
        printf("\tb)El numero de pacientes de cada una de las categorias de condicion\n");
        printf("\tc)Nombre y telefono de los que se van a morir\n");
        printf("\td)Salir\n");
        scanf(" %c", &opcion);

        if (opcion == 'a') {
            printPorcentaje(hospitalArray);
        } else if (opcion == 'b') {
            printCategorias(hospitalArray);
        } else if (opcion == 'c') {
            printTelefonos(hospitalArray);
        } else if (opcion == 'd') {
            continuar = 0;
        } else {
            continuar = 0;
        }
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
    }
    system("pause");
    return 0;
}

void printPorcentaje(paciente hospitalArray[NUMBER]) {
    int i;
    int mujeres = 0;
    int hombres = 0;
    char MASCULINO = 'm';
    char FEMENINO = 'f';
    for (i = 0; i<NUMBER; i++) {
        if(hospitalArray[i].sexo == MASCULINO) {
            ++hombres;
        } else if (hospitalArray[i].sexo == FEMENINO) {
            ++mujeres;
        }
    }
    double porcentaje = (hombres/NUMBER)*100;
    printf("\nEl numero de hombres es: %f", porcentaje);
    porcentaje = (mujeres/NUMBER)*100;
    printf("\nEl numero de mujeres es: %f", porcentaje);
}

void printCategorias(paciente hospitalArray[NUMBER]) {
    int condicion1 = 0;
    int condicion2 = 0;
    int condicion3 = 0;
    int condicion4 = 0;
    int condicion5 = 0;
    int i;
    for (i = 0; i<NUMBER; i++) {
        if(hospitalArray[i].condicion == 1) {
            condicion1++;
            printf("enter");
        } else if (hospitalArray[i].condicion == 2) {
            condicion2++;
           printf("enter");
        } else if (hospitalArray[i].condicion == 3) {
            condicion3++;
            printf("enter");
        } else if (hospitalArray[i].condicion == 4) {
            condicion4++;
            printf("enter");
        } else if (hospitalArray[i].condicion == 5) {
            condicion5++;
            printf("enter");
        }
    }

    printf("\nEl numero de pacientes con condicion 1 es: %d", condicion1);
    printf("\nEl numero de pacientes con condicion 2 es: %d", condicion2);
    printf("\nEl numero de pacientes con condicion 3 es: %d", condicion3);
    printf("\nEl numero de pacientes con condicion 4 es: %d", condicion4);
    printf("\nEl numero de pacientes con condicion 5 es: %d", condicion5);
}

void printTelefonos(paciente hospitalArray[NUMBER]) {
    int i;
    printf("\nDatos de los pacientes graves: ");
    for (i = 0; i<NUMBER; i++) {
        if(hospitalArray[i].condicion == 5) {
            printf("\nNombre: %s", hospitalArray[i].nombre);
            printf("\nTelefono: %d", hospitalArray[i].telefono);
        }
    }
}

void alta(paciente hospitalArray[NUMBER]) {
    int i;

    for (i = 0; i<NUMBER; i++) {
        printf("Ingresa los datos del paciente numero %d", i+1);
        fflush(stdin);
        printf("\nNombre: ");
        gets(hospitalArray[i].nombre);

        printf("Apellido: ");
        gets(hospitalArray[i].apellido);

        printf("Edad: ");
        scanf("%d", &(hospitalArray[i].edad));

        printf("Sexo:");
        scanf(" %c", &(hospitalArray[i].sexo));

        printf("Telefono: ");
        scanf("%d", &(hospitalArray[i].telefono));

        printf("Condicion 1-5: ");
        scanf("%d", &(hospitalArray[i].condicion));
    }
}

void imprime(paciente hospitalArray[NUMBER]) {

    int i;

    for (i = 0; i<NUMBER; i++) {
        printf("\nDatos del Paciente numero %d:", i+1);
        printf("\nNombre: %s", hospitalArray[i].nombre);
        printf("\nApellido: %s", hospitalArray[i].apellido);
        printf("\nEdad: %d", hospitalArray[i].edad);
        printf("\nSexo: %c", hospitalArray[i].sexo);
        printf("\nTelefono: %d", hospitalArray[i].telefono);
        printf("\nCondicion: %d", hospitalArray[i].condicion);
    }

}
