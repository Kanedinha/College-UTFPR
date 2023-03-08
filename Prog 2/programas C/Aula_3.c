#include<stdio.h>

int fib(int n){			//*** Interativo ***//
	int a = 0, b = 1;
	for( 1 ; n > 1 ; n--){
		b = b+a;
		a = b-a;
	}
	return a;
}					

int fibo(int n){   		//*** Recursivo ***//
	int x;
	if(n==1)
		return 0;
	else if(n==2)
		return 1;
	else{
		x=fibo(n-1)+fibo(n-2);
		return x;
	}
}

void main(){
	int n;
	printf("\nBem vindo ao programa que retrna o n termo da sequencia de Fibonacci!!!");
	printf("\nqual o termo que voce deseja obter?\n");
	scanf("%d",&n);
	if(n>0)
		printf("\nO %d termo da sequencia eh: %d\n", n, fibo(n));
	else
		printf("\nvoce nao digitou um numero inteiro positivo\n");
}

