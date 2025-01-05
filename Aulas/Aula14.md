# Aula 14 - Introdução à Manipulação de Arquivos em C

## Objetivos da Aula

- Compreender os conceitos básicos de manipulação de arquivos em C.
- Aprender sobre os modos de abertura de arquivos.
- Explorar funções para leitura e escrita de arquivos.

## 1. Conceitos Básicos

Manipulação de arquivos é um aspecto fundamental da programação, permitindo que um programa leia de e escreva em arquivos no disco. Isso é útil para armazenar dados permanentemente, como configurações, resultados de cálculos, ou qualquer informação que precise ser preservada entre execuções do programa.

### 1.1. Tipos de Arquivos

- **Arquivos de Texto**: Contêm dados em formato legível, como .txt e .csv.
- **Arquivos Binários**: Contêm dados em formato binário, não legível diretamente, como imagens e executáveis.

## 2. Abrindo Arquivos

Para manipular arquivos em C, utilizamos a biblioteca padrão `<stdio.h>`. A função principal para abrir um arquivo é `fopen`.

### 2.1. Modos de Abertura

Os modos de abertura determinam como o arquivo será manipulado:

- `"r"`: Abre um arquivo para leitura (o arquivo deve existir).
- `"w"`: Abre um arquivo para escrita (cria um novo arquivo ou sobrescreve um existente).
- `"a"`: Abre um arquivo para anexar (adiciona dados ao final do arquivo).
- `"r+"`: Abre um arquivo para leitura e escrita (o arquivo deve existir).
- `"w+"`: Abre um arquivo para leitura e escrita (cria um novo arquivo ou sobrescreve um existente).
- `"a+"`: Abre um arquivo para leitura e escrita (adiciona dados ao final do arquivo).

### Exemplo de Abertura de Arquivo

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

## 3. Lendo e Escrevendo Arquivos

### 3.1. Escrevendo em Arquivos

Usamos a função `fprintf` para escrever dados formatados em arquivos.

```c
FILE *arquivo = fopen("exemplo.txt", "w");
fprintf(arquivo, "Linha 1\n");
fprintf(arquivo, "Linha 2\n");
fclose(arquivo);
```

### 3.2. Lendo de Arquivos

A função `fscanf` é usada para ler dados formatados de arquivos.

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

## 4. Manipulação de Arquivos Binários

Para manipular arquivos binários, usamos as funções `fwrite` e `fread`.

### 4.1. Escrevendo um Arquivo Binário

```c
#include <stdio.h>

int main() {
    FILE *arquivo = fopen("dados.bin", "wb"); // Abre para escrita binária
    int numeros[] = {1, 2, 3, 4, 5};

    fwrite(numeros, sizeof(int), 5, arquivo); // Escreve um array
    fclose(arquivo); // Fecha o arquivo

    return 0;
}
```

### 4.2. Lendo um Arquivo Binário

```c
#include <stdio.h>

int main() {
    FILE *arquivo = fopen("dados.bin", "rb"); // Abre para leitura binária
    int numeros[5];

    fread(numeros, sizeof(int), 5, arquivo); // Lê os dados
    fclose(arquivo); // Fecha o arquivo

    for (int i = 0; i < 5; i++) {
        printf("%d ", numeros[i]); // Imprime os números lidos
    }
    printf("\n");

    return 0;
}
```

## 5. Conclusão

Nesta aula, aprendemos os conceitos básicos de manipulação de arquivos em C, incluindo como abrir, ler e escrever em arquivos de texto e binários. A manipulação de arquivos é uma habilidade essencial para qualquer programador que deseja criar aplicativos que interagem com dados persistentes.

Se você tiver dúvidas ou quiser discutir mais sobre manipulação de arquivos ou suas aplicações, sinta-se à vontade para perguntar!
