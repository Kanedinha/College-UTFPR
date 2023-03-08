#include<stdio.h>

void selectsort(int *v, int length){

	for(int i = 0; i < length - 1; i++){
		int p1 = i;
		for(int j = i + 1; j < length; j++){
			
			int p2 = j;
			if(v[p1] > v[p2]){
				p1 = p2;
			}
		}
		int temp = v[i];
		v[i] = v[p1];
		v[p1] = temp;
	}

}

void show(int *v, int length){
	for(int i = 0; i < length; i++)
		printf("[%d]->%d\n", i, v[i]);
	printf("\n");	
}

void main(){
	int v[10] = {1,11,5,0,3,2,12,10,9,6};
	int length = 10;

	show(v, length);
	selectsort(v, length);
	show(v, length);

}