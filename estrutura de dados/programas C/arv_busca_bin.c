#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int info;
	struct no *dir;
	struct no *esq;
}No;

No* inicializa(){
	return NULL;
}

int vazia(No* a){
	return a==NULL;
}

void imprime (No* a){
	if (!vazia(a)){
		printf("%d \n", a->info);
		imprime(a->esq);
		imprime(a->dir);
	}
}

No* cria(No *raiz, int info){
	No *novo = (No*)malloc(sizeof(No));
	No *aux = raiz;
	No *ant = NULL;

	novo -> info = info;
	novo -> dir = NULL;
	novo -> esq = NULL;
	if(raiz == NULL)
		raiz = novo;
	else{
		printf("Aqui\n");
		while(ant != NULL){
			ant = aux;
			if(info < aux->info) //percorrer a árvore pela esquerda
				aux = aux->esq;
			else //percorrer a árvore pela direita
				aux = aux->dir;
		}
		if(info < ant->info){
			ant->esq = novo;
					printf("NOVO\n");
		}
		else
			ant->dir = novo;
	}
	printf("Aqui\n");
	imprime(novo);
	return novo;
}

int main(){
	No * raiz = NULL;
	No* a = raiz = cria(raiz, 5);
	imprime(a);	
	No* a1= cria(raiz, 2);
	printf("Aquiiii\n");
	imprime(a);	
	No* a2= cria(raiz, 7);
	imprime(a);	
	No* a3= cria(raiz, 1);
	imprime(a);	
	No* a4= cria(raiz, 3);
	imprime(a);	

	imprime(a);	
	return 0;
}