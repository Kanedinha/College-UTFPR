#include<stdio.h>
#include<stdlib.h>

void show(int *v, int length){
	for(int i = 0; i < length; i++)
		printf("v[%d] -> %d\n", i, v[i]);
	printf("\n");
}

void quick(int *v, int begin, int end){
	int pivo = v[(end + begin)/2];
	int i = begin;
	int j = end;

	while( i <= j){
		while(v[i] < pivo && i < end)
			i++;
		while(v[j] > pivo && j > begin)
			j--;
		if(i < j){
			int aux = v[i];
			v[i] = v[j];
			v[j] = aux;
			i++;
			j--;
		}
		else if(i == j){
			i++;
			j--;
		}
		if(begin < j)
			quick(v, begin, j);
		if(end > i)
			quick(v, i, end);
	}
}

void main(){
	int v[] = {12,26,9,15,19,20};
	int length = sizeof(v)/sizeof(v[0]);

	show(v, length);
	quick(v, 0, length-1);
	show(v, length);


}