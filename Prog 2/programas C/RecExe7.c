#include<stdio.h>

void inverte(int * vet, int comeco, int final){
	int aux;
	if(comeco > 50 && final < 50){
	}
	else{
		aux = vet [comeco];
		vet [comeco] = vet [final];
		vet [final] = aux;
		inverte(vet,comeco+1,final-1);
	}
}

void main(){
	int vet[100];
	int comeco = 0, final = 99;
	for(int i = 0; i < 100; i++)
		vet[i] = i;
	inverte(vet,comeco,final);
	for(int i = 0; i < 100; i++)
		printf("%d\n",vet[i]);
}