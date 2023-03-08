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

int tamanhoFila(Fila* f){
	Fila* f2 = cria();
	int aux;
	int cont = 0;

	while(!vazia(f)){
		aux = retira(f);
		insere(f2, aux);
		cont++;
	}

	refilar(f2, f);
	free(f2);
	
	return cont;
}

int maiorFila(Fila* f1, Fila* f2){
	int tamanho_1;
	int tamanho_2;

	tamanho_1 = tamanhoFila(f1);
	tamanho_2 = tamanhoFila(f2);

	if(tamanho_1 > tamanho_2){
		printf("Fila 1 tem mais elementos !!!\n");
		return tamanho_1;
	}
	else if(tamanho_1 < tamanho_2){
		printf("Fila 2 tem mais elementos !!!\n");
		return tamanho_2;	
	}
	else{
		printf("As duas filas tem a mesma quantidade de elementos !!!\n");
		return tamanho_1;
	}
}

int main(){
	Fila* f = cria();
	Fila* f2 = cria();

	int m;

	insere(f, 9);
	insere(f, 8);
	insere(f, 15);
	insere(f, 21);
	insere(f, 2);
	insere(f, 0);
	insere(f, 6);
	insere(f, 78);

	insere(f2, 4);
	insere(f2, 12);
	insere(f2, 15);
	insere(f2, 12);
	insere(f2, 45);
	insere(f2, 6);
	insere(f2, 1);
	insere(f2, 7);

	m = maiorFila(f2, f);

	return 0;
}