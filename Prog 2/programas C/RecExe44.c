#include<stdio.h>

int cubo(int n){
	if(n == 0)
		return 0;
	if(n < 0)
		return -1;
	else 
		return n*n*n + cubo(n-1);
}

void main(){
	int n;
	printf("Digite um numero: ");
	scanf("%d",&n);
	int aux = cubo(n);
	aux != -1? printf("a soma dos cubos eh: %d\n", aux) : printf("Valor invalido!!!\n");
}