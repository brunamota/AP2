#include <stdio.h>
#include <stdlib.h>

#include "Calculadora.h"

int main(){
  float a, b;
  int op;

  do{
    printf("Escolha um valor para A: ");
    scanf("%f", &a);
    printf("Escolha um valor para B: ");
    scanf("%f", &b);

    printf("Escolha uma operacao: \n");
    printf("1 - Soma\n");
    printf("2 - Subtracao\n");
    printf("3 - Multiplicacao\n");
    printf("4 - Divisao\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &op);

    switch(op){
      case 1:
        printf("Soma: %f\n", soma(a,b));
      break;
      case 2:
        printf("Subtracao: %f\n", subtracao(a,b));
      break;
      case 3:
        printf("Multiplicacao: %f\n", multiplicacao(a,b));
      break;
      case 4:
        if(b==0){
          printf("Divisão por zero nao existe");
        }else{
          printf("Dvisao: %f\n", divisao(a,b));
        }
      break;
      case 0:
        printf("Saindo...\n");
      break;
      default:
        printf("Opcao invalida\n");
      break;
    }
  }while(op != 0);

}