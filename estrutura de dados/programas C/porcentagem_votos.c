#include<stdio.h>

int main(){

	float brancos;
	float nulos;
	float validos;

	printf("\nDigite quantos votos brancos registrados: ");
	scanf("%f", &brancos);

	printf("Digite quantos votos nulos registrados: ");
	scanf("%f", &nulos);
	
	printf("Digite quantos votos validos registrados: ");
	scanf("%f", &validos);

	printf("\nO numero de votos brancos foi de %.2f %c \n", (brancos / (brancos + nulos + validos) ) * 100, '%');
	printf("\nO numero de votos nulos foi de %.2f %c \n", (nulos / (brancos + nulos + validos) ) * 100, '%');
	printf("\nO numero de votos validos foi de %.2f %c \n", (validos / (brancos + nulos + validos) ) * 100, '%');

	return 0;

}