# Aula 15 - Leitura e Escrita de Arquivos

## Objetivos da Aula

- Compreender como realizar operações de leitura e escrita de arquivos em diferentes linguagens de programação.
- Comparar a sintaxe e as funcionalidades de manipulação de arquivos em C, Python e Java.
- Explorar exemplos práticos em cada linguagem.

## Manipulação de Arquivos em C

### Abertura e Escrita de Arquivos

Em C, usamos a biblioteca `<stdio.h>` para manipular arquivos. A função `fopen` é utilizada para abrir arquivos, e `fprintf` para escrever.

#### Exemplo

```c
#include <stdio.h>

int main() {
    FILE *arquivo = fopen("exemplo.txt", "w"); // Abre para escrita

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    fprintf(arquivo, "Olá, mundo!\n"); // Escreve no arquivo
    fclose(arquivo); // Fecha o arquivo

    return 0;
}
```

### Leitura de Arquivos

Para ler dados, usamos `fgets` ou `fscanf`.

#### Exemplo de Leitura

```c
#include <stdio.h>

int main() {
    FILE *arquivo = fopen("exemplo.txt", "r"); // Abre para leitura
    char linha[100];

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha); // Imprime cada linha lida
    }

    fclose(arquivo); // Fecha o arquivo
    return 0;
}
```
