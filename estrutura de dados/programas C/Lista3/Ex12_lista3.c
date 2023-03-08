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

Fila* cria (){
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

void refilar(Fila* f1, Fila* f2){
	int aux;

	while(!vazia(f1)){
		aux = retira(f1);
		insere(f2, aux);
	}
}

int pares(Fila* f){
	Fila* f2 = cria();
	int par = 0;
	int aux;

	while(!vazia(f)){
		aux = retira(f);
		insere(f2, aux);
		if(aux % 2 == 0)
			par++;
	}
	
	refilar(f2, f);

	free(f2);

	return par;
}

int main(){
	Fila* f = cria();
	int par;

	for(int i = 0; i < 10; i ++)
		insere(f,i);

	par = pares(f);

	printf("elementos pares: %d\n", par);

	return 0;
}