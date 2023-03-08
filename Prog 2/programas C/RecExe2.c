#include<stdio.h>

int fib(int n){
	if(n==1)
		return 0;
	else if(n==2)
		return 1;
	else
		return n = fib(n-1) + fib(n-2);
	
}

void main(){
	int n;
	printf("\nBem vindo ao programa que retrna o n termo da sequencia de Fibonacci!!!");
	printf("\nqual o termo que voce deseja obter?\n");
	scanf("%d",&n);
	if(n>0)
		printf("\nO %d termo da sequencia eh: %d\n", n, fib(n));
	else
		printf("\nvoce nao digitou um numero inteiro positivo\n");
}
