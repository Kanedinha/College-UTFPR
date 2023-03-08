#include <stdio.h>
#include <stdlib.h>

int main(){

	FILE* nomes;
	char nome[100];
	int menu = 1;

	while(menu){

		switch(menu){
			case 1:
			nomes = fopen("nomes.txt", "a");
			printf("oh passa um Nome ai: ");
			scanf("%s", nome);
			fprintf(nomes, "%s\n", nome);
			fclose(nomes);
		}
	}
	exit(0);

	return 0;
}