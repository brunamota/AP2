#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *entrada = fopen("nomes.txt", "r");
    FILE *saida = fopen("nomes_copiados.txt", "w");

    if (entrada == NULL || saida == NULL) {
        printf("Erro ao abrir os arquivos!\n");
    } else{

        char nome[100];

        while (fgets(nome, sizeof(nome), entrada) != NULL) {
            fprintf(saida, "%s", nome);
        }

    }

    fclose(entrada);
    fclose(saida);
}
