#ifndef juridica_h
#define juridica_h

#include "Pessoa.h"
#include <iostream>

using namespace std;

class Juridica : public Pessoa{
  private:
    string cnpj;

  public:
    void setCnpj(string cnpj);
    string getCnpj();

};

#endif