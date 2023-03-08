#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int valor;
	struct lista *prox;
} TLista;

TLista* inicializa(){
	return NULL;
}

TLista* insere(TLista* l){
	
	TLista* novo = (TLista*) malloc(sizeof(TLista));
	int valor;

	printf("Digite o valor: ");
	scanf("%d", &valor);

	novo->valor = valor;
	novo->prox = l;

	return novo;
}

int valorAcumulado(TLista* l){

	TLista* p = l;
	int valorAc;

	for(p; p != NULL; p = p->prox){
		valorAc += p->valor;
	}

	return valorAc;
}

int main(){

	TLista * l;
	int tamanho;

	l = inicializa();

	printf("Tamanho da lista: ");
	scanf("%d", &tamanho);

	for (tamanho; tamanho > 0; tamanho--){
		l = insere(l);
	}

	printf("Valor acumulado: %d \n", valorAcumulado(l));

}