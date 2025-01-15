#include <stdio.h>
#include "Cadastro.h"

int main() {
    const char *nomeArquivo = "usuarios.txt";
    int opcao;

    printf("1. Cadastrar\n2. Autenticar\nEscolha uma opção: ");
    scanf("%d", &opcao);
    getchar(); // Consumir o caractere de nova linha

    if (opcao == 1) {
        cadastrarUsuario(nomeArquivo);
    } else if (opcao == 2) {
        if (autenticarUsuario(nomeArquivo)) {
            printf("Login bem-sucedido!\n");
        } else {
            printf("Login falhou!\n");
        }
    } else {
        printf("Opção inválida!\n");
    }

    return 0;
}