#ifndef CadastroGeral_h
#define CadastroGeral_h

#include <string.h>
#include <iostream>
#include "RecebeDados.h"
#include "Arquivo.h"
#include "BDPessoa.h"
#include "BDFisica.h"
#include "BDAluno.h"
#include "BDJuridica.h"
#include "ImprimiDados.h"
#include "MenuDoBancoDeDadosNoConsole.h"
#include "Fisica.h"
#include "Aluno.h"
#include "Juridica.h"

using namespace std;

class BDGeral{
	private:
		static int id;
	public:
		void CadastroGeral(char escolha);

		void ImprimirDados();
};

#endif