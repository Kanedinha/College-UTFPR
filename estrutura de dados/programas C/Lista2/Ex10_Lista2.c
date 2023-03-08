#include <stdio.h>
#include <stdlib.h>

struct lista{
	int info;
	struct lista* prox;
};
typedef struct lista Lista;

Lista* inicializa(){
	return NULL;
}

Lista* insere(Lista* l, int info){
	Lista* novo = (Lista*)malloc(sizeof(Lista));

	novo->info = info;
	novo->prox = l;

	return novo;

}

int tamanhoLista(Lista* l){
	Lista* p = l;
	int tamanho = 0;

	for(p; p != NULL; p = p->prox){
		tamanho++;
	}

	return tamanho;
}

void listJoin(Lista* l_1, Lista* l_2){
	Lista* p = l_1;
	Lista* aux = (Lista*)malloc(sizeof(Lista));
	while(p->prox != NULL){
		p = p->prox;
	}

	*aux = *l_2;
	p->prox = aux;
	*l_2 = *l_1;

}

void imprime (Lista* l) {
	Lista* p = l;
	
	printf("_____________________________\ninfo ");
	for(p = l; p != NULL; p = p->prox){
		printf("-> %d    ", p->info);

	}

	printf("\n_____________________________\n");

	p = NULL;
}

int main(){
	Lista* l_1 ;
	Lista* l_2 ;
	Lista* aux ;

	l_1 = inicializa();
	l_2 = inicializa();

	l_1 = insere(l_1, 3);
	l_1 = insere(l_1, 2);
	l_1 = insere(l_1, 1);

	l_2 = insere(l_2, 5);
	l_2 = insere(l_2, 4);
	l_2 = insere(l_2, 8);

	imprime(l_1);
	imprime(l_2);

	listJoin(l_1, l_2);

	imprime(l_1);
	imprime(l_2);

	free(l_1);
	free(l_2);
	return 0;
}