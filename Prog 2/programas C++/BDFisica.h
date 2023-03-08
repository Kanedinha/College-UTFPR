#ifndef BDfisica_h
#define BDfisica_h

#include <iostream>
#include <fstream>
#include "fisica.h"

using namespace std;

class BDFisica{
  public:
    bool ArquivarFisica(Fisica fisica){
      ofstream arquivo;
      Arquivo ID;
      arquivo.open("Fisica.txt", fstream::app);

      // armazena no arquivo os atributos na ordem id: |nome: |idade: |cpf: \n
      arquivo << "id: " << ID.GerarId() + 1 << "|nome: " << fisica.getNome() << "|idade: " << fisica.getIdade();
      arquivo << "|cpf: " << fisica.getCpf() << endl ;

      arquivo.close();
    };

    // pega e armazena o nome e idade da pessoa
    Fisica CadastroFisica(){
      Fisica fisica;
      string nome;
      string cpf;
      int idade;

      cout << "Digite o nome:";
      cin >> nome;
      cout << "Digite a idade:";
      cin >> idade;
      cout << "Digite o cpf:";
      cin >> cpf;

      fisica.setNome(nome);
      fisica.setIdade(idade);
      fisica.setCpf(cpf);

      return fisica;
    
    };
};