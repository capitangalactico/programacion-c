#include <stdio.h>
#include <stdlib.h>

#define VACIO -1
#define C 0
#define X 1
#define YAGANO 1

void dibujar(int gato[3][3]);
void iniciar(int gato[3][3]);
void tirar(int gato[3][3]);
int checar(int gato[3][3]);

int main() {
	int gato[3][3];
	int i;

	iniciar(gato);
	dibujar(gato);
	for(i=0; i<9; i++){
        tirar(gato);
        dibujar(gato);
        if (checar(gato) == YAGANO)
            i=9;
    }
	system("pause");
	return 0;
}

void iniciar(int gato[3][3]){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
	    	gato[i][j]=VACIO;
	    }
    }
}

void dibujar(int gato[3][3]){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(gato[i][j] == VACIO)
				printf(" ");
			else
				if(gato[i][j] == C)
			   		printf("%d", C);
			   	else
					printf("X");
			if(j<2)
			printf("|");
		}
  	  if(i<2)
	     printf("\n------\n");
	}
	printf("\n");
}

void tirar(int gato[3][3]){
    static int tiradas = 0;
	int r,c;
	do{
	printf("\nElige el renglon y la columna donde quieres tirar (0 0 a 2 2): ");
	scanf("%d %d", &r, &c);
	}while(r<0 || r>2 || c<0 || c>2);
	if(tiradas == 9)
		return 0;
	if(tiradas % 2 == 0)
		gato[r][c]=C;
	else
		gato[r][c]=X;
	tiradas++;
}

int checar(int gato[3][3]){
    // Filas
	if (gato[0][0] == gato[0][1] && gato[0][1] == gato[0][2] && gato[0][2] != VACIO){
	    printf("\nGano el jugador de las %c \n ", (gato[0][1] == C)?'0':'X');
		return YAGANO;
	}
	if (gato[1][0] == gato[1][1] && gato[1][1] == gato[1][2] && gato[1][2] != VACIO){
	    printf("\nGano el jugador de las %c \n ", (gato[1][2] == C)?'0':'X');
		return YAGANO;
	}
	if (gato[2][0] == gato[2][1] && gato[2][1] == gato[2][2] && gato[2][2] != VACIO){
	    printf("\nGano el jugador de las %c \n ", (gato[2][2] == C)?'0':'X');
		return YAGANO;
	}
	// Columnas
	if (gato[0][0] == gato[1][0] && gato[1][0] == gato[2][0] && gato[2][0] != VACIO){
	    printf("\nGano el jugador de las %c \n ", (gato[2][0] == C)?'0':'X');
		return YAGANO;
	}
	if (gato[0][1] == gato[1][1] && gato[1][1] == gato[2][1] && gato[2][1] != VACIO){
	    printf("\nGano el jugador de las %c \n ", (gato[2][1] == C)?'0':'X');
		return YAGANO;
	}
	if (gato[0][2] == gato[1][2] && gato[1][2] == gato[2][2] && gato[2][2] != VACIO){
	    printf("\nGano el jugador de las %c \n ", (gato[2][2] == C)?'0':'X');
		return YAGANO;
	}
	// Cruz
	if (gato[0][0] == gato[1][1] && gato[1][1] == gato[2][2] && gato[2][2] != VACIO){
	    printf("\nGano el jugador de las %c \n ", (gato[2][2] == C)?'0':'X');
		return YAGANO;
	}
	if (gato[0][2] == gato[1][1] && gato[1][1] == gato[2][0] && gato[2][0] != VACIO){
	    printf("\nGano el jugador de las %c \n ", (gato[2][0] == C)?'0':'X');
		return YAGANO;
	}
    return 0;
}
