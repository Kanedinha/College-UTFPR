#include<stdio.h>
#include<stdlib.h>

#define TAM 36

void merge(int *v, int begin, int middle, int end){
	
	int i, j, k;
	int lengthRigth = end - middle;
	int lengthLeft = middle - begin + 1;
	int vLeft[lengthLeft], vRigth[lengthRigth];
	
	for(i = 0; i < lengthLeft; i++)
		vLeft[i] = v[begin + i];
	for(j = 0; j < lengthRigth; j++)
		vRigth[j] = v[middle + 1 + j];

	i = 0;
	j = 0;
	k = begin;

	while( i < lengthLeft && j < lengthRigth){
		if(vLeft[i] <= vRigth[j]){
			v[k] = vLeft[i];
			i++;
		}	
		else{
			v[k] = vRigth[j];
			j++;
		}
		k++;
	}
	while(i < lengthLeft){
		v[k] = vLeft[i];
		i++;
		k++;
	}

	while(j < lengthRigth){
		v[k] = vRigth[j];
		j++;
		k++;
	}
}



void mergesort(int *v, int begin, int end){
	
	if(end < 2)
		return;

	if(begin < end){

		int middle = begin + (end-1)/2;
		
		mergesort(v, begin, middle);
		mergesort(v, middle + 1, end);

		merge(v, begin, middle, end);
	}
	for(int i = 0; i < TAM; i++)
		printf("[%d]->%d\n", i, v[i]);
	printf("\n");
}

void show(int *v, int length){
	for(int i = 0; i < length; i++)
		printf("[%d]->%d\n", i, v[i]);
	printf("\n");	
}

void main(){
	int v[] = {12,26,9,15,19,28,24,20,35,14,25,29,32,36,38,27,19,29,15,34,30,29,23,38,26,29,14,17,10,	21,	31,	11,	19,	20,	25,	23};
	int length = 36;

	show(v, length);
	mergesort(v, 0, length - 1);

	printf("vetor ordenado:\n");
	show(v, length);

}





