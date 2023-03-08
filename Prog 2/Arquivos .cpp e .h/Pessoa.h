#ifndef pessoa_h
#define pessoa_h
#include <iostream>

using namespace std;

class Pessoa{
  private:  
    int id ;
    string nome;

  public:
    
    void setNome(string nome);
    string getNome();

    void setId(int id);
    int getId();

};

#endif