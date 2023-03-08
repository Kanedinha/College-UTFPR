#ifndef arquivo_h
#define arquivo_h

#include <iostream>
#include <string.h>
#include <fstream>
#include "aluno.h"
#include "juridica.h"
#include "BDPessoa.h"
#include "BDFisica.h"
#include "BDAluno.h"
#include "BDJuridica.h"

using namespace std;

class Arquivo{
  public:

    void ImprimirOsDadosDaPessoaNoConsole(string Dados);

    int GerarId();
};

#endif