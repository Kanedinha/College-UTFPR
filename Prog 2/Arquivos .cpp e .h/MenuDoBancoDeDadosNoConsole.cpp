#include "MenuDoBancoDeDadosNoConsole.h"

using namespace std;

void MenuDoBancoDeDadosNoConsole:: MostrarMenu(){
	cout << "\nDigite 'F' para cadastrar uma pessoa fisica" << endl;
	cout << "Digite 'J' para cadastrar uma pessoa juridica" << endl;
	cout << "Digite 'A' para cadastrar um aluno" << endl;
	cout << "Ditige 'I' para ver os dados de uma pessoa" << endl;
	cout << "Digite '0' para sair do programa\n" << endl;
};

void MenuDoBancoDeDadosNoConsole:: MostrarEscolhaDePesquisa(){
	cout << "\n---------------------------------------------------" << endl;
	cout << "Deseja procurar por cpf ou cnpj?\n" << endl;
	cout << "Digite 1 para procurar pelo cpf" << endl;
	cout << "Digite 2 para procurar pelo cnpj\n" << endl;
};

char MenuDoBancoDeDadosNoConsole:: EscolhaDoUsuario(){
	cout << "Opcao: " ;
	cin >> escolha ;
	return escolha ;
};

void MenuDoBancoDeDadosNoConsole:: MensagemOpcaoInvalida(){
	cout << "\nXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	cout << "X    Opcao invalida!    X" << endl;
	cout << "X    Tente Novamente    X" << endl;
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
}

char MenuDoBancoDeDadosNoConsole:: getEscolha(){ return this->escolha; };

void MenuDoBancoDeDadosNoConsole:: OpcaoDeRemoverOuAlterarCpf(Fisica* fisica){
	BDAluno bda;

	cout << "\n---------------------------------------------------\n" << endl;
	cout << "Deseja fazer alguma operacao?" << endl;
	cout << "Digite 1 para Remover" << endl;
	cout << "Digite 2 para Alterar" << endl;
	cout << "Digite outra coisa se nao quiser fazer nada\n" << endl;

	switch(EscolhaDoUsuario()){
		case '0':
		break;
		case '1':
		bda.RemoverAluno(fisica);
		cout << "\nUsuario Removido com sucesso!" << endl;
		cout << "---------------------------------------------------" << endl;
		break;
		case '2':
		Aluno* aluno = new Aluno();
		aluno->setId(fisica->getId());
		aluno = bda.ProcuraDadosNoArquivoAluno(aluno->getId(), aluno);
		if(aluno == NULL){
			AlterarFisica(fisica);
		}
		else{
			aluno->setNome(fisica->getNome());
			aluno->setCpf(fisica->getCpf());
			aluno->setIdade(fisica->getIdade());
			AlterarAluno(aluno);
			cout << "\nAlteracao feita com sucesso!" << endl;
			cout << "---------------------------------------------------" << endl;
		}
		break;
	}
};

void MenuDoBancoDeDadosNoConsole:: OpcaoDeRemoverOuAlterarCnpj(Juridica* juridica){
	BDJuridica bdj;
	
	cout << "\n---------------------------------------------------\n" << endl;
	cout << "Deseja fazer alguma operacao?" << endl;
	cout << "Digite 1 para Remover" << endl;
	cout << "Digite 2 para Alterar" << endl;
	cout << "Digite outra coisa se nao quiser fazer nada\n" << endl;
	
	switch(EscolhaDoUsuario()){
		case '1':
		bdj.RemoverJuridica(juridica);
		cout << "\nUsuario Removido com sucesso!" << endl;
		cout << "---------------------------------------------------" << endl;
		break;
		case '2':
		AlterarJuridca(juridica);
		cout << "\nAlteracao feita com sucesso!" << endl;
		cout << "---------------------------------------------------" << endl;
		break;
		case '0':
		break;
	}
};

void MenuDoBancoDeDadosNoConsole:: AlterarAluno(Aluno* a_antigo){
	BDAluno bda;
	Aluno* aluno = new Aluno();
	aluno = a_antigo;
	aluno->setId(a_antigo->getId());
	
	cout << "\n---------------------------------------------------\n" << endl;
	cout << "Digite 1 para alterar o nome" << endl;
	cout << "Digite 2 para alterar a idade" << endl;
	cout << "Digite 3 para alterar o cpf" << endl;
	cout << "Digite 4 para alterar a faculdade" << endl;
	cout << "Digite 5 para alterar o curso" << endl;
	cout << "Digite outra coisa se nao quiser fazer nada\n" << endl;
	
	switch(EscolhaDoUsuario()){
		case '1':
		aluno->setNome(dados.RecebeAtributoString("nome"));
		bda.AlteraAluno(a_antigo, aluno);
		break;
		case '2':
		aluno->setIdade(dados.RecebeIdade());
		bda.AlteraAluno(a_antigo, aluno);
		break;
		case '3':
		aluno->setCpf(dados.VerificaCpf());
		bda.AlteraAluno(a_antigo, aluno);
		break;
		case '4':
		aluno->setFaculdade(dados.RecebeAtributoString("faculdade"));
		bda.AlteraAluno(a_antigo, aluno);
		break;
		case '5':
		aluno->setCurso(dados.RecebeAtributoString("curso"));
		bda.AlteraAluno(a_antigo, aluno);
		break;
	}
};

void MenuDoBancoDeDadosNoConsole:: AlterarFisica(Fisica* f_antigo){
	BDFisica bdf;
	Fisica* fisica = new Fisica();
	fisica = f_antigo;
	fisica->setId(f_antigo->getId());
	
	cout << "\n---------------------------------------------------\n" << endl;
	cout << "Digite 1 para alterar o nome" << endl;
	cout << "Digite 2 para alterar a idade" << endl;
	cout << "Digite 3 para alterar o cpf" << endl;
	cout << "Digite outra coisa se nao quiser fazer nada\n" << endl;
	
	switch(EscolhaDoUsuario()){
		case '1':
		fisica->setNome(dados.RecebeAtributoString("nome"));
		bdf.AlteraFisica(f_antigo, fisica);
		break;
		case '2':
		fisica->setIdade(dados.RecebeIdade());
		bdf.AlteraFisica(f_antigo, fisica);
		break;
		case '3':
		fisica->setCpf(dados.VerificaCpf());
		bdf.AlteraFisica(f_antigo, fisica);
		break;
	}
};

void MenuDoBancoDeDadosNoConsole:: AlterarJuridca(Juridica* j_antigo){
	BDJuridica bdj;
	Juridica* juridica = new Juridica();
	juridica = j_antigo;
	juridica->setId(j_antigo->getId());
	
	cout << "\n---------------------------------------------------\n" << endl;
	cout << "Digite 1 para alterar o nome" << endl;
	cout << "Digite 2 para alterar o cnpj" << endl;
	cout << "Digite outra coisa se nao quiser fazer nada\n" << endl;
	
	switch(EscolhaDoUsuario()){
		case '1':
		juridica->setNome(dados.RecebeAtributoString("nome"));
		bdj.AlteraJuridica(j_antigo, juridica);
		break;
		case '2':
		juridica->setCnpj(dados.VerificaCnpj());
		bdj.AlteraJuridica(j_antigo, juridica);
		break;
	}
};

