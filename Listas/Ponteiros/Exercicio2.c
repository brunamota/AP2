#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Digite o número de elementos: ");
    scanf("%d", &n);

    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        array[i] = i + 1; // Preenche o array com valores de 1 a n
    }

    printf("Valores do array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array); // Libera a memória alocada
    return 0;
}
