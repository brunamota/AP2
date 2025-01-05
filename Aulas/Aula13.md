# Aula 13 - Aplicações Práticas de Ponteiros em Estruturas de Dados

## 1. Estruturas de Dados e Ponteiros

Ponteiros são fundamentais para a implementação de várias estruturas de dados dinâmicas, como listas encadeadas e pilhas. Eles permitem que você crie estruturas que podem crescer e encolher conforme necessário durante a execução do programa, utilizando a memória de forma eficiente.

## 2. Listas Encadeadas

Uma lista encadeada é uma estrutura de dados que consiste em uma sequência de elementos, onde cada elemento aponta para o próximo. Isso permite a inserção e remoção de elementos de forma dinâmica.

### 2.1. Estrutura de um Nó

Cada nó da lista encadeada contém um valor e um ponteiro para o próximo nó.

```c
#include <stdio.h>
#include <stdlib.h>

// Definição do nó
typedef struct Nodo {
    int valor;
    struct Nodo *proximo; // Ponteiro para o próximo nó
} Nodo;
```

### 2.2. Funções Básicas

Vamos implementar funções básicas para criar uma lista encadeada: inserção e impressão dos elementos.

#### Função para Inserir um Novo Nó

```c
Nodo* inserir(Nodo *cabeca, int valor) {
    Nodo *novo_nodo = (Nodo*)malloc(sizeof(Nodo));
    novo_nodo->valor = valor;
    novo_nodo->proximo = cabeca; // Novo nó aponta para a antiga cabeça
    return novo_nodo; // Retorna nova cabeça
}
```

#### Função para Imprimir a Lista

```c
void imprimirLista(Nodo *cabeca) {
    Nodo *atual = cabeca;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}
```

### 2.3. Exemplo Completo

```c
#include <stdio.h>
#include <stdlib.h>

// Definição do nó
typedef struct Nodo {
    int valor;
    struct Nodo *proximo;
} Nodo;

// Função para inserir um novo nó
Nodo* inserir(Nodo *cabeca, int valor) {
    Nodo *novo_nodo = (Nodo*)malloc(sizeof(Nodo));
    novo_nodo->valor = valor;
    novo_nodo->proximo = cabeca;
    return novo_nodo;
}

// Função para imprimir a lista
void imprimirLista(Nodo *cabeca) {
    Nodo *atual = cabeca;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

// Função principal
int main() {
    Nodo *lista = NULL; // Inicializa a lista como vazia

    lista = inserir(lista, 10);
    lista = inserir(lista, 20);
    lista = inserir(lista, 30);

    printf("Lista encadeada: ");
    imprimirLista(lista);

    // Libera a memória alocada
    Nodo *atual = lista;
    while (atual != NULL) {
        Nodo *temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    return 0;
}
```

## 3. Pilhas

Uma pilha é uma estrutura de dados que segue o princípio LIFO (Last In, First Out). As operações principais são `push` (inserir) e `pop` (remover).

### 3.1. Estrutura da Pilha

A pilha pode ser implementada usando uma lista encadeada.

```c
typedef struct Pilha {
    Nodo *topo; // Ponteiro para o topo da pilha
} Pilha;
```

### 3.2. Funções para a Pilha

#### Função para Criar uma Pilha

```c
Pilha* criarPilha() {
    Pilha *pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}
```

#### Função para Inserir (Push)

```c
void push(Pilha *pilha, int valor) {
    pilha->topo = inserir(pilha->topo, valor);
}
```

#### Função para Remover (Pop)

```c
int pop(Pilha *pilha) {
    if (pilha->topo == NULL) {
        printf("Pilha vazia!\n");
        return -1; // Retorna -1 se a pilha estiver vazia
    }
    Nodo *nodo_removido = pilha->topo;
    int valor = nodo_removido->valor;
    pilha->topo = pilha->topo->proximo; // Atualiza o topo
    free(nodo_removido); // Libera a memória do nó removido
    return valor;
}
```

### 3.3. Exemplo Completo de Pilha

```c
#include <stdio.h>
#include <stdlib.h>

// Definição do nó
typedef struct Nodo {
    int valor;
    struct Nodo *proximo;
} Nodo;

// Definição da pilha
typedef struct Pilha {
    Nodo *topo;
} Pilha;

// Funções para a pilha
Pilha* criarPilha() {
    Pilha *pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

void push(Pilha *pilha, int valor) {
    Nodo *novo_nodo = (Nodo*)malloc(sizeof(Nodo));
    novo_nodo->valor = valor;
    novo_nodo->proximo = pilha->topo;
    pilha->topo = novo_nodo;
}

int pop(Pilha *pilha) {
    if (pilha->topo == NULL) {
        printf("Pilha vazia!\n");
        return -1;
    }
    Nodo *nodo_removido = pilha->topo;
    int valor = nodo_removido->valor;
    pilha->topo = pilha->topo->proximo;
    free(nodo_removido);
    return valor;
}

// Função principal
int main() {
    Pilha *pilha = criarPilha();

    push(pilha, 10);
    push(pilha, 20);
    push(pilha, 30);

    printf("Pop: %d\n", pop(pilha)); // Imprime 30
    printf("Pop: %d\n", pop(pilha)); // Imprime 20
    printf("Pop: %d\n", pop(pilha)); // Imprime 10
    printf("Pop: %d\n", pop(pilha)); // Tenta remover da pilha vazia

    // Libera a memória da pilha
    free(pilha);

    return 0;
}
```
