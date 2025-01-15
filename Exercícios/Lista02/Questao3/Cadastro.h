#include <stdio.h>
#include <string.h>

void cadastrarUsuario(char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para cadastro!\n");
        return;
    }

    char usuario[50], senha[50];
    printf("Digite o nome de usuário: ");
    fgets(usuario, sizeof(usuario), stdin);
    printf("Digite a senha: ");
    fgets(senha, sizeof(senha), stdin);

    fprintf(arquivo, "%s%s", usuario, senha);
    fclose(arquivo);
}

int autenticarUsuario(char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para autenticação!\n");
        return 0;
    }

    char usuario[50], senha[50];
    char usuarioDB[50], senhaDB[50];

    printf("Digite o nome de usuário: ");
    fgets(usuario, sizeof(usuario), stdin);
    printf("Digite a senha: ");
    fgets(senha, sizeof(senha), stdin);

    while (fgets(usuarioDB, sizeof(usuarioDB), arquivo) != NULL &&
           fgets(senhaDB, sizeof(senhaDB), arquivo) != NULL) {
        if (strcmp(usuario, usuarioDB) == 0 && strcmp(senha, senhaDB) == 0) {
            fclose(arquivo);
        }
           }

    fclose(arquivo);
}