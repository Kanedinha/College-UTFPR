#ifndef juridica_h
#define juridica_h

#include "pessoa.h"
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