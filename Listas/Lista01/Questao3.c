#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Biblioteca{
    char titulo[50];
    char autor[50];
    int anoPublicacao;
};

int main(){
  struct Biblioteca biblioteca;

  printf("Digite o titulo: ");
  gets(biblioteca.titulo);
  setbuf(stdin, NULL);
  printf("Digite o autor: ");
  gets(biblioteca.autor);
  setbuf(stdin, NULL);
  printf("Digite o ano publicacao: ");
  scanf("%d", &biblioteca.anoPublicacao);

  printf("Biblioteca:\n");
  printf("Titulo: %s\n", biblioteca.titulo);
  printf("Autor: %s\n", biblioteca.autor);
  printf("Ano publicacao: %d\n", biblioteca.anoPublicacao);
}