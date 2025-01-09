#include <stdio.h>
#include "Media.h"

int main() {
    int tamanho;

    printf("Digite o tamanho do arquivo: ");
    scanf("%d", &tamanho);

    int numeros[tamanho];
    for (int i = 0; i < tamanho; i++) {
        printf("Digite um numero: ");
        scanf("%d", &numeros[i]);
    }

    float media = calcularMedia(numeros, tamanho);
    printf("Media: %.2f\n", media);

    imprimirAcimaDaMedia(numeros, tamanho, calcularMedia(numeros, tamanho));
    imprimirAbaixoDaMedia(numeros, tamanho, media);
}