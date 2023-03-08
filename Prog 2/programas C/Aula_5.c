/*** Grafos ***/

/*G1 = ({A,B,C,D,E,F,G},{A-B:1,A-C:2,A-D:3,B-D:5,C-D:3,B-E:4,C-F:2,D-E:1,D-F:2,D-G:7,E-G:1,F-G:2})*/

#include<stdio.h>

int destino = 6;

int vertices = 7;
int matAdj[7][7] = {
			{0,1,2,3,0,0,0}
			{0,0,0,5,4,0,0}
			{0,0,0,3,0,2,0}
			{0,0,0,0,1,2,7}
			{0,0,0,0,0,0,1}
			{0,0,0,0,0,0,2}
			{0,0,0,0,0,0,0}
};
buscatenta(asfasfojba)

int buscatenta(int mat[][], int n, int start, int finish){
	if(start == finish)
			return mat[start][finish];
	int menor = INT_MAX;
	int vmenor = -1;
	for(int j = 0; j < n; j++)
		if(mat[start][j] != 0){
			aculmula = mat[start][j];
			custo = buscatenta(mat, n, j, finish);
		}
		if(acumula + custo < menor){
			menor = acumula + custo;
			vmenor = j;
		}
		printf("")
}