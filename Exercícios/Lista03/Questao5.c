#include <stdio.h>

int contarCaracteres(char *str) {
    int contador = 0;
    while (*str != '\0') {
        contador++;
        str++;
    }
    return contador;
}

int main() {
    char string[100];
    printf("Digite uma string: ");
    fgets(string, sizeof(string), stdin);
    int total = contarCaracteres(string);
    printf("Total de caracteres: %d\n", total);
}