#include<stdio.h>

void funcao (int num){

	if(num > 20){ /* nao faz nada*/ }

	else{
		printf("%d ", num);
		funcao(num + 1);
		printf("%d ", num);
	}
}

void main(){
	int num;
	while(1){
		num = 0;
		printf("\nDigite um numero: ");
		scanf("%d", &num);
		funcao(num);
	}
}
