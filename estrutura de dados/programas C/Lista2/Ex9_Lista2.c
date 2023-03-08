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

Lista* busca(Lista* l, int info){
	Lista* p = l;

	while(p->info != info){
		p = p->prox;
	}		

	return p;
}

Lista* novaListaPlus(Lista* l){
	Lista* new_l = (Lista*)malloc(sizeof(Lista));
	Lista* p = l;
	int t = tamanhoLista(l);
	int infos[t];
	int i;
	int new_termo;

	new_l = inicializa();
	
	printf("Digite o novo termo: ");
	scanf("%d", &new_termo);

	for(i = 0; i < t; i++){
		infos[i] = p->info;
		p = p->prox;
		new_l = insere(new_l,infos[i]);
		new_l = insere(new_l,new_termo);
	}

	return new_l;
}

void imprime (Lista* l) {
	Lista* p = l;
	
	printf("_____________________________\n");
	for(p = l; p != NULL; p = p->prox){
		printf("info -> %d\n", p->info);
		printf("_____________________________\n");
	}

	p = NULL;
}

int main(){
	Lista* l;
	int t1, t2;

	l = inicializa();

	l = insere(l, 3);
	l = insere(l, 2);
	l = insere(l, 1);

	imprime(l);

	l = novaListaPlus(l);

	imprime(l);

	return 0;
}