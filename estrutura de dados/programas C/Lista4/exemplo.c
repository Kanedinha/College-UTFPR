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
	return (mat%N);
}

int hash2 (int mat){
	return N - 2 - mat%(N-2);
}

Aluno* busca (Hash tab, int mat){
	int h = hash(mat);
	int h2 = hash2(mat);
	while (tab[h] != NULL) {
		if (tab[h]->mat == mat)
			return tab[h];
		h = (h+h2) % N;
	}
	return NULL;
}

Aluno* insere (Hash tab, int mat, char* nome, char* email, char turma){
	int h = hash(mat);
	int h2 = hash2(mat);
	while (tab[h] != NULL) {
		if (tab[h]->mat == mat)
			break;
		h = (h+h2) % N;
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
	return tab[h];
}

void inicializa(Hash tab){
	int i;
	for(i = 0; i< N; i++){
		tab[i] = NULL;
	}
}

int main(){
	int i;
	Aluno *a, *p;//o elemento em si e um auxiliar para a busca
	Hash h;//a tabela hash que "indexa" os elementos por matricula
	inicializa(h);//o valor atual na tabela � usado em compara��es para tratar a colis�o, por isso TEM QUE inicializar

	a = insere(h, 100,"teste 100", "email 100", 'A');
	a = insere(h, 200,"teste 200", "email 200", 'A');
	a = insere(h, 65,"teste 65", "email 65", 'A');
	a = insere(h, 165,"teste 165", "email 165", 'A');
	a = insere(h, 4236,"teste 4236", "email 4236", 'A');
	a = insere(h, 86,"teste 86", "email 86", 'A');
	a = insere(h, 36,"teste 36", "email 36", 'A');
	a = insere(h, 42,"teste 42", "email 42", 'A');
	a = insere(h, 4200,"teste 4200", "email 4200", 'A');
	
	//imprimi a tabela com as posi��es preenchidas
	//repare que mesmo que a fun��o hash p/ 100 e 200 tenham o mesmo resultado
	//a colis�o � resolvida calculando um novo indice p/ 200
	for(i = 0; i<N; i++){
		if(h[i] != NULL)
			printf("tabela[%d] = %d\n",i, h[i]->mat);
	}
	
	p = busca(h,201);
	if(p != NULL)
		printf("%s\n",p->nome);//usa a funcao hash e encontra o 100, continua com o mesmo tratamento de colis�o do inserir e encontra o 200
	else
		printf("N�o encontrado");
		
	return 0;
}