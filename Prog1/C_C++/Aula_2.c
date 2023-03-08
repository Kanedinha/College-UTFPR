/*****************************************
****NAO APAGAR, EXERCICIO 18 DE STRING****
*****************************************/
#include<stdio.h>
#include<string.h>
void receber(char*str){
    puts("Digite uma palavra");
    scanf("%[^\n]s",str);
}
void vogal(char*str){
    int i;
    for(i=0;i<strlen(str);i++){
        switch(str[i]){
        case 'a':
            str[i]=' ';
            break;
        case 'e':
            str[i]=' ';
            break;
        case 'i':
            str[i]=' ';
            break;
        case 'o':
            str[i]=' ';
            break;
        case 'u':
            str[i]=' ';
            break;
        }
    }
    str[i]='\0';
}
void main(){
    char str[100];
    receber(str);
    vogal(str);
    printf("%s", str);
}
