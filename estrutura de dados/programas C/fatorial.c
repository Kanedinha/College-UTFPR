#include<stdio.h>

int main(){

	int fatorial;
	int resultado = 1;
	
	printf("Digite o numero para calcular o fatorial: ");
	scanf("%d", &fatorial);

	for(fatorial; fatorial > 1; fatorial--){
		resultado = resultado * fatorial;
	}

	printf("O resultado eh: %d\n", resultado);

	return 0;
}