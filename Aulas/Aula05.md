# Aula 05 - Introdução à Programação Modular em C e Importância

## O que é Programação Modular?

Programação modular é uma abordagem que divide um programa em partes menores e independentes, chamadas de módulos. Cada módulo é responsável por uma parte específica da funcionalidade do programa.

### Características da Programação Modular

- **Divisão de Tarefas**: O programa é dividido em módulos que podem ser desenvolvidos, testados e mantidos separadamente.
- **Reutilização de Código**: Módulos podem ser reutilizados em diferentes partes do programa ou em projetos diferentes.
- **Facilidade de Manutenção**: Alterações em um módulo têm pouco ou nenhum impacto sobre outros módulos.

## Benefícios da Programação Modular

### Organização do Código

A modularidade ajuda a manter o código organizado, facilitando a navegação e a compreensão da estrutura do programa.

### Reutilização

Módulos podem ser reutilizados em outros projetos, economizando tempo e esforço de desenvolvimento.

### Facilita o Trabalho em Equipe

Vários desenvolvedores podem trabalhar em diferentes módulos simultaneamente, reduzindo conflitos e melhorando a colaboração.

### Testes e Depuração

Módulos podem ser testados individualmente, o que facilita a identificação e correção de erros. Isso resulta em um processo de depuração mais eficiente.

### Escalabilidade

A modularidade permite que novos módulos sejam adicionados ao programa sem a necessidade de reescrever o código existente, tornando o software mais escalável.

## Princípios da Programação Modular

### Encapsulamento

Os detalhes de implementação de um módulo devem ser ocultados. Apenas a interface pública deve ser exposta.

### Coesão

Um módulo deve ser altamente coeso, ou seja, todos os seus componentes devem estar relacionados e contribuir para uma única funcionalidade.

### Acoplamento

Os módulos devem ser fracamente acoplados, minimizando as dependências entre eles.

## Exemplo de Programação Modular em C

### Estrutura de Arquivos

Vamos criar um simples módulo de calculadora, que terá funções para soma e subtração.

- **calculadora.h** (arquivo de cabeçalho)
- **calculadora.c** (arquivo de implementação)
- **main.c** (arquivo principal)

### Arquivo de Cabeçalho (`calculadora.h`)

```c
#include "calculadora.h"

// Implementação da função soma
float soma(float a, float b) {
    return a + b;
}

// Implementação da função subtracao
float subtracao(float a, float b) {
    return a - b;
}
```

### Arquivo Principal (`main.c`)

```c
#include <stdio.h>
#include "calculadora.h"

int main() {
    float a = 5.0, b = 3.0;

    printf("Soma: %.2f\n", soma(a, b));
    printf("Subtração: %.2f\n", subtracao(a, b));

    return 0;
}
```
