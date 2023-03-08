#ifndef BDfisica_h
#define BDfisica_h

#include "Fisica.h"
#include "Arquivo.h"
#include "BDPessoa.h"
#include "SeparaString.h"
#include <fstream>
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

class BDFisica{
  public:
    void ArquivarFisica(Fisica fisica, int id);

    Fisica* ProcuraDadosNoArquivoFisica(string cpf);

    void RemoverFisica(Fisica* fisica);

    void AlteraFisica(Fisica* fisica_antiga, Fisica* fisica_nova);
};

#endif