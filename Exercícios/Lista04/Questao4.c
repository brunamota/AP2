#include <stdio.h>

int main() {
    FILE *arquivo = fopen("saida.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    int contador = 0;
    char c;
    while ((c = fgetc(arquivo)) != EOF) {
        contador++;
    }

    printf("Total de caracteres no arquivo: %d\n", contador);
    fclose(arquivo);

}