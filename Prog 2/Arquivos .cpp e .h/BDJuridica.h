#ifndef BDJuridica_h
#define BDJuridica_h

#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include "Juridica.h"
#include "Arquivo.h"
#include "BDPessoa.h"
#include "SeparaString.h"

using namespace std;

class BDJuridica{
  public:
    void ArquivarJuridica(Juridica juridica, int id);

    Juridica* ProcuraDadosNoArquivoJuridica(string cnpj);

    void RemoverJuridica(Juridica* juridica);

    void AlteraJuridica(Juridica* juridica_antiga, Juridica* juridica_nova);

};

#endif