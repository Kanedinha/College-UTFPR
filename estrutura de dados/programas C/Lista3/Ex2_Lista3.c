#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct docs{
	int registro;
	int valor;
	struct docs* prim;
};
typedef struct docs Docs;


struct pilha {
	Docs* prim;
};
typedef struct pilha Pilha;

void delay(int number_of_seconds){ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds); 
}

Pilha* cria (){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->prim = NULL;

	return p;
}

int vazia(Pilha* p){
	return (p->prim == NULL);
}

Docs* ins_ini (Docs* l, int registro, int valor){
	Docs* p = (Docs*) malloc(sizeof(Docs));

	p->registro = registro;
	p->valor = valor;
	p->prim = NULL;

	if(l != NULL){
		l->prim = p;
	}

	return p;
}

Docs* ret_ini (Docs* l){
	Docs* p = l->prim;

	free(l);

	return p;
}

void push (Pilha* p, int registro, int valor){
	p->prim = ins_ini(p->prim,registro,valor);
	printf("push registro -> %d\n", registro);
}

Docs pop (Pilha* p){
	Docs aux;

	if (vazia(p)) {
		printf("Pilha vazia.\n");
		exit(1);
	}

	aux.registro = p->prim->registro;
	aux.valor = p->prim->valor;
	p->prim = ret_ini(p->prim);

	return aux;
}

void reempilha(Pilha* p1, Pilha* p2){
	Docs aux;
	printf("_____________________________\n");
	printf("\nreempilhando");
	delay(1);
	for (int i = 0; i < 3; i++)	{
		printf(".");	
		delay(1);		
	}
	printf("\n");

	while(!vazia(p1)){
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

	reempilha(p2,p);
	printf("_____________________________\n");
	printf("Registro nao encontrado\n");
	free(p2);

	exit(1);
}


int main(){

	Pilha* p = cria();
	Docs d;

	push(p, 1, 10);
	push(p, 2, 20);
	push(p, 3, 65);
	push(p, 4, 12);
	push(p, 5, 96);
	push(p, 6, 45);

	printf("_____________________________\n");
	printf("buscando registro");
	
	delay(1);
	for (int i = 0; i < 3; i++)	{
		printf(".");	
		delay(1);		
	}

	d = busca(p, 2);

	printf("_____________________________\n");
	printf("registro encontrado\n");
	printf("registro: %d\n", d.registro);
	printf("valor: %d\n", d.valor);

	free(p);

	return 0;
}