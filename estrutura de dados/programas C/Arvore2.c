#include <stdio.h>
#include <stdlib.h>

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
/*
int altura (Arv* r) {
	if (r == NULL) 
      return -1; // altura da �rvore vazia
  else {
  	int he = altura (r->esq);
  	int hd = altura (r->dir);
  	if (he < hd) return hd + 1;
  	else return he + 1;
  }
}*/

int altura(Arv* a){
	if(a == NULL)
		return -1;
	else{
		int esq = altura(a->esq);
		int dir = altura(a->dir);
		if(esq > dir)
			return esq + 1;
		else
			return dir + 1;
	}
}

int main(){
	Arv* a1 = cria(10,inicializa(),inicializa()); //folha
	Arv* a2 = cria(2,inicializa(),inicializa()); //folha
	Arv* a3 = cria(30,inicializa(),inicializa()); //folha
	Arv* a4 = cria(60,inicializa(),inicializa()); //folha
	Arv* a5 = cria(20,inicializa(),inicializa()); //folha 
	Arv* a6 = cria(11,inicializa(),inicializa());
	Arv* a7 = cria(1,inicializa(),inicializa());//raiz
	Arv* a8 = cria(3,inicializa(),inicializa());
	Arv* a9 = cria(4,inicializa(),inicializa());
	Arv* a10 = cria(5, a1, a2);
	Arv* a11 = cria(5, a10, a3);
	Arv* a12 = cria(5, a4, a5);
	Arv* a13 = cria(5, a6, a7);
	Arv* a14 = cria(5, a8, a9);
	Arv* a15 = cria(5, a11, a12);
	Arv* a16 = cria(5, a13, a14);
	Arv* a17 = cria(5, a15, a16);
	int h;

	imprime(a17);
	
	printf("___________________________\n");

	h = altura(a17);

	printf("Menor altura -> %d\n", h);

	printf("___________________________\n");

	a1 = cria(10,inicializa(),inicializa()); //folha
	a2 = cria(2, a1,inicializa()); //folha
	a3 = cria(30, a2,inicializa()); //folha
	a4 = cria(60, a3,inicializa()); //folha
	a5 = cria(20, a4,inicializa()); //folha 
	a6 = cria(11, a5,inicializa());
	a7 = cria(1, a6,inicializa());//raiz
	a8 = cria(3, a7,inicializa());
	a9 = cria(4, a8,inicializa());
	a10 = cria(5, a9, inicializa());
	a11 = cria(5, a10, inicializa());
	a12 = cria(5, a11, inicializa());
	a13 = cria(5, a12, inicializa());
	a14 = cria(5, a13, inicializa());
	a15 = cria(5, a14, inicializa());
	a16 = cria(5, a15, inicializa());
	a17 = cria(5, a16, inicializa());

	printf("___________________________\n");

	h = altura(a17);

	printf("Maior altura -> %d\n", h);

	printf("___________________________\n");

	return 0;
	}
