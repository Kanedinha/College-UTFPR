#ifndef BDAluno_h
#define BDAluno_h

#include "Aluno.h"
#include "Arquivo.h"
#include "BDFisica.h"
#include "SeparaString.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>

class BDAluno{
  public:
    void ArquivarAluno(Aluno aluno, int id);

    Aluno* ProcuraDadosNoArquivoAluno(int id, Aluno* aluno);

    void RemoverAluno(Fisica* fisica);

    void AlteraAluno(Aluno* aluno_antiga, Aluno* aluno_nova);
};

#endif