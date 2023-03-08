#ifndef bdpessoa_h
#define bdpessoa_h

#include "Pessoa.h"
#include "Arquivo.h"
#include <string.h>
#include "SeparaString.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class BDPessoa{
  public:

    void ArquivarPessoa(Pessoa pessoa);

    Pessoa* ProcuraDadosNoArquivoPessoa(int id);

    void RemoverPessoa(Pessoa* pessoa);

    void AlteraPessoa(Pessoa* pessoa_antiga, Pessoa* pessoa_nova);

};

#endif