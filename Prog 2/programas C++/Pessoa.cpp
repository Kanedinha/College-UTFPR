#include<stdio.h>
#include<string.h>

class Pessoa{
  protected:
    long id;
    char nome;
    int idade;
  public:
    Pessoa(int id){
      this->id = id;
    };
    Pessoa(int id, int idade){
      this->id = id; 
      this->idade = idade;
    };
    int getIdade(){ 
      return this->idade; 
    };
    void setIdade(int idade){
      if(idade > 120) this->idade = 120; else this->idade = idade;
    };     
};


class Fisica: public Pessoa {
  char cpf;
  
  public:
    Fisica(int idade) : Pessoa(idade){};
    char getCpf(){return this->cpf;};
    void setCpf(char c){ this->cpf = c; };
};

class Aluno: public Fisica{


};

class atleta: public Pessoa{
  char federacao;
  char modalidade; 
  
    public: 
  char posicao;
  char getfederacao(){return this->federacao;};
  void setfederacao(char c){this->federacao = c;};
  char getmodalidade(){return this->modalidade;};
  void setmodalidade(char c){this->modalidade = c;};
};

class estudante: public Pessoa{
    public:
  char faculdade;
  char curso;
  char material;
};


class Juridica: public Pessoa {
  char cnpj;
  
  public:
    char getCnpj(){return this->cnpj;};
    void setCnpj(char c){ this->cnpj = c; };
    void setIdade(int idade){
      if(idade > 1000) this->idade = 1000; else this->idade = idade;
    };     
};

int main(){
  Fisica p1 = Fisica(1), p2 = Fisica(2);
  
  p1.setIdade(180000);
  
  p2.setIdade(18);
  
  printf("P1.idade=%d\n", p1.getIdade());
  printf("P2.idade=%d\n", p2.getIdade()); 

}