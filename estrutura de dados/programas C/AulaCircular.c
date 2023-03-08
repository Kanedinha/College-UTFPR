#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista{
	int id;
	struct lista* prox;
};
typedef struct lista Lista;

Lista* inicializa(){
	return NULL;
}

Lista* insere(Lista* l, int id, Lista* comeco){
	
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	
	novo->id = id;

	novo->prox = comeco;
	l->prox = novo;

	return novo;
}

void imprime (Lista* l, Lista* inicio) {
	Lista* p = l;

	do{
		printf("-> %d\n", p->id);
		printf("________________________\n");
		p = p->prox;
	}while(p != inicio);

	// for(p = l; p->prox != inicio; p = p->prox){
	// 	printf("-> %d\n", p->id);
	// 	printf("________________________\n");
	// }

	p = NULL;
}

Lista* busca(Lista* l, int id){
	Lista* p = l;

	while(p->id != id){
		p = p->prox;
		if(p == NULL){
			printf("O id nao existe\n");
			return NULL;
		}
	}

	printf("id -> %d\n", p->id);

	return p;
}

int main(){
	
	Lista *l;
	Lista *inicio;
	Lista *aux;

	l = inicio = inicializa();
	printf(" asasdasd\n");
	l =  insere(l, 1, inicio);
	inicio = l;
	l = insere(l, 2, inicio);
	l = insere(l, 3, inicio);
	printf(" inseriu\n");
	imprime(l,inicio);

	// aux = busca(l, 2);

	return 0;
}