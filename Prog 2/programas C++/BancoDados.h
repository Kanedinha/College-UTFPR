#ifndef BancoDados
#define BancoDados

#include <string>
#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include "classes.h"

using namespace std;

class BDPessoa {
  public:
    bool guardar(Pessoa pessoa){
      ofstream arquivo;
      arquivo.open("pessoa.txt", ios::app);
      arquivo<<pessoa.getId()<<";"<<pessoa.getNome()<<endl;
      return true;
    };
    bool mostrar(string id){
      string line;
      ifstream arquivo("pessoa.txt");
      arquivo.open("pessoa.txt", ifstream::in);
      while(getline(arquivo, line)){
        if(nome == line){
          cout << line<< '\n' << endl;
        }
      }
      arquivo.close();
      return true;
    };
};

class BDFisica {
  public:
    bool guardar(Fisica fisica){
      ofstream arquivo;
      arquivo.open("fisica.txt", ios::app);
      arquivo<<fisica.getId()<<";"<<fisica.getNome()<<endl;
      return true;
    };
    bool mostrar(){
      string line;
      ifstream arquivo ("fisica.txt");
      if (arquivo.is_open()){
      while ( getline (arquivo,line) ){
        cout << line << '\n';
        }
        arquivo.close();
      }
    return true;
  }
    };
class BDJuridica {
  public:
    bool guardar(Juridica juridica){
      ofstream arquivo;
      arquivo.open("juridica.txt", ios::app);
      arquivo<<juridica.getId()<<";"<<juridica.getNome()<<endl;
      return true;
    };
    bool mostrar(){
    	
    return true;
  }
    };
class BDAluno {
  public:
    bool guardar(Aluno aluno){
      BDFisica bd;
      bd.guardar(aluno);
      ofstream arquivo;
      arquivo.open("aluno.txt", ios::app);
      arquivo<<aluno.getId()<<";"<<aluno.getNome()<<";"<<aluno.getRa()<<";"<<aluno.getFaculdade()<<";"<<aluno.getCurso()<<";"<<endl;
      return true;
    };
    bool mostrar(){
      string line;
      ifstream arquivo ("aluno.txt");
      if (arquivo.is_open()){
      while ( getline (arquivo,line) ){
        cout << line << '\n';
        }
        arquivo.close();
      }
    return true;
  }
};


#endif