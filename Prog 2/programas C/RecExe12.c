#include<stdio.h>

void imprimi(int n, int x){
	if(x==n)
		printf("%d\n", x);
	else{
		printf("%d\n", x);
		imprimi(n, x+1); 
	}
}

void main(){
	int n, x=0;
	printf("\nDigite um numero : ");
	scanf("%d", &n);
	imprimi(n,x);
}