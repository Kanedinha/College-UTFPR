/*escreva uma função que implemente um vetor e que ordene os elementos*/

#include<stdio.h>

void bubblesort(int *v, int length){
	for(int i = 0; i < length; i++){
		for(int j = 0; j < length; j++){
			int p1 = j;
			int p2 = j + 1;
			if(v[p1] < v[p2]){
				int temp = v[p1];
				v[p1] = v[p2];
				v[p2] = temp;
			}
		}
	}
}

void show(int *v, int length){
	for(int i = 0; i < length; i++){
		printf("[%d] -> %d\n", i, v[i]);
	}
}

void main(){
	int v[6] = {1,11,5,0,3,2};
	int length = 6;
	bubblesort(v, length);
	show(v, length);
}