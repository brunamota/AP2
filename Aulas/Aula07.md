# Aula 07 - Funções Recursivas: Conceitos e Exemplos

## O que é Recursão?

Recursão é uma técnica de programação onde uma função chama a si mesma para resolver um problema. Essa abordagem é útil para resolver problemas que podem ser divididos em subproblemas menores e semelhantes.

### Estrutura de uma Função Recursiva

Uma função recursiva geralmente tem duas partes:

1. **Caso Base**: A condição que interrompe a recursão e evita chamadas infinitas.
2. **Caso Recursivo**: A chamada à função que divide o problema em subproblemas menores.

## Criando Funções Recursivas em C

### Exemplo: Fatorial

Uma função recursiva clássica é a que calcula o fatorial de um número. O fatorial de um número `n` (denotado como `n!`) é o produto de todos os números inteiros de 1 a `n`.

#### Definição Recursiva do Fatorial:

- Caso Base: `0! = 1`
- Caso Recursivo: `n! = n * (n - 1)!`

### Implementação em C

```c
#include <stdio.h>

// Função recursiva para calcular o fatorial
int fatorial(int n) {
    // Caso base
    if (n == 0) {
        return 1;
    }
    // Caso recursivo
    return n * fatorial(n - 1);
}

int main() {
    int numero = 5;
    printf("Fatorial de %d: %d\n", numero, fatorial(numero));
    return 0;
}
```

## Exemplo: Sequência de Fibonacci

A sequência de Fibonacci é outra aplicação clássica de recursão. Os números de Fibonacci são definidos como:

- Caso Base: `F(0) = 0`, `F(1) = 1`
- Caso Recursivo: `F(n) = F(n - 1) + F(n - 2)`

### Implementação em C

```c
#include <stdio.h>

// Função recursiva para calcular o n-ésimo número de Fibonacci
int fibonacci(int n) {
    // Casos base
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    // Caso recursivo
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int numero = 6;
    printf("Fibonacci de %d: %d\n", numero, fibonacci(numero));
    return 0;
}
```

## Considerações sobre Recursão

### Vantagens

- **Simplicidade**: A recursão pode tornar o código mais simples e mais fácil de entender, especialmente para problemas que naturalmente se dividem em subproblemas.

### Desvantagens

- **Desempenho**: Funções recursivas podem ser menos eficientes em comparação com suas contrapartes iterativas, especialmente se não forem otimizadas (por exemplo, usando memoização).
- **Uso de Memória**: Cada chamada recursiva adiciona uma nova camada à pilha de chamadas, o que pode levar a um estouro de pilha se a profundidade da recursão for muito grande.
