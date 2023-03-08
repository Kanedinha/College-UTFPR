#include<stdio.h>
#include<stdlib.h>

// função

int main(){
	int i = 2;
	int tamanho;
	int *fib;
	fib = malloc(sizeof(int));

	printf("Digite quantos termos da sequencia voce quer: ");
	scanf("%d", &tamanho);

	fib = realloc(fib, tamanho);

	fib[0] = 1;
	fib[1] = 1;

	printf("\n%d\t%d\t", fib[0], fib[1]);
	for(i; i < tamanho; i++){
		fib[i] = fib[i-1] + fib[i-2];
		printf("%d\t", fib[i]);
	}

		return 0;
}
