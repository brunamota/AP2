#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Digite o número de elementos: ");
    scanf("%d", &n);

    float *array = (float *)calloc(n, sizeof(float));
    if (array == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        array[i] = (float)(i + 1) / 2; // Preenche o array com valores de 0.5, 1.0, 1.5, ...
    }

    printf("Valores do array: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");

    free(array); // Libera a memória alocada
    return 0;
}
