# Aula 08 - Funções Recursivas: Exemplos Práticos

## Revisão de Funções Recursivas

Recapitulando, uma função recursiva é uma função que chama a si mesma para resolver um problema. Importante lembrar que toda função recursiva deve ter um caso base que interrompe a recursão.

## Exemplos Práticos

### Exemplo 1: Potência de um Número

Vamos criar uma função recursiva que calcula a potência de um número `base` elevado a um `expoente`.

#### Definição Recursiva:

- Caso Base: \( \text{potencia}(b, 0) = 1 \)
- Caso Recursivo: \( \text{potencia}(b, e) = b \times \text{potencia}(b, e - 1) \)

#### Implementação em C

```c
#include <stdio.h>

// Função recursiva para calcular a potência
int potencia(int base, int expoente) {
    // Caso base
    if (expoente == 0) {
        return 1;
    }
    // Caso recursivo
    return base * potencia(base, expoente - 1);
}

int main() {
    int base = 2;
    int expoente = 3;
    printf("%d elevado a %d é %d\n", base, expoente, potencia(base, expoente));
    return 0;
}
```

### Exemplo 2: Inversão de uma String

Vamos criar uma função recursiva que inverte uma string.

#### Definição Recursiva:

- Caso Base: Se a string estiver vazia ou tiver um único caractere, retorne a própria string.
- Caso Recursivo: Retorne o último caractere seguido da chamada recursiva para a substring sem o último caractere.

#### Implementação em C

```c
#include <stdio.h>
#include <string.h>

// Função recursiva para inverter uma string
void inverterString(char *str, int inicio, int fim) {
    // Caso base
    if (inicio >= fim) {
        return;
    }
    // Troca os caracteres
    char temp = str[inicio];
    str[inicio] = str[fim];
    str[fim] = temp;

    // Chamada recursiva
    inverterString(str, inicio + 1, fim - 1);
}

int main() {
    char str[] = "Recursão";
    int n = strlen(str);
    inverterString(str, 0, n - 1);
    printf("String invertida: %s\n", str);
    return 0;
}
```

### Exemplo 3: Soma de Números Naturais

Vamos criar uma função recursiva que calcula a soma de todos os números naturais até `n`.

#### Definição Recursiva:

- Caso Base: \( \text{soma}(0) = 0 \)
- Caso Recursivo: \( \text{soma}(n) = n + \text{soma}(n - 1) \)

#### Implementação em C

```c
#include <stdio.h>

// Função recursiva para calcular a soma de números naturais
int soma(int n) {
    // Caso base
    if (n == 0) {
        return 0;
    }
    // Caso recursivo
    return n + soma(n - 1);
}

int main() {
    int n = 5;
    printf("Soma dos primeiros %d números naturais: %d\n", n, soma(n));
    return 0;
}
```

## Comparação com Soluções Iterativas

Embora a recursão seja elegante e muitas vezes mais fácil de entender, é importante considerar a eficiência. Em alguns casos, uma solução iterativa pode ser mais eficiente em termos de desempenho e uso de memória. Por exemplo, a soma de números naturais pode ser feita com uma simples fórmula \( \frac{n(n + 1)}{2} \).

### Exemplo Iterativo para Soma

```c
#include <stdio.h>

// Função iterativa para calcular a soma de números naturais
int somaIterativa(int n) {
    int soma = 0;
    for (int i = 1; i <= n; i++) {
        soma += i;
    }
    return soma;
}

int main() {
    int n = 5;
    printf("Soma dos primeiros %d números naturais (iterativa): %d\n", n, somaIterativa(n));
    return 0;
}
```

## 4. Conclusão

Nesta aula, exploramos funções recursivas com exemplos práticos, como calcular potência, inverter uma string e somar números naturais. Também discutimos a comparação entre soluções recursivas e iterativas, destacando a importância de escolher a abordagem mais adequada para cada problema.

Se você tiver dúvidas ou quiser discutir mais exemplos de funções recursivas, sinta-se à vontade para perguntar!
