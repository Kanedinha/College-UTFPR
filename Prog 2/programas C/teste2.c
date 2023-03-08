#include<stdio.h>
#include<limits.h>

int busca(int mat[7][7], int vertices, int comeco, int fim){
	int menor = INT_MAX;
	if( comeco == fim ){
		return mat[comeco][fim];
	}
	for(int j = 0; j < vertices; j++){
		if(mat[comeco][j] != 0){
			int acumula = mat[comeco][j];
			int custo = busca(mat,vertices,j,fim);
			if(acumula + custo < menor){
				menor = acumula + custo;
			}	
		}
	}
	return menor;
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
	printf("\nO menor valor possivel eh: %d\n",busca(matAdj,vertices,comeco,fim));
}

