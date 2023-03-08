#include<stdio.h>

int expo(int n, int k){
	if(k == 0)
		return 1;
	else
		return n *= expo(n,k-1);
}

int hiper(int n){
	if(n == 1)
		return n;
	else{
		return hiper(expo(n-1,n-1))*hiper(expo(n-2,n-2));
	}
}	
void main(){
	int num;
	printf("\nDigite um numero para calcular o hiperfatorial: ");
	scanf("%d", &num);
	printf("\nO resultado eh: %d\n", hiper(num));
}