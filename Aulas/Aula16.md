# Aula 16 - Utilização de Manipulação de Arquivos

## Importância da Manipulação de Arquivos

A manipulação de arquivos é uma habilidade essencial em programação, pois permite que programas:

- Armazenem dados persistentemente.
- Façam backup de informações.
- Realizem leitura de configurações e logs.
- Compartilhem dados entre diferentes partes de um sistema.

## Estrutura Básica para Manipulação de Arquivos

- **Abertura de Arquivo:** Para manipular um arquivo, você deve primeiro abri-lo com o modo apropriado. Isso é feito utilizando as funções específicas de cada linguagem.

- **Leitura e Escrita:** Após abrir o arquivo, você pode realizar operações de leitura ou escrita. É essencial garantir que o arquivo seja fechado após o uso para liberar recursos.

- **Tratamento de Erros:** Sempre verifique se o arquivo foi aberto corretamente. O tratamento de erros é crucial para evitar falhas no programa.

## Exemplos Práticos

### Exemplo: Gerenciamento de Notas

Vamos criar um programa simples que permite adicionar notas a um arquivo e exibi-las.

#### Código para Adicionar Notas

```c
#include <stdio.h>

void adicionarNota(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "a"); // Abre para anexar

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    char nota[100];
    printf("Digite a nota: ");
    fgets(nota, sizeof(nota), stdin);
    fprintf(arquivo, "%s", nota); // Escreve a nota no arquivo
    fclose(arquivo); // Fecha o arquivo
}

int main() {
    adicionarNota("notas.txt");
    return 0;
}
```

#### Código para Exibir Notas

```c
#include <stdio.h>

void exibirNotas(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r"); // Abre para leitura

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha); // Imprime cada nota
    }

    fclose(arquivo); // Fecha o arquivo
}

int main() {
    exibirNotas("notas.txt");
    return 0;
}
```
