#include "ImprimiDados.h"

using namespace std;

void ImprimiDados:: ImprimirDadosFisica(Fisica* fisica){
	cout << "------------------- Seus dados --------------------" << endl;
	
	ImprimirDadosPessoa(fisica->getId());
	cout << "\nCpf: " << fisica->getCpf();
	cout << "\nIdade: " << fisica->getIdade();
	ImprimirDadosAluno(fisica->getId());
};

void ImprimiDados:: ImprimirDadosPessoa(int id){
	BDPessoa bdp;
	Pessoa* pessoa = new Pessoa(); 
	pessoa = bdp.ProcuraDadosNoArquivoPessoa(id);
	cout << "\nNome: " << pessoa->getNome();
};

void ImprimiDados:: ImprimirDadosAluno(int id){
	BDAluno bda;
	Aluno* aluno = new Aluno();
	aluno = bda.ProcuraDadosNoArquivoAluno(id,aluno);
	if(aluno != NULL){
		cout << "\nFaculdade: " << aluno->getFaculdade();
		cout << "\nCurso: " << aluno->getCurso() << endl;
	}
};

void ImprimiDados:: ImprimirDadosJuridica(Juridica* juridica){
	cout << "------------------- Seus dados --------------------" << endl;
	ImprimirDadosPessoa(juridica->getId());
	cout << "\nCnpj: " << juridica->getCnpj() << endl;   
};

void ImprimiDados:: ImprimirDados(){
	BDPessoa bdp;
	MenuDoBancoDeDadosNoConsole menu;
	ImprimiDados dados;

	menu.MostrarEscolhaDePesquisa();
	switch (menu.EscolhaDoUsuario()){
		case '1':{
			RecebeDados cpf;
			BDFisica bdf;
			Fisica * f = new Fisica();
			f = bdf.ProcuraDadosNoArquivoFisica(cpf.RecebeAtributoString("Cpf"));
			if(f!=NULL){
				Pessoa * pessoa = new Pessoa();
				pessoa = bdp.ProcuraDadosNoArquivoPessoa(f->getId());
				f->setNome(pessoa->getNome());
				dados.ImprimirDadosFisica(f);
				menu.OpcaoDeRemoverOuAlterarCpf(f);
			}
			else{

				cout << "\n---------------------------------------------------" << endl;
				cout << "Nada foi encontrado!" << endl;
				cout << "Verifique se o cpf inserido esta correto." << endl;
				cout << "---------------------------------------------------\n" << endl;
			}
			break;
		}
		case '2':{
			RecebeDados cnpj;
			BDJuridica bdj;
			Juridica* j = new Juridica();
			j = bdj.ProcuraDadosNoArquivoJuridica(cnpj.RecebeAtributoString("Cnpj"));
			if(j!=NULL){
				Pessoa * pessoa = new Pessoa();
				pessoa = bdp.ProcuraDadosNoArquivoPessoa(j->getId());
				j->setNome(pessoa->getNome());
				dados.ImprimirDadosJuridica(j);
				menu.OpcaoDeRemoverOuAlterarCnpj(j);
			}  
			else{	
				cout << "\n---------------------------------------------------" << endl;
				cout << "Nada foi encontrado!" << endl;
				cout << "Verifique se o cpf inserido esta correto." << endl;
				cout << "---------------------------------------------------\n" << endl;
			}
			break;
		}}
	};
