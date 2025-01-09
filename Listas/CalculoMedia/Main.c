#include <stdio.h>
#include <stdlib.h>
#include "Media.h"


int main() {
    int tamanho;

    printf("Quantos numeros você deseja inserir? ");
    scanf("%d", &tamanho);

    int numeros[tamanho];

    // Ler os números do usuário
    printf("Digite os numeros:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &numeros[i]);
    }

    // Calcular a média
    float media = calcularMedia(numeros, tamanho);
    printf("A média é: %.2f\n", media);

    // Imprimir números acima e abaixo da média
    imprimirAcimaDaMedia(numeros, tamanho, media);
    imprimirAbaixoDaMedia(numeros, tamanho, media);

}