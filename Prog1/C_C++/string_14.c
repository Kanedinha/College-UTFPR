#include<stdio.h>
#include<string.h>

void troca(char*palavra,char L1, char L2){
    int i;
    for(i=0;i<strlen(palavra);i++){
        if(palavra[i]==L1)
            palavra[i]=L2;
    }
}

void main(){
    char palavra[50], L1, L2;
    printf("digite uma palavra: ");
    scanf("%[^\n]s",palavra);
    printf("qual letra sera trocada: ");
    scanf(" %c",&L1);
    printf("qual letra entrara no lugar: ");
    scanf(" %c",&L2);
    troca(palavra,L1,L2);
    printf("sua palavra ficou dessa maneira:\n");
    printf("%s",palavra);
}
