float calcularMedia(int numeros[], int tamanho) {
    float soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += numeros[i];
    }
    return (float) soma / tamanho;
}

void imprimirAcimaDaMedia(int numeros[], int tamanho, float media) {
    printf("Numeros digitados que estao acima da media: ");
    for (int i = 0; i < tamanho; i++) {
        if (numeros[i] > media) {
            printf("%d ", numeros[i]);
        }
    }
    printf("\n");
}

void imprimirAbaixoDaMedia(int numeros[], int tamanho, float media) {
    printf("Numeros digitados que estao abaixo da media: ");
    for (int i = 0; i < tamanho; i++) {
        if (numeros[i] < media) {
            printf("%d ", numeros[i]);
        }
    }
    printf("\n");
}