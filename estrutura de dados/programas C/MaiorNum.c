#include<stdio.h>
#include<limits.h>
int main()
{
	int maior = INT_MIN;
	int num;
	int i = 0;
	
	for(i = 0; i < 5; i++){
		printf("Digite o %d' valor: ", i+1);
		scanf("%d", &num);
		if(num > maior){
			maior = num;
		}
	}
	printf("O maior valor eh: %d\n", maior);

	return 0;
}