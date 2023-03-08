#include <stdio.h>
#include <stdlib.h>

struct lista{
	int info;
	struct lista * ant;
	struct lista * prox;
};
typedef struct lista Lista;

Lista* inicializa(){
	return NULL;
}

Lista* ins_ini(Lista* l, int info){
	Lista* p = (Lista*)malloc(sizeof(Lista));

	p->info = info;
	p->prox = l;
	p->ant = NULL;

	if(l != NULL){
		l->ant = p;
	}

	return p;
}

Lista* ins_fim(Lista* l, int info){
	Lista* p = (Lista*)malloc(sizeof(Lista));

	p->info = info;
	p->prox = NULL;
	p->ant = l;

	if(l != NULL){
		l->prox = p;
	}

	return p;
}

Lista* retira(Lista* l, int info){
	Lista* p = l;
	int aux;

	do{
		if(p->info == info){
			aux = p->info;
			p->prox->ant = p->ant;
			p->ant->prox = p->prox;
			free(p);
			return l;
		}
		p = p->prox;
	}while(p != NULL);
	
	free(p);

	return l;
}

Lista* busca(Lista* l, int info){
	Lista* p;
	
	for(p = l; p != NULL; p = p->prox){
		if(p->info == info)
			return p;
	}

	return NULL;
}

int tamanho(Lista* l){
	Lista* p;
	int cont = 0;
	for(p = l; p != NULL; p = p->prox){
		cont++;
	}

	return cont;
}

void imprimi(Lista* l){
	Lista* p = l;

	while(p != NULL){
		printf("-> %d\n", p->info);
		p = p->prox;
	}

	free(p);
}

void troca(Lista* p1, Lista* p2){
	int aux = p1->info;
	p1->info = p2->info;
	p2->info = aux;
}

Lista* p_pivo(Lista* inicio, Lista* fim){
	Lista* i = inicio;
	Lista* f = fim;
	while(i != f && i != f->ant){
		i = i->prox;
		f = f->ant;
	}
	return i;
}

void quick(Lista* inicio, Lista* fim){
	Lista* i = inicio->prox;
	Lista* f = fim;
	Lista* pivo = inicio;


}

int main(){
	Lista* l_ini;
	Lista* l_fim;
	int tam;

	l_ini = l_fim = inicializa(); 

	l_ini = l_fim = ins_ini(l_ini,1);
	l_ini = ins_ini(l_ini,5);
	l_ini = ins_ini(l_ini,4);
	l_ini = ins_ini(l_ini,6);

	l_fim = ins_fim(l_fim,2);
	l_fim = ins_fim(l_fim,7);
	l_fim = ins_fim(l_fim,3);
	l_fim = ins_fim(l_fim,9);

	imprimi(l_ini);

	quick(l_ini,l_fim);

	imprimi(l_ini);

	return 0;
}