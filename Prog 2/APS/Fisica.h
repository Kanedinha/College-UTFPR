#ifndef fisica_h
#define fisica_h

#include <iostream>
#include "Pessoa.h"

using namespace std;

class Fisica : public Pessoa{
  private:
    string cpf;
    int idade;

  public:
    void setCpf(string cpf);
    string getCpf();

    void setIdade(int idade);
    int getIdade();
};

#endif