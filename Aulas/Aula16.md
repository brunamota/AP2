# Aula 16 - Utilização de Manipulação de Arquivos

## 1. Importância da Manipulação de Arquivos

A manipulação de arquivos é uma habilidade essencial em programação, pois permite que programas:

- Armazenem dados persistentemente.
- Façam backup de informações.
- Realizem leitura de configurações e logs.
- Compartilhem dados entre diferentes partes de um sistema.

## 2. Estrutura Básica para Manipulação de Arquivos

### 2.1. Abertura de Arquivo

Para manipular um arquivo, você deve primeiro abri-lo com o modo apropriado. Isso é feito utilizando as funções específicas de cada linguagem.

### 2.2. Leitura e Escrita

Após abrir o arquivo, você pode realizar operações de leitura ou escrita. É essencial garantir que o arquivo seja fechado após o uso para liberar recursos.

### 2.3. Tratamento de Erros

Sempre verifique se o arquivo foi aberto corretamente. O tratamento de erros é crucial para evitar falhas no programa.

## 3. Exemplos Práticos

### 3.1. Exemplo em C: Gerenciamento de Notas

Vamos criar um programa simples que permite adicionar notas a um arquivo e exibi-las.

#### 3.1.1. Código para Adicionar Notas

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

#### 3.1.2. Código para Exibir Notas

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

### 3.2. Exemplo em Python: Gerenciamento de Contatos

Vamos criar um programa que permite adicionar e listar contatos.

#### 3.2.1. Código para Adicionar Contatos

```python
def adicionar_contato(nome_arquivo):
    with open(nome_arquivo, "a") as arquivo:
        nome = input("Digite o nome do contato: ")
        telefone = input("Digite o telefone do contato: ")
        arquivo.write(f"{nome},{telefone}\n")  # Escreve contato no arquivo

adicionar_contato("contatos.txt")
```

#### 3.2.2. Código para Listar Contatos

```python
def listar_contatos(nome_arquivo):
    with open(nome_arquivo, "r") as arquivo:
        for linha in arquivo:
            nome, telefone = linha.strip().split(',')
            print(f"Nome: {nome}, Telefone: {telefone}")

listar_contatos("contatos.txt")
```

### 3.3. Exemplo em Java: Manipulação de Configurações

Vamos criar um programa que lê e grava configurações em um arquivo.

#### 3.3.1. Código para Gravar Configurações

```java
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Configuracao {
    public static void gravarConfiguracao(String nomeArquivo) {
        try (FileWriter arquivo = new FileWriter(nomeArquivo, true)) {
            Scanner scanner = new Scanner(System.in);
            System.out.print("Digite a configuração: ");
            String configuracao = scanner.nextLine();
            arquivo.write(configuracao + "\n"); // Escreve no arquivo
        } catch (IOException e) {
            System.out.println("Erro ao abrir o arquivo!");
        }
    }

    public static void main(String[] args) {
        gravarConfiguracao("configuracoes.txt");
    }
}
```

#### 3.3.2. Código para Ler Configurações

```java
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Configuracao {
    public static void lerConfiguracao(String nomeArquivo) {
        try (BufferedReader arquivo = new BufferedReader(new FileReader(nomeArquivo))) {
            String linha;
            while ((linha = arquivo.readLine()) != null) {
                System.out.println(linha); // Imprime cada configuração
            }
        } catch (IOException e) {
            System.out.println("Erro ao abrir o arquivo!");
        }
    }

    public static void main(String[] args) {
        lerConfiguracao("configuracoes.txt");
    }
}
```

## 4. Boas Práticas

- **Verifique se o arquivo foi aberto corretamente**: Sempre verifique se a abertura do arquivo foi bem-sucedida.
- **Use `with` em Python**: O uso da instrução `with` em Python garante que o arquivo seja fechado automaticamente.
- **Trate exceções**: Em Java, utilize blocos `try-catch` para gerenciar erros de I/O.
- **Feche os arquivos**: Sempre feche os arquivos após terminar as operações para liberar recursos.
