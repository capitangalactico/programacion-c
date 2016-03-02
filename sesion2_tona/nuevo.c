#include <stdio.h>
void main(){
    int array[100];
    int hola = 2;
    printf("Dir %x \n", array);
    printf("Arreglo %d \n", sizeof(array));
    printf("prueba %d \n", sizeof(hola));
    int i;
    int *apuntador = array;
    for(i=0; i<100; i++) {    
        printf("Direcciones: %x \n", &array[i]);
    }

    *(apuntador+49) = 200;
    printf("%d /n", array[49]); 
}
