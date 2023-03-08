#ifndef aluno_h
#define aluno_h

#include <iostream>
#include "Fisica.h"

using namespace std;

class Aluno : public Fisica{
  private:
    string faculdade;
    string curso;

  public:
  	// define a faculdade
    void setFaculdade(string faculdade);
    // acessa a faculdade
    string getFaculdade();

    // define o curso
    void setCurso(string curso);
    // acessa o curso
    string getCurso();

};

#endif