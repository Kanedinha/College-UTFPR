#include <stdio.h>
#include <stdlib.h>

#define MAX 23

typedef struct fila{
	int ini;
	int fim;
	float vet[MAX];
}Fila;

int incr (int i){
	if (i == MAX-1)
		return 0;
	else
		return i+1;
}

Fila* cria (){
	Fila* f = (Fila*) malloc(sizeof(Fila));
	f->ini = f->fim = 0;
	return f;
}

int vazia(Fila* f){
	return (f->ini == f->fim);
}

void insere (Fila* f, float v){
	if (incr(f->fim) == f->ini) {
		printf("Capacidade da fila estourou.\n");
		return;
	}
	f->vet[f->fim] = v;
	f->fim = incr(f->fim);

	printf("Insere -> %.2f\n", v);
}

float retira (Fila* f){
	float v;
	if (vazia(f)) {
		printf("Fila vazia.\n");
		exit(1);
	}
	v = f->vet[f->ini];
	f->ini = incr(f->ini);
	return v;
}


int main(){

	Fila* f = cria();
	float v;

	insere(f, 10);
	insere(f, 20);
	insere(f, 30);
	insere(f, 40);
	insere(f, 50);

	printf("____________________________________\n");

	v = retira(f);
	printf("retira -> %.2f\n",v);
	v = retira(f);
	printf("retira -> %.2f\n",v);
	v = retira(f);
	printf("retira -> %.2f\n",v);
	v = retira(f);
	printf("retira -> %.2f\n",v);
	v = retira(f);
	printf("retira -> %.2f\n",v);
	v = retira(f);
	printf("retira -> %.2f\n",v);
	v = retira(f);
	printf("retira -> %.2f\n",v);
	v = retira(f);
	printf("retira -> %.2f\n",v);
	
	return 0;
}