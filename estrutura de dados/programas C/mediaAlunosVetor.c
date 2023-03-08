#include<stdio.h>

int verifica(int teste){
	if(teste > 10 || teste < 0){
		printf("\nNota invalida, digite novamente: ");
		scanf("%f", &teste);
		printf("\n");
		return verifica(teste);
	}
	else{
		return teste;
	}
}

int main(){

	float notas[30];
	float media = 0;
	float menor = 10;
	float maior = 0;
	int i;

	for(i = 0; i < 30; i++){
		printf("nota %d: ", i + 1);
		scanf("%f", &notas[i]);
		notas[i] = verifica(notas[i]);
		media += notas[i];
		if(notas[i] > maior){
			maior = notas[i];
		}
		if(notas[i] < menor){
			menor = notas[i];
		}
	}

	printf("\nA maior nota foi: %.2f\n", maior);
	printf("A menor nota foi: %.2f\n", menor);
	printf("A media da sala foi: %.2f\n", media/30);
} 