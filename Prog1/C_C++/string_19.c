#include<stdio.h>
#include<string.h>
void main(){
    char data[10];
    int i, aux, dia, mes, ano;
    printf("Digite a data do seu nascimento no formato DD/MM/AAAA: ");
    scanf("%s", data);
    for(i=0;i<10;i++){
        aux = data[i];
        if(aux<47 || aux>57)
            printf("caractere invalido!!\n");
        else{
        aux = 1;
        }
    }
    if(aux==1){
        dia = (data[0]-48)*10 + (data[1]-48);
        mes = (data[3]-48)*10 + (data[4]-48);
        ano = (data[6]-48)*1000 + (data[7]-48)*100 + (data[8]-48)*10 + (data[9]-48);
        printf("dia %d\n",dia);
        printf("mes %d\n",mes);
        printf("ano %d\n",ano);
    }
}
