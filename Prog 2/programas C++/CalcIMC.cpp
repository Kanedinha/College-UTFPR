#include<stdio.h>

// Classe pessoa
struct pessoa{	
	float peso;
	float altura;
	// não é permitido esse uso, pois inicializa a variável com lixo de memória
	// float imc = peso / altura*altura

	float CalcIMC(){						// A função é um comportamento da classe
		return peso / ( altura * altura );	// As variáveis estão juntas com a função
	};

	//MÉTODO NORMAL:
	//tipo retorno, nome método, (argumentos){implementação};

	//MÉTODO CONSTRUTOR:
	pessoa(){
		printf("nhaaaaaaaa\n");
	};
	~pessoa(){
		printf("vlw flw\n");
	};
};


int main(){
	
	// Declarando uma variável do tipo pessoa com nome p
	struct pessoa *p;
	p = new pessoa();
	// ou struct pessoa p;
	// O .(ponto) siginifica o deslocamento na memória 
	// p -> $0   p.peso mesma coisa que p.desloque(0)
	// p -> $0	 p.altura mesma coisa que p.desloque(4)
	p->peso = 80;
	p->altura = 1.8;

	float imc = p->CalcIMC();

	printf("%.2f\n", imc);

	delete p;

	return 0;
}