#include <stdio.h>
#include <stdlib.h>

typedef struct Biblioteca {
    char titulo[100];
    char autor[100];
    int ano;
} Livro;

int main() {
    Livro livro;

    printf("Digite o título do livro: ");
    gets(livro.titulo);
    setbuf(stdin, NULL);
    printf("Digite o autor do livro: ");
    gets(livro.autor);
    setbuf(stdin, NULL);
    printf("Digite o ano de publicação: ");
    scanf("%d", &livro.ano);

    printf("Livro cadastrado:\n");
    printf("Título: %sAutor: %sAno: %d\n", livro.titulo, livro.autor, livro.ano);
}
