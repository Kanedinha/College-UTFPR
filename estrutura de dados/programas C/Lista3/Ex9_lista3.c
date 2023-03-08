#include <stdio.h>
#include <stdlib.h>

struct numero{
	int num;
	struct numero* prim;
};
typedef struct num Numero;

struct pilha{
	Numero* prim;
};
typedef struct pilha Pilha;

Pilha* cria(){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->prim = NULL;

	return p;
}

int vazia(Pilha* p){
	return(p->prim == NULL);
}

Numero* ins_ini(Numero* l, int num){
	Numero* p = (Numero*) malloc(sizeof(Numero));

	p->num = num;
	p->prim = NULL;

	if(l != NULL){
		l->prim = p;
	}

	return p;
}

void push(Pilha* p, int num){
	p->prim = ins_ini(p->prim, num);
}

Numero* ret_ini (Numero* l){
	Numero* p = l->prim;

	free(l);

	return p;
}

int pop (Pilha* p){
	int aux;

	if (vazia(p)) {
		printf("Pilha vazia.\n");
		exit(1);
	}

	aux = p->prim->num; 	
	p->prim = ret_ini(p->prim);

	return aux;
}

//reempilha(origem, destino);
void reempilha(Pilha* p1, Pilha* p2){
	int aux;

	while(!vazia(p1)){
		aux = pop(p1);
		push(p2,aux);
	}
}

int tamanhoPilha(Pilha* p1){
	Pilha* p2;
	int aux;
	int cont = 0;

	while(!vazia(p1)){
		aux = pop(p1);
		push(p2, aux);
		cont++;
	}

	reempilha(p2,p1);
	free(p2);

	return cont;
}

Pilha* maiorPilha(Pilha* p1, Pilha* p2){
	int t1;
	int t2;

	t1 = tamanhoPilha(p1);
	t2 = tamanhoPilha(p2);
	
	if(t1 > t2){
		printf("p1\n");
		return p1;
	}
	else{
		printf("p2\n");
		return p2;
	}
}

int main(){
	Pilha* p1 = cria();
	Pilha* p2 = cria();
	Pilha* aux = cria();

	push(p1, 1);
	push(p1, 2);
	push(p1, 3);
	push(p1, 6);
	push(p1, 5);
	push(p1, 4);

	push(p2, 1);
	push(p2, 2);
	push(p2, 3);
	push(p2, 6);
	push(p2, 5);

	printf("\n_____________________________________\n");

	aux = maiorPilha(p1, p2);

	return 0;
}