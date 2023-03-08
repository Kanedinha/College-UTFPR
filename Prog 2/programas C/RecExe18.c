#include<stdio.h>

int fatorial(int n){
	if(n <=1 )
		return 1;
	else
		return n *= fatorial(n-1);
}

int super(int n, int x, int y){
	if(x==1)
		return y;
	else{
		y *= fatorial(n);
		return super(n,x-1,y);
	}

}

void main(){
	int n,x,y;
	printf("\nDigite um numero para calcular o fatorial quadruplo: ");
	scanf("%d", &n);
	printf("\nO fatorial quadruplo eh: %d\n", super(n,x=n,y=1));
}