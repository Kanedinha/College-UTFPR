#ifndef arquivo_h
#define arquivo_h

#include <string.h>
#include "aluno.h"
#include "juridica.h"

using namespace std;

class Arquivo{
  public:

    void ImprimirOsDadosDaPessoaNoConsole(string Dados);

    int GerarId();
    
};

#endif