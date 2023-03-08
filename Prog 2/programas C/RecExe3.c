#include<stdio.h>

inverte(int num){
	if(num<=0)
		printf(" ");
	else{
		printf("%d", num%10);
		inverte(num/10);
	}
}

void main(){
	int num;
	printf("\nBem vindo ao programa que inverte um numero inteiro!!!\n");
	printf("Digite um numero: ");
	scanf("%d", &num);
	printf("Numero invertido: ");
	inverte(num);
}