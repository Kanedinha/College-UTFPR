#include<stdio.h>

void vet(int tv, int*v){
	
}

int verif(int i, int*v, int tv){
	tv--;
	if(tv>0){
		if(v[tv]==i)
			return tv;
		else{
			return verif(i,v,tv);
		}
	}
	else
		return -1;
}

void main(){
	int i,tv;
	int v[tv];
	printf("digite o tamanho do vetor: ");
	scanf("%d", &tv);
	printf("digite os elementos do vetor:\n");

	printf("o numero %d esta na posicao %d", i, verif(i,v,tv));

}