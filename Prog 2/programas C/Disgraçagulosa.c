#include<stdio.h>
#include<limits.h>

int gulosa(int mat[7][7], int vertices, int comeco, int fim){
	int menor = INT_MAX, aux, custo, acumulado = INT_MAX;
	if( comeco == fim )
		return mat[comeco][fim];
	for(int j = 0; j < vertices; j++){
		if(mat[comeco][j] != 0){
			if(mat[comeco][j] < acumulado){
				acumulado = mat[comeco][j];
				aux = j;
			}
		}
	}
	printf("\npassei por %d", aux);
	custo = gulosa(mat, vertices, aux, fim);
	return acumulado + custo;
}

void main(){
int vertices = 7, comeco = 0, fim = 6;
int matAdj[7][7] = {
			{0,1,2,3,0,0,0},
			{0,0,0,5,4,0,0},
			{0,0,0,3,0,2,0},
			{0,0,0,0,1,2,7},
			{0,0,0,0,0,0,1},
			{0,0,0,0,0,0,2},
			{0,0,0,0,0,0,0},
	};
	printf("\nO menor valor possivel eh: %d\n",gulosa(matAdj,vertices,comeco,fim));
}

