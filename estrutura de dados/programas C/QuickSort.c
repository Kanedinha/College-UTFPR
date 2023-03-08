#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct lista{
	char nome[50];
	int idade;
	char cpf[11];
	int pontos;
	struct lista* prox;
	struct lista* ant;

};
typedef struct lista Lista;

Lista *inicializa(){
	return NULL;
}

Lista *insereComeco(Lista *l, char nome[], int idade, char cpf[], int pontos){
	
	Lista* novo = (Lista*) malloc(sizeof(Lista));

	strcpy(novo->nome, nome);
	novo->idade = idade;
	strcpy(novo->cpf, cpf);
	novo->pontos = pontos;

	novo->prox = l;
	novo->ant = NULL;

	if(l != NULL)
		l->ant = novo;
	return novo;

}

Lista *insereFinal(Lista *l, char nome[], int idade, char cpf[], int pontos){
	
	Lista* novo = (Lista*) malloc(sizeof(Lista));

	strcpy(novo->nome, nome);
	novo->idade = idade;
	strcpy(novo->cpf, cpf);
	novo->pontos = pontos;

	novo->ant = l;
	novo->prox = NULL;

	if(l != NULL)
		l->prox = novo;
	return novo;

}

void imprimiComeco(Lista *l){
	Lista* p = l;
	char nome[50];
	char cpf[11];

	printf("\n__________________________\n");
	for(p = l; p != NULL; p = p->prox){
		printf("nome: %s\n", p->nome);
		printf("idade: %d\n", p->idade);
		printf("cpf: %s\n", p->cpf);
		printf("pontos: %d\n", p->pontos);
	}
	printf("\n__________________________\n");

	free(p);
}

void imprimiFinal(Lista *l){
	Lista* p = l;
	printf("\n__________________________\n");
	for(p = l; p != NULL; p = p->ant){
		printf("nome: %s\n", p->nome);
		printf("idade: %d\n", p->idade);
		printf("cpf: %s\n", p->cpf);
		printf("pontos: %d\n", p->pontos);
	}
	printf("\n__________________________\n");

	free(p);
}

void retira(Lista* comeco, Lista* final, char info[]) {
	
	Lista *cCpy = comeco;
	Lista *fCpy = final;

	if(!strcmp(cCpy->nome, info)){
		comeco = cCpy->prox;
		return;
	}
	else{
		for ( cCpy; strcmp(cCpy->prox->nome,info) != 0; cCpy = cCpy->prox )	{
			if(cCpy->prox->prox == NULL){
				printf("A informacao nao existe\n");
				return;
			}
		}
	}

	if( !strcmp(fCpy->nome, info)){
		for ( fCpy; strcmp(fCpy->ant->nome, info) != 0; fCpy = fCpy->ant )	{
			
		}
	}
	else{
		final = fCpy->ant;
		return;
	}
	
	cCpy->prox = fCpy;
	fCpy->ant = cCpy;

	return;
}





void show(int *v, int length){
	for(int i = 0; i < length; i++)
		printf("v[%d] -> %d\n", i, v[i]);
	printf("\n");
}

void quick(Lista* l, int begin, int end){
	int pivo = v[(end + begin)/2];
	int i = begin;
	int j = end;

	while( i <= j){
		while(v[i] < pivo && i < end)
			i++;
		while(v[j] > pivo && j > begin)
			j--;
		if(i < j){
		
			i++;
			j--;
		}
		else if(i == j){
			i++;
			j--;
		}
		if(begin < j)
			quick(v, begin, j);
		if(end > i)
			quick(v, i, end);
	}
}

int main(){

	Lista *final;
	Lista *comeco;

	final = comeco = inicializa();
	
	final = comeco = insereFinal(final, "Emerson", 18, "06203829960", 100);
	final = insereFinal(final, "avatar", 18, "00000000000", 99);
	comeco = insereComeco(comeco, "boltz", 18, "11111111111", 99);
	comeco = insereComeco(comeco, "Lupi", 19, "22222222222", 98);
	final = insereFinal(final, "vina", 30, "33333333333", 90);

	imprimiComeco(comeco);
	imprimiFinal(final);

	retira(comeco, final, "avatar");

	imprimiComeco(comeco);
	imprimiFinal(final);

	return 0;

	show(v, length);
	quick(v, 0, length-1);
	show(v, length);

}


