#include<stdio.h>
#include<string.h>

void ordem(char * str_1, char *str_2){
    int i, j=0;
    char aux, a='a';
    if (strlen(str_1)<=strlen(str_2)){
        for(i=0;i<strlen(str_1);i++){
            if(str_1[i]==a){
                str_2[j]=str_1[i];
                j++;
            }
            a += 1;
        }
        printf ("%s", str_2);
    }
    else if(strlen(str_1)>strlen(str_2)){
        for(i=0;i<strlen(str_2);i++){
            if(str_2[i]==a){
                aux = str_2[i];
                str_2[j]=a;
                str_2[i]=aux;
                j++;
            }
            a += 1;
        }
        printf("\n\n%s",str_2);
    }
}

void main(){
    char str_1[50],str_2[50];
    printf("digite uma cadeia de caracteres: ");
    scanf("%s",str_1);
    printf("digite uma segunda cadeia de caracteres: ");
    scanf("%s",str_2);
    ordem(str_1,str_2);
}
