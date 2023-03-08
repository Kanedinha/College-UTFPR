#include<stdio.h>

void bubblesort(int *v, int length){
	int i;
	int j;
	int p1;
	int p2;
	int temp;
	for(i = 0; i < length; i++){
		for(j = 0; j < length; j++){
			p1 = j;
			p2 = j + 1;
			if(v[p1] < v[p2]){
				temp = v[p1];
				v[p1] = v[p2];
				v[p2] = temp;
			}
		}
	}
}

void show(int *v, int length){
	int i;
	for(i = 0; i < length; i++){
		printf("[%d] -> %d\n", i, v[i]);
	}
}

void get(int *RA, int length){
	int i;
	for(i = 0; i < length; i++){
		printf("Digite o %d' RA:\n", i+1);
		scanf("%d", &RA[i]);
	}
}

int main(){
	int tamanho = 5;
	unsigned int RA[tamanho];

	get(RA,tamanho);

	bubblesort(RA,tamanho);

	show(RA,tamanho);

	return 0;
}