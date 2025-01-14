#include <stdio.h>

void adicionaNota(char *nomeArquivo){
  FILE *notasAlunos = fopen(nomeArquivo, "a");
  if(notasAlunos == NULL){
    printf("Erro ao abrir o arquivo\n");
  }else{
    char nota[100];
    printf("Digite a nota do aluno:\n");
    fgets(nota, 100, stdin);
    fprintf(notasAlunos, "Nota: %s\n", nota);
    fclose(notasAlunos);
  }
}

void exibirNotas(char *nomeArquivo){
    FILE *notasAlunos = fopen(nomeArquivo, "r");
    if(notasAlunos == NULL){
      printf("Erro ao abrir o arquivo\n");
    }else{
      char linha[100];
      while(fgets(linha, 100, notasAlunos) != NULL){
        printf("%s", linha);
      }
    }
}

int main(){
  int op;

  do {
    printf("1 - Adicionar nota\n");
    printf("2 - Exibir notas\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &op);
    setbuf(stdin, NULL);

    switch (op) {
      case 1:
        adicionaNota("Aluno.txt");
      break;
      case 2:
        exibirNotas("Aluno.txt");
      break;
      case 0:
        printf("Saindo...\n");
      break;
      default:
        printf("Opcao invalida\n");
      break;
    }
  }while (op != 0);

}
