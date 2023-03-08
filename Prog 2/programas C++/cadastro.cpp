#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Pessoa{
    private:
    	int id;
    	string nome;
    //	int idade;

    public:

    	int getId(){ return this -> id; };
    	void setId(int Id){ this -> id = id; };

	    string getNome(){ return this -> nome; };
   		void setNome(string nome){ this -> nome = nome; };    

	   	/* int getIdade(){ return this -> idade; };
	    void setIdade(int idade){ 
	    	if(idade > 120) this -> idade = 120; 
	    	else this -> idade = idade;
	    }; */

};

class BDPessoa{

	public:
		void guardar(Pessoa p1){
			ofstream cadastro;
			cadastro.open("cadastro.txt", ios::app);
			cadastro << p1.getId() << ";" << p1.getNome() << ";" << endl;
			cadastro.close();
			//return true;
		};
		/*Pessoa recuperar(int id){
			
			return pessoa;
		};*/
};

class CadastroConsole{
	public:
	int escolha;
	menu(){
		cout << "Escolha sua operacao: " << endl;
		cout << "1 - Cadastrar pessoa " << endl;
		cout << "2 - Ver cadastro " << endl;
		cout << "3 - Sair " << endl;
	};

	cadastroPessoa(Pessoa p1){
	
	};

	

};

int main(){

	Pessoa p1;
	BDPessoa bd;
	CadastroConsole cc;
	int escolha = 0;
	int idaux;
	string nomeaux;
	while(escolha != 3){

		cc.menu();

		cin >> escolha;

		if(escolha == 1){
		
		cout << "Id: " ;
		cin >> idaux ;
		cout << "Nome: " ;
		cin >> nomeaux ;
		p1.setId(idaux);
		p1.setNome(nomeaux);
		bd.guardar(p1);
			
		}
		else if(escolha == 2){
			
		}
		else if(escolha == 3){

		}
		else
			cout << "\nopcao invalida !\n" << endl;
	}
}