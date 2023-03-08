#include <stdio.h>
#include <stdlib.h>

struct docs{
	int registro;
	int valor;
};
typedef struct docs Docs;

struct pilha{
	int num;
	Docs pilha[10];
};
typedef struct pilha Pilha;

Pilha* cria (){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));

	p->num = 0;

	return p;
}

int vazia(Pilha* p){
	return (p->num == 0);
}

void push (Pilha* p, int registro, int valor){
	if (p->num == 10) {
		printf("Capacidade da pilha estourou.\n");
		exit(1);
	}

	p->pilha[p->num].registro = registro;
	p->pilha[p->num].valor = valor;
	p->num++;
	printf("push do registro -> %d\n", registro);
}

Docs pop (Pilha* p){
	Docs v;

	if (vazia(p)) {
		printf("Pilha vazia.\n");
		exit(1);
	}

	v.registro = p->pilha[p->num-1].registro;
	v.valor = p->pilha[p->num-1].valor;
	p->num--;
	
	return v;
}

void reempilha(Pilha* p1, Pilha* p2){
	Docs aux;
	printf("_____________________________\n");
	printf("\nreempilhando...\n");

	while(p2->num < 9){
		aux = pop(p1);
		push(p2, aux.registro, aux.valor);
	}

}

Docs busca(Pilha* p, int registro){
	Pilha* p2 = cria();
	Docs aux;
	
	do{
		aux = pop(p);
		if(aux.registro == registro){
			printf("\nFoi para a pilha 2:\n");
			push(p2, aux.registro, aux.valor);
			reempilha(p2,p);
			free(p2);
			return aux;
		}
		else{
			printf("\nFoi para a pilha 2:\n");
			push(p2, aux.registro, aux.valor);
		}
	}while(!vazia(p));

	printf("Registro nao encontrado\n");
	reempilha(p2,p);
	free(p2);

	exit(1);
}

int main(){
	Pilha* 	p = cria();
	Docs v;

	printf("_____________________________\n");

	push(p, 1, 52);
	push(p, 2, 65);
	push(p, 3, 96);
	push(p, 4, 100);

	push(p, 5, 10);
	push(p, 6, 52);
	push(p, 7, 69);
	push(p, 8, 65);

	push(p, 9, 100);

	v = busca(p, 8);
	printf("\nbusca:\nregistro -> %d\nvalor -> %d\n", v.registro, v.valor);

	return 0;

}