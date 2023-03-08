#ifndef MenuDoBancoDeDadosNoConsole
#define MenuDoBancoDeDadosNoConsole

// BY: Emerson Kaneda
// Este header contém um método chamado MostrarMenu()
// e um método chamado EscolhaDoUsuario()
//
// Função do método MostrarMenu():
//  
// Exibi um menu no console para o usuário
//
// Função do método EscolhaDoUsuario():
//
// Receba a escolha do usuário e retorna um tipo char
//
// Cabeçalho
class MenuDoBancoDeDadosNoConsole{
  private:
  	char escolha;
  public:
  	void MostrarMenu();

  	char EscolhaDoUsuario();

};

#endif