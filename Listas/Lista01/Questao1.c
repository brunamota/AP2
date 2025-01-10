#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Funcionario{
  char nome[50];
  int idade;
  float salario;
};

int main(){
   struct Funcionario f;

   printf("Digite o nome do funcionario: ");
   gets(f.nome);
   setbuf(stdin, NULL);
   printf("Digite a idade do funcionario: ");
   scanf("%d", &f.idade);
   printf("Digite o salario do funcionario: ");
   scanf("%f", &f.salario);

   printf("Funcionario:\n");
   printf("Nome: %s\n", f.nome);
   printf("Idade: %d\n", f.idade);
   printf("Salario: R$ %.2f\n", f.salario);

}