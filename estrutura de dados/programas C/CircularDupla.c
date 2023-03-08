#include <stdio.h>
#include <stdlib.h>

struct lista{

	int info;
	struct lista* prox;
	struct lista* ant;

};
typedef struct lista Lista;

Lista* inicializa(){
	return NULL;
}

Lista* insere(Lista* comeco, Lista* final, int info){

	Lista* novo = (Lista*) malloc(sizeof(Lista));

	novo->info = info;
	novo->prox = comeco;
	novo->ant = final;

	if(comeco != NULL){
		final->prox = novo;
		comeco->ant = novo;
	}
	
	return novo;
}

void imprimeAntiHorario(Lista* final) {

	Lista* p = final;

	printf("________________________\n");
	do{
		printf("%d\n", p->info);
		printf("________________________\n");
		p = p->ant;	
	}while(p != final);

	p = NULL;
}

void imprimeHorario(Lista* comeco) {

	Lista* p = comeco;

	printf("________________________\n");
	do{
		printf("%d\n", p->info);
		printf("________________________\n");
		p = p->prox;	

	}while(p != comeco);
	
	p = NULL;
}

Lista* retira(Lista* comeco, int info){
	
	Lista *c = comeco;

	while(c->info != info){
		c = c->prox;
	}

	// for(c; c->info != info; c = c->prox){
	// }
	c->prox->ant = c->ant;
	c->ant->prox = c->prox;
	
	if(comeco->info == info){
		return c->prox;
	}
	else{
		return comeco;
	}
}

int main(){

	Lista *final;
	Lista *comeco;

	final = comeco = inicializa();

	final = comeco = insere(comeco,final,1);
	final = insere(comeco, final, 7);
	comeco = insere(comeco, final, 2);
	comeco = insere(comeco, final, 3);
	comeco = insere(comeco, final, 4);
	comeco = insere(comeco, final, 5);
	comeco = insere(comeco, final, 6);
	final = insere(comeco, final, 8);
	comeco = insere(comeco, final, 10);
	final = insere(comeco, final, 9);

	imprimeHorario(comeco);
	printf("*****************************\n");
	imprimeAntiHorario(final);
	printf("*****************************\n");

	comeco = retira(comeco, 1);

	imprimeHorario(comeco);

	return 0;
}