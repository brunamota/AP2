#include <stdio.h>
#include <stdlib.h>

int somaArray(int *ponteiro, int tamanho){
  int soma = 0;
  for(int i = 0; i < tamanho; i++){
    soma += *ponteiro;
    ponteiro++;
  }
  return soma;
}

int main() {
  int *ponteiro;
  int tamanho;
  printf("Digite o tamanho do ponteiro: ");
  scanf("%d", &tamanho);
  ponteiro = (int *)malloc(tamanho * sizeof(int));

  for(int i = 0; i < tamanho; i++){
    printf("Digite o ponteiro[%d]: ", i);
    scanf("%d", &ponteiro[i]);
  }

  printf("Soma: %d", somaArray(ponteiro, tamanho));
}
