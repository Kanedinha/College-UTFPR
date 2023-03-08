#include<stdio.h>
#include<limits.h>

int busca(int mat[7][7], int vertices, int comeco, int fim){
	int menor = INT_MAX;
	int vmenor = -1;
	if( comeco == fim ){
		*tmcaminho = 1;
		mcaminho[0] = destinho
		return mat[comeco][fim];
	}
	for(int j = 0; j < vertices; j++){
		if(mat[comeco][j] != 0){
			int tamanhomenortemp = 0;
			int menorcaminhotemp[vertices];
			int acumula = mat[comeco][j];
			int custo = busca(mat,vertices,j,fim);
			if(acumula + custo < menor){
				for (int i = 0; i < tamanhomenor; ++i){
					menorcaminho[i] = menorcaminhotemp;
					*tamanhomenor = tamanhomenortemp; 
				}
				menor = acumula + custo;
				vmenor = j;
			}	
		}
	}
	mcaminho[tmcaminho] = origem;
	*tmcaminho = *tmcaminho + 1;
	return menor;
}

void main(){
	int *tmcaminho
	int tamanhomenor[7];
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
	printf("\nO menor valor possivel eh: %d\n",busca(matAdj,vertices,comeco,fim,tmcaminho,tamanhomenor));

}

