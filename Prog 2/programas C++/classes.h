#ifndef classes
#define classes

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

/************class Pessoa**************
    //Pega o Id da Pessoa
    int getId(); 
    //Pega o Nome de Pessoa
    string getNome();
    
    //Insere o Nome de Pessoa
    void setNome(string nome);
    //Mostra o Id e o Nome de Pessoa
    string toString();

//************class Fisica**************
	//Pega o Cpf de Fisica
	string getCpf();
	//Insere o Cpf de Fisica
	void setCpf(string cpf);

	//Pega o Nome de Fisica
    string getNome();
    //Insere o Nome de Fisica
    void setNome(string nome);

//************class Aluno***************
    //Pega o Ra do Aluno
    string getRa();
    //Insere o Ra do Aluno
    void setRa(string ra);

    //Pega o Curso do Aluno
    string getCurso();
    //Insere o Curso do aluno
    void setCurso(string curso);
     
    string getFaculdade();
    void setFaculdade(string faculdade);

//************class Juridica************

    string getNome();
    void setNome(string nome);

    string getCnpj();
    void setCnpj(string c);
*/

class Pessoa{
  protected:
    string id;
    string nome;

  public:
    string getId(){ return id;}; 
    void setId(string id){ this->id = id;};

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


#endif