#include <stdio.h>

int expo(int n, int k){
	if(k == 0)
		return 1;
	else
		return n *= expo(n,k-1);
}

void main(){
	int n, k;
	printf("\nBem vindo ao programa que calcula exponenciais!!!\n");
	printf("Digite a base: ");
	scanf("%d", &n);
	printf("Digite o expoente: ");
	scanf("%d", &k);
	printf("O resultado eh: %d\n", expo(n,k));
}