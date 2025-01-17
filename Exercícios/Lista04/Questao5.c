#include <stdio.h>

int main() {
    FILE *entrada = fopen("saida.txt", "r");
    FILE *copia = fopen("copia.txt", "w");

    if (entrada == NULL || copia == NULL) {
        printf("Erro ao abrir os arquivos!\n");
        return 1;
    }

    char linha[100];
    while (fgets(linha, sizeof(linha), entrada) != NULL) {
        fprintf(copia, "%s", linha);
    }

    fclose(entrada);
    fclose(copia);
    return 0;
}