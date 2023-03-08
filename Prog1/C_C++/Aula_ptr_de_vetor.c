#include<stdio.h>
#include<stdlib.h>

void main(){
    int * ptr;
    ptr = (int*)malloc(12*size (int));      //alguns compiladores tem tamanhos de bytes diferentes, por isso se usa sizeof * (tipo)
    ptr[0]=10;
    ptr[1]=20;
}
