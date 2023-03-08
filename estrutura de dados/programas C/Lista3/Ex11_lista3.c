#include <stdio.h>
#include <stdlib.h>

#define MAX 15

struct fila{
	int ini;
	int fim;
	int vet[MAX];	
};
typedef struct fila Fila;

Fila* cria(){
	Fila* f = (Fila*)malloc(sizeof(Fila));
	f->ini = f->fim = 0;
	return f;
}

int vazia(Fila* f){
	return (f->ini == f->fim);
}

int incr (int i){
	if (i == MAX-1)
		return 0;
	else
		return i+1;
}

void insere (Fila* f, int v){
	if (incr(f->fim) == f->ini) {
		printf("Capacidade da fila estourou.\n");
		return;
	}
	f->vet[f->fim] = v;
	f->fim = incr(f->fim);
}

int retira (Fila* f){
	int v;
	if (vazia(f)) {
		printf("Fila vazia.\n");
		exit(1);
	}
	v = f->vet[f->ini];
	f->ini = incr(f->ini);
	return v;
}


Fila* fib(Fila* f){
	int aux1 = 1;
	int aux2 = 1;
	int n = MAX-1;

	while(n > 0){
		insere(f, aux1);
		printf("-> %d\n", aux1);
		aux2 = aux2 + aux1;
		aux1 = aux2 - aux1;
		n--;
	}
	return f;
}

int main(){
	Fila* f = cria();

	f = fib(f);

	return 0;
}
