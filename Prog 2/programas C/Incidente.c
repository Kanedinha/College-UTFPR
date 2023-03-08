#include<stdio.h>

int comunica(int comeco, int fim, int pessoas, int mat[4][4], int *lingua, int *quem){

	if(comeco == fim)
		return 1;
	for(int i = 0; i < pessoas; i++)
		if(mat[comeco][i]==1){
			if(mat[fim][i]==1)
				printf("a pessoa %d fala diretamen\n", );
				return 1

		}
}

void main(){
	int *lingua = -1;
	int pessoas = 4;
	int mat[4][4] = {  /*ing fra ale port*/
		/*Jensen*/		{ 1 , 1 , 1 , 1 },
		/*Leuzigner	*/	{ 1 , 1 , 1 , 0 },
		/*Dofour*/		{ 0 , 1 , 1 , 0 },
		/*Meideiros	*/	{ 1 , 0 , 0 , 1 },
	};

}