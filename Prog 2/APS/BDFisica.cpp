#include "BDFisica.h"

using namespace std;

void BDFisica:: ArquivarFisica(Fisica fisica, int id){
  BDPessoa bdp;
  Pessoa * pessoa = new Pessoa();
  pessoa->setId(id);
  pessoa->setNome(fisica.getNome());
  fisica.setId(id);
  bdp.ArquivarPessoa(*pessoa);
  ofstream arquivo;
  arquivo.open("Fisica.txt", fstream::app);

  arquivo << fisica.getId() << ";" << fisica.getCpf() << ";" << fisica.getIdade() << endl ;

  arquivo.close();
};

Fisica* BDFisica:: ProcuraDadosNoArquivoFisica(string cpf){
  Fisica* fisica = new Fisica();
  SeparaStr separa;
  ifstream arquivo( "Fisica.txt" );
  string linha_de_dados[3];
  string aux;

  while(getline(arquivo, aux)){
    separa.SeparaDadosEmUmVetor(linha_de_dados, aux);

    if(linha_de_dados[1] == cpf){
      fisica->setId(stoi(linha_de_dados[0]));
      fisica->setCpf(linha_de_dados[1]);
      fisica->setIdade(stoi(linha_de_dados[2]));
      return fisica;
    }
  }
  return NULL;
};

void BDFisica:: RemoverFisica(Fisica* fisica){
  BDPessoa bdp;
  Pessoa* pessoa = new Pessoa();
  pessoa->setId(fisica->getId());
  bdp.RemoverPessoa(pessoa);

  SeparaStr separa;
  string linha_de_dados[3];
  ifstream arquivo("Fisica.txt");
  ofstream temp_arquivo;
  temp_arquivo.open("FisicaTemp.txt", fstream::app);
  string aux;

  while(getline(arquivo, aux)){
    separa.SeparaDadosEmUmVetor(linha_de_dados, aux);
    if(stoi(linha_de_dados[0]) != fisica->getId()){
      temp_arquivo << aux << endl;
    } 
  }

  arquivo.close();
  temp_arquivo.close();

  remove("Fisica.txt");
  rename("FisicaTemp.txt", "Fisica.txt");

};

void BDFisica:: AlteraFisica(Fisica* fisica_antiga, Fisica* fisica_nova){
  RemoverFisica(fisica_antiga);
  ArquivarFisica(*fisica_nova, fisica_antiga->getId());
};
