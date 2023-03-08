#include <stdio.h>
#include <stdlib.h>

typedef struct arvgen {
	char info;
	struct arvgen *prim;
	struct arvgen *prox;
} ArvGen;

ArvGen* cria (char c){
	ArvGen *a =(ArvGen *) malloc(sizeof(ArvGen));
	a->info = c;
	a->prim = NULL;
	a->prox = NULL;
	return a;
}

int vazia(ArvGen* a){
	return a == NULL;
}

void insere (ArvGen* pai, ArvGen* filho){
	filho->prox = pai->prim;
	pai->prim = filho;
}

void imprime (ArvGen* a){
	ArvGen* p;
	printf("%c\n",a->info);
	for (p=a->prim; p!=NULL; p=p->prox)
		imprime(p);
}

int busca(ArvGen* a, char info){
	if(vazia(a))
		return 0;
	else
		return a->info == info || busca(a->prox, info) || busca(a->prim, info);
}

ArvGen* buscaCara(ArvGen* a, char info){
	if(vazia(a))
		return NULL;
	if(a->info == info)
		return a;
	if(busca(a->prox, info))
		return a = buscaCara(a->prox, info);
	if(busca(a->prim, info))
		return a = buscaCara(a->prim, info);

}

int altura(ArvGen* a){
	int he = 0;
	int hd = 0;
	if(a->prox != NULL)
		hd = altura(a->prox) + 1;
	if(a->prim != NULL)
		he = altura(a->prim) + 1;
	if(he >= hd)
		return he;
	if(he < hd)
		return hd;
}

int main(){
	ArvGen* a = cria('a');
	ArvGen* b = cria('b');
	ArvGen* c = cria('c');
	ArvGen* d = cria('d');
	ArvGen* e = cria('e');
	ArvGen* f = cria('f');
	ArvGen* g = cria('g');
	ArvGen* h = cria('h');
	ArvGen* i = cria('i');
	ArvGen* j = cria('j');
	int k;

	insere(c,d);
	insere(b,e);
	insere(b,c);
	insere(a,b);
	imprime(a);

	k = busca(a, 'c');
	j = buscaCara(a, 'e');

	k = altura(a);

	printf("deu bom? %d \n", k);
	return 0;
}