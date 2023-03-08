#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;



// TODO separa os arquivos em .h e .o

// TODO modularizar as informações de uma pessoa no arquivo pessoa.txt
// TODO modularizar as informações de uma pessoa fisica no arquivo fisica.txt e os atributos de pessoa em pessoa.txt
// TODO modularizar as informações de uma pessoa juridica, atributos de jurica em juridica.txt e de pessoa em pessoa.txt
// TODO modularizar as informações de um aluno 

class Pessoa{
  private:  
    static int id;
    string nome;
    int idade;

  public:
    // setAtributo() defini o atributo6
    // getAtributo() retorna o atributo
    
    void setNome(string nome){ this->nome = nome;};
    string getNome(){ return this->nome;};

    void setIdade(int idade){ this->idade = idade;};
    int getIdade(){ return this->idade;};

// problema do id, gerar automaticamente*********************************APAGAR dpois
    static int getId(){ return Pessoa::id;};

};

class Fisica : public Pessoa{
  private:
    string cpf;

  public:
    void setCpf(string cpf){ this->cpf = cpf;};
    string getCpf(){ return this->cpf;};

};

class Aluno : public Fisica{
  private:
    string faculdade;
    string curso;

  public:
    void setFaculdade(string faculdade){ this->faculdade = faculdade;};
    string getFaculdade(){ return this->faculdade;};

    void setCurso(string curso){ this->curso = curso;};
    string getCurso(){ return this->curso;};

};

class Juridica : public Pessoa{
  private:
    string cnpj;

  public:
    void setCnpj(string cnpj){ this->cnpj = cnpj;};
    string getCnpj(){ return this->cnpj;};

};

class Arquivo{
  public:
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
      formato = "id: " + id;
      formato = formato + "|";
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
};

class BDPessoa{
  public:
    bool ArquivarPessoa(Pessoa pessoa){
      Arquivo ID;
      // Pessoa p; *******************************************************************************************************
      ofstream arquivo;
      arquivo.open("Pessoa.txt", fstream::app);
      // Pessoa::id = ID.GerarId() + 1;  *********************************************************************************
      // armazena no arquivo os atributos na ordem id: |nome: |idade: \n
      arquivo << "id: " << ID.GerarId() + 1 << "|nome: " << pessoa.getNome() << "|idade: " << pessoa.getIdade() << endl ;

      arquivo.close();
    };

    // pega e armazena o nome e idade da pessoa
    Pessoa CadastroPessoa(){
      Pessoa pessoa;
      string nome;
      int idade;

      cout << "Digite o nome:";
      cin >> nome;
      cout << "Digite a idade:";
      cin >> idade;

      pessoa.setNome(nome);
      pessoa.setIdade(idade);

      return pessoa;
    
    };
};

class BDFisica{
  public:
    bool ArquivarFisica(Fisica fisica){
      ofstream arquivo;
      Arquivo ID;
      arquivo.open("Fisica.txt", fstream::app);

      // armazena no arquivo os atributos na ordem id: |nome: |idade: |cpf: \n
      arquivo << "id: " << ID.GerarId() + 1 << "|nome: " << fisica.getNome() << "|idade: " << fisica.getIdade();
      arquivo << "|cpf: " << fisica.getCpf() << endl ;

      arquivo.close();
    };

    // pega e armazena o nome e idade da pessoa
    Fisica CadastroFisica(){
      Fisica fisica;
      string nome;
      string cpf;
      int idade;

      cout << "Digite o nome:";
      cin >> nome;
      cout << "Digite a idade:";
      cin >> idade;
      cout << "Digite o cpf:";
      cin >> cpf;

      fisica.setNome(nome);
      fisica.setIdade(idade);
      fisica.setCpf(cpf);

      return fisica;
    
    };
};

