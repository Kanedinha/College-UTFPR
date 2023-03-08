#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

6#define RET 0
#define TRI 1
#define CIR 2
#define PI 3.14159

struct retangulo {
	float b;
	float h;
};
typedef struct retangulo Retangulo;

struct triangulo {
	float b;
	float h;
};
typedef struct triangulo Triangulo;

struct circulo {
	float r;
};
typedef struct circulo Circulo;

struct listagen {
	int tipo;
	void *info;
	struct listagen *prox;
};
typedef struct listagen ListaGen;

ListaGen* cria_ret (ListaGen* l, float b, float h){
	Retangulo* r;
	ListaGen* p;
	
	r = (Retangulo*) malloc(sizeof(Retangulo));
	r->b = b;
	r->h = h;
	
	p = (ListaGen*) malloc(sizeof(ListaGen));
	p->tipo = RET;
	p->info = r;
	p->prox = l;
	return p;
}

ListaGen* cria_tri (ListaGen* l, float b, float h){
	Triangulo* t;
	ListaGen* p;
	
	t = (Triangulo*) malloc(sizeof(Triangulo));
	t->b = b;
	t->h = h;
	
	p = (ListaGen*) malloc(sizeof(ListaGen));
	p->tipo = TRI;
	p->info = t;
	p->prox = l;
	return p;
}

ListaGen* cria_cir (ListaGen* l, float r){
	Circulo* c;
	ListaGen* p;
	
	c = (Circulo*) malloc(sizeof(Circulo));
	c->r = r;
	
	p = (ListaGen*) malloc(sizeof(ListaGen));
	p->tipo = CIR;
	p->info = c;
	p->prox = l;
	return p;
}

float ret_area (Retangulo* r){
	return r->b * r->h;
}

float tri_area (Triangulo* t){
	return (t->b * t->h) / 2;
}

float cir_area (Circulo* c){
	return PI * c->r * c->r;
}

float area (ListaGen* p){
	float a;
	switch (p->tipo) {
		case RET:
		a = ret_area(p->info);
		break;
		case TRI:
		a = tri_area(p->info);
		break;
		case CIR:
		a = cir_area(p->info);
		break;
	}
	return a;
}

float max_area (ListaGen* l){
	float amax = 0.0;
	ListaGen* p;
	for (p=l; p!=NULL; p=p->prox) {
		float a = area(p); 
		if (a > amax)
			amax = a;
	}
	return amax;
}

ListaGen* inicializa(){
	return NULL;
}

void imprime(ListaGen* l){
	ListaGen* p; 
	float x;
	Circulo* c;
	for (p = l; p != NULL; p = p->prox){
		if(p->tipo == CIR){
			c = (Circulo*) p->info;
			printf("ciruclo %f\n",c->r);
		}
		if(p->tipo == RET)
			printf("retangulo\n");
		if(p->tipo == TRI)
			printf("triangulo\n");
	}
}

void retiraCirculo(ListaGen* l){
	ListaGen* p = l;
	Circulo* c;
	int r;
	printf("Digite o raio do ciruclo: ");
	scanf("%d", &r);
	if(p->tipo == CIR){
		c = p->info;
		if(c->r == r){
			l = p->prox;
			return;
		}
	}
	while(p != NULL){
		if(p->prox->tipo == CIR){
			c = p->prox->info;
			if(c->r == r){
				p->prox = p->prox->prox;
			}
		}
	}
}

void retiraRetangulo(ListaGen* l){
	ListaGen* p = l;
	Retangulo* c;
	int b, h;
	printf("Digite a base do retangulo: ");
	scanf("%d", &b);
	printf("Digite a altura do retangulo: ");
	scanf("%d", &h);
	if(p->tipo == RET){
		c = p->info;
		if(c->b == b && c->h == h){
			l = p->prox;
			return;
		}
	}
	while(p != NULL){
		if(p->prox->tipo == RET){
			c = p->prox->info;
			if(c->b == b && c->h == h){
				p->prox = p->prox->prox;
			}
		}
	}
}

void retiraTriangulo(ListaGen* l){
	ListaGen* p = l;
	Triangulo* c;
	int b, h;
	printf("Digite a base do triangulo: ");
	scanf("%d", &b);
	printf("Digite a altura do triangulo: ");
	scanf("%d", &h);
	if(p->tipo == TRI){
		c = p->info;
		if(c->b == b && c->h == h){
			l = p->prox;
			return;
		}
	}
	while(p != NULL){
		if(p->prox->tipo == TRI){
			c = p->prox->info;
			if(c->b == b && c->h == h){
				p->prox = p->prox->prox;
			}
		}
	}
}

void retira(ListaGen* l, int tipo){	
	switch(tipo){
		case 0:
		retiraRetangulo(l);
		break;

		case 1:
		retiraTriangulo(l);
		break;

		case 2:
		retiraCirculo(l);
		break;
	}
}

int main(){
	ListaGen* lista_Het;
	lista_Het = inicializa();
	lista_Het = cria_ret(lista_Het, 10, 20);
	lista_Het = cria_cir(lista_Het, 20);
	lista_Het = cria_cir(lista_Het, 10);
	lista_Het = cria_tri(lista_Het, 10, 5);
	imprime(lista_Het);
	printf("________________________\n");
	retira(lista_Het, CIR);
	imprime(lista_Het);	
	return 0;
}