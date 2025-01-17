#include <stdio.h>
#include "GestaoBiblioteca.h.h"

int main() {
    Biblioteca biblioteca = { .totalLivros = 0, .totalUsuarios = 0 };
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar Livro\n");
        printf("2. Adicionar Usuário\n");
        printf("3. Listar Livros\n");
        printf("4. Listar Usuários\n");
        printf("5. Buscar Livro\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                adicionarLivro(&biblioteca);
            break;
            case 2:
                adicionarUsuario(&biblioteca);
            break;
            case 3:
                listarLivros(&biblioteca);
            break;
            case 4:
                listarUsuarios(&biblioteca);
            break;
            case 5: {
                char titulo[100];
                printf("Digite o título do livro a buscar: ");
                fgets(titulo, sizeof(titulo), stdin);
                titulo[strcspn(titulo, "\n")] = '\0'; // Remove a nova linha

                int indice = buscarLivro(&biblioteca, titulo, 0);
                if (indice != -1) {
                    printf("Livro encontrado: Título: %s, Autor: %s, Ano: %d\n",
                           biblioteca.livros[indice].titulo,
                           biblioteca.livros[indice].autor,
                           biblioteca.livros[indice].ano);
                } else {
                    printf("Livro não encontrado.\n");
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