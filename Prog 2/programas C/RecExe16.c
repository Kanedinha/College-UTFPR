#include<stdio.h>

int fatduplo(int n, int x){
	if(x==1)
		return n;
	else{
		return fatduplo(n*=x,x-2);
	}
}

void main(){
	int n, x;
	printf("\nDigite um numero impar: ");
	scanf("%d", &n);
	if(n%2!=0)
		printf("\nO resultado eh: %d",fatduplo(n,x=n-2));
	else
		printf("\nVoce nao digitou um numero impar!!!\n\n");
}