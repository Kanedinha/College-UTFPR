#include<stdio.h>
#include<string.h>

void fib(int n){
	if(n==0)
		printf("b");
	else if(n==1)
		printf("a");
	else
		printf("%s",strcat(fib(n-1),fib(n-2)));
}

void main(){
	int n;
	printf("\nDigite um numero: ");
	scanf("%d", &n);
	printf("\n");
	fib(n);
}