#include<stdio.h>

int main(){

	int num;
	float media = 0;
	int i;

	for(i = 0; i < 5; i++){
		printf("Digite o %d' numero: ", i + 1);
		scanf("%d", &num);
		media += num;
	}

	printf("A media eh: %.2f\n", media/5);

	return 0;
}