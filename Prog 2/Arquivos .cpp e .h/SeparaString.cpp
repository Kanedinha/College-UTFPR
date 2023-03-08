#include "SeparaString.h"

using namespace std;

void SeparaStr:: SeparaDadosEmUmVetor(string vetor[], string linha){
	int posicao = 0;
	char letra;
	string str = "" ; 
	for(int i = 0; i < linha.length(); i++){
		if(linha[i] != ';'){
			str += linha[i];
		}
		else{
			vetor[posicao] = str;
			str = "";
			posicao++;
		}
	}
	vetor[posicao] = str;
};