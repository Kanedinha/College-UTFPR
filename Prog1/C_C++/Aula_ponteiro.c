#include<stdio.h>

// tipo * variavel
// ponteiro armazena o endereço de memória

void main(){
    /*

    int x = 2;
    int * y = &x;               // ponteiro y recebe o endereço de x
    printf("antes %d\n", x);
    *y = 3;                     // alterando o valor do endereço dentro do ponteiro usa (* nome do ponteiro;)
    printf("dpois %d\n", x);
    printf("dpois %d\n", y);
    printf("dpois %d\n", *y);

    */

    int var[4] = {10,20,30,40};
    int * p;
    int i;
    p = var;
    for(i = 0; i < 4; i++){
        printf("%d \n", *p);
        p++;
    }
}
