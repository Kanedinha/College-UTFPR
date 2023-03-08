#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct docs{
	int registro;
	int valor;
};
typedef struct docs Docs;

struct pilha{
	int num;
	Docs pi[10];
};
typedef struct pilha Pilha;

Pilha* cria (){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));

	p->num = 0;

	return p;
}

Docs func(Pilha* p){
	Docs v;
	printf("aqui 0\n");
	p->num = 0;
	printf("aqui 1\n");
	v.valor = 10;
	printf("aqui 2\n");
	p->pi[p->num].registro = 12;
	printf("aqui 3\n");
	v.registro = p->pi[p->num].registro;
	printf("aqui 4\n");
	
	return v;
}


int main(){
	Pilha* p;
	Docs aux;
	p = cria();
	aux = func(p);

	printf("registro -> %d \n", aux.registro);
	printf("valor -> %d \n", aux.valor);


	return 0;
}