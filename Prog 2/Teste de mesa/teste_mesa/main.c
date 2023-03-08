#include <stdio.h>

void mergeSort(int *v, int length){
  if(length<2) // Condição de parada da recursão
    return;

  // 1o Divide as partições
  int middle = length/2;

  // Ordena as partes
  mergeSort(v, middle);
  mergeSort(&v[middle], length - middle);

  // Merge as partes ### ACHE O ERRO!!!
  int temp[length];
  int dedo1 = 0;
  int dedo2 = middle;
  for(int dedoPe = 0; dedoPe < length; dedoPe++){
     if(v[dedo1] < v[dedo2]){
     	temp[dedoPe] = v[dedo1];
     	dedo1++;
      printf("passei aqui 1\n");
     }else{
        temp[dedoPe] = v[dedo2];
        dedo2++;
        printf("passei aqui 2\n");
     }
  }

  for(int i = 0; i < length; i++){
    v[i] = temp[i];
  }
}

void show(int *v, int length){
  int i = 0;
  for(;i<length;i++)
     printf("[%d]->%d\n", i, v[i]);
}

int main(){
  int vLength = 6;
  int v[6] = {1,11,5,0,3,2};
  show(v, vLength);

  mergeSort(v, vLength);
  show(v, vLength);

  return 0;
}
