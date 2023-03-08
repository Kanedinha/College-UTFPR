#include<stdio.h>

void binario(int num){
	
	//Esse metodo retorna o numero binario ao contrario
	if(num>0){
		//recursividade primeiro retorna o numero ao contrario
		binario(num/2);
		printf("%d",num%2);
	}
}

void main(){
	int num;
	printf("Digite o numero para a convercao em binario: ");
	scanf("%d", &num);
	binario(num);
}