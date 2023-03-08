#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int info;
	struct lista *prox;
} TListaCircular;

TListaCircular* insere (TListaCircular* l, int info, TListaCircular* p) {
	TListaCircular* novo = (TListaCircular*) malloc(sizeof(TListaCircular));
	novo->info = info; 
	novo->prox = p; 
	l->prox = novo;
	return novo; 
}

void imprime_circular (TListaCircular* l){
	TListaCircular* p = l;
	if (p) {
		do {
			printf("%p, ", p);
			printf("%d, ", p->info);
			printf("%p\n", p->prox);
			p = p->prox;
		} while (p != l);
	}
}

TListaCircular* inicializa ( int info) {
	TListaCircular* novo = (TListaCircular*) malloc(sizeof(TListaCircular));
	novo->info = info; 
	novo->prox = NULL; 
	return novo; 
}

void retira(TListaCircular* l, int info){
	TListaCircular* p = l;
	
	do{
		p = p->prox;
	}while(p->prox->info != info);

	p->prox = p->prox->prox;
}

TListaCircular* busca(TListaCircular* l, int info){
	TListaCircular* p = l;

	while(p->info != info){
		p = p->prox;
		if(p == l){
			printf("Nao encontrado\n");
			return NULL;
		}
	}

	printf("info encontrada = %d\n", p->info);

	return p;
}

int main(){
	TListaCircular *lista, *inicio, *aux;
	inicio = lista = inicializa(1);
	lista = insere(lista, 2, inicio);
	lista = insere(lista, 3, inicio);
	lista = insere(lista, 4, inicio);
	lista = insere(lista, 5, inicio);
	lista = insere(lista, 6, inicio);
	lista = insere(lista, 7, inicio);
	imprime_circular(lista);
	printf("____________________________\n");
	aux = busca(lista, 10);
}