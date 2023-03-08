#include <stdio.h>
#include <stdlib.h>

struct lista{
	int info;
	struct lista* prox;
};
typedef struct lista Lista;

Lista* inicializa(){
	return NULL;
}

Lista* insere(Lista* l, int info){
	Lista* novo = (Lista*)malloc(sizeof(Lista));

	novo->info = info;
	novo->prox = l;

	return novo;

}

int tamanhoLista(Lista* l){
	Lista* p = l;
	int tamanho = 0;

	for(p; p != NULL; p = p->prox){
		tamanho++;
	}

	return tamanho;
}

Lista* busca(Lista* l, int info){
	Lista* p = l;

	while(p->info != info){
		p = p->prox;
	}		

	return p;
}

int verifica(int v[], int pos){
	int num;
	int i;
	
	scanf("%d", &num);
	
	for(i = 0; i < pos; i++){
		if(num == v[i]){
			printf("id ja inserido, digite outro: ");
			num = verifica(v,pos);
		}
	}
	return num;
}

Lista* novaLista(Lista* l){
	Lista* new_l = (Lista*)malloc(sizeof(Lista));
	int t = tamanhoLista(l);
	int v[t];
	int i;

	new_l = inicializa();

	for(i = 0; i < t; i++){
		printf("Qual o %d' id da nova Lista: ", i+1);
		v[i] = verifica(v, i);
		new_l = insere(new_l,v[i]);
	}
	
	// for(i = 0; i < t; i++){
	// }

	return new_l;
}

void imprime (Lista* l) {
	Lista* p = l;
	
	printf("_____________________________\n");
	for(p = l; p != NULL; p = p->prox){
		printf("info -> %d\n", p->info);
		printf("_____________________________\n");
	}

	p = NULL;
}

int main(){
	Lista* l;
	int t1, t2;

	l = inicializa();
	l = insere(l, 10);
	l = insere(l, 9);
	l = insere(l, 8);
	l = insere(l, 7);
	l = insere(l, 6);
	l = insere(l, 5);
	l = insere(l, 4);
	l = insere(l, 3);
	l = insere(l, 2);
	l = insere(l, 1);

	imprime(l);

	l = novaLista(l);

	imprime(l);

	return 0;
}