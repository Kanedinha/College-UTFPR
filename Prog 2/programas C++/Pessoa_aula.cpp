#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

class Pessoa{
  protected:
    int id;
    string nome;

  public:
    Pessoa(int id){ this->id = id; printf("Passei aqui int:\n");};

    int getId(){ return id;};
    
    string getNome(){ return nome;};
    void setNome(string nome){ this->nome = nome;};
};


class Fisica: public Pessoa {
  string cpf;
  int idade;
  
  public:
    Fisica(int i):Pessoa(i){};
    
    string getCpf(){return this->cpf;};
    void setCpf(string cpf){ this->cpf = cpf;};
 
    int getIdade(){ return this->idade; };
    void setIdade(int idade){
      if(idade > 120) this->idade = 120; else this->idade = idade;
    };     
};

class Aluno: public Fisica{
   string curso;
   string faculdade;
   
   public:
     string getCurso(){ return curso; };
     void setCurso(string curso){ this->curso = curso;};
     
     string getFaculdade(){ return faculdade;};
     void setFaculdade(string faculdade){ this->faculdade = faculdade;};

};

 
class Juridica: public Pessoa {
  char cnpj;
 
  public:
    char getCnpj(){return this->cnpj;};
    void setCnpj(char c){ this->cnpj = c; };
  
};

int main(){
  Pessoa p = Pessoa(1l); //<- ERRO AQUI, pq?
  Fisica p1 = Fisica(1), p2 = Fisica(2);
  
  p1.setIdade(180000);
  
  p2.setIdade(18);
  
  std::cout << "P1.idade=" <<  p1.getIdade() << "\n");
  printf("P2.idade=%d\n", p2.getIdade()); 

}