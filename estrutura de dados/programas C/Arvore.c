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

Arv* add_esq(Arv* a, int info){
	Arv* p = (Arv*)malloc(sizeof(Arv));
	p->info = info;
	p->esq = inicializa();
	p->dir = inicializa();
	a->dir = p;

	return p;
}

int main(){
	Arv* a1= cria(10,inicializa(),inicializa()); //folha
	Arv* a2= cria(2,inicializa(),a1); 
	Arv* a3= cria(30,inicializa(),inicializa()); //folha
	Arv* a4= cria(60,inicializa(),inicializa()); //olha
	Arv* a5= cria(20,a3,a4); 
	Arv* a = cria(1,a2,a5 );//raiz
	imprime(a);

	Arv* a6 = add_esq(a3, 12);

	imprime(a);
	if(busca(a,60)){
		printf("Encontrou");
	}else{
		printf("N�o encontrou");
	}
	
	return 0;
}
