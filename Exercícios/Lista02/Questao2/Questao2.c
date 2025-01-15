#include <stdio.h>
#include "Alunos.h"

#define MAX_ALUNOS 100

int main() {
    Aluno alunos[MAX_ALUNOS];
    int totalAlunos = 0;
    int op;

    do {
        printf("1- Adicionar aluno\n");
        printf("2- Listar alunos\n");
        printf("3- Media dos alunos\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                adicionarAluno(&alunos[totalAlunos]);
                totalAlunos++;
                break;
            case 2:
                listarAlunos(alunos, totalAlunos);
                break;
            case 3:
                for (int i = 0; i < totalAlunos; i++) {
                    printf("Média de %s: %.2f\n", alunos[i].nome, calcularMedia(alunos[i]));
                }
                break;
            case 0:
                printf("Saindo... ");
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }

    } while (op != 0);

}