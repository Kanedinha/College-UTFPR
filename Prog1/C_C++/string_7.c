#include<stdio.h>
#include<string.h>
void criptografia(char*str){
    int i;
    for(i=0;i<strlen(str);i++){
        switch(str[i]){
            case 'x':
                str[i]='a';
                break;
            case 'y':
                str[i]='b';
                break;
            case 'z':
                str[i]='c';
                break;
            case ' ':
                str[i]=' ';
                break;
            default:
                str[i]+=-2;
        }
    }
}
void main(){
    char str[100];
    puts("digite uma palavra");
    scanf("%[^\n]s", str);
    criptografia(str);
    puts("\nsua criptografia esta pronta");
    printf("\n%s\n",str);
}
