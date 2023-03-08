#include "BDGeral.h"

using namespace std;

void BDGeral:: CadastroGeral(char escolha){
	Arquivo arquivo;
	BDPessoa bdpessoa;
	BDFisica bdfisica;
	BDAluno bdaluno;
	BDJuridica bdjuridica;
	RecebeDados dados;
	int id = arquivo.GerarId();
	
	cout << "\n----------------- Insira os dados -----------------" << endl;

	switch(escolha){
		case'F':case'f':
			bdfisica.ArquivarFisica(dados.RecebeAtributoFisica(),id);			
			break;
		case'A':case'a':
			bdaluno.ArquivarAluno(dados.RecebeAtributoAluno(),id);
			break;
		case'J':case'j':
			bdjuridica.ArquivarJuridica(dados.RecebeAtributoJuridica(),id);
			break;
	}

	cout << "\nSeus dados foram arquivados com sucesso !!!" << endl;
	cout << "---------------------------------------------------" << endl;
};

