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

int distancia(Lista* l, int t1, int t2){
	Lista* p = l;
	int distancia = 0;

	if(t1 > t2){
		while(p->info != t2){
			p = p->prox;
		}
		for(p; p->info != t1; p = p->prox){
			distancia ++;
		}
	}
	else if(t2 > t1){
		while(p->info != t1){
			p = p->prox;
		}
		for(p; p->info != t2; p = p->prox){
			distancia ++;
		}
	}
	else{
		distancia = 0;
	}
	return distancia;
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

	printf("Digite o 1' termos: ");
	scanf("%d", &t1);
	printf("Digite o 2' termos: ");
	scanf("%d", &t2);
	
	printf("a distancia eh: %d", distancia(l,t1,t2));

	return 0;
}