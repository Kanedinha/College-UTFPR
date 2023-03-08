#ifndef RecebeDados_h
#define RecebeDados_h

#include "Pessoa.h"
#include "Fisica.h"
#include "Aluno.h"
#include "Juridica.h"
#include "BDJuridica.h"
#include "BDFisica.h"
#include <string.h>
#include <iostream>

using namespace std;

class RecebeDados{
	public:
		int RecebeIdade();

		string RecebeAtributoString(string atributo);

		Fisica RecebeAtributoFisica();

		Aluno RecebeAtributoAluno();

		Juridica RecebeAtributoJuridica();

		string VerificaCpf();

		string VerificaCnpj();
};

#endif