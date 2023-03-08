#ifndef SeparaDados_h
#define SeparaDados_h

#include <string.h>
#include <fstream>
#include "Pessoa.h"
#include "Fisica.h"
#include "Aluno.h"
#include "Juridica.h"

using namespace std;

class SeparaDados{
  public:
	string SeparaDados(ifstream arquivo, int qnt_de_dados);
};
#endif