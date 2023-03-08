#include<stdio.h>
#include<string.h>

typedef struct cadastro{
    char nome[50];
    int idade;
    char endereco[50];
    int casa;
}cadastro;

cadastro funcion(){
    int i;
    cadastro nome, idade, casa, var1[2];
    for(i=0;i<2;i++){
        printf("digite seu nome\n");
        scanf("%[^\n]s", var1[i].nome);
        printf("digite sua idade\n");
        scanf("%d", &var1[i].idade);
        printf("digite o numero da sua casa\n");
        scanf("%d", &var1[i].casa);
        printf(" suas informacoes: \n\nnome: %s \nidade: %d \nnumero da casa: %d\n",var1[i].nome,var1[i].idade,var1[i].casa);
    }
}

void main(){
    cadastro nome, idade, casa, var1[2];
    funcion();
}
