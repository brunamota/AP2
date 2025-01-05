# Aula 15 - Leitura e Escrita de Arquivos em Diferentes Linguagens

## Objetivos da Aula

- Compreender como realizar operações de leitura e escrita de arquivos em diferentes linguagens de programação.
- Comparar a sintaxe e as funcionalidades de manipulação de arquivos em C, Python e Java.
- Explorar exemplos práticos em cada linguagem.

## 1. Manipulação de Arquivos em C

### 1.1. Abertura e Escrita de Arquivos

Em C, usamos a biblioteca `<stdio.h>` para manipular arquivos. A função `fopen` é utilizada para abrir arquivos, e `fprintf` para escrever.

#### Exemplo em C

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

### 1.2. Leitura de Arquivos

Para ler dados, usamos `fgets` ou `fscanf`.

#### Exemplo de Leitura em C

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

## 2. Manipulação de Arquivos em Python

Python oferece uma maneira mais simples e intuitiva para manipulação de arquivos, utilizando a função `open()`.

### 2.1. Abertura e Escrita de Arquivos

#### Exemplo em Python

```python
# Escrita em arquivo
with open("exemplo.txt", "w") as arquivo:
    arquivo.write("Olá, mundo!\n")  # Escreve no arquivo
```

### 2.2. Leitura de Arquivos

#### Exemplo de Leitura em Python

```python
# Leitura de arquivo
with open("exemplo.txt", "r") as arquivo:
    for linha in arquivo:
        print(linha, end='')  # Imprime cada linha lida
```

## 3. Manipulação de Arquivos em Java

Em Java, a classe `FileWriter` é usada para escrever em arquivos, e `FileReader` para ler.

### 3.1. Abertura e Escrita de Arquivos

#### Exemplo em Java

```java
import java.io.FileWriter;
import java.io.IOException;

public class Main {
    public static void main(String[] args) {
        try (FileWriter arquivo = new FileWriter("exemplo.txt")) {
            arquivo.write("Olá, mundo!\n"); // Escreve no arquivo
        } catch (IOException e) {
            System.out.println("Erro ao abrir o arquivo!");
        }
    }
}
```

### 3.2. Leitura de Arquivos

#### Exemplo de Leitura em Java

```java
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) {
        try (BufferedReader arquivo = new BufferedReader(new FileReader("exemplo.txt"))) {
            String linha;
            while ((linha = arquivo.readLine()) != null) {
                System.out.println(linha); // Imprime cada linha lida
            }
        } catch (IOException e) {
            System.out.println("Erro ao abrir o arquivo!");
        }
    }
}
```

## 4. Comparação entre as Linguagens

- **C**:
  - Mais detalhado e exige gerenciamento manual de memória.
  - Uso de ponteiros e funções específicas para manipulação de arquivos.
  
- **Python**:
  - Sintaxe simples e intuitiva.
  - Gerenciamento automático de recursos com `with`.
  
- **Java**:
  - Orientado a objetos, utilizando classes para manipulação de arquivos.
  - Tratamento de exceções obrigatório para operações de I/O.

## 5. Conclusão

Nesta aula, exploramos a leitura e escrita de arquivos em C, Python e Java, comparando as abordagens de cada linguagem. Cada uma tem suas próprias características e sintaxes, mas todas permitem manipular arquivos de forma eficaz.

Se você tiver dúvidas ou quiser discutir mais sobre manipulação de arquivos em diferentes linguagens, sinta-se à vontade para perguntar!
