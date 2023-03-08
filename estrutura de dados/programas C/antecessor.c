#include<stdio.h>

int main(){

	int num;

	printf("\nDigite um numero: ");
	scanf("%d", &num);

	printf("\nO antecessor do numero %d eh %d\n", num, num - 1);

	return 0;
}