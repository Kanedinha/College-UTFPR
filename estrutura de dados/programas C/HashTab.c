#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

struct docs{
	int registro;
	char nome[50];
	int idade;
	char curso[50];
	struct docs * prox;
};
typedef struct docs Docs;

typedef Docs* Hash[N];

int hash(int registro){
	return (( registro * 2 ) % N );
}

void inicializa(Hash tab){
	int i;
	for(i = 0; i < N; i++){
		tab[i] = NULL;
	}
}



void insere(Hash tab, int registro, char nome[], int idade, char curso[]){
	int h = hash(registro);
	Docs* a = tab[h]; 	// aux
	Docs* p = NULL; 	// anterior
	while(a != NULL){
		if(a->registro == registro)
			break;
		p = a;
		a = a->prox;
	}
	if(a == NULL){
		a = (Docs*)malloc(sizeof(Docs));
		a->registro = registro;
		a->prox = NULL;
		if(p == NULL)
			tab[h] = a;
		else
			p->prox = a;
	}

	strcpy(a->nome, nome);
	a->idade = idade;
	strcpy(a->curso, curso);
}

int arquivo(){
	FILE* f = fopen("exemplo", "r");
	int registro = 0;
	//char nome[50];
	//int idade = 0;
	//char curso[50];
	char c;
	char aux[50];
	int i = 0;

	while(c = getc(f) != EOF){
		
		if(c == ';'){
			if (registro == 0){
				registro = atoi(aux);
			}
		}
		aux[i] = c;
	}	

	fclose(f);
	return registro;
}

int main(){
	Hash tab;
	Docs* aux;
	inicializa(tab);
	insere(tab,1, "kanedinha", arquivo(), "eletronica");
	insere(tab,2, "lupi", 19, "eletronica");
	insere(tab,32, "Vina", 40, "DCE");
	insere(tab,132, "Paulo", 12, "joga APEX");

	for(int i = 0; i < N; i++){
		if(tab[i] != NULL){
			for(aux = tab[i]; aux != NULL; aux = aux->prox){
				printf("\n______________________________________\n");
				printf("Posicao: [%d]\n", i);
				printf("Registro: %d\n", aux->registro);
				printf("Nome: %s\n", aux->nome);
				printf("Idade: %d\n", aux->idade);
				printf("Curso: %s\n", aux->curso);
			}
		}
	}

	return 0;
}