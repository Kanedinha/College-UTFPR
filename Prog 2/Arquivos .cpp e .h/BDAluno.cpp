#include "BDAluno.h"


using namespace std;

void BDAluno:: ArquivarAluno(Aluno aluno, int id){
 BDFisica bdf;
 Fisica * fisica = new Fisica();
 aluno.setId(id);
 fisica->setId(aluno.getId());
 fisica->setNome(aluno.getNome());
 fisica->setCpf(aluno.getCpf());
 fisica->setIdade(aluno.getIdade());
 bdf.ArquivarFisica(*fisica, aluno.getId());

 ofstream arquivo;

 arquivo.open("Aluno.txt", fstream::app);

 arquivo << aluno.getId()<< ";" << aluno.getFaculdade() << ";" << aluno.getCurso() << endl;

 arquivo.close();
};

Aluno* BDAluno:: ProcuraDadosNoArquivoAluno(int id, Aluno* aluno){
  SeparaStr separa;
  ifstream arquivo( "Aluno.txt" );
  string linha_de_dados[3];
  string aux;
  linha_de_dados[0] = "0";

  while(getline(arquivo, aux)){
    separa.SeparaDadosEmUmVetor(linha_de_dados, aux);
    if(stoi(linha_de_dados[0]) == id){
      aluno->setFaculdade(linha_de_dados[1]);
      aluno->setCurso(linha_de_dados[2]);
      return aluno;
    }    
  }
  return NULL;
};

void BDAluno:: RemoverAluno(Fisica* fisica){
  BDFisica bdf;
  bdf.RemoverFisica(fisica);

  SeparaStr separa;
  string linha_de_dados[3];
  ifstream arquivo("Aluno.txt");
  ofstream temp_arquivo;
  temp_arquivo.open("AlunoTemp.txt", fstream::app);
  string aux;

  while(getline(arquivo, aux)){
    separa.SeparaDadosEmUmVetor(linha_de_dados, aux);
    if(stoi(linha_de_dados[0]) != fisica->getId()){
      temp_arquivo << aux << endl;
    } 
  }

  arquivo.close();
  temp_arquivo.close();

  remove("Aluno.txt");
  rename("AlunoTemp.txt", "Aluno.txt");
};

void BDAluno:: AlteraAluno(Aluno* aluno_antigo, Aluno* aluno_novo){
  RemoverAluno(aluno_antigo);
  ArquivarAluno(*aluno_novo, aluno_novo->getId());
};