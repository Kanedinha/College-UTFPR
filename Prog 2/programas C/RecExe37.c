#include <stdio.h>
#define TAM 10

void labi(int lab[10][10], int * start, int * finish, int * anterior, int i, int j){
	
	//condição de parada: chegar no destino
	printf("linha: %d - coluna: %d", i,j);
	if(start == finish){
		printf("\nChegou no destino!!!\n");
	}

	//condição de parada: beco sem saída

	if(lab[i][j + 1] == 0){
		if(&lab[i][j + 1] != anterior){
			int *aux = &lab[i][j + 1];
			int *aux2 = &lab[i][j];
			labi(lab, aux, finish, aux2, i, j + 1);
		}
	}
	if(lab[i][j - 1] == 0){
		if(&lab[i][j - 1] != anterior){
			int *aux = &lab[i][j - 1];
			int *aux2 = &lab[i][j];
			labi(lab, aux, finish, aux2, i, j - 1);
		}
	}
	if(lab[i - 1][j] == 0){
		if(&lab[i - 1][j] != anterior){
			int *aux = &lab[i - 1][j];
			int *aux2 = &lab[i][j];
			labi(lab, aux, finish, aux2, i - 1, j);
		}
	}
	if(lab[i + 1][j] == 0){
		if(&lab[i + 1][j] != anterior){
			int *aux = &lab[i + 1][j];
			int *aux2 = &lab[i][j];
			labi(lab, aux, finish, aux2, i + 1, j);
		}
	}
}

void labirinto(int lab[10][10], int * start, int * finish){
	//memoria de onde passou
	
	int *anterior = start;
	int i = 0;
	int j = 0;

	labi(lab, start, finish, anterior, i, j);
}


void main(){
	/*
	int lab[2][2]={	{0,1},
					{0,0}};*/
	
	int lab[10][10] = {	{0,0,0,0,0,0,1,0,0,0},
						{0,1,1,1,0,1,0,0,1,0},
						{0,0,1,0,0,1,0,1,1,0},
						{1,0,1,0,1,0,0,1,0,0},
						{0,1,0,0,1,0,1,0,0,1},
						{0,1,0,1,0,0,0,1,0,0},
						{0,1,0,0,0,1,0,1,1,0},
						{0,0,1,1,0,1,0,1,0,0},
						{0,1,0,0,0,1,0,0,1,1},
						{0,0,0,1,0,0,1,0,0,0},
						};
	

	int *start = &lab[0][0];
	int *finish = &lab[9][9];

	labirinto(lab, start, finish);
}