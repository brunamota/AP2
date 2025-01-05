# Aula 1 - Introdução às Estruturas de Dados Heterogêneas

## O que são Estruturas de Dados Heterogêneas?

- Estruturas de dados heterogêneas são aquelas que podem armazenar diferentes tipos de dados sob um mesmo nome. Isso é útil quando precisamos agregar informações de diferentes tipos que fazem parte de uma mesma entidade. Em C, isso é frequentemente realizado através de struct.

## Definindo e Usando struct em C

Em C, uma struct é definida utilizando a palavra-chave **struct**. Aqui está um exemplo básico:

- Exemplo: Uma struct que representa um aluno pode conter um nome (string), uma idade (inteiro) e uma nota (float).
```C
#include <stdio.h>
#include <string.h>

// Definição da estrutura 'Aluno'
struct Aluno {
    char nome[50];
    int idade;
    float nota;
};
```

### Criando e Inicializando Estruturas

Para criar uma instância de uma struct, você pode fazer o seguinte:
```C
int main() {
    // Criação de uma variável do tipo 'Aluno'
    struct Aluno aluno1;

    // Inicializando os campos
    strcpy(aluno1.nome, "Maria");
    aluno1.idade = 20;
    aluno1.nota = 8.5;

    // Exibindo os dados
    printf("Nome: %s\n", aluno1.nome);
    printf("Idade: %d\n", aluno1.idade);
    printf("Nota: %.2f\n", aluno1.nota);

    return 0;
}
```
### Acessando Campos da struct
Os campos de uma struct são acessados utilizando o operador ponto (.):

```C
printf("Nome: %s\n", aluno1.nome);
```

## Exemplo Prático feito em sala:

```C
#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 100

struct Aluno {
    char nome[50];
    int idade;
    float nota;
};

int main() {
    struct Aluno alunos[MAX_ALUNOS];
    int i, numAlunos;

    printf("Digite o número de alunos: ");
    scanf("%d", &numAlunos);

    for (i = 0; i < numAlunos; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf("%s", alunos[i].nome);
        printf("Digite a idade do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].idade);
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota);
    }

    printf("\nLista de Alunos:\n");
    for (i = 0; i < numAlunos; i++) {
        printf("Nome: %s, Idade: %d, Nota: %.2f\n", alunos[i].nome, alunos[i].idade, alunos[i].nota);
    }
}
```
