
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno{
  char nome[50];
  int matricula;
  float nota[2];

};

int main(){
  struct Aluno aluno;
  float media;

  printf("Digite o nome do aluno: ");
  gets(aluno.nome);
  setbuf(stdin, NULL);
  printf("Digite a matricula do aluno: ");
  scanf("%d", &aluno.matricula);

  for(int i =0 ; i < 2; i++){
    printf("Digite a nota %d do aluno: ", i+1);
    scanf("%f", &aluno.nota[i]);
  }

  printf("Escola:\n");
  printf("Nome do aluno: %s\n", aluno.nome);
  printf("Matricula: %d\n", aluno.matricula);
  media = (aluno.nota[0] + aluno.nota[1])/2;
  printf("Media do aluno: %.2f\n", media);

}