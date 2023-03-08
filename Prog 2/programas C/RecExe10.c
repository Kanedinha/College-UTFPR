#include<stdio.h>

int verifica(int n, int k, int qnt){
	if(n%10 == k){
		qnt++;
		return verifica(n/10,k,qnt);
	}
	else if(n/10 == 0)
		return qnt; 
	else
		return verifica(n/10,k,qnt);
}

void main(){
	int n, k, qnt=0;
	printf("\nDigite numeros: ");
	scanf("%d", &n);
	printf("Qual numero deseja achar: ");
	scanf("%d", &k);
	printf("O numero %d aparece: %d \n", k, verifica(n,k,qnt));
}
