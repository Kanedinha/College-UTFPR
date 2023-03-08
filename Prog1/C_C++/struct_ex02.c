#include<stdio.h>
#include<string.h>

typedef struct paciente{
    char nome[50];
    char medico[50];
    char sexo;
    char data[10];
}paciente;

paciente cadastro(paciente*vet,int i){
    printf("Nome: ");
    scanf("%s",vet[i].nome);
    printf("Medico: ");
    scanf("%s",vet[i].medico);
    printf("Data de nascimento: ");
    scanf("%s",vet[i].data);
    printf("Sexo do paciente: ");
    scanf(" %c", &vet[i].sexo);
    printf("\nCadastro feito\n\n");
}

paciente ordem_cadastro(paciente*vet,int i){
    int j;
    for(j = 0 ;j < i ; j++){
        printf("\nCadastro numero: %d\n\n", j+1);
        printf("Nome: %s\n", vet[j].nome);
        printf("Medico: %s\n", vet[j].medico);
        printf("Data de nascimento: %s\n", vet[j].data);
        printf("Sexo do paciente: %c\n", vet[j].sexo);
    }
}

paciente ordem_crescente(paciente*vet,int i){

}

void main(){
    paciente vet[10];
    int i=0;
    char menu;
    while(menu!='7'){
        printf("\n**** Menu ****\n");
        printf("1 - cadastrar paciente \n2 - ordem de cadastro \n3 - ordem crescente \n");
        printf("4 - ordem decrescente \n5 - excluir paciente individualmente \n6 - excluir paciete por medico\n7 - sair do programa\n");
        scanf(" %c",&menu);
        switch(menu){
            case '1':
                cadastro(vet,i);
                i++;
                break;
            case '2':
                ordem_cadastro(vet,i);
                break;
            case '3':

                break;
        }
    }
}
