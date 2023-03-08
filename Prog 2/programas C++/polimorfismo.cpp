#include<iostream>
#include<string>
using namespace std;

class Pessoa{
	public:
		string nome;
		int documento;
	virtual f(){
		printf("Pessoa\n");
	};
};

class Fisica : public Pessoa{
	public:
		string mae;
	f(){
		printf("Fisica\n");
	};
};

class Aluno : public Fisica{
	public:
		string curso;
		string faculdade;
	f(){
		printf("Aluno\n");
	};
};

int main(){
	Pessoa p1, *pp1;
	Fisica f1;
	Aluno a1, *aa1;

	pp1 -> f();

}