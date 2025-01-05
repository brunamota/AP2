# Aula 03 - Implementação de uma Estrutura de Dados Heterogênea

## Estrutura da Lista de Contatos

Vamos criar uma estrutura que representa um contato, que pode incluir nome, número de telefone e um e-mail. Para armazenar esses dados, utilizaremos `struct` para definir o contato e `union` para permitir que o número de telefone possa ser armazenado como um inteiro ou como uma string.

### Definindo as Estruturas

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTATOS 100

// Definição da união para o telefone
union Telefone {
    char telefone_str[15]; // Número de telefone como string
    long telefone_int;      // Número de telefone como inteiro
};

// Definição da estrutura 'Contato'
struct Contato {
    char nome[50];
    union Telefone telefone;
    char email[50];
    char tipo_telefone; // 's' para string, 'i' para inteiro
};

// Definição da lista de contatos
struct ListaContatos {
    struct Contato contatos[MAX_CONTATOS];
    int total_contatos;
};
```

## Operações Básicas

### Função para Adicionar Contato

Vamos implementar uma função para adicionar um contato à lista.

```c
void adicionarContato(struct ListaContatos* lista, const char* nome, const char* telefone, const char* email) {
    if (lista->total_contatos >= MAX_CONTATOS) {
        printf("A lista de contatos está cheia!\n");
        return;
    }

    struct Contato* novo_contato = &lista->contatos[lista->total_contatos++];
    strcpy(novo_contato->nome, nome);
    strcpy(novo_contato->email, email);

    // Verificando se o telefone é numérico (inteiro) ou não (string)
    if (telefone[0] >= '0' && telefone[0] <= '9') {
        novo_contato->telefone.telefone_int = atol(telefone); // converte string para long
        novo_contato->tipo_telefone = 'i'; // Define como inteiro
    } else {
        strcpy(novo_contato->telefone.telefone_str, telefone);
        novo_contato->tipo_telefone = 's'; // Define como string
    }
}
```

### Função para Exibir Contatos

Agora, vamos implementar uma função para exibir os contatos da lista.

```c
void exibirContatos(const struct ListaContatos* lista) {
    printf("Lista de Contatos:\n");
    for (int i = 0; i < lista->total_contatos; i++) {
        struct Contato contato = lista->contatos[i];
        printf("Nome: %s\n", contato.nome);
        if (contato.tipo_telefone == 'i') {
            printf("Telefone: %ld\n", contato.telefone.telefone_int);
        } else {
            printf("Telefone: %s\n", contato.telefone.telefone_str);
        }
        printf("Email: %s\n\n", contato.email);
    }
}
```

## Exemplo de Uso

Agora, vamos criar um programa principal que utiliza essas funções.

```c
int main() {
    struct ListaContatos lista;
    lista.total_contatos = 0;

    // Adicionando contatos
    adicionarContato(&lista, "Maria", "123456789", "maria@example.com");
    adicionarContato(&lista, "João", "joao@example.com"); // telefone como string
    adicionarContato(&lista, "Ana", "987654321", "ana@example.com");

    // Exibindo os contatos
    exibirContatos(&lista);

    return 0;
}
```

## Explicação do Código

- **Estruturas**: A `struct Contato` armazena informações sobre cada contato, incluindo nome, telefone e e-mail. A `union Telefone` permite armazenar o telefone de duas maneiras.
- **Adicionar Contato**: A função `adicionarContato` verifica o tipo de telefone (número inteiro ou string) e armazena na estrutura apropriada.
- **Exibir Contatos**: A função `exibirContatos` itera pela lista e imprime as informações de cada contato.
