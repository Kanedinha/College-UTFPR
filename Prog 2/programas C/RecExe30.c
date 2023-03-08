#include<stdio.h>

int acherman(int m, int n){
	if(m < 0 || n < 0)
		return -1;
	if(m == 0)
		return n + 1;
	if(m > 0 && n == 0)
		return acherman(m - 1, 1);
	if(m > 0 && n > 0)
		return acherman(m - 1, acherman(m, n - 1));
}

void main(){
	int n, m;
	printf("Digite o valor de n : ");
	scanf("%d", &n);
	printf("Digite o valor de m : ");
	scanf("%d", &m);
	int aux = acherman(m,n);
	if(aux != -1){
		printf("\nO resultado eh: %d\n", acherman(m,n));
	}
	else{
		printf("Valores invalidos");	
	}
}