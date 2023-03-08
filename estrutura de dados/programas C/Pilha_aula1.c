#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct pilha{
	
	int n;
	float vet[MAX];

}Pilha;

Pilha* cria (){

	Pilha* p = (Pilha*) malloc(sizeof(Pilha));

	p->n = 0;

	return p;

}

int vazia(Pilha* p){
	return (p->n == 0);
}

void push (Pilha* p, float v){
	
	if (p->n == MAX) {
		printf("Capacidade da pilha estourou.\n");
		return;
	}

	p->vet[p->n] = v;
	p->n++;
	printf("push de %.2f\n", v);
}

float pop (Pilha* p){
	float v;

	if (vazia(p)) {
		printf("Pilha vazia.\n");
		exit(1);
	}

	v = p->vet[p->n-1];
	p->n--;
	
	return v;
}


int main(){	

	Pilha* p = cria();
	float v;

	push(p, 10);
	push(p, 2);
	push(p, 2.4);
	push(p, 15);

	push(p, 10);
	push(p, 2);
	push(p, 2.4);
	push(p, 15);

	push(p, 10);
	push(p, 2);
	push(p, 2.4);
	push(p, 15);

	printf("_____________________________\n");

	v = pop(p);
	printf("pop -> %.2f\n", v);
	v = pop(p);
	printf("pop -> %.2f\n", v);	
	v = pop(p);
	printf("pop -> %.2f\n", v);
	v = pop(p);
	printf("pop -> %.2f\n", v);
	v = pop(p);
	printf("pop -> %.2f\n", v);

	v = pop(p);
	printf("pop -> %.2f\n", v);
	v = pop(p);
	printf("pop -> %.2f\n", v);	
	v = pop(p);
	printf("pop -> %.2f\n", v);
	v = pop(p);
	printf("pop -> %.2f\n", v);
	v = pop(p);
	printf("pop -> %.2f\n", v);

	v = pop(p);
	printf("pop -> %.2f\n", v);
	
	return 0;
}