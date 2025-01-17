#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    char codigo[20];
    float preco;
    int quantidade;
} Produto;

typedef struct {
    Produto *produtos;
    int total;
} Inventario;

void inicializarInventario(Inventario *inventario) {
    inventario->produtos = (Produto *)malloc(sizeof(Produto) * 100);
    inventario->total = 0;
}

void adicionarProduto(Inventario *inventario) {
    if (inventario->total < 100) {
        printf("Digite o nome do produto: ");
        fgets(inventario->produtos[inventario->total].nome, sizeof(inventario->produtos[inventario->total].nome), stdin);
        inventario->produtos[inventario->total].nome[strcspn(inventario->produtos[inventario->total].nome, "\n")] = '\0'; // Remove a nova linha

        printf("Digite o código do produto: ");
        fgets(inventario->produtos[inventario->total].codigo, sizeof(inventario->produtos[inventario->total].codigo), stdin);
        inventario->produtos[inventario->total].codigo[strcspn(inventario->produtos[inventario->total].codigo, "\n")] = '\0'; // Remove a nova linha

        printf("Digite o preço do produto: ");
        scanf("%f", &inventario->produtos[inventario->total].preco);

        printf("Digite a quantidade do produto: ");
        scanf("%d", &inventario->produtos[inventario->total].quantidade);

        inventario->total++;
    } else {
        printf("Inventário cheio!\n");
    }
}

void listarProdutos(Inventario inventario) {
    printf("Lista de Produtos:\n");
    for (int i = 0; i < inventario.total; i++) {
        printf("Nome: %s, Código: %s, Preço: %.2f, Quantidade: %d\n",
               inventario.produtos[i].nome,
               inventario.produtos[i].codigo,
               inventario.produtos[i].preco,
               inventario.produtos[i].quantidade);
    }
}

int buscarProduto(Inventario inventario, const char *codigo) {
    for (int i = 0; i < inventario.total; i++) {
        if (strcmp(inventario.produtos[i].codigo, codigo) == 0) {
            return i; // Retorna o índice do produto encontrado
        }
    }
    return -1; // Retorna -1 se não encontrado
}

void salvarEmArquivo(Inventario inventario, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return;
    }

    for (int i = 0; i < inventario.total; i++) {
        fprintf(arquivo, "%s\n%s\n%.2f\n%d\n", inventario.produtos[i].nome, inventario.produtos[i].codigo, inventario.produtos[i].preco, inventario.produtos[i].quantidade);
    }

    fclose(arquivo);
    printf("Produtos salvos no arquivo %s com sucesso!\n", nomeArquivo);
}

void carregarDeArquivo(Inventario *inventario, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return;
    }

    while (fscanf(arquivo, "%99[^\n]\n%19[^\n]\n%f\n%d\n",
                  inventario->produtos[inventario->total].nome,
                  inventario->produtos[inventario->total].codigo,
                  &inventario->produtos[inventario->total].preco,
                  &inventario->produtos[inventario->total].quantidade) != EOF) {
        inventario->total++;
    }

    fclose(arquivo);
    printf("Produtos carregados do arquivo %s com sucesso!\n", nomeArquivo);
}

void liberarInventario(Inventario *inventario) {
    free(inventario->produtos);
    inventario->total = 0;
}

