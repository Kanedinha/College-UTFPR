#include "arquivo.h"

using namespace std;

    void Arquivo:: ImprimirOsDadosDaPessoaNoConsole(string Dados){
      cout << "Dados: \n" << endl; 
      cout << Dados << '\n'<< endl;
    };

    int Arquivo:: GerarId(){
      ofstream escreve_arquivo;
      ifstream ler_arquivo("Id.txt");
      string linha;

      getline(ler_arquivo,linha);
      ler_arquivo.close();

      int id = stoi(linha) + 1;

      escreve_arquivo.open("Id.txt", ofstream::trunc);
      escreve_arquivo << id;
      escreve_arquivo.close();

      return id;
    };
