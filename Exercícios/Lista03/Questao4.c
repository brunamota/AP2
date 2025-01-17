#include <stdio.h>

typedef struct {
    int x;
    int y;
} Ponto;

void atualizarPonto(Ponto *p, int novoX, int novoY) {
    p->x = novoX;
    p->y = novoY;
}

int main() {
    Ponto p = {0, 0};
    printf("Antes: Ponto(%d, %d)\n", p.x, p.y);
    atualizarPonto(&p, 5, 10);
    printf("Depois: Ponto(%d, %d)\n", p.x, p.y);
}
