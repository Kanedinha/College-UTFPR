#include <stdio.h>
#include <stdlib.h>

struct no {
	float valor;
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

No* ins_fim(No* f, float valor){
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

void insere (Fila* f, float valor){
	f->fim = ins_fim(f->fim, valor);

	if (f->ini==NULL)
		f->ini = f->fim;
}

float retira (Fila* f){
	float valor;

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
	float aux;

	while(!vazia(f1)){
		aux = retira(f1);
		insere(f2, aux);
	}
}

float maior(Fila* f){
	Fila* f2 = cria();
	float maior = retira(f);
	float aux;

	insere(f2, maior);

	while(!vazia(f)){
		aux = retira(f);
		insere(f2, aux);
		if(aux > maior){
			maior = aux;
		}
	}
	
	refilar(f2, f);

	free(f2);

	return maior;
}

float menor(Fila* f){
	Fila* f2 = cria();
	float menor = retira(f);
	float aux;

	insere(f2, menor);

	while(!vazia(f)){
		aux = retira(f);
		insere(f2, aux);
		if(aux < menor){
			menor = aux;
		}
	}
	
	refilar(f2, f);

	free(f2);

	return menor;
}

float media(Fila* f){
	Fila* f2 = cria();
	float aux;
	float media = 0;
	int cont = 0;

	insere(f2, media);

	while(!vazia(f)){
		aux = retira(f);
		insere(f2, aux);
		media += aux;
		cont++;
	}
	
	refilar(f2, f);

	free(f2);

	return (media/cont);
}

void imprimi(Fila* f){
	No* l;
	for(l = f->ini;l != NULL; l = l->prox){
		printf("oi-> %.2f -> %p -> %p\n" ,l->valor, l, l->prox);
	}
}

int main(){
	Fila* f = cria();

	float m;

	insere(f, 9);
	insere(f, 8);
	insere(f, 15);
	insere(f, 21);
	// insere(f, 2);
	// insere(f, 0);
	// insere(f, 6);
	// insere(f, 78);
	// insere(f, 4);
	// insere(f, 12);
	// insere(f, 15);
	// insere(f, 12);
	// insere(f, 45);
	// insere(f, 6);
	// insere(f, 1);
	// insere(f, 7);


	m = maior(f);
	printf("Maior valor: %.2f\n", m);

	printf("\n______________________________\n");

	m = menor(f);
	printf("Menor valor: %.2f\n", m);

	printf("\n______________________________\n");

	m = media(f);
	printf("Media: %.2f\n", m);
}
