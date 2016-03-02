#include <stdio.h>
#include <stdlib.h>

/*int main(int argc, char *argv[])
{
  int num, i;
  long factorial = 1L;
  printf("Introduce un numero y calculare su factorial ");
  scanf("%d", &num);

  for (i = num; i > 0; i--) {
      if(i > 1)
           printf("%d x ", i);
      else
          printf("%d", i);

    factorial = factorial * i;
  }

  printf("\nEl factorial de %d es:  %ld \n", num, factorial);
  system("PAUSE");
  return 0;
}*/

int main(int argc, char const *argv[]) {
  int VOT, C1 = 0, C2 = 0, C3 = 0, C4 = 0, C5 = 0, NU = 0, SVO;
  float PO1, PO2, PO3, PO4, PO5, PON;
  printf("Ingrese el primer voto: \n");
  scanf("%d", &VOT);

  while (VOT && (C1+C2+C3+C4+C5+NU<20)) {
    switch (VOT) {
      case 1:
        C1++;
        break;
      case 2:
        C2++;
        break;
      case 3:
        C3++;
        break;
      case 4:
        C4++;
        break;
      case 5:
        C5++;
        break;
      default:
        NU++;
        break;
    }
    printf("Ingrese el siguiente voto - 0 para terminar -:\n");
    scanf("%d", &VOT);
  }
  SVO = C1 + C2 + C3 + C4 + C5 + NU;

  PO1 = ((float) C1 / SVO) * 100;
  PO2 = ((float) C2 / SVO) * 100;
  PO3 = ((float) C3 / SVO) * 100;
  PO4 = ((float) C4 / SVO) * 100;
  PO5 = ((float) C5 / SVO) * 100;
  PON = ((float) NU / SVO) * 100;

  printf("\n Total de votos: %d \n", SVO);

  printf("\n Canditato 1: %d votos -- Porcentaje: %5.2f", C1, PO1);
  printf("\n Canditato 2: %d votos -- Porcentaje: %5.2f", C2, PO2);
  printf("\n Canditato 3: %d votos -- Porcentaje: %5.2f", C3, PO3);
  printf("\n Canditato 4: %d votos -- Porcentaje: %5.2f", C4, PO4);
  printf("\n Canditato 5: %d votos -- Porcentaje: %5.2f", C5, PO5);

  printf("\n Nulos:       %d votos --- Porcentaje: %5.2f \n", NU, PON);

  if(C1>C2 && C1>C3 && C1>C4 && C1>C5) {
    printf("Ganador 1");
  } else {
    if (C2>C1 && C2>C3 && C2>C4 && C2>C5) {
      printf("Ganador 2");
    } else {
      if (C3>C1 && C3>C2 && C3>C4 && C2>C5) {
        printf("Ganador 3");
      } else {
        if (C4>C1 && C4>C2 && C4>C3 && C4>C5) {
          printf("Ganador 4");
        } else {
          if (C5>C1 && C5>C2 && C5>C3 && C5>C4) {
            printf("Ganador 5");
          } else {
            printf("Nadie gano =(");
          }
        }
      }
    }
  }
  system("PAUSE");
  return 0;
}
