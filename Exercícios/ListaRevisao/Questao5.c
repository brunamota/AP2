#include <stdio.h>
#include <string.h>

int main() {
  FILE *entrada = fopen("nomes.txt", "w"); // Abre para escrita
  if (entrada == NULL) {
    printf("Erro ao abrir o arquivo nomes.txt para escrita!\n");
    return 1;
  }

  // Solicita ao usuário para digitar nomes
  char nome[100];
  printf("Digite nomes (digite 'sair' para finalizar):\n");
  while (1) {
    fgets(nome, sizeof(nome), stdin);
    if (strncmp(nome, "sair", 4) == 0) {
      break; // Sai do loop se o usuário digitar "sair"
    }
    fprintf(entrada, "%s", nome); // Escreve o nome no arquivo
  }
  fclose(entrada); // Fecha o arquivo de entrada

  // Agora abre o arquivo para leitura e copia os dados
  entrada = fopen("nomes.txt", "r"); // Abre para leitura
  FILE *saida = fopen("nomes_copiados.txt", "w"); // Abre para escrita

  if (entrada == NULL || saida == NULL) {
    printf("Erro ao abrir os arquivos!\n");
    return 1;
  }

  // Copia os nomes do arquivo de entrada para o arquivo de saída
  while (fgets(nome, sizeof(nome), entrada) != NULL) {
    fprintf(saida, "%s", nome);
  }

  fclose(entrada); // Fecha o arquivo de entrada
  fclose(saida);   // Fecha o arquivo de saída

  printf("Nomes copiados com sucesso para nomes_copiados.txt\n");

}
