#include<stdio.h>

typedef struct {
	int valor;
	int peso;
}item;

int calculaMochila(int bagTamanho, item* itens, int qntItens, int valorItens, int actualItem){
	if(bagTamanho <= 0 || actualItem >= qntItens){
		return valorItens;
	}

	int entrou;
	if(bagTamanho >= itens[actualItem].peso) {
		entrou = calculaMochila(bagTamanho - itens[actualItem].peso, itens, qntItens, valorItens + itens[actualItem].valor, actualItem + 1);
	}

	int naumEntrou = calculaMochila(bagTamanho, itens, qntItens, valorItens, actualItem + 1);

	if(entrou > naumEntrou)
		return entrou;
	else
		return naumEntrou;
}

void main(){
	
	int tamanho = 20;
	int qntItens = 6;
	item it[qntItens];

	it[0].valor = 3;
	it[0].peso = 10;

	it[1].valor = 12;
	it[1].peso = 5;

	it[2].valor = 3;
	it[2].peso = 2;

	it[3].valor = 5;
	it[3].peso = 4;

	it[4].valor = 9;
	it[4].peso = 7;

	it[5].valor = 3;
	it[5].peso = 1;

	int result = calculaMochila(tamanho, it, qntItens, 0, 1);
	printf("maior valor: %d\n", result);
}