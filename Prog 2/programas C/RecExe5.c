#include <stdio.h>

int soma(int num){
	if(num <= 0)
		return num;
	else
		return num += soma(num-1);
}

void main(){
	int num;
	printf("\nDigite o numero para calcular o seu somatorio: ");
	scanf("%d", &num);
	printf("O resultado do somatorio de %d eh: %d\n", num, soma(num));
}