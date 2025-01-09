
// Função para calcular a média
float calcularMedia(int numeros[], int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += numeros[i];
    }
    return (float) soma / tamanho;
}

// Função para imprimir números acima da média
void imprimirAcimaDaMedia(int numeros[], int tamanho, float media) {
    printf("Numeros acima da media (%.2f):\n", media);
    for (int i = 0; i < tamanho; i++) {
        if (numeros[i] > media) {
            printf("%d ", numeros[i]);
        }
    }
    printf("\n");
}

// Função para imprimir números abaixo da média
void imprimirAbaixoDaMedia(int numeros[], int tamanho, float media) {
    printf("Numeros abaixo da media (%.2f):\n", media);
    for (int i = 0; i < tamanho; i++) {
        if (numeros[i] < media) {
            printf("%d ", numeros[i]);
        }
    }
    printf("\n");
}