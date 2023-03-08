#include <stdio.h>
#include <stdlib.h>

// primeiramente para ter uma busca binária é necessário
// que a árvore esteja ditribuida uniformemente as infos
// de suas folhas e seus ramos, ou seja uma árvore de 
// Busca binária

typedef struct arv {
	int info;
	struct arv* esq;
	struct arv* dir;
} Arv;

Arv* inicializa(){
	return NULL;
}

Arv* cria(int c, Arv* sae, Arv* sad){
	Arv* p = (Arv*)malloc(sizeof(Arv));
	p->info = c;
	p->esq = sae;
	p->dir = sad;
	return p;
}

int vazia(Arv* a){
	return a == NULL;
}

int busca (Arv* a, int c){
	if (vazia(a))
		return 0;
	else
		return a->info==c || busca(a->esq,c) || busca(a->dir,c);
}

void imprime (Arv* a){
	if (!vazia(a)){
		printf("%d \n", a->info);
		imprime(a->esq);
		imprime(a->dir);
	}
}

Arv* add_esq(Arv* a, int info){
	Arv* p = (Arv*)malloc(sizeof(Arv));
	p->info = info;
	p->esq = inicializa();
	p->dir = inicializa();
	a->esq = p;

	return p;
}

Arv* add_dir(Arv* a, int info){
	Arv* p = (Arv*)malloc(sizeof(Arv));
	p->info = info;
	p->esq = inicializa();
	p->dir = inicializa();
	a->dir = p;

	return p;
}

int buscaBin(Arv* a, int info){
	if(a->info == info)
		return a->info;
	if(info > a->info){ // se a infor
		if(a->dir != NULL)
			return buscaBin(a->dir, info);
		else
			return -1;
	}
	if(info < a->info){ // se a infor
		if(a->esq != NULL)
			return buscaBin(a->esq, info);
		else
			return -1;
	}
}

int altura(Arv* a){
	int he = 0;
	int hd = 0;
	if(a->dir != NULL)
		(hd = altura(a->dir) + 1);
	if(a->esq != NULL)
		(he = altura(a->esq) + 1);
	if(he > hd)
		return he;
	if(he < hd)
		return hd;
}

int main(){
	Arv* a1 = cria(20,inicializa(),inicializa()); 
	Arv* a2 = cria(16,inicializa(),inicializa()); 
	Arv* a3 = cria(14,inicializa(),inicializa()); 
	Arv* a4 = cria(11,inicializa(),inicializa()); 
	Arv* a5 = cria(8,inicializa(),inicializa()); 
	Arv* a6 = cria(6,inicializa(),inicializa());
	Arv* a7 = cria(4,inicializa(),inicializa());
	Arv* a8 = cria(1,inicializa(),inicializa());
	Arv* a9 = cria(17,a2,a1);
	Arv* a10 = cria(12,a4,a3);
	Arv* a11 = cria(7,a6,a5);
	Arv* a12 = cria(3,a8,a7);
	Arv* a13 = cria(15,a10,a9);
	Arv* a14 = cria(5,a12,a11);
	Arv* a = cria(10,a14,a13);
	int aux;

	imprime(a);

	aux = buscaBin(a, 6);

	printf("encontrei: %d\n", aux);
	
	return 0;
}
