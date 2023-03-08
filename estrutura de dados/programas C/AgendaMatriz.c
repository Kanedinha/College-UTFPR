#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void menu(){
	printf("_________  Menu  _________\n");
	printf("Listar todos - 1\n");
	printf("Procurar - 2\n");	
	printf("Atualizar - 3\n");	
	printf("Sair - 0\n");
}

void listarAluno(int aluno, char agenda[][3][100]){

	printf("Nome: %s\n", agenda[aluno][0]);
	printf("RA: %s\n", agenda[aluno][1]);
	printf("Telefone: %s\n", agenda[aluno][2]);

}

void cadastrar(int aluno, char agenda[][3][100]){
	printf("Digite o nome: ");
	scanf(" %[^\n]s ", agenda[aluno][0]);
	printf("Digite o RA: ");
	scanf(" %[^\n]s ", agenda[aluno][1]);
	printf("Digite o numero do telefone com o DDD: ");
	scanf(" %[^\n]s ", agenda[aluno][2]);
}

int procurar(char nome[], char agenda[][3][100]){
	int i = 0;
	for(i; i < 10; i++){
		if(strcmp(nome, agenda[i][0]) == 0){
			return i;
		}
	}
	return -1;
}

int main(){

	char agenda[10][3][100];
	char busca[100];
	char escolha;
	int i = 0;

	printf("___________________________________________________\n");
	for(i; i < 10; i ++){
		cadastrar(i, agenda);
		printf("___________________________________________________\n");
	}

	while(1){
		menu();
		printf("\nDigite sua escolha: ");
		scanf(" %c", &escolha);
		switch(escolha){
			case '1':
			
			printf("___________________________________________________\n");
			for(i = 0; i < 10; i++){
				listarAluno(i,agenda);
				printf("___________________________________________________\n");
			}
			break;

			case '2':
			printf("\n___________________________________________________\n");
			printf("Nome para a busca: ");
			scanf("%s", busca);
			i = procurar(busca, agenda);
			if(i == -1){
				printf("Nao foi possivel encontrar o aluno\n");
				printf("Tente novamente\n");
				printf("___________________________________________________\n");
			}
			else{
				listarAluno(i, agenda);
				printf("___________________________________________________\n");
			}
			break;

			case '3': 
			printf("___________________________________________________\n");
			printf("Nome do aluno para alterar o telefone: ");
			scanf("%s", busca);
			i = procurar(busca, agenda);
			if(i == -1){
				printf("\nNao foi possivel encontrar o aluno\n");
				printf("Tente novamente\n");
				printf("___________________________________________________\n");
			}
			else{
				printf("___________________________________________________\n");
				listarAluno(i, agenda);
				printf("___________________________________________________\n");
				printf("Digite o novo numero: ");
				scanf("%s", agenda[i][2]);
				printf("\nAlteracao realizada com sucesso");
				printf("___________________________________________________\n");
			}
			break;

			case '0':
			
			return 0;

			default:

			printf("X X X X X X X X X X X X\n");
			printf("X    Opcao invalida   X\n");
			printf("X X X X X X X X X X X X\n");

			break;
		}
	}
	return 0;	
}