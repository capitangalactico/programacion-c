#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main(int argc, char const *argv[]) {
  /* code */
  int error = 0;
  FILE *file = NULL;

  file = fopen(argv[1], "r");
  if (file == NULL) {
    printf("Error");
    exit(0);
  }

  mostrar_conetenido(file);
  return 0;
}
