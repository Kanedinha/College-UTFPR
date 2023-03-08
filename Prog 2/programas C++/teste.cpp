#include <iostream>
#include <fstream>
#include <string.h>
#include "pessoa.h"
#include "fisica.h"
#include "aluno.h"
#include "juridica.h"
#include "arquivo.h"
#include "BDPessoa.h"
#include "BDFisica.h"
#include "BDAluno.h"
#include "BDJuridica.h"
#include "FormatacaoDePesquisa.h"
#include "MenuDoBancoDeDadosNoConsole.h"

using namespace std;

int main(){
  MenuDoBancoDeDadosNoConsole menu;
  BDPessoa bdpessoa;
  BDFisica bdfisica;
  BDAluno bdaluno;
  BDJuridica bdjuridica;
  Arquivo arquivo;

  cout << "\nBem vindo ao Banco de Dados!" << endl;

  while(true){
    menu.MostrarMenu();
    switch(menu.EscolhaDoUsuario()){
      case 'p':case 'P': bdpessoa.ArquivarPessoa(bdpessoa.CadastroPessoa()); break;
      case 'f':case 'F': bdfisica.ArquivarFisica(bdfisica.CadastroFisica()); break;
      case 'j':case 'J': bdjuridica.ArquivarJuridica(bdjuridica.CadastroJuridica()); break;
      case 'a':case 'A': bdaluno.ArquivarAluno(bdaluno.CadastroAluno()); break;
      case 'i':case 'I': arquivo.ImprimirOsDadosDaPessoaNoConsole(arquivo.ProcuraDadosNoArquivoPessoa(arquivo.FormataId())); break;
      case '0': return 0;
   
    }
  }

}