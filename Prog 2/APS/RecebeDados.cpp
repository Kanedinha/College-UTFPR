#include "RecebeDados.h"

using namespace std;

int RecebeDados:: RecebeIdade(){
	int idade;
	cout << "Digite sua idade: ";
	cin >> idade;
	return idade;
};

string RecebeDados:: RecebeAtributoString(string atributo){
	string aux;
	cout << "Digite seu " << atributo << ": ";
	getline(cin>>ws, aux);
	return aux;
};

Fisica RecebeDados:: RecebeAtributoFisica(){
	Fisica* fisica = new Fisica();
	fisica->setNome(RecebeAtributoString("nome"));
	fisica->setCpf(VerificaCpf());
	fisica->setIdade(RecebeIdade());
	return *fisica;
};

Aluno RecebeDados:: RecebeAtributoAluno(){
	Aluno* aluno = new Aluno();
	aluno->setNome(RecebeAtributoString("nome"));
	aluno->setCpf(VerificaCpf());
	aluno->setIdade(RecebeIdade());
	
	aluno->setFaculdade(RecebeAtributoString("faculdade"));
	aluno->setCurso(RecebeAtributoString("curso"));
	return *aluno;
};

Juridica RecebeDados:: RecebeAtributoJuridica(){
	Juridica* juridica = new Juridica();
	juridica->setNome(RecebeAtributoString("nome"));
	juridica->setCnpj(VerificaCnpj());
	return *juridica;
};

string RecebeDados:: VerificaCpf(){
	string cpf;
	cpf = RecebeAtributoString("cpf");
	Fisica* fisica = new Fisica();
	BDFisica bdf;
	fisica = bdf.ProcuraDadosNoArquivoFisica(cpf);
	if(fisica != NULL){
		cout << "\nX     Cpf invalido!     X" << endl;
	    cout << "X    Tente Novamente    X\n" << endl;
		return VerificaCpf();
	}
	else{
			return cpf;
	}
};

string RecebeDados:: VerificaCnpj(){
	string cnpj;
	cnpj = RecebeAtributoString("cnpj");
	Juridica* juridica = new Juridica();
	BDJuridica bdj;
	juridica = bdj.ProcuraDadosNoArquivoJuridica(cnpj);
	if(juridica != NULL){
		cout << "\nX    Cnpj invalido!     X" << endl;
      	cout << "X    Tente Novamente    X\n" << endl;
		return VerificaCnpj();
	}
	else{
			return cnpj;
	}
};

