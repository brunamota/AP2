#include <stdio.h>

int main() {
    FILE *arquivo = fopen("saida.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    fprintf(arquivo, "Olá, mundo!\n");
    fprintf(arquivo, "Bem-vindo ao curso de ciência da computação.\n");
    fprintf(arquivo, "Este é um exemplo de escrita em arquivo.\n");

    fclose(arquivo);
}