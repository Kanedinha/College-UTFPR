#include <stdio.h>
#include <stdlib.h>

struct docs {
	int registro;
	int valor;
	struct docs* prox;
	struct docs* ant;
};
typedef struct docs Docs;

struct fila {
	Docs* ini;
	Docs* fim;
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

Docs* ins_fim(Docs* f, int registro, int valor){
	Docs* p = (Docs*)malloc(sizeof(Docs));

	p->registro = registro;
	p->valor = valor;
	p->ant = f;
	p->prox = NULL;

	if(f != NULL){
		f->prox = p;
	}

	return p;
}

Docs* ins_ini(Docs* f, int registro, int valor){
	Docs* p = (Docs*)malloc(sizeof(Docs));

	p->registro = registro;
	p->valor = valor;
	p->prox = f;
	p->ant = NULL;

	if(f != NULL){
		f->ant = p;
	}

	return p;
}

Docs* ret_ini(Docs* f){
	Docs* d = f->prox;
	free(f);
	return d;
}

Docs* ret_fim(Docs* f){
	Docs* d = f->ant;
	free(f);
	return d;
}

void insere_fim(Fila* f, int registro, int valor){
	f->fim = ins_fim(f->fim, registro, valor);

	if (f->ini == NULL){
		f->ini = f->fim;
	}
	printf("Registro na fila -> %d\n", registro);
}

void insere_ini(Fila* f, int registro, int valor){
	f->ini = ins_ini(f->ini, registro, valor);

	if (f->fim == NULL){
		f->fim = f->ini;
	}
	printf("Registro na fila -> %d\n", registro);
}

Docs retira_ini(Fila* f){
	Docs v;
	if (vazia(f)) {
		printf("Fila vazia.\n");
		exit(1);
	}

	v.registro = f->ini->registro;
	v.valor = f->ini->valor;

	f->ini = ret_ini(f->ini);

	if (f->ini == NULL)
		f->fim = NULL;
	return v;
}

Docs retira_fim(Fila* f){
	Docs v;
	if (vazia(f)) {
		printf("Fila vazia.\n");
		exit(1);
	}

	v.registro = f->fim->registro;
	v.valor = f->fim->valor;

	f->fim = ret_ini(f->fim);

	if (f->fim == NULL)
		f->ini = NULL;
	return v;
}

void imprimi(Fila* f){
	Docs* l;
	for(l = f->ini;l != NULL; l = l->prox){
		printf("oi-> %d -> %p -> %p\n" ,l->valor, l, l->prox);
	}
}

int main(){
	Fila* f = cria();
	Docs v;

	insere_fim(f, 1, 12);
	insere_ini(f, 2, 23);
	insere_fim(f, 3, 66);
	insere_fim(f, 4, 45);
	insere_fim(f, 5, 47);
	insere_ini(f, 6, 24);
	insere_ini(f, 7, 65);
	insere_ini(f, 8, 75);

	imprimi(f);

	v = retira_fim(f);
	printf("\n_____________________\n");
	printf("Registro: %d\n", v.registro);
	printf("Valor: %d\n", v.valor);

	return 0;
}
