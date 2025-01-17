#include <stdio.h>
#include "GestaoInventario.h"

int main() {
    Inventario inventario;
    inicializarInventario(&inventario);
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Buscar Produto\n");
        printf("4. Salvar em Arquivo\n");
        printf("5. Carregar de Arquivo\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Consumir a nova linha

        switch (opcao) {
            case 1:
                adicionarProduto(&inventario);
                break;
            case 2:
                listarProdutos(inventario);
                break;
            case 3: {
                char codigo[20];
                printf("Digite o código do produto a buscar: ");
                fgets(codigo, sizeof(codigo), stdin);
                codigo[strcspn(codigo, "\n")] = '\0'; // Remove a nova linha

                int indice = buscarProduto(inventario, codigo);
                if (indice != -1) {
                    printf("Produto encontrado: Nome: %s, Código: %s, Preço: %.2f, Quantidade: %d\n",
                           inventario.produtos[indice].nome,
                           inventario.produtos[indice].codigo,
                           inventario.produtos[indice].preco,
                           inventario.produtos[indice].quantidade);
                } else {
                    printf("Produto não encontrado.\n");
                }
                break;
            }
            case 4: {
                char nomeArquivo[100];
                printf("Digite o nome do arquivo para salvar: ");
                fgets(nomeArquivo, sizeof(nomeArquivo), stdin);
                nomeArquivo[strcspn(nomeArquivo, "\n")] = '\0'; // Remove a nova linha

                salvarEmArquivo(inventario, nomeArquivo);
                break;
            }
            case 5: {
                char nomeArquivo[100];
                printf("Digite o nome do arquivo para carregar: ");
                fgets(nomeArquivo, sizeof(nomeArquivo), stdin);
                nomeArquivo[strcspn(nomeArquivo, "\n")] = '\0'; // Remove a nova linha

                carregarDeArquivo(&inventario, nomeArquivo);
                break;
            }
            case 0:
                printf("Saindo...\n");
                liberarInventario(&inventario);
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 0);
}