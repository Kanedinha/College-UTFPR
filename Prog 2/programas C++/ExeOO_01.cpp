#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Funcionario{
	private:
		string nome;
		float salario;
		string data;
	public:
		void setNome(string nome){ this -> nome = nome; };
		string getNome(){ return this -> nome; };
		void setSalario(float salario){ this -> salario = salario; };
		float getSalario(){ return this -> salario; };
		void setData(string data){ this -> data = data; };
		string getData(){ return this -> data; };
};

class Empresa{
	private:
		string nome;
		int cnpj;
	public:
		void setNome(string nome){ this -> nome = nome; };
		string getNome(){ return this -> nome; };
		void setCnpj(int cnpj){ this -> cnpj = cnpj; };
		int getCnpj(){return this -> cnpj; };
};

int main(){
	Empresa e1;
	Funcionario f1,f2;

	cout << "Nome da Empresa: ";
	cin >> e1.nome;
	cout << "CNPJ da Empresa: ";
	cin >> e1.cnpj;
/*
	cout >> "Nome do Funcionario 1: ";
	cin << f1.nome;
	cout >> "Salario do Funcionario 1: ";
	cin << f1.salario;
	cout >> "Data de admissao (dd/mm/aaaa) : ";
	cin << f1.data;

	cout >> "Nome do Funcionario 2: ";
	cin << f2.nome;
	cout >> "Salario do Funcionario 2: ";
	cin << f2.salario;
	cout >> "Data de admissao (dd/mm/aaaa) : ";
	cin << f2.data;


	*/
}