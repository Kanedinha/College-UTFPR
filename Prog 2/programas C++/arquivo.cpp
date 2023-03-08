#include <iostream>
#include <string.h>
#include "pessoa.h"
#include "fisica.h"
#include "aluno.h"
#include "juridica.h"
#include "arquivo.h"

using namespace std;

    string ProcuraDadosNoArquivoPessoa(string id){
      ifstream arquivo( "Pessoa.txt" );
      string linha;
      string resultado;
      bool verifica;

      while( getline( arquivo, linha) ) {
          // a função find retorna a posição (2º parametro) 
          // da ocorrencia do primeiro caractere que foi passado (1º parametro)
          if (linha.find(id, 0) != string::npos) {
            // variável resultado recebe uma substring começando da posição retornada por find() 
            // até o final da linha que contém um '\n'
            resultado = linha.substr(linha.find(id, 0), linha.find('\n',0) );
            verifica = true;
          }
      }

      if(verifica == false)
        resultado = ProcuraDadosNoArquivoFisica(id);
      return resultado;
    };

    string ProcuraDadosNoArquivoFisica(string id){
      ifstream arquivo( "Fisica.txt" );
      string linha;
      string resultado;
      bool verifica = false;

      while( getline( arquivo, linha) ) {
          // a função find retorna a posição (2º parametro) 
          // da ocorrencia do primeiro caractere que foi passado (1º parametro)
          if (linha.find(id, 0) != string::npos) {
            // variável resultado recebe uma substring começando da posição retornada por find() 
            // até o final da linha que contém um '\n'
            resultado = linha.substr(linha.find(id, 0), linha.find('\n',0) );
            verifica = true;
          }
      }

      if(verifica == false)
        resultado = ProcuraDadosNoArquivoJuridica(id);
      return resultado;
    };

    string ProcuraDadosNoArquivoJuridica(string id){
      ifstream arquivo( "Juridica.txt" );
      string linha;
      string resultado;
      bool verifica = false;

      while( getline( arquivo, linha) ) {
          // a função find retorna a posição (2º parametro) 
          // da ocorrencia do primeiro caractere que foi passado (1º parametro)
          if (linha.find(id, 0) != string::npos) {
            // variável resultado recebe uma substring começando da posição retornada por find() 
            // até o final da linha que contém um '\n'
            resultado = linha.substr(linha.find(id, 0), linha.find('\n',0) );
            verifica = true;
          }
      }

      if(verifica == false)
        resultado = ProcuraDadosNoArquivoAluno(id);
      return resultado;
    };

    string ProcuraDadosNoArquivoAluno(string id){
      ifstream arquivo( "Aluno.txt" );
      string linha;
      string resultado = "Nada foi encontrado";

      while( getline( arquivo, linha) ) {
          // a função find retorna a posição (2º parametro) 
          // da ocorrencia do primeiro caractere que foi passado (1º parametro)
          if (linha.find(id, 0) != string::npos) {
            // variável resultado recebe uma substring começando da posição retornada por find() 
            // até o final da linha que contém um '\n'
            resultado = linha.substr(linha.find(id, 0), linha.find('\n',0) );
          }
      }

      return resultado;
    };

    void ImprimirOsDadosDaPessoaNoConsole(string Dados){
      cout << "Dados: \n" << endl; 
      cout << Dados << '\n'<< endl;
    };

    string FormataId(){
      string formato;
      string id;
      cout << "\nid: ";
      cin >> id;
      formato = "id: " + id + "|";
      return formato;
    };

    int GerarId(){
      string MaiorIdPessoa = ProcuraDadosNoArquivoPessoa("id: ");
      MaiorIdPessoa = MaiorIdPessoa.substr(MaiorIdPessoa.find(ProcuraDadosNoArquivoPessoa("id: "),0),MaiorIdPessoa.find('|',0));
      
      string MaiorIdFisica = ProcuraDadosNoArquivoFisica("id: ");
      MaiorIdFisica = MaiorIdFisica.substr(MaiorIdFisica.find(ProcuraDadosNoArquivoFisica("id: "),0),MaiorIdFisica.find('|',0));
      
      string MaiorIdAluno = ProcuraDadosNoArquivoAluno("id: ");
      MaiorIdAluno = MaiorIdAluno.substr(MaiorIdAluno.find(ProcuraDadosNoArquivoAluno("id: "),0),MaiorIdAluno.find('|',0));
      
      string MaiorIdJuridica = ProcuraDadosNoArquivoJuridica("id: ");
      MaiorIdJuridica = MaiorIdJuridica.substr(MaiorIdJuridica.find(ProcuraDadosNoArquivoJuridica("id: "),0),MaiorIdJuridica.find('|',0));
          
      int IdPessoa = stoi(MaiorIdPessoa.erase(0,4)), IdFisica = stoi(MaiorIdFisica.erase(0,4));
      int IdAluno = stoi(MaiorIdAluno.erase(0,4)), IdJuridica = stoi(MaiorIdJuridica.erase(0,4));
      
      if(IdPessoa > IdFisica && IdPessoa > IdJuridica && IdPessoa > IdAluno)
        return IdPessoa;
      else if(IdFisica > IdPessoa && IdFisica > IdJuridica && IdFisica > IdAluno)
        return IdFisica;
      else if(IdAluno > IdPessoa && IdAluno > IdFisica && IdAluno > IdJuridica)
        return IdAluno;
      else
        return IdJuridica;
    };
