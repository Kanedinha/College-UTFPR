#include<stdio.h>

void imprimi(int x){
	if(x==0)
		printf("%d\n", x);
	else{
		printf("%d\n", x);
		imprimi(x-1); 
	}
}

void main(){
	int n, x;
	printf("\nDigite um numero : ");
	scanf("%d", &x);
	imprimi(x);
}