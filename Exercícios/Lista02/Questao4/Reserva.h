#include <stdio.h>

typedef struct {
    char nome[50];
    int numeroQuarto;
} Reserva;

void fazerReserva(char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para reservas!\n");
        return;
    }

    Reserva reserva;
    printf("Nome do cliente: ");
    fgets(reserva.nome, sizeof(reserva.nome), stdin);
    printf("Número do quarto: ");
    scanf("%d", &reserva.numeroQuarto);
    getchar(); // Consumir o caractere de nova linha

    fprintf(arquivo, "%s%d\n", reserva.nome, reserva.numeroQuarto);
    fclose(arquivo);
}

void listarReservas(char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para listar reservas!\n");
        return;
    }

    Reserva reserva;
    while (fscanf(arquivo, "%s%d\n", reserva.nome, &reserva.numeroQuarto) != EOF) {
        printf("Hospede: %sNúmero do Quarto: %d\n", reserva.nome, reserva.numeroQuarto);
    }
    fclose(arquivo);
}