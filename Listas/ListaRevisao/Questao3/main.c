#include <stdio.h>
#include "geometria.h"

float calcularAreaCirculo(float raio) {
    return PI * raio * raio;
}

float calcularAreaRetangulo(float largura, float altura) {
    return largura * altura;
}

int main() {
    float raio, largura, altura;

    printf("Digite o raio do círculo: ");
    scanf("%f", &raio);
    printf("Área do círculo: %.2f\n", calcularAreaCirculo(raio));

    printf("Digite a largura e altura do retângulo: ");
    scanf("%f %f", &largura, &altura);
    printf("Área do retângulo: %.2f\n", calcularAreaRetangulo(largura, altura));

    return 0;
}
