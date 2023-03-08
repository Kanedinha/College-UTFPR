#include<stdio.h>
#include<string.h>
#define TAM 15

typedef struct cadastro{
    int conta;
    char nome[50];
    float saldo;
}cadastro;

void criar(cadastro*vet_conta,int qntd_conta){
    int i;
    printf("__Criando_cadastro__\n");
    printf("\nNumero da conta: ");
    scanf("%d",&vet_conta[qntd_conta].conta);
    printf("Nome: ");
    scanf("%s",vet_conta[qntd_conta].nome);
    printf("Saldo: ");
    scanf("%f",&vet_conta[qntd_conta].saldo);
    printf("\nVoce foi cadastrado!\n\n");
}

void visualiza(cadastro*vet_conta,int qntd_conta){
    int i;
    for(i=0;i<qntd_conta;i++){
        printf("cadastro %d:\n\n",i);
        printf("Numero da conta: %d\n",vet_conta[i].conta);
        printf("Nome do cliente: %s\n",vet_conta[i].nome);
        printf("Seu saldo eh de: %.2f\n\n",vet_conta[i].saldo);
    }
}

void exclui(cadastro*vet_conta,int qntd_conta){
    int i, aux;
    printf("qual conta deseja excluir?");
    scanf("%d",&aux);
    for(i=0;i<15;i++){
        if(aux==vet_conta[i].conta){
            vet_conta[i].conta=vet_conta[i+1].conta;
            strcpy(vet_conta[i].nome,vet_conta[i+1].nome);
            vet_conta[i].saldo=vet_conta[i+1].saldo;
        }
    }
    vet_conta[qntd_conta-1].conta=0;
    strcpy(vet_conta[qntd_conta-1].nome," ");
    vet_conta[qntd_conta-1].saldo=0;
    printf("\nconta excluida!\n\n");
}

void main(){
    char menu = '1';
    int qntd_conta=0;
    cadastro vet_conta[TAM];
    while(menu!='4'){
        printf("__Escolha_uma_opcao__\n\nCadastrar conta digite 1\nVisualizar todas as conta digite 2\n");
        printf("Excluir uma conta digite 3\nSair digite 4\n");
        scanf(" %c",&menu);
        switch(menu){
            case '1':
                if(qntd_conta<15){
                    criar(vet_conta,qntd_conta);
                    qntd_conta++;
                    break;
                }
            case '2':
                visualiza(vet_conta,qntd_conta);
                break;
            case '3':
                exclui(vet_conta,qntd_conta);
                qntd_conta--;
                break;
            case '4':
                printf("finalizando programa\n");
                break;
            default:
                printf("opcao invalida\n\n");
        }
    }
}

/*
    for(i=0;i<TAM;i++){
            if(vet_conta[qntd_conta].conta==vet_conta[i].conta && i!=qntd_conta){
                printf("o numero da conta ja existe, digite outro numero");
                scanf("%d",&vet_conta[qntd_conta].conta);
            }
        }
*/
