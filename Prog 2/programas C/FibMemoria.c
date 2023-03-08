#include <stdio.h>
#include <limits.h>

int fibMem(int n, int * mem){

	int result;

	//fib(n) está na mamoria?
	if(mem[n] != INT_MAX) return mem[n];

	//se nao estiver calcula e memoriza	
	else result = fibMem(n-1,mem) + fibMem(n-2,mem);
		
	mem[n] = result;	//memoriza o resultado
	return result;		//retorna resultado
	
}

int fib(int n){
	
	//cria memoria

	unsigned int mem[n];
	
	mem[0] = 0;
	mem[1] = 1;

	for(int i = 2; i < n; i++){
		mem[i] = INT_MAX;
	}

	fibMem(n - 1, mem);
}

void main(){
	int n;
	printf("digite o n\n");
	scanf("%d", &n);
	printf("\nValor final -> %d\n", fib(n));
}