class BDAluno{
  public:
    bool ArquivarAluno(Aluno aluno){
      ofstream arquivo;
      Arquivo ID;
      arquivo.open("Aluno.txt", fstream::app);

      // armazena no arquivo os atributos na ordem id: |nome: |idade: |cpf: |faculdade: |Curso: \n
      arquivo << "id: " << ID.GerarId() + 1 << "|nome: " << aluno.getNome() << "|idade: " << aluno.getIdade();
      arquivo << "|cpf: " << aluno.getCpf() << "|faculdade: " << aluno.getFaculdade() << "|curso: " << aluno.getCurso() << endl;

      arquivo.close();
    };

    // pega e armazena o nome e idade da pessoa
    Aluno CadastroAluno(){
      Aluno aluno;
      string nome, cpf, faculdade, curso;
      int idade;

      cout << "Digite o nome: ";
      cin >> nome;
      cout << "Digite a idade: ";
      cin >> idade;
      cout << "Digite o cpf: ";
      cin >> cpf;
      cout << "Digite a faculdade: ";
      cin >> faculdade;
      cout << "Digite o curso: ";
      cin >> curso;
     
      aluno.setNome(nome);
      aluno.setIdade(idade);
      aluno.setCpf(cpf);
      aluno.setFaculdade(faculdade);
      aluno.setCurso(curso);
      
      return aluno;
    };
};

class BDJuridica{
  public:
    bool ArquivarJuridica(Juridica juridica){
      ofstream arquivo;
      Arquivo ID;
      arquivo.open("Juridica.txt", fstream::app);

      // armazena no arquivo os atributos na ordem id: |nome: |idade: |cnpj: \n
      arquivo << "id: " << ID.GerarId() + 1 << "|nome: " << juridica.getNome() << "|idade: " << juridica.getIdade() ;
      arquivo << "|cpf: " << juridica.getCnpj() << endl ;

      arquivo.close();
    };

    // pega e armazena o nome e idade da pessoa
    Juridica CadastroJuridica(){
      Juridica juridica;
      string nome, cnpj;
      int idade;

      cout << "Digite o nome:";
      cin >> nome;
      cout << "Digite a idade:";
      cin >> idade;
      cout << "Digite o cnpj:";
      cin >> cnpj;
      
      juridica.setNome(nome);
      juridica.setIdade(idade);
      juridica.setCnpj(cnpj);

      return juridica;
    
    };
};

class MenuDoBancoDeDadosNoConsole{
  char escolha;
  public:
    void MostrarMenu(){
    cout << endl;
    cout << "Digite 'P' para cadastrar uma pessoa" << endl;
    cout << "Digite 'F' para cadastrar uma pessoa fisica" << endl;
    cout << "Digite 'J' para cadastrar uma pessoa juridica" << endl;
    cout << "Digite 'A' para cadastrar um aluno" << endl;
    cout << "Digite 'I' para imprimir os dados cadastrados do ID escolhido" << endl;
    cout << "Digite '0' para sair do programa\n" << endl;
  };

    char EscolhaDoUsuario(){
      cout << "Opcao: " ;
      cin >> escolha ;
      return escolha ;
    };
};

int main(){
  MenuDoBancoDeDadosNoConsole menu;
  BDPessoa bdpessoa;
  BDFisica bdfisica;
  BDAluno bdaluno;
  BDJuridica bdjuridica;
  Arquivo arquivo;

  cout << "\nBem vindo ao Banco de Dados!" << endl;

  while(true){
    menu.MostrarMenu();
    switch(menu.EscolhaDoUsuario()){
      case 'p':case 'P': bdpessoa.ArquivarPessoa(bdpessoa.CadastroPessoa()); break;
      case 'f':case 'F': bdfisica.ArquivarFisica(bdfisica.CadastroFisica()); break;
      case 'j':case 'J': bdjuridica.ArquivarJuridica(bdjuridica.CadastroJuridica()); break;
      case 'a':case 'A': bdaluno.ArquivarAluno(bdaluno.CadastroAluno()); break;
      case 'i':case 'I': arquivo.ImprimirOsDadosDaPessoaNoConsole(arquivo.ProcuraDadosNoArquivoPessoa(arquivo.FormataId())); break;
      case '0': return 0;
   
    }
  }

  cout << "Ultimo id -> " << arquivo.GerarId() << endl;
}
