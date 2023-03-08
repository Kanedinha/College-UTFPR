#include "classes.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Pessoa{
  protected:
    int id;
    string nome;

  public:
    int getId(){ return id;}; 

    string getNome(){ return nome;};
    void setNome(string nome){ this->nome = nome;};
    
    string toString(){
      stringstream ss;
      ss << "id = " << this->id << "\nnome=" << this->nome << endl; 
      return ss.str();
    };
};

class Fisica: public Pessoa{
  	string cpf;
  	int idade;
  
  public:
    string getCpf(){return cpf;};
    void setCpf(string cpf){ this->cpf = cpf;};

    string getNome(){ return nome;};
    void setNome(string nome){ this->nome = nome;};
	
};

class Aluno: public Fisica{
   string ra;
   string curso;
   string faculdade;
   
   public:
     string getRa(){return ra;};
     void setRa(string ra){this ->ra = ra;};

     string getCurso(){ return curso; };
     void setCurso(string curso){ this->curso = curso;};
     
     string getFaculdade(){ return faculdade;};
     void setFaculdade(string faculdade){ this->faculdade = faculdade;};

};

class Juridica: public Pessoa {
  string cnpj;
  string nome;
 
  public:
    string getNome(){return nome;};
    void setNome(string nome){this -> nome = nome;};

    string getCnpj(){return cnpj;};
    void setCnpj(string c){ this->cnpj = c;};
	
};

