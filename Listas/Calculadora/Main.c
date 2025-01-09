#include <stdio.h>
#include <stdlib.h>

int main(){
  float a, b;
  int op;
  
  do{
    printf("Escolha uma operacao: ");
    printf("1 - Soma\n");
    printf("2 - Subtracao\n");
    printf("3 - Multiplicacao\n");
    printf("4 - Divisao\n");
    scanf("%d", &op);

    switch(op){
      case 1:
      break;
      case 2:
      break;
      case 3:
      break;
      case 4:
      break;
      case 0:
      break;
      default:
      break;
    }
}while(op != 0);