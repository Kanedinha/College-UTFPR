#include <stdio.h>

int calcula(int num){
	if(num % 10 == 0)
		return num;
	if(num < 0){
		printf("um valor invalido\n");
		return;
	}
	printf("%d + ", num % 10);
	return num % 10 + calcula(num/10);
}

void main(){
	int num;
	printf("\nDigite um numero: ");
	scanf("%d", &num);
	printf("\nO resultado da soma dos numeros eh: %d\n", calcula(num));
}