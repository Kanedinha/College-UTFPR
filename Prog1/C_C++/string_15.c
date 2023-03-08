#include<stdio.h>
#include<string.h>

void um(char*s_1){
    printf("\ndigite a nova palavra: ");
    scanf("%s",s_1);
    printf("a nova palavra eh: %s\n",s_1);
}

int dois(char*s_1){
    int tam = strlen(s_1);
    return tam;
}

int tres(char*s_1,char*s_2){
    int comp;
    printf("digite a palavra a ser comparada: ");
    scanf("%s",s_2);
    return comp = strcmp(s_1,s_2);
}

void quatro(char*s_1,char*s_2){
    printf("digite a palavra que sera concatenada");
    scanf("%s",s_2);
    strcat(s_1,s_2);
}

void cinco(char*s_1,char*s_2){
    int i, tam = strlen(s_1);
    char c;
    strcpy(s_2,s_1);
    for(i=0;i<tam/2;i++){
        c = s_2[i];
        s_2[i]=s_2[tam-i];
        s_2[tam-i]=c;
    }
}

int seis(char*s_1){
    int i, qntd=0;
    char letra;
    printf("digite a letra: ");
    scanf(" %c",&letra);
    for(i=0;i<strlen(s_1);i++);
        if(s_1[i]==letra)
            qntd++;
    return qntd;
}

void sete(char*s_1){
    char c1,c2;
    int i=0, j=1;
    printf("qual letra voce quer substituir: ");
    scanf(" %c", &c1);
    printf("por qual letra: ");
    scanf(" %c", &c2);
    while(j=1){
        if(s_1[i]==c1)
            s_1[i]=c2;
        i++;
    }
}

void oito(char*s_1,char*s_2){

}

void nove(char*s_1,char*s_2){
    int a, b, j=0;
    printf("digite o comeco: ");
    scanf("%d",&a);
    printf("digite o final: ");
    scanf("%d",&b);
    for(a;a<b;a++){
        s_2[j]=s_1[a];
        j++;
    }
    printf("a subpalavra criada eh: %s",s_2);
}

void main(){
    char s_1[20],s_2[20],menu;
    printf("insira uma palavra: ");
    scanf("%s", s_1);
    while(menu!='0'){
        printf("**** Menu ****\n\n");
        printf("1 - inserir uma nova palavra\n2 - tamanho da palavra\n3 - comparar com uma nova palavra\n4 - juntar com outra palavra\n");
        printf("5 - inverter a palavra\n6 - quantas vezes uma letra se repete\n7 - trocar uma letra por outra\n8 - procurar uma subpalavra\n9 - criar subpalavra\n0 - para sair do programa\n\n");
        scanf(" %c",&menu);
        switch(menu){
            case '1':
                um(s_1);
                break;
            case '2':
                printf("a tamanho da palavra eh: %d\n\n", dois(s_1));
                break;
            case '3':
                printf("a comparacao: %d\n\n",tres(s_1,s_2));
                break;
            case '4':
                quatro(s_1,s_2);
                break;
            case '5':
                cinco(s_1,s_2);
                break;
            case '6':
                seis(s_1);
                break;
            case '7':
                sete(s_1);
                break;
            case '9':
                nove(s_1,s_2);
                break;
            case '0':
                break;
            default:
                printf("opcao invalida\n");
        }
    }
}
