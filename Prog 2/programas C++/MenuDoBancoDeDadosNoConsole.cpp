#include <iostream>
#include <string.h>
#include "MenuDoBancoDeDadosNoConsole.h"

using namespace std;

	void MostrarMenu(){
		cout << "Bem vindo ao Banco de dados!" << endl;
		cout << " Digite 'P' para cadastrar uma pessoa" << endl;
		cout << " Digite 'F' para cadastrar uma pessoa física" << endl;
		cout << " Digite 'J' para cadastrar uma pessoa juridica" << endl;
		cout << " Digite 'A' para cadastrar um aluno" << endl;
	};

	char EscolhaDoUsuario(){
      cout << "Opcao: " ;
      cin >> escolha ;
      return escolha ;
    };
