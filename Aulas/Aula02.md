# Aula 02 - Implementação de uma Estrutura de Dados Heterogênea

## Estrutura da Lista de Contatos

Vamos criar uma estrutura que representa um contato, que pode incluir nome, número de telefone e um e-mail. Para armazenar esses dados, utilizaremos `struct` para definir o contato e `union` para permitir que o número de telefone possa ser armazenado como um inteiro ou como uma string.

### Definindo as Estruturas

``` C
typedef struct {
  char nome[50];
  int telefone;
  char email[50];
}Cadastros;

typedef struct ListaDeContatos{
    Cadastros cadastros[5];
    int quantidade;
};
```

## Operações Básicas

### Função para Adicionar Contato

Vamos implementar uma função para adicionar um contato à lista.

```c
void adicionarContato(struct ListaDeContatos *lista) {
    if (lista->quantidade < 5) {
        printf("Digite o nome: ");
        setbuf(stdin, NULL);
        gets(lista->cadastros[lista->quantidade].nome);
        setbuf(stdin, NULL);
        printf("Digite a telefone: ");
        scanf("%d", &lista->cadastros[lista->quantidade].telefone);
        setbuf(stdin, NULL);
        printf("Digite a email: ");
        gets(lista->cadastros[lista->quantidade].email);
        setbuf(stdin, NULL);

        lista->quantidade++;
    } else {
        printf("Lista cheia");
    }
}
```

### Função para Exibir Contatos

Agora, vamos implementar uma função para exibir os contatos da lista.

``` C
void exibirContato(struct ListaDeContatos lista) {
    printf("Lista de Contatos:\n");
    for (int i = 0; i < lista.quantidade; i++) {
        printf("Contato %d\n", i + 1);
        printf("Nome: %s\n", lista.cadastros[i].nome);
        printf("Telefone: %d\n", lista.cadastros[i].telefone);
        printf("Email: %s\n", lista.cadastros[i].email);
    }
}
```

### Função para Buscar Contatos

```C
int buscarContato(struct ListaContatos lista, const char *nome) {
    for (int i = 0; i < lista.total; i++) {
        if (strcmp(lista.contatos[i].nome, nome) == 0) {
            return i; // Retorna o índice do contato encontrado
        }
    }
    return -1; // Retorna -1 se não encontrado
}
```

## Exemplo de Uso

Agora, vamos criar um programa principal que utiliza essas funções.

```C
int main() {
    struct ListaDeContatos lista;
    lista.quantidade = 0;
    int op;
    char nome[100];

    do {
        printf("1. Adicionar Contato\n");
        printf("2. Exibir Lista de Contato\n");
        printf("3. Buscar contato\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                adicionarContato(&lista);
                break;
            case 2:
                exibirContato(lista);
                break;
            case 3:
            printf("Digite o nome a buscar: ");
            setbuf(stdin, NULL);
            gets(nome);
            setbuf(stdin, NULL);

            int indice = buscarContato(lista, nome);
            if (indice == -1) {
                printf("Contato nao encontrado\n");
            }else {
                printf("Contato encontrado %d\n", indice + 1);
                printf("Nome: %s\n", lista.cadastros[indice].nome);
                printf("Telefone: %d\n", lista.cadastros[indice].telefone);
                printf("Email: %s\n", lista.cadastros[indice].email);
            }
                break;
            case 0:
                printf("Saindo...\n");
            break;
            default:
                printf("Opcao invalida\n");
                break;
        }
    }while (op != 0);
}
```

## Explicação do Código

- **Estruturas**: A `struct Contato` armazena informações sobre cada contato, incluindo nome, telefone e e-mail. A `union Telefone` permite armazenar o telefone de duas maneiras.
- **Adicionar Contato**: A função `adicionarContato` verifica o tipo de telefone (número inteiro ou string) e armazena na estrutura apropriada.
- **Exibir Contatos**: A função `exibirContatos` itera pela lista e imprime as informações de cada contato.
