#ifndef PesquisaDados_h
#define PesquisaDados_h

#include <string.h>
#include <iostream>
#include "BDFisica.h"
#include "Fisica.h"
#include "Juridica.h"
#include "BDPessoa.h"
#include "Pessoa.h"
#include "BDAluno.h"
#include "Aluno.h"
#include "BDJuridica.h"
#include "MenuDoBancoDeDadosNoConsole.h"
#include "RecebeDados.h"
using namespace std;

class ImprimiDados{
  public:
	void ImprimirDadosFisica(Fisica* fisica);

	void ImprimirDadosPessoa(int id);

	void ImprimirDadosAluno(int id);

	void ImprimirDadosJuridica(Juridica* juridica);

	void ImprimirDados();
};

#endif