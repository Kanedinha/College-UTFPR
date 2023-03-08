#include<stdio.h>

void imprimi(int n){
	if(n>20){}
	else{
		printf("%d ", n);
		imprimi(n+1);
		printf("%d ", n);
	}
}

void main(){
	int n;
	printf("Digite um numero: ");
	scanf("%d", &n);
	imprimi(n);
}