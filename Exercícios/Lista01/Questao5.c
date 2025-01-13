#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cadastro{
  char nome[50];
  char telefone[15];
  char email[50];
};

int main(){

  struct Cadastro cadastro;

  printf("Digite seu nome: ");
  gets(cadastro.nome);
  setbuf(stdin, NULL);
  printf("Digite seu telefone: ");
  gets(cadastro.telefone);
  setbuf(stdin, NULL);
  printf("Digite seu email: ");
  gets(cadastro.email);
  setbuf(stdin, NULL);

  printf("Nome: %s\n", cadastro.nome);
  printf("Telefone: %s\n", cadastro.telefone);
  printf("Email: %s\n", cadastro.email);

}

