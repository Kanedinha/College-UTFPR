#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// A ideia deste código é usar pilha e fila para organizar os bits
// de maneira fácil, visto que a pilha retorna o resultado ao contrário
// sendo bem útil para a conversão dos numeros inteiros, já a fila para a 
// parte decimal.

struct no {
	int info;
	struct no* prox;
};
typedef struct no No;

struct pilha {
	No* prim;
};
typedef struct pilha Inteiro;

struct fila{
	No* ini;
	No* fim;
};
typedef struct fila Decimal;

struct padrao{
	int magnitude;
	Inteiro* mantisa;
	Decimal* bin;
};
typedef struct padrao Padrao;

struct binario{
	Inteiro* i;
	Decimal* d;
	Padrao ieee;
};
typedef struct binario Binario;

Decimal* criaFila(){
	Decimal* f = (Decimal*) malloc(sizeof(Decimal));

	f->ini = f->fim = NULL;
	
	return f;
}

int vaziaFila(Decimal* f){
	return(f->ini == NULL);
}

No* insere_fim(No* f, int info){
	No* p = (No*)malloc(sizeof(No));

	p->info = info;
	p->prox = NULL;

	if(f != NULL){
		f->prox = p;
	}

	return p;
}

No* retira_ini(No* f){
	No* d = f->prox;
	free(f);
	return d;
}

void insere (Decimal* f, int info){
	f->fim = insere_fim(f->fim, info);

	if (f->ini==NULL){
		f->ini = f->fim;
	}
}

int retira (Decimal* f){
	int v;
	if (vaziaFila(f)) {
		printf("Decimal vazia.\n");
		exit(1);
	}

	v = f->ini->info;

	f->ini = retira_ini(f->ini);

	if (f->ini == NULL)
		f->fim = NULL;
	return v;
}

Inteiro* criaPilha (){
	Inteiro* p = (Inteiro*) malloc(sizeof(Inteiro));
	p->prim = NULL;

	return p;
}

int vaziaPilha(Inteiro* p){
	return (p->prim == NULL);
}

No* ins_ini (No* l, int v){
	No* p = (No*) malloc(sizeof(No));
	p->info = v;
	p->prox = l;

	return p;
}

No* ret_ini (No* l){
	No* p = l->prox;

	free(l);

	return p;
}

void push (Inteiro* p, int v){
	p->prim = ins_ini(p->prim,v);
}

int pop (Inteiro* p){
	int v;

	if (vaziaPilha(p)) {
		printf("Inteiro vazia.\n");
		exit(1);

	}

	v = p->prim->info;
	p->prim = ret_ini(p->prim);

	return v;
}

void reempilha(Inteiro* p1, Inteiro* p2){
	int aux;

	while(!vaziaPilha(p1)){
		aux = pop(p1);
		push(p2,aux);
	}
}

void refilar(Decimal* f1, Decimal* f2){
	float aux;

	while(!vaziaFila(f1)){
		aux = retira(f1);
		insere(f2, aux);
	}
}

Inteiro* converteParteInteira(float aux){
	Inteiro* i = criaPilha();
	int num = aux;

	while(num != 0){
		push(i, num % 2);
		num = num / 2;
	}

	return i;
}

Decimal* converteParteDecimal(float num){
	Decimal* d = criaFila();
	int aux = num;

	num = num - aux;
	aux = 0;

	while(num - aux != 0){
		num = (num * 2);
		aux = num;
		num -= aux;
		insere(d, aux);
	}

	return d;
}

int magnitude(float num){
	return !(num > 0);
}

Binario padraoIEEE(Binario bin, float num){
	int exp = 0;
	int aux = 0;
	int bit = 0;
	bin.ieee.mantisa = criaPilha();
	bin.ieee.bin = criaFila();
	bin.ieee.magnitude = magnitude(num);
	
	if(vaziaPilha(bin.i)){
		if(vaziaFila(bin.d)){
			bin.ieee.mantisa = converteParteInteira(127);
		}
		else{
			while(aux != 1){
				aux = retira(bin.d);
				exp++;
			}
			bin.ieee.mantisa = converteParteInteira(127 - exp);
			while(!vaziaFila(bin.d)){
				aux = retira(bin.d);
				bit++;
				if(bit < 24)
					insere(bin.ieee.bin, aux);
			}
		}
	}
	else{
		while(!vaziaPilha(bin.i)){
			aux = pop(bin.i);
			bit++;
			if(bit < 24)
				insere(bin.ieee.bin, aux);
			exp++;
		}
		bin.ieee.mantisa = converteParteInteira(127 + exp - 1);
		while(!vaziaFila(bin.d)){
			aux = retira(bin.d);
			bit++;
			if(bit < 24)
				insere(bin.ieee.bin, aux);
		}
	}
	while(bit < 24){
		insere(bin.ieee.bin, 0);
		bit++;
	}

	aux = retira(bin.ieee.bin);

	return bin;
}

Binario dtob(float num){
	Binario bin;

	if(num > 0){
		bin.i = converteParteInteira(num);
		bin.d = converteParteDecimal(num);
	}
	else{
		bin.i = converteParteInteira(-num);
		bin.d = converteParteDecimal(-num);		
	}
	return bin;
}

void imprimi(Binario bin){
	Inteiro* inte = criaPilha();
	Decimal* dec = criaFila();
	int aux;
	
	while(!vaziaPilha(bin.i)){
		aux = pop(bin.i);
		push(inte, aux);
		printf("%d ", aux);
	}
	reempilha(inte, bin.i);

	printf("- ");

	while(!vaziaFila(bin.d)){
		aux = retira(bin.d);
		insere(dec,aux);
		printf("%d ", aux);
	}
	refilar(dec, bin.d);
	printf("\n");
}

Binario criaBinario(Binario bin){
	bin.i = criaPilha();
	bin.d = criaFila();

	return bin;	
}

int main(){
	Binario bin = criaBinario(bin);
	int aux;
	float num = 0.1217;

	bin = dtob(num);
	imprimi(bin);
	bin = padraoIEEE(bin, num);

	printf("\n------------------------------------\n");
	printf("Padrao IEEE:\n");

	printf("%d  ", bin.ieee.magnitude);

	while(!vaziaPilha(bin.ieee.mantisa)){
		aux = pop(bin.ieee.mantisa);
		printf("%d", aux);
	}
	printf("  ");

	while(!vaziaFila(bin.ieee.bin)){
		aux = retira(bin.ieee.bin);
		printf("%d", aux);
	}
	printf("\n");

	return 0;
}