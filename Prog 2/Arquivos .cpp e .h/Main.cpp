#include <iostream>
#include <fstream>
#include <string.h>
#include "Arquivo.h"
#include "MenuDoBancoDeDadosNoConsole.h"
#include "BDGeral.h"
#include "ImprimiDados.h"

using namespace std;

int main(){
  MenuDoBancoDeDadosNoConsole menu;
  BDGeral bdgeral;
  Arquivo arquivo;
  ImprimiDados imprimi;

  cout << "\n**************************************************" << endl;
  cout << "*         Bem vindo ao Banco de Dados!           *" << endl;
  cout << "*                                                *" << endl;
  cout << "**************************************************" << endl;
  
  while(true){
    menu.MostrarMenu();
    switch(menu.EscolhaDoUsuario()){
      case 'f':case 'F': bdgeral.CadastroGeral('f'); break;
      case 'j':case 'J': bdgeral.CadastroGeral('j'); break;
      case 'a':case 'A': bdgeral.CadastroGeral('a'); break;
      case 'i':case 'I': imprimi.ImprimirDados(); break;
      case '0': return 0;
      default:
      menu.MensagemOpcaoInvalida();
    }
  }
}