#include<stdio.h>

int fatorial(int fat){
	if(fat <=1 )
		return 1;
	else
		return fat *= fatorial(fat-1);
}

void main(){
	int fat;
	printf("\nBem vindo ao programa que calcula fatorial!!!\n");
	printf("Digite o fatorial desejado: ");
	scanf("%d", &fat);
	printf("O fatorial de %d eh : %d\n", fat, fatorial(fat));
}