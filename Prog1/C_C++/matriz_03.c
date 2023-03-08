#include <stdio.h>
#define TAM 4
#define TAM1 7

void main (){
    int mat  [TAM][TAM1];
    int linha, coluna, lin_menor = 0, col_maior = 0, aux, i;
    for (linha = 0; linha < TAM; linha++){
        for (coluna = 0; coluna < TAM1; coluna++){
            printf ("DIGITE O VALOR DA POSICAO [%d][%d]: ", linha+1, coluna+1);
            scanf ("%d", &mat[linha][coluna]);
        }
    }
    for (linha = 0; linha < TAM; linha++){
        for (coluna = 0; coluna < TAM1; coluna++){
            printf ("%d\t",mat[linha][coluna]);
        }
        printf("\n");
    }
    for (linha = 0; linha < TAM; linha++){
        for (coluna = 0; coluna < TAM1; coluna++){
            if(mat[linha][coluna]<aux){
                aux = mat[linha][coluna];
                i = linha;
            }
        }
    }
    for(coluna = 0; coluna < TAM1; coluna++){
        if(mat[i][coluna]>aux){
            aux = mat[i][coluna];
        }
    }
    printf("\no termo MINMAX eh: %d",aux);
}
