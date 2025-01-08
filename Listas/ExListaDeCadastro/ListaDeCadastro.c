#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nome[50];
  int telefone;
  char email[50];
}Cadastros;

typedef struct ListaDeContatos{
    Cadastros cadastros[5];
    int quantidade;
};

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

void exibirContato(struct ListaDeContatos lista) {
    printf("Lista de Contatos:\n");
    for (int i = 0; i < lista.quantidade; i++) {
        printf("Contato %d\n", i + 1);
        printf("Nome: %s\n", lista.cadastros[i].nome);
        printf("Telefone: %d\n", lista.cadastros[i].telefone);
        printf("Email: %s\n", lista.cadastros[i].email);
    }
}

int buscarContato(struct ListaDeContatos lista, char *nome) {
    for (int i = 0; i < lista.quantidade; i++) {
        if (strcmp(lista.cadastros[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1;
}

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