#include "BDPessoa.h"

using namespace std;

    void BDPessoa:: ArquivarPessoa(Pessoa pessoa){
      ofstream arquivo;

      arquivo.open("Pessoa.txt", fstream::app);


      arquivo << pessoa.getId() << ";" << pessoa.getNome() << endl ;

      arquivo.close();
    };

    Pessoa* BDPessoa:: ProcuraDadosNoArquivoPessoa(int id){
      Pessoa* pessoa = new Pessoa();
      SeparaStr separa;
      ifstream arquivo( "Pessoa.txt" );
      string linha_de_dados[2];
      string aux;
      
      while(getline(arquivo, aux)){
        separa.SeparaDadosEmUmVetor(linha_de_dados, aux);
        if(stoi(linha_de_dados[0]) == id){
          pessoa->setNome(linha_de_dados[1]);
          return pessoa;
        } 
      }
      return NULL;
    };

    void BDPessoa:: RemoverPessoa(Pessoa* pessoa){
      SeparaStr separa;
      string linha_de_dados[2];
      ifstream arquivo("Pessoa.txt");
      ofstream temp_arquivo;
      temp_arquivo.open("PessoaTemp.txt", fstream::app);
      string aux;

      while(getline(arquivo, aux)){
        separa.SeparaDadosEmUmVetor(linha_de_dados, aux);
        if(stoi(linha_de_dados[0]) != pessoa->getId()){
            temp_arquivo << aux << endl;
        } 
      }

      arquivo.close();
      temp_arquivo.close();

      remove("Pessoa.txt");
      rename("PessoaTemp.txt", "Pessoa.txt");
    };

    