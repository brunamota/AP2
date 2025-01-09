#include <stdio.h>
#include <stdlib.h>

void calcularQuadrado(int *num) {
    *num = (*num) * (*num);
}

int main() {
    int numero;
    printf("Digite um número: ");
    scanf("%d", &numero);
    calcularQuadrado(&numero);
    printf("O quadrado é: %d\n", numero);
}
