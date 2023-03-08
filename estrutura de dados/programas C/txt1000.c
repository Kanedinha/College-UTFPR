#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	
	char txt[1000];
	
	int palavras = 0;
	int caractere = 0;
	int frases = 0;
	int i = 0;

	printf("\nDigite um texto: \n");
	scanf(" %[^\n]s  ", txt);

	while(txt[i] != '\0'){
		i++;
		caractere++;
		if(txt[i] == ' ' && txt[i+1] != ' ' && txt[i+1] != '\0'){
			if(i != 0){ 
				palavras++;
			}
		}

		if((txt[i] == '.' && txt[i+1] != '.') || (txt[i] == ';' && txt[i+1] != ';') || (txt[i] == '!' && txt[i+1] != '!') || (txt[i] == '?' && txt[i+1] != '?')){
			frases++;
		}
	}

	printf("caracteres -> %d\n", caractere );
	printf("palavras -> %d\n", palavras + 1);
	printf("frases -> %d\n", frases);

	return 0;
}