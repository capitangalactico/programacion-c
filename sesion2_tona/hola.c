#include <stdio.h>
void main(){
    int hola;
    char variable;
    float flotante;

    hola = 789;
    variable = 'c';
    flotante = 8.5f;

    int * apuntador1 = &hola;
    char *apuntador2 = &variable;
    float *apuntador3 = &flotante;

    printf("entero %d \n", hola);
    printf("float %f \n", flotante);
    printf("char %c \n", variable);

    printf("Tam int %ld \n", sizeof(int));
    printf("Tamano float %ld \n", sizeof(float));
    printf("Tamano char %ld \n", sizeof(char));

    printf("Dir 1 %d \n", apuntador1);
    printf("Dir 2 %d \n", apuntador2);
    printf("Dir 3 %d \n", apuntador3);
}
