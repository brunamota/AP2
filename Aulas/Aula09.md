# Aula 09 - Criação de Arquivos `.h` e Suas Relações com a Orientação a Objetos

## O que são Arquivos de Cabeçalho (`.h`)?

Arquivos de cabeçalho são arquivos que contêm declarações de funções, tipos de dados, constantes e macros que podem ser compartilhados entre diferentes arquivos de implementação (`.c`). Eles são fundamentais para organizar o código e promover a reutilização.

### Estrutura de um Arquivo de Cabeçalho

Um arquivo de cabeçalho geralmente contém:

- Declarações de funções
- Definições de estruturas e tipos
- Constantes e macros

### Exemplo de Arquivo de Cabeçalho

Vamos criar um arquivo de cabeçalho para um módulo de operações matemáticas.

**Arquivo: `matematica.h`**

```c
#define MATEMATICA_H

// Declarações de funções
float soma(float a, float b);
float subtracao(float a, float b);
float multiplicacao(float a, float b);
float divisao(float a, float b);

```

## Criando Arquivos de Implementação (`.c`)

Os arquivos de implementação contêm a definição real das funções declaradas no arquivo de cabeçalho.

**Arquivo: `matematica.c`**

```c
#include "matematica.h"

// Implementações das funções
float soma(float a, float b) {
    return a + b;
}

float subtracao(float a, float b) {
    return a - b;
}

float multiplicacao(float a, float b) {
    return a * b;
}

float divisao(float a, float b) {
    if (b != 0) {
        return a / b;
    } else {
        return 0; // Retorna 0 se houver divisão por zero
    }
}
```

## Utilizando Arquivos de Cabeçalho

Para usar as funções definidas em um arquivo de cabeçalho, você deve incluí-lo em seu arquivo principal (`.c`) usando a diretiva `#include`.

**Arquivo Principal: `main.c`**

```c
#include <stdio.h>
#include "matematica.h"

int main() {
    float a = 10.0, b = 5.0;

    printf("Soma: %.2f\n", soma(a, b));
    printf("Subtração: %.2f\n", subtracao(a, b));
    printf("Multiplicação: %.2f\n", multiplicacao(a, b));
    printf("Divisão: %.2f\n", divisao(a, b));

    return 0;
}
```

## Relações com Orientação a Objetos

Embora C não seja uma linguagem orientada a objetos (OOP) como C++ ou Java, podemos implementar conceitos de OOP usando estruturas e arquivos de cabeçalho.

### Estruturas como Objetos

Em C, podemos usar `structs` para criar "objetos". Uma `struct` pode conter diferentes tipos de dados, semelhante a um objeto em OOP.

**Exemplo de `struct`**

```c
typedef struct {
    float x;
    float y;
} Ponto;

// Função para criar um ponto
Ponto criarPonto(float x, float y) {
    Ponto p;
    p.x = x;
    p.y = y;
    return p;
}
```

### Funções como Métodos

As funções que operam sobre essas estruturas podem ser vistas como "métodos" do objeto.

**Exemplo de "método" para calcular a distância**

```c
#include <math.h>

// Função para calcular a distância entre dois pontos
float distancia(Ponto p1, Ponto p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}
```

### Arquivo de Cabeçalho para Estruturas

Crie um arquivo de cabeçalho para as definições de `struct` e suas funções.

**Arquivo: `ponto.h`**

```c
#define PONTO_H

typedef struct {
    float x;
    float y;
} Ponto;

Ponto criarPonto(float x, float y);
float distancia(Ponto p1, Ponto p2);
```
