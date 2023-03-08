#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista{
	int id;
	char nome[50];
	int idade;
	char cpf[11];
	float pontos;
	struct lista* prox;
};
typedef struct lista Lista;

int vazia(Lista* l){
	if(l == NULL){
		return 1;
	}
	else{
		return 0;
	}
}

Lista* inicializa(){
	return NULL;
}

int tamanhoLista(Lista* l){
	int tamanho = 0;
	Lista* p = l;

	for(p = l; p != NULL; p = p->prox){
		tamanho++;
	}
	
	free(p);

	return tamanho;
}

Lista* insere(Lista* l, int id, char new_nome[], int new_idade, char new_cpf[], float new_pontos){
	
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	
	strcpy(novo->nome, new_nome);
	novo->idade = new_idade;
	strcpy(novo->cpf, new_cpf);
	novo->pontos = new_pontos;
	novo->prox = l;

	return novo;
}

Lista* retira (Lista* l, char nome[]) {
	
	Lista* ant = NULL;
	Lista* p = l;
	
	while (p != NULL && strcmp(nome, p->nome)) {
		ant = p;
		p = p->prox;
	}
	if (p == NULL)
		return l;
	if (ant == NULL) {
		l = p->prox;
	}
	else {
		ant->prox = p->prox;
	}
	
	free(p);
	
	return l;
}

void imprime (Lista* l) {

	int i = tamanhoLista(l);
	Lista* p = l;
	Lista dados[i];

	for(p = l; p != NULL; p = p->prox){
		if(p != NULL){
			if(!vazia(l)){
				strcpy(dados[i-1].nome, p->nome);
				dados[i-1].idade = p->idade;
				strcpy(dados[i-1].cpf, p->cpf);
				dados[i-1].pontos = p->pontos;
				i--;
			}
		}
	}

	for(i = 0; i < tamanhoLista(l); i++){
		printf("nome = %s\n", dados[i].nome);
		printf("idade = %d\n", dados[i].idade);
		printf("cpf = %s\n", dados[i].cpf);
		printf("pontos = %.2f\n", dados[i].pontos);
		printf("\n__________________________\n");
	}
	free(p);
}

int main(){
	
	struct lista* l;

	l = inicializa();

	l = insere(l, 1,"emerson", 18,"06203829960", 10000);
	l = insere(l, 2,"boltz", 18,"00000000000", 200);
	l = insere(l, 3,"perobinha", 5,"11111111111", 0);	
	l = insere(l, 4,"avatar", 18,"22222222222", 300);
	l = insere(l, 5,"lambianos", 18,"33333333333", 400);
	l = insere(l, 6,"gado takami", 18,"44444444444", 500);
	l = insere(l, 7,"lupi", 18,"55555555555", 600);
	l = insere(l, 8,"goku", 30,"66666666666", 8001);
	l = insere(l, 9,"Vina", 24,"77777777777", 700);

	printf("\n\ntamanho lista-> %d\n\n", tamanhoLista(l));

	imprime(l);

	l = retira(l, "a");
	printf("\n__________________________\n");


	imprime(l);
	
	return 0;
}