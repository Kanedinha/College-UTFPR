#include<stdio.h>

int fatorial(int n){
	if(n <= 1 )
		return 1;
	else
		return n *= fatorial(n-1);
}

void main(){
	int n;
	printf("\nDigite um numero para calcular o fatorial quadruplo: ");
	scanf("%d", &n);
	printf("\nO fatorial quadruplo eh: %d\n", (fatorial(2*n))/(fatorial(n)));
}