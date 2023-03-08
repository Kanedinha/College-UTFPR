#ifndef MenuDoBancoDeDadosNoConsole_h
#define MenuDoBancoDeDadosNoConsole_h

#include <iostream>
#include <string.h>
#include "Fisica.h"
#include "Juridica.h"
#include "BDAluno.h"
#include "BDFisica.h"
#include "BDJuridica.h"
#include "RecebeDados.h"

using namespace std;

class MenuDoBancoDeDadosNoConsole{
  private:
  	char escolha;
  public:
  	RecebeDados dados;
  	void MostrarMenu();

  	void MostrarEscolhaDePesquisa();

  	char EscolhaDoUsuario();

  	void setEscolha(char escolha);

  	char getEscolha();

  	void OpcaoDeRemoverOuAlterarCpf(Fisica* fisica);

  	void OpcaoDeRemoverOuAlterarCnpj(Juridica* juridica);

  	void AlterarAluno(Aluno* aluno_antigo);

  	void AlterarFisica(Fisica* fisica_antigo);

  	void AlterarJuridca(Juridica* j_antigo);

  	void MensagemOpcaoInvalida();

};

#endif