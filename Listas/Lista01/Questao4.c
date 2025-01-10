#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Estoque{
  char nome[100];
  int codigo;
  float preco;
  int quantidade;
}Produto;

int main(){
   Produto produto;

   printf("Digite o nome do produto: ");
   gets(produto.nome);
   setbuf(stdin, NULL);
   printf("Digite a codigo do produto: ");
   scanf("%d", &produto.codigo);
   printf("Digite o preco do produto: ");
   scanf("%f", &produto.preco);
   printf("Digite a quantidade do produto: ");
   scanf("%d", &produto.quantidade);

   printf("Estoque: \n");
   printf("Nome: %s\n", produto.nome);
   printf("Codigo: %d\n", produto.codigo);
   printf("Preco:R$ %.2f\n", produto.preco);
   printf("Quantidade: %d\n", produto.quantidade);

   float totalEstoque = produto.preco * produto.quantidade;

   printf("Valor total do estoques: R$ %.2f\n", totalEstoque);
}