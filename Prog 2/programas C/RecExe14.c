#include<stdio.h>

void imprimi(int n, int x){
	if(x==n)
		printf("%d\n", x);
	else{
		printf("%d\n", x);
		imprimi(n, x+2); 
	}
}

void main(){
	int n, x=0;
	printf("\nDigite um numero par: ");
	scanf("%d", &n);
	if(n%2==0)
		imprimi(n,x);
	else
		printf("\nVoce nao digitou um numero par!!!\n");
}