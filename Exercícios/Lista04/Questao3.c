#include <stdio.h>

int main() {
    FILE *arquivo = fopen("saida.txt", "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    fprintf(arquivo, "Adicionando mais uma linha.\n");
    fprintf(arquivo, "Esta é outra linha adicionada.\n");

    fclose(arquivo);

}