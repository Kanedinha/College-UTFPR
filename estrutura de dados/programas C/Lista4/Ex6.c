#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

struct aluno {
	int mat;
	char nome[81];
	char email[41];
	char turma;
};
typedef struct aluno Aluno;

typedef Aluno* Hash[N];


int hash (int mat){
	return ( N * N * (mat* 2) % N);
}

Aluno* busca (Hash tab, int mat){
	int h = hash(mat);
	while (tab[h] != NULL) {
		if (tab[h]->mat == mat)
			return tab[h];
		h = (h+1) % N;
	}
	return NULL;
}

void insere (Hash tab, int mat, char* nome, char* email, char turma){
	int h = hash(mat);
	while (tab[h] != NULL) {
		if (tab[h]->mat == mat)
			break;
		h = (h+1) % N;
	}
	if (tab[h]==NULL) { 
		/* n�o encontrou o elemento */
		tab[h] = (Aluno*) malloc(sizeof(Aluno));
		tab[h]->mat = mat;
	}
	/* atribui informa��o */
	strcpy(tab[h]->nome,nome);
	strcpy(tab[h]->email,email);
	tab[h]->turma = turma;
	//return tab[h];
}

void inicializa(Hash tab){
	int i;
	for(i = 0; i< N; i++){
		tab[i] = NULL;
	}
}

int main(){
	int i;
	Aluno * a, *p;//o elemento em si e um auxiliar para a busca
	Hash h ;//a tabela hash que "indexa" os elementos por matricula
	inicializa(h);//o valor atual na tabela � usado em compara��es para tratar a colis�o, por isso TEM QUE inicializar

	insere(h, 100,"teste 100", "email 100", 'A');
	insere(h, 200,"teste 200", "email 200", 'A');
	insere(h, 65,"teste 65", "email 65", 'A');
	insere(h, 165,"teste 165", "email 165", 'A');
	insere(h, 4236,"teste 4236", "email 4236", 'A');
	
	//imprimi a tabela com as posi��es preenchidas
	//repare que mesmo que a fun��o hash p/ 100 e 200 tenham o mesmo resultado
	//a colis�o � resolvida colocando o 200 no proximo indice
	for(i = 0; i<N; i++){
		if(h[i] != NULL)
			printf("tabela[%d] = %d\n",i, h[i]->mat);
	}
	
	p = busca(h,200);
	if(p != NULL)
		printf("%s\n",p->nome);//usa a funcao hash e encontra o 100, continua com o mesmo tratamento de colis�o do inserir e encontra o 200
	else
		printf("N�o encontrado");

	return 0;
}