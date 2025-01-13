#include <stdio.h>
#include <stdlib.h>

int fatorial(int n) {
    if (n == 0) {
        return 1; // Base da recursão
    }
    return n * fatorial(n - 1); // Chamada recursiva
}

int main() {
    int numero;
    printf("Digite um número: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("Fatorial de número negativo não é definido.\n");
    } else {
        printf("Fatorial de %d é: %d\n", numero, fatorial(numero));
    }

    return 0;
}
