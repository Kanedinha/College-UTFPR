#include<stdio.h>

void main(){
    char dia1,dia2,dia3;
    printf("digite um dia da semana: ");
    scanf("%s%s%s", dia1,dia2,dia3);
    switch(dia1&&dia2&&dia3){
        case 's'&&'e'&&'g' :
            printf("segunda-feira");
            break;
    }
}
