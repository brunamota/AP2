#include <stdio.h>
#include "Calculadora.h"

int main(){
    int op;
    float num1, num2;

    do{
        printf("\nEscolha uma operação matematica:\n");
      printf("1- Soma\n");
      printf("2- Subtracao\n");
      printf("3- Multiplicacao\n");
      printf("4- Divisao\n");
      printf("0- Sair\n");
      printf("Opcao: ");
      scanf("%d", &op);

      switch(op){
        case 1:
            printf("Insira um numero: ");
            scanf("%f", &num1);
            printf("Insira outro numero: ");
            scanf("%f", &num2);
            printf("%.2f + %.2f = %.2f\n",num1, num2, soma(num1, num2));
            break;
        case 2:
            printf("Insira um numero: ");
            scanf("%f", &num1);
            printf("Insira outro numero: ");
            scanf("%f", &num2);
            printf("%.2f - %.2f = %.2f\n",num1, num2, subtracao(num1, num2));
            break;
        case 3:
            printf("Insira um numero: ");
            scanf("%f", &num1);
            printf("Insira outro numero: ");
            scanf("%f", &num2);
            printf("%.2f * %.2f = %.2f\n",num1, num2, multiplicacao(num1, num2));
            break;
        case 4:
            printf("Insira um numero: ");
            scanf("%f", &num1);
            printf("Insira outro numero: ");
            scanf("%f", &num2);
            if (num2 == 0) {
                printf("Nao existe divisao por zero\n");
            }else {
                printf("%.2f / %.2f = %.2f\n",num1, num2, divisao(num1, num2));
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
