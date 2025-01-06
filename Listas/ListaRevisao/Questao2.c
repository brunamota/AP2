#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char titulo[100];
    char autor[100];
    int ano;
} Livro;

int main() {
    Livro livro;

    printf("Digite o título do livro: ");
    fgets(livro.titulo, sizeof(livro.titulo), stdin);
    printf("Digite o autor do livro: ");
    fgets(livro.autor, sizeof(livro.autor), stdin);
    printf("Digite o ano de publicação: ");
    scanf("%d", &livro.ano);

    printf("Livro cadastrado:\n");
    printf("Título: %sAutor: %sAno: %d\n", livro.titulo, livro.autor, livro.ano);
    return 0;
}
