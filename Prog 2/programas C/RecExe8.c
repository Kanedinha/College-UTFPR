#include<stdio.h>

int mdc(int x, int y){
	if(y == 0)
		return x;
	else
		return mdc(y,x%y);
}

void main(){
	int x, y;
	printf("\nBem vindo ao programa que calcula o minimo multiplo comum(mdc)!!!\n");
	printf("Digite um numero: ");
	scanf("%d", &x);
	printf("Digite outro numero: ");
	scanf("%d", &y);
	printf("mdc eh: %d\n", mdc(x,y));
}