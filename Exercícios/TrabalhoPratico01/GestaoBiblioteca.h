#include <stdio.h>
#include <string.h>

typedef struct {
    char titulo[100];
    char autor[100];
    int ano;
} Livro;

typedef struct {
    char nome[100];
    int id;
} Usuario;

typedef struct {
    Livro livros[100];
    Usuario usuarios[100];
    int totalLivros;
    int totalUsuarios;
} Biblioteca;

void adicionarLivro(Biblioteca *biblioteca) {
    if (biblioteca->totalLivros < 100) {
        printf("Digite o título do livro: ");
        fgets(biblioteca->livros[biblioteca->totalLivros].titulo, sizeof(biblioteca->livros[biblioteca->totalLivros].titulo), stdin);
        biblioteca->livros[biblioteca->totalLivros].titulo[strcspn(biblioteca->livros[biblioteca->totalLivros].titulo, "\n")] = '\0';

        printf("Digite o autor do livro: ");
        fgets(biblioteca->livros[biblioteca->totalLivros].autor, sizeof(biblioteca->livros[biblioteca->totalLivros].autor), stdin);
        biblioteca->livros[biblioteca->totalLivros].autor[strcspn(biblioteca->livros[biblioteca->totalLivros].autor, "\n")] = '\0';

        printf("Digite o ano de publicação: ");
        scanf("%d", &biblioteca->livros[biblioteca->totalLivros].ano);
        getchar(); // Consumir nova linha

        biblioteca->totalLivros++;
    } else {
        printf("Capacidade máxima de livros atingida!\n");
    }
}

void adicionarUsuario(Biblioteca *biblioteca) {
    if (biblioteca->totalUsuarios < 100) {
        printf("Digite o nome do usuário: ");
        fgets(biblioteca->usuarios[biblioteca->totalUsuarios].nome, sizeof(biblioteca->usuarios[biblioteca->totalUsuarios].nome), stdin);
        biblioteca->usuarios[biblioteca->totalUsuarios].nome[strcspn(biblioteca->usuarios[biblioteca->totalUsuarios].nome, "\n")] = '\0';

        printf("Digite o ID do usuário: ");
        scanf("%d", &biblioteca->usuarios[biblioteca->totalUsuarios].id);
        getchar(); // Consumir nova linha

        biblioteca->totalUsuarios++;
    } else {
        printf("Capacidade máxima de usuários atingida!\n");
    }
}

void listarLivros(Biblioteca *biblioteca) {
    printf("Lista de Livros:\n");
    for (int i = 0; i < biblioteca->totalLivros; i++) {
        printf("Título: %s, Autor: %s, Ano: %d\n", biblioteca->livros[i].titulo, biblioteca->livros[i].autor, biblioteca->livros[i].ano);
    }
}

void listarUsuarios(Biblioteca *biblioteca) {
    printf("Lista de Usuários:\n");
    for (int i = 0; i < biblioteca->totalUsuarios; i++) {
        printf("Nome: %s, ID: %d\n", biblioteca->usuarios[i].nome, biblioteca->usuarios[i].id);
    }
}

int buscarLivro(Biblioteca *biblioteca, const char *titulo, int indice) {
    if (indice >= biblioteca->totalLivros) {
        return -1; // Livro não encontrado
    }
    if (strcmp(biblioteca->livros[indice].titulo, titulo) == 0) {
        return indice; // Retorna o índice do livro encontrado
    }
    return buscarLivro(biblioteca, titulo, indice + 1); // Chamada recursiva
}
