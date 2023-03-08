#include<stdio.h>
#include<stdlib.h>  //biblioteca do random
#include<time.h>

void main(){
    int i, vet[100];
    srand(time(NULL));
    for(i=0;i<100;i++){
        vet[i]=rand()%200;
        printf("%d\n",vet[i]);
    }
    printf("\n");
}
