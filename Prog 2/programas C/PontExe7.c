#include<stdlib.h>
#include<stdio.h>
int main (void)
{
	int i, n, * pvetor, qnt=0, aux;
	float media ;
	scanf ("%d", &n);
	pvetor = ( int *) malloc (n*sizeof ( int ));
	if (!pvetor ){
		puts ("Sem memória .");
		return 1;
	}
	for (i = 0; i < n; i++){
		scanf ("%d", pvetor + i);
	}
	media = 0.0;
	for (i = 0; i < n; i++){
		media += *( pvetor + i);
	}
	media = media/n;
	aux = media;
	for(i = 0; i < n; i++){
		if((pvetor + i)>aux)
			qnt++;
	}
	printf ("%.2f\n", media );
	printf("%d\n", qnt);
	free ( pvetor );
	return 0;
}