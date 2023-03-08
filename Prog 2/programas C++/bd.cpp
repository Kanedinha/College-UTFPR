#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "classes.h"
#include "BancoDados.h"

using namespace std;

// gerar ID automaticamente

// procurar como ler arquivo]
// while(in.good()){
// if(o ID que eu quero)
// mostrar linha
// }

class CadastroGeralEmConsole{
private:
     
void boasVindasAoCadastro(string nomeCadastro){
    cout << endl << "Bem vindo ao cadastro de " << nomeCadastro << "===========" << endl;

  };
     
void mostraNomeAtributoParaColetar(string nomeAtributo){
    cout << nomeAtributo << ":" << ;
   
  };
    
string obtemValorAtributoString(string nomeAtributo){
    mostraNomeAtributoParaColetar(nomeAtributo);
    string aux;
    cin >> aux;
    return aux;

  };
    
int obtemValorAtributoInt(string nomeAtributo){
    mostraNomeAtributoParaColetar(nomeAtributo);
    int aux;
    cin >> aux;
    return aux;

    };

public:

void mostraMenu(){
      cout << "\n\tMenu de opcoes"<< endl;
      cout<< "Aluno: A \nPessoa fisica: F \nPessoa juridica: J"<< endl;
      cout<<"\nSair do programa: 0\n"<<endl;
     
     };

char obtemEscolha(){
    char escolha;
    cin >> escolha;
    return escolha;

     };

void cadastrarAluno(){
    Aluno a1;

    boasVindasAoCadastro("ALUNO");
    a1.setNome(obtemValorAtributoString("Nome completo"));
    a1.setRa(obtemValorAtributoString("Registro Acadêmico (RA)"));
    a1.setFaculdade(obtemValorAtributoString("Faculdade"));
    a1.setCurso(obtemValorAtributoString("Curso"));
    
    BDAluno obj;
    obj.guardar(a1);
   
    };

void cadastrarJuridica(){
    boasVindasAoCadastro("JURIDICA");
      string aux;
      Juridica pessoa;
      
      cout<<"\nCNPJ: "<<endl;
      cin>>aux;
      pessoa.setCnpj(aux);
      
      cout<<"\nNome: "<<endl;
      cin>>aux;
      pessoa.setNome(aux);
      
      BDJuridica bdJ;
      bdJ.guardar(pessoa);

     };

void cadastrarFisica(){
  boasVindasAoCadastro("FISICA");
    string aux;
    int idade;
    Fisica pessoa;

    cout<<"\nNome: "<<endl;
    cin>>aux;
    pessoa.setNome(aux);

    cout<<"\nCPF: "<<endl;
    cin>>aux;
    pessoa.setCpf(aux);

    BDFisica bdF;
    bdF.guardar(pessoa);
    cout << "Dados cadastrados:" << pessoa.toString() << endl;

     };
void cadPessoa(){
    string aux;
    int idade;
    Pessoa pessoa;

    cout<<"\nNome: "<<endl;
    cin>>aux;
    pessoa.setNome(aux);

    cout<<"\nCPF: "<<endl;
    cin>>aux;
    pessoa.setId(aux);

    BDPessoa bd;
    bd.guardar(pessoa);
    bd.mostrar(pessoa.getNome());
    cout << "Dados cadastrados:" << pessoa.toString() << endl;
  };
};

int main(){
  CadastroGeralEmConsole cad;
  BDPessoa bd;
  while(true){
    cad.mostraMenu();
    switch(cad.obtemEscolha()){
      case '0': return 0;
      case 'a': case 'A': cad.cadastrarAluno(); break;
      case 'j': case 'J': cad.cadastrarJuridica(); break;
      case 'f': case 'F': cad.cadastrarFisica(); break;
      case 'p': case 'P': cad.cadPessoa(); break;
      case '1': bd.mostrar("321"); break;
    }

  }

}