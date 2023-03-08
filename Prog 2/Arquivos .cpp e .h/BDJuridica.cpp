#include "BDJuridica.h"

using namespace std;

void BDJuridica:: ArquivarJuridica(Juridica juridica, int id){
 BDPessoa bdp;
 Pessoa * pessoa = new Pessoa();
 juridica.setId(id);
 pessoa->setId(juridica.getId());
 pessoa->setNome(juridica.getNome());
 bdp.ArquivarPessoa(*pessoa);
 ofstream arquivo;

 arquivo.open("Juridica.txt", fstream::app);

 arquivo << juridica.getId() << ";" << juridica.getCnpj() << endl ;

 arquivo.close();
};

Juridica* BDJuridica:: ProcuraDadosNoArquivoJuridica(string cnpj){
  Juridica* juridica = new Juridica();
  SeparaStr separa;
  ifstream arquivo( "Juridica.txt" );
  string linha_de_dados[2];
  string aux;

  while(getline(arquivo, aux)){
    separa.SeparaDadosEmUmVetor(linha_de_dados, aux);
    if(linha_de_dados[1] == cnpj){
      juridica->setId(stoi(linha_de_dados[0]));
      juridica->setCnpj(linha_de_dados[1]);
      return juridica;
    }    
  }
  return NULL;
};

void BDJuridica:: RemoverJuridica(Juridica* juridica){
  BDPessoa bdp;
  Pessoa* pessoa = new Pessoa();
  pessoa->setId(juridica->getId());
  bdp.RemoverPessoa(pessoa);

  SeparaStr separa;
  string linha_de_dados[2];
  ifstream arquivo("Juridica.txt");
  ofstream temp_arquivo;
  temp_arquivo.open("JuridicaTemp.txt", fstream::app);
  string aux;

  while(getline(arquivo, aux)){
    separa.SeparaDadosEmUmVetor(linha_de_dados, aux);
    if(stoi(linha_de_dados[0]) != juridica->getId()){
      temp_arquivo << aux << endl;
    } 
  }

  arquivo.close();
  temp_arquivo.close();

  remove("Juridica.txt");
  rename("JuridicaTemp.txt", "Juridica.txt");
};

void BDJuridica:: AlteraJuridica(Juridica* juridica_antiga, Juridica* juridica_nova){
  RemoverJuridica(juridica_antiga);
  ArquivarJuridica(*juridica_nova, juridica_nova->getId());
};