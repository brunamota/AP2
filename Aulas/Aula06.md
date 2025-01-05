# Aula 06 - Criação de Funções e Procedimentos

## O que são Funções e Procedimentos?

- **Funções:** Funções são blocos de código que realizam uma tarefa específica e podem retornar um valor. Elas são úteis para reutilizar código e organizar a lógica do programa.

- **Procedimentos:** Procedimentos, por outro lado, são semelhantes às funções, mas não retornam um valor. Eles realizam ações, mas não produzem um resultado que pode ser utilizado diretamente.

- **Diferença:** Em C, a terminologia comum é "funções", pois todas as funções podem ser vistas como procedimentos se não retornarem um valor.

## Criando Funções em C

### Sintaxe de uma Função

A sintaxe para declarar uma função em C é a seguinte:

```c
tipo_retorno nome_da_funcao(parametros) {
    // corpo da função
}
```

- **tipo_retorno**: Tipo de dado que a função vai retornar (por exemplo, `int`, `float`, `void`).
- **nome_da_funcao**: Nome da função, que deve ser único.
- **parametros**: Lista de variáveis que a função pode receber como entrada.

### Exemplo de Função

Vamos criar uma função simples que calcula a soma de dois números.

```c
#include <stdio.h>

// Declaração da função
int soma(int a, int b);

int main() {
    int num1 = 5, num2 = 3;
    int resultado = soma(num1, num2); // Chamada da função

    printf("Soma: %d\n", resultado);
    return 0;
}

// Implementação da função
int soma(int a, int b) {
    return a + b;
}
```

## Parâmetros e Valores de Retorno

-** Parâmetros:** As funções podem receber parâmetros, que são passados entre parênteses. Os parâmetros podem ser de diferentes tipos (int, float, char, etc.).
- **Valores de Retorno:** As funções podem retornar um valor usando a instrução `return`. O tipo do valor retornado deve corresponder ao tipo especificado na declaração da função.

### Exemplo com Parâmetros e Valores de Retorno

```c
#include <stdio.h>

// Função para calcular a média
float media(float a, float b) {
    return (a + b) / 2;
}

int main() {
    float nota1 = 7.5, nota2 = 9.0;
    float resultado = media(nota1, nota2); // Chamada da função

    printf("Média: %.2f\n", resultado);
    return 0;
}
```

## Boas Práticas na Criação de Funções

1. **Nome Descritivo:** Dê nomes descritivos às funções que indiquem claramente o que elas fazem. Por exemplo, use `calcularMedia` em vez de `func1`.
2. **Tamanho da Função:** Mantenha as funções curtas e focadas em uma única tarefa. Isso melhora a legibilidade e facilita a manutenção.
3. **Documentação:** Comente seu código e documente suas funções, explicando o que elas fazem, os parâmetros que recebem e os valores que retornam.
4. **Evite Efeitos Colaterais:** Minimize efeitos colaterais, ou seja, evite que funções alterem variáveis globais ou parâmetros. Prefira retornar valores em vez de modificar diretamente.
