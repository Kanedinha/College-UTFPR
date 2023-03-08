#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct parenteses{
	int num;
	struct parenteses* prim;
};
typedef struct parenteses Parenteses;

struct pilha{
	Parenteses* prim;
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

Parenteses* ins_ini (Parenteses* l, int num){
	Parenteses* p = (Parenteses*) malloc(sizeof(Parenteses));

	p->num = num;
	p->prim = l;

	return p;
}

Parenteses* ret_ini (Parenteses* l){
	Parenteses* p = l->prim;

	free(l);

	return p;
}

void push (Pilha* p, int num){
	p->prim = ins_ini(p->prim,num);
}

Parenteses pop (Pilha* p){
	Parenteses aux;

	if (vazia(p)) {
		printf("Pilha vazia.\n");
		exit(1);
	}

	aux.num = p->prim->num;
	p->prim = ret_ini(p->prim);

	return aux;
}

void verifica(char aux[]){
	Pilha* p = cria();
	Parenteses par;
	int tamanho = strlen(aux);
	
	for(int i = 0; i < tamanho; i++){
		if(aux[i] == '('){ 
			push(p, 1);
		}
		else if(aux[i] == ')'){
			if(vazia(p)){
				printf("\nProcedencia dos parenteses esta errada!!!\n");
				free(p);
				exit(1);
			}
			par = pop(p);
		}
	}
	if(vazia(p)){
		printf("Procedencia correta!\n");
	}
	else
		printf("\nProcedencia dos parenteses esta errada!!!\n");
	free(p);
}	

int main(){
	char aux[10] = {"(()()(()(("};

	verifica(aux);

	return 0;
}