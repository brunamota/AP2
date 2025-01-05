# Aula 02 - Uso de `union` para Estruturas Heterogêneas

## O que é `union`?

Em C, uma `union` permite que diferentes tipos de dados compartilhem o mesmo espaço de memória. Isso é útil quando você deseja economizar espaço, armazenando um único valor de diferentes tipos em momentos diferentes.

#### Exemplo de `union`

```c
#include <stdio.h>

union Dados {
    int inteiro;
    float ponto_flutuante;
    char caractere;
};

int main() {
    union Dados d;

    d.inteiro = 10;
    printf("Inteiro: %d\n", d.inteiro);

    d.ponto_flutuante = 3.14;
    printf("Ponto Flutuante: %f\n", d.ponto_flutuante); // O valor anterior é sobrescrito

    d.caractere = 'A';
    printf("Caractere: %c\n", d.caractere); // O valor anterior é sobrescrito

    return 0;
}
```

## Implementação de Estruturas Heterogêneas

### 2.1. Usando `union` em C

Vamos criar uma estrutura que utiliza `union` para armazenar diferentes tipos de dados, como em uma lista de contatos, onde o telefone pode ser um número inteiro ou uma string.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTATOS 100

// Definição da união para o telefone
union Telefone {
    char telefone_str[15];
    long telefone_int;
};

// Definição da estrutura 'Contato'
struct Contato {
    char nome[50];
    union Telefone telefone;
    char tipo_telefone; // 's' para string, 'i' para inteiro
};

// Função para adicionar contato
void adicionarContato(struct Contato* contato, const char* nome, const char* telefone) {
    strcpy(contato->nome, nome);
    
    // Verifica se o telefone é numérico
    if (telefone[0] >= '0' && telefone[0] <= '9') {
        contato->telefone.telefone_int = atol(telefone);
        contato->tipo_telefone = 'i'; // Inteiro
    } else {
        strcpy(contato->telefone.telefone_str, telefone);
        contato->tipo_telefone = 's'; // String
    }
}

// Função para exibir contato
void exibirContato(struct Contato contato) {
    printf("Nome: %s\n", contato.nome);
    if (contato.tipo_telefone == 'i') {
        printf("Telefone: %ld\n", contato.telefone.telefone_int);
    } else {
        printf("Telefone: %s\n", contato.telefone.telefone_str);
    }
}

int main() {
    struct Contato contato1;
    adicionarContato(&contato1, "Maria", "123456789");
    
    struct Contato contato2;
    adicionarContato(&contato2, "João", "joao@example.com");

    // Exibindo contatos
    exibirContato(contato1);
    exibirContato(contato2);

    return 0;
}
```

## Vantagens e Desvantagens

### `union` em C

**Vantagens:**
- Economiza espaço, pois todos os membros compartilham a mesma área de memória.

**Desvantagens:**
- Menos seguro, pois não há verificação de tipo em tempo de execução, podendo levar a acesso a dados inválidos.
