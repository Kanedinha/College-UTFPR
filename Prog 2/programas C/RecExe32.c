#include<stdio.h>

void serie(int num, float *v, float aux){
	if(num == 1)
		v[0] = 2;
	else if(num < 1)
		printf("Valor inválido\n");
	else{
	v[num - 1] = (1 + aux*aux)/aux;
	serie(num - 1, v, aux - 1);
	}
}

void main(){

	int num;
	float result = 2;

	printf("Digite um numero: ");
	scanf("%d", &num);

	float aux = num;
	float v[num];

	serie(num, v, aux);

	printf("%.2f ",v[0]);
	for(int i = 1; i < num; i++){
		printf("+ %.2f ", v[i]);
		result += v[i];
	}
	printf("\nO resultado da soma eh: %.2f\n", result);
}