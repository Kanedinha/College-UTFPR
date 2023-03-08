#include <stdio.h>
#include <stdlib.h>

struct no {
	float info;
	struct no* prox;

};
typedef struct no No;

struct pilha {
	No* prim;

};
typedef struct pilha Pilha;

Pilha* cria (){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->prim = NULL;

	return p;

}

int vazia(Pilha* p){
	return (p->prim == NULL);
}

No* ins_ini (No* l, float v){
	No* p = (No*) malloc(sizeof(No));
	p->info = v;
	p->prox = l;

	return p;
}

No* ret_ini (No* l){
	No* p = l->prox;

	free(l);

	return p;
}

void push (Pilha* p, float v){
	p->prim = ins_ini(p->prim,v);
	printf("push -> %.2f\n", v);

}

float pop (Pilha* p){
	float v;

	if (vazia(p)) {
		printf("Pilha vazia.\n");
		exit(1);

	}

	v = p->prim->info;
	p->prim = ret_ini(p->prim);

	return v;
}


int main(){

	Pilha* p = cria();
	float v;

	push(p, 1);
	push(p, 12);
	push(p, 13);
	push(p, 14);
	push(p, 15);
	push(p, 16);

	v = pop(p);
	printf("Pop -> %.2f\n", v);
	v = pop(p);
	printf("Pop -> %.2f\n", v);
	v = pop(p);
	printf("Pop -> %.2f\n", v);
	v = pop(p);
	printf("Pop -> %.2f\n", v);
	v = pop(p);
	printf("Pop -> %.2f\n", v);
	v = pop(p);
	printf("Pop -> %.2f\n", v);
	v = pop(p);
	printf("Pop -> %.2f\n", v);
	v = pop(p);
	printf("Pop -> %.2f\n", v);

	return 0;
}