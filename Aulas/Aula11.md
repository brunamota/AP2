# Aula 11 - Manipulação de Ponteiros

## Manipulação Básica de Ponteiros

### Atribuição e Dereferenciamento

Os ponteiros podem ser atribuídos a endereços e usados para acessar ou modificar valores. O operador `*` é utilizado para dereferenciar, ou seja, acessar o valor que o ponteiro aponta.

#### Exemplo:

```c
#include <stdio.h>

int main() {
    int a = 10;
    int *p = &a; // p aponta para a

    printf("Valor de a: %d\n", *p); // Dereferenciamento
    *p = 20; // Modifica o valor de a através do ponteiro
    printf("Novo valor de a: %d\n", a); // Imprime 20

    return 0;
}
```

## Aritmética de Ponteiros

A aritmética de ponteiros permite que você manipule endereços de memória. Isso é útil, especialmente ao trabalhar com arrays.

### Incremento e Decremento de Ponteiros

Quando você incrementa um ponteiro, ele se move para o próximo elemento do tipo que ele aponta. Por exemplo, se `p` é um ponteiro para um `int`, `p++` move o ponteiro para o próximo `int` na memória.

#### Exemplo:

```c
#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40};
    int *p = arr; // p aponta para o primeiro elemento do array

    printf("Elementos do array usando ponteiros:\n");
    for (int i = 0; i < 4; i++) {
        printf("%d ", *p); // Imprime o valor apontado
        p++; // Move para o próximo elemento
    }
    printf("\n");

    return 0;
}
```

## 3. Ponteiros e Arrays

Ponteiros e arrays estão intimamente relacionados. O nome do array pode ser tratado como um ponteiro para o primeiro elemento.

### Acesso a Elementos de um Array

Você pode acessar elementos de um array usando ponteiros.

#### Exemplo:

```c
#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int *p = arr; // p aponta para arr[0]

    printf("Acesso aos elementos do array utilizando ponteiros:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(p + i)); // Acesso usando aritmética de ponteiros
    }
    printf("\n");

    return 0;
}
```

## Alocação Dinâmica de Memória

A alocação dinâmica permite que você reserve memória durante a execução do programa. As funções `malloc`, `calloc`, `realloc` e `free` são usadas para gerenciar memória dinâmica.

### Usando `malloc`

A função `malloc` aloca um bloco de memória do tamanho especificado e retorna um ponteiro para o primeiro byte.

#### Exemplo:

```c
#include <stdio.h>
#include <stdlib.h> // Para malloc e free

int main() {
    int *p;
    int n;

    printf("Digite o número de elementos: ");
    scanf("%d", &n);

    // Aloca memória para n inteiros
    p = (int *)malloc(n * sizeof(int));

    if (p == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1; // Sai do programa se a alocação falhar
    }

    // Inicializa e imprime os elementos
    for (int i = 0; i < n; i++) {
        p[i] = i + 1; // Inicializa
        printf("%d ", p[i]); // Imprime
    }

    // Libera a memória alocada
    free(p);

    return 0;
}
```

### Usando `calloc`

A função `calloc` também aloca memória, mas inicializa todos os bytes a zero.

#### Exemplo:

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p;
    int n;

    printf("Digite o número de elementos: ");
    scanf("%d", &n);

    // Aloca memória para n inteiros e inicializa a zero
    p = (int *)calloc(n, sizeof(int));

    if (p == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Imprime os elementos (todos devem ser zero)
    for (int i = 0; i < n; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");

    // Libera a memória alocada
    free(p);

    return 0;
}
```
