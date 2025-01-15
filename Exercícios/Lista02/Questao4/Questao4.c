#include <stdio.h>
#include "reserva.h"

int main() {
    const char *nomeArquivo = "reservas.txt";
    int opcao;

    printf("1. Fazer Reserva\n2. Listar Reservas\nEscolha uma opção: ");
    scanf("%d", &opcao);
    getchar(); // Consumir o caractere de nova linha

    if (opcao == 1) {
        fazerReserva(nomeArquivo);
    } else if (opcao == 2) {
        printf("Reservas:\n");
        listarReservas(nomeArquivo);
    } else {
        printf("Opção inválida!\n");
    }

    return 0;
}