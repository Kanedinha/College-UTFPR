#include<stdio.h>

int multiplicacao(int n, int k, int x){
	if(k==0)
		return x;
	else if(k > 0){
		x += n;
		return multiplicacao(n,k-1,x);
	}
}

void main(){
	int n,k,x=0;
	printf("\nDigite um numero: ");
	scanf("%d", &n);
	printf("Quantas vezes voce quer somar esse numero: ");
	scanf("%d", &k);
	printf("\nO resultado eh: %d", multiplicacao(n,k,x));
}