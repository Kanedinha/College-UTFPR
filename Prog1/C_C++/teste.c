/*
#include <stdio.h>
void troca (int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void main (){
    int x, y;
    scanf("%d %d", &x, &y);
    troca(&x, &y);
    printf("Troquei ----> %d %d\n", x, y);
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
int main (void) {
    int i = 10, j = 20;
    int temp;
    int *p1, *p2;
    p1 = &i; /* p1 recebe endereco de i /
    p2 = &j; /* p2 recebe endereco de j /
    temp = *p1; /* conteudo apontado por p1 para temp /
    *p1 = *p2; /* conteudo apontado por p2 para o apontado p1 /
    *p2 = temp; /* conteudo apontado por p1 para p2 / /* O que sera impresso???? /
    printf("%d %d %x\n", i, j);
    return 0;
}
*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main(){
    int i, vet[15];
    srand (time(NULL));
    for(i=0;i<15;i++){
        vet[i] = (rand()%61)-30;
        printf("%d\n", vet[i]);
    }
}
*/

#include<stdio.h>

void main(){
    uint8_t a;
    printf("tamanho: %d\n", sizeof(a));

}



