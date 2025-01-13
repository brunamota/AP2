#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    // Passo 1: Peça ao usuário para inserir o número de elementos
    printf("Digite o número de elementos que deseja armazenar: ");
    scanf("%d", &n);

    // Passo 2: Alocar memória dinamicamente para o array usando malloc
    int *ptr = (int *)malloc(n * sizeof(int));

    // Verifique se a alocação foi bem-sucedida
    if (ptr == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Passo 3: Use um loop para ler os números inteiros do usuário
    printf("Digite %d números inteiros:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &ptr[i]); // Armazena o valor no array usando o ponteiro
    }

    // Passo 4: Exiba os números armazenados
    printf("Os números digitados foram:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", ptr[i]); // Acessando os valores através do ponteiro
    }
    printf("\n");

    // Libere a memória alocada
    free(ptr);

    return 0;
}
