#include<stdio.h>

int soma(int*v, int tv){
	tv--;
	if(tv<0)
		return v[0];
	else
		return v[tv] += soma(v, tv);
}

void main(){
	int tv = 6;
	int v[] = {0, 1, 5, 4, 8, 9};
	printf("soma: %d", soma(v, tv));
}