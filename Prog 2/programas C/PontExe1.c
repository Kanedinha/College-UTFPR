#include <stdio.h>
void troca ( int *a, int *b)
{
int temp ;
temp = *a;
*a = *b;
*b = temp;/* ******* Falta um comando aqui (nao falta mais!!!)*/
} /* Fim de troca */
int main (void)
{
int x, y;
scanf ("%d %d", &x, &y);
troca (&x, &y);
printf (" Troquei ----> %d %d\n", x, y);
return 0;
}
