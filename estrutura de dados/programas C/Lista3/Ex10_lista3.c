#include <stdio.h>
#include <stdlib.h>

struct no {
	int valor;
	struct no* prox;
};
typedef struct no No;

struct fila {
	No* ini;
	No* fim;
};
typedef struct fila Fila;

struct numero{
	int num;
	struct numero* prim;
};
typedef struct numero Numero;

struct pilha{
	Numero* prim;
};
typedef struct pilha Pilha;

Pilha* criaPilha(){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->prim = NULL;

	return p;
}

int pilhaVazia(Pilha* p){
	return(p->prim == NULL);
}

Numero* ins_ini(Numero* l, int num){
	Numero* p = (Numero*) malloc(sizeof(Numero));

	p->num = num;
	p->prim = l;

	return p;
}

Numero* ret_pilha (Numero* l){
	Numero* p = l->prim;

	free(l);
	return p;
}

void push(Pilha* p, int num){
	p->prim = ins_ini(p->prim, num);
}

int pop (Pilha* p){
	int aux;

	if (pilhaVazia(p)) {
		printf("Pilha vazia.\n");
		exit(1);
	}

	aux = p->prim->num; 	
	p->prim = ret_pilha(p->prim);

	return aux;
}

Fila* criaFila(){
	Fila* f = (Fila*) malloc(sizeof(Fila));

	f->ini = f->fim = NULL;

	return f;
}

int vazia(Fila* f){
	return(f->ini == NULL);
}

No* ins_fim(No* f, int valor){
	No* p = (No*)malloc(sizeof(No));

	p->valor = valor;
	p->prox = NULL;

	if(f != NULL){
		f->prox = p;
	}

	return p;
}

No* ret_ini(No* f){
	No* d = f->prox;

	free(f);

	return d;
}

void insere (Fila* f, int valor){
	f->fim = ins_fim(f->fim, valor);

	if (f->ini==NULL)
		f->ini = f->fim;
}

int retira (Fila* f){
	int valor;

	if (vazia(f)) {
		printf("Fila vazia.\n");
		exit(1);
	}

	valor = f->ini->valor;
	f->ini = ret_ini(f->ini);
	
	if (f->ini == NULL)
		f->fim = NULL;
	
	return valor;
}

void imprimi(Fila* f){
	No* l;

	printf("\n______________________________\n");

	for(l = f->ini;l != NULL; l = l->prox){
		printf("-> %d\n" ,l->valor);
	}
}

Fila* inverte(Fila* f){
	Pilha* p = criaPilha();
	int aux;

	while(!vazia(f)){
		aux = retira(f);
		push(p, aux);
	}

	while(!pilhaVazia(p)){
		aux = pop(p);
		insere(f, aux);
	}

	return f;
}

int main(){
	Fila* f = criaFila();

	insere(f, 1);
	insere(f, 2);
	insere(f, 3);
	insere(f, 4);
	insere(f, 5);
	insere(f, 6);
	insere(f, 7);
	insere(f, 8);
	insere(f, 9);
	insere(f, 10);
	
	imprimi(f);

	f = inverte(f);

	imprimi(f);

	return 0;
}

