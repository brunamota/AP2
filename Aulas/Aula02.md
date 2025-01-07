# Aula 02 - Implementação de uma Estrutura de Dados Heterogênea

## Estrutura da Lista de Contatos

Vamos criar uma estrutura que representa um contato, que pode incluir nome, número de telefone e um e-mail. Para armazenar esses dados, utilizaremos `struct` para definir o contato e `union` para permitir que o número de telefone possa ser armazenado como um inteiro ou como uma string.

### Definindo as Estruturas

``` C
typedef struct {
    char nome[100];
    char telefone[15];
} Contato;

typedef struct {
    Contato contatos[MAX_CONTATOS];
    int total;
} ListaContatos;
```

## Operações Básicas

### Função para Adicionar Contato

Vamos implementar uma função para adicionar um contato à lista.

```c
void adicionarContato(ListaContatos lista) {
    if (lista.total < MAX_CONTATOS) {
        printf("Digite o nome: ");
        fgets(lista.contatos[lista.total].nome, sizeof(lista.contatos[lista.total].nome), stdin);
        lista.contatos[lista.total].nome[strcspn(lista.contatos[lista.total].nome, "\n")] = '\0'; // Remove a nova linha

        printf("Digite o telefone: ");
        fgets(lista.contatos[lista.total].telefone, sizeof(lista.contatos[lista.total].telefone), stdin);
        lista.contatos[lista.total].telefone[strcspn(lista.contatos[lista.total].telefone, "\n")] = '\0'; // Remove a nova linha

        lista.total++;
    } else {
        printf("Lista de contatos cheia!\n");
    }
}
```

### Função para Exibir Contatos

Agora, vamos implementar uma função para exibir os contatos da lista.

``` C
void exibirContatos(ListaContatos lista) {
    printf("Lista de Contatos:\n");
    for (int i = 0; i < lista.total; i++) {
        printf("Nome: %s, Telefone: %s\n", lista.contatos[i].nome, lista.contatos[i].telefone);
    }
}
```

### Função para Buscar Contatos

```C
int buscarContato(ListaContatos lista, const char *nome) {
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

```c
int main() {
    ListaContatos lista;
    lista.total = 0;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar Contato\n");
        printf("2. Listar Contatos\n");
        printf("3. Buscar Contato\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Consumir a nova linha

        switch (opcao) {
            case 1:
                adicionarContato(lista);
                break;
            case 2:
                listarContatos(lista);
                break;
            case 3: {
                char nome[100];
                printf("Digite o nome a buscar: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0'; // Remove a nova linha

                int indice = buscarContato(lista, nome);
                if (indice != -1) {
                    printf("Contato encontrado: Nome: %s, Telefone: %s\n", lista.contatos[indice].nome, lista.contatos[indice].telefone);
                } else {
                    printf("Contato não encontrado.\n");
                }
                break;
            }
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
```

## Explicação do Código

- **Estruturas**: A `struct Contato` armazena informações sobre cada contato, incluindo nome, telefone e e-mail. A `union Telefone` permite armazenar o telefone de duas maneiras.
- **Adicionar Contato**: A função `adicionarContato` verifica o tipo de telefone (número inteiro ou string) e armazena na estrutura apropriada.
- **Exibir Contatos**: A função `exibirContatos` itera pela lista e imprime as informações de cada contato.
