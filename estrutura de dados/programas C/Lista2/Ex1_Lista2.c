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

Lista* inicializa(){
	return NULL;
}

int tamanhoLista(Lista* l){
	int tamanho = 0;
	Lista* p = l;

	for(p = l; p != NULL; p = p->prox){
		tamanho++;
	}
	
	p = NULL;

	return tamanho;
}

Lista* insere(Lista* l, int id, char new_nome[], int new_idade, char new_cpf[], float new_pontos){
	
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	
	novo->id = id;
	strcpy(novo->nome, new_nome);
	novo->idade = new_idade;
	strcpy(novo->cpf, new_cpf);
	novo->pontos = new_pontos;
	
	novo->prox = l;

	return novo;
}

void imprime (Lista* l) {

	int i = tamanhoLista(l);
	Lista* p = l;
	Lista dados[i];

	for(p = l; p != NULL; p = p->prox){
		strcpy(dados[i-1].nome, p->nome);
		dados[i-1].idade = p->idade;
		strcpy(dados[i-1].cpf, p->cpf);
		dados[i-1].pontos = p->pontos;
		i--;
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

//********  a) **********//
Lista* buscaNome(Lista* l, char info[]){
	Lista* p = l;
	char nome[50];
	char cpf[11];

	while(strcmp(p->nome, info)){
		
		p = p->prox;
	}

	printf("id-> %d\n", p->id);
	printf("nome-> %s\n", strcpy(nome, p->nome));
	printf("idade-> %d\n", p->idade);
	printf("cpf-> %s\n", strcpy(cpf, p->cpf));
	printf("pontos-> %.2f\n", p->pontos);

	return p;
}

void limpaVetor(int v[], int tamanho){
	for(tamanho; tamanho > 0; tamanho--){
		v[tamanho] = 0;
	}
}

void buscaPts(Lista* l, int ids[]){
	Lista* p = l;
	char nome[50];
	char cpf[11];
	int maiorPts = 0;
	int qnt = 0;
	int aux = 0;
	int i = tamanhoLista(l);

	while(p != NULL){
		if(p->pontos > maiorPts){
			limpaVetor(ids, i);
			maiorPts = p->pontos;
			qnt = 0;
			ids[qnt] = p->id;
		}
		else if(p->pontos == maiorPts){
			qnt++;
			ids[qnt] = p->id;
		}
		p = p->prox;
	}

	p = l;

	printf("\n__________________________\n");
	while(p != NULL){
		if(p->id == ids[aux]){
			printf("id-> %d\n", p->id);
			printf("nome-> %s\n", strcpy(nome, p->nome));
			printf("idade-> %d\n", p->idade);
			printf("cpf-> %s\n", strcpy(cpf, p->cpf));
			printf("pontos-> %.2f\n", p->pontos);
			printf("__________________________\n");
			aux++;	
		}
		p = p->prox;
	}
	for(i; i >= 0; i--){
		printf("-> %d \n", ids[i]);
	}
}

Lista* desempate(Lista* l, int ids[]){
	Lista* p = l;
	char nome[50];
	char cpf[11];
	int maiorIdade = 0;
	int id = 0;
	int aux = 0;

	while(p != NULL){
		if(p->id == ids[aux]){
			if(p->idade > maiorIdade){
				maiorIdade = p->idade;
				id = p->id;
			}
			aux++;
		}
		p = p->prox;
	}
	
	p = l;
	while(p->id != id){
		p = p->prox;
	}

	printf("\n__________________________\n");
	printf("id-> %d\n", p->id);
	printf("nome-> %s\n", strcpy(nome, p->nome));
	printf("idade-> %d\n", p->idade);
	printf("cpf-> %s\n", strcpy(cpf, p->cpf));
	printf("pontos-> %.2f\n", p->pontos);
	printf("__________________________\n");

	return p;
}

int main(){

	Lista* l;
	int i;

	l = inicializa();

	l = insere(l, 1,"Kanedinha", 18,"06203829960", 9000);
	l = insere(l, 2,"boltz", 18,"00000000000", 9000);
	l = insere(l, 3,"perobinha", 5,"11111111111", 0);	
	l = insere(l, 4,"avatar", 18,"22222222222", 9000);
	l = insere(l, 5,"lambianos", 18,"33333333333", 9000);
	l = insere(l, 6,"gado takami", 18,"44444444444", 9000);
	l = insere(l, 7,"lupi", 18,"55555555555", 9000);
	l = insere(l, 8,"goku", 30,"66666666666", 8001);
	l = insere(l, 9,"Vina", 24,"77777777777", 9000);

	i = tamanhoLista(l);
	int ids[i];
	buscaPts(l,ids);

	l = desempate(l, ids);

/****************************************
	este programa funciona devido à maneira de como foi organizada a lista,
	o vetor ids[] sempre terá no primeiro espaço um valor de id maior que o dos anteriores,
	e apartir dai nunca terá um p->pontos maior que maiorPts para que haja um id maior que o do primeiro espaço no vetor,
	assim printando sem querer algum indivíduo indesejado.

*****************************************/
	return 0;
}