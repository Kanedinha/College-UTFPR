#include <stdio.h>
#include <stdlib.h>

struct num{
	int num;
	struct num* prim;
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

Numero ins_ini(Numero l, int num){
	Numero* p = (Numero*)malloc(sizeof(Numero));

	p->num = num;
	p->prim = NULL;

	if(l != NULL){
		l->prim = p;
	}

	return p;
}

void push(Pilha* p, int num){
	p->prim = ins_ini(p->prim,num);
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

void reempilha(Pilha* p1, Pilha* p2){
	int aux;

	while(!vazia(p1)){
		aux = pop(p1);
		push(p2,aux);
	}
}

int maior(Pilha* p){
	Pilha* p2 = cria();
	int maior = pop(p);
	int aux;

	push(p2, maior);

	while(!vazia(p)){
		aux = pop(p);
		push(p2, aux);
		if(aux > maior){
			maior = aux;
		}
	}

	reempilha(p2,p);
	free(p2);

	return maior;
}

int menor(Pilha* p){
	Pilha* p2 = cria();
	int menor = pop(p);
	int aux;

	push(p2, menor);

	while(!vazia(p)){
		aux = pop(p);
		push(p2, aux);
		if(aux > menor){
			menor = aux;
		}
	}

	reempilha(p2,p);
	free(p2);

	return menor;
}

int media(Pilha* p){
	Pilha* p2 = cria();
	int media = 0;
	int aux;
	int cont = 0;

	push(p2, media);

	while(!vazia(p)){
		aux = pop(p);
		push(p2, aux);
		media += aux;
		cont++;
	}

	reempilha(p2,p);
	free(p2);

	return (media/cont);
}

int main(){
	Pilha* p = cria();
	int m;

	push(p, 1);
	push(p, 2);
	push(p, 3);
	push(p, 6);
	push(p, 5);
	push(p, 4);

	printf("\n_____________________________________\n");

	m = maior(p);
	printf("Maior valor: %d\n", m);

	m = menor(p);
	printf("Menor valor: %d\n", m);

	m = media(p);
	printf("media: %d\n", m);

	printf("\n_____________________________________\n");

	return 0;
}