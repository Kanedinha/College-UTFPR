#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

struct aluno {
	int mat;
	char nome[81];
	char turma;
	char email[41];
	struct aluno* prox; /* encadeamento na lista de colis�o */
};
typedef struct aluno Aluno;

typedef Aluno* Hash[N];


int hash (int mat){
	return ( N * N * (mat* 2) % N );
}

Aluno* busca (Hash tab, int mat){
	int h = hash(mat);
	Aluno* a = tab[h];
	while (a != NULL) {
		if (a->mat == mat)
			return a;
		a = a->prox;
	}
	return NULL;
}

void insere (Hash tab, int mat, char* nome, char* email, char turma){
	int h = hash(mat);
	Aluno* a = tab[h];
	Aluno* p = NULL; /* ponteiro para anterior */
	while (a != NULL) {
		if (a->mat == mat)
			break;
		p = a;
		a = a->prox;
	}
	if (a==NULL) { /* n�o encontrou o elemento */
		a = (Aluno*) malloc(sizeof(Aluno));
		a->mat = mat;
		a->prox = NULL;
		if (p==NULL)
			tab[h] = a;
		else
			p->prox = a;
	}
	/* atribui informa��o */
	strcpy(a->nome,nome);
	strcpy(a->email,email);
	a->turma = turma;
	
}

void inicializa(Hash tab){
	int i;
	for(i = 0; i< N; i++){
		tab[i] = NULL;
	}
}

int main(){
	int i;
	Aluno *a, *p;//o elemento em sim e um auxiliar p/ impressao
	Hash h;//a tabela hash que "indexa" os elementos por matricula
	inicializa(h);//o valor atual na tabela � usado em compara��es para tratar a colis�o, por isso TEM QUE inicializar

	insere(h, 100,"teste 100", "email 100", 'A');
	insere(h, 200,"teste 200", "email 200", 'A');
	insere(h, 65,"teste 65", "email 65", 'A');
	insere(h, 165,"teste 165", "email 165", 'A');
	insere(h, 4236,"teste 4236", "email 4236", 'A');
	
	//imprimi a tabela com as posi��es preenchidas
	//repare que mesmo que a fun��o hash p/ 100 e 200 tenham o mesmo resultado
	//a colis�o � resolvida colocando criando um encadeamento extreno para o 200
	for(i = 0; i<N; i++){
		if(h[i] != NULL){
			for(p = h[i]; p!=NULL; p = p->prox){//imprimi todos os elementos na lista encadeada do mesmo indice
				printf("tabela[%d] = %d\n",i, p->mat);
			}
		}
	}
	
	printf("%s\n",busca(h,200)->nome);//usa a funcao hash e encontra o 100, continua com o mesmo tratamento de colis�o do inserir e encontra o 200
	return 0;
}