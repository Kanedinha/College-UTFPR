#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;
class pessoa{
  protected:
    int id;
    string nome;

  public:
    int getId(){ return id;}; 
    string getNome(){ return nome;};
    void setNome(char nome){ this->nome = nome;};
};
class fisica: public pessoa {
  string cpf;
  int idade;
  
  public:    
    string getCpf(){return cpf;};
    void setCpf(string cpf){ this->cpf = cpf;};
 
    int getIdade(){ return idade; };
    void setIdade(int idade){
      if(idade > 120) this->idade = 120; else this->idade = idade;
    };     
};
class aluno: public fisica{
   string nome;
   string ra;
   string curso;
   string faculdade;
   
   public:
     string getNome(){return nome;};
     void setNome(string nome){this->nome = nome;};

     string getRa(){return ra;};
     void setRa(string ra){this ->ra = ra;};

     string getCurso(){ return curso; };
     void setCurso(string curso){ this->curso = curso;};
     
     string getFaculdade(){ return faculdade;};
     void setFaculdade(string faculdade){ this->faculdade = faculdade;};
}; 
class juridica: public pessoa {
  string cnpj;
  string nome;
 
  public:
    string getNome(){return nome;};
    void setNome(string nome){this -> nome = nome;};
    string getCnpj(){return cnpj;};
    void setCnpj(string c){ this->cnpj = c; };
};
void menu(){
  char escolha;
  cout << "\n\tMenu de opcoes"<< endl;
  cout << "Digite sua opcao:\nA para aluno, J para pessoa juridica ou F para pessoa fisica:"<< endl;
  cin >> escolha;
  string aux;
  if(escolha == 'a' || escolha == 'A'){
    aluno a1;
    cout << "\nNome: "<<endl;
    cin >> aux;
    a1.setNome(aux);
    cout<<"\nRA: "<<endl;
    cin>>aux;
    a1.setRa(aux);
    cout<<"\nFaculdade: "<<endl;
    cin>>aux;
    a1.setFaculdade(aux);
    cout<<"\nCurso: "<<endl;
    cin>>aux;
    a1.setCurso(aux);
  }
  if(escolha == 'j'||escolha == 'J'){
    string aux;
    juridica pessoa;
    cout<<"\nCNPJ: "<<endl;
    cin>>aux;
    pessoa.setCnpj(aux);
    cout<<"\nNome: "<<endl;
    cin>>aux;
    pessoa.setNome(aux);
  }
  if(escolha == 'f' || escolha=='F'){
    string cpf;
    int idade;
    fisica pessoa;
    cout<<"\nIdade: "<<endl;
    cin>>idade;
    pessoa.setIdade(idade);
    cout<<"\nCPF: "<<endl;
    cin>>cpf;
    pessoa.setCpf(cpf);
  }
}

int main(){
  menu();
}