#include<stdio.h>

float expo(float x, float y){
	int i;
	float num = 1;
	if(y==0)
		return 1;
	else if(y<0){
		for( i = 0; i > y; i-- )
			num *= x;
		return 1/num;
	}
	else{
		for( i = 0; i < y; i++ )
			num *= x;
		return num;
	}
}

void main(){
	float x, y;
	printf("\n\nBem vindo ao programa que calcula expoentes!!!\n");
	printf("digite a base: ");
	scanf("%f", &x);
	printf("digite o expoente: ");
	scanf("%f", &y);
	printf("o resultado eh: %.5f\n", expo(x,y));
	printf("By Emerson Kaneda\n\n");
}
