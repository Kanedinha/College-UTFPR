#include<stdio.h>


void main(){
    int tamanho;
    int vetor[tamanho];

    printf("digite qnts numeros tem\n");
    scanf("%d", &tamanho);

    for(int i = 0; i < tamanho; i++){
        printf("digite o %d numero\n", i+1);
        scanf("%d", vetor[i]);
    }

    for(int i = tamanho-1; i > 0; i--)
        printf("%d \n", vetor[i]);
}
