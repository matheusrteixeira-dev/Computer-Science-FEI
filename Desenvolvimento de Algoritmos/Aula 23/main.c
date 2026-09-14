/*
 * Aula 23 - Ponteiros para funções passados como parâmetro de outras funções:
 * busca com regra de comparação e fator multiplicativo configuráveis.
 */
#include <stdio.h>

struct Ponto {
    int x;
    int y;
};

typedef int (*Fator)(void);
typedef int (*Regra)(const struct Ponto *, const struct Ponto *, Fator);

int retorna2(void) {
    return 2;
}

int retorna3(void) {
    return 3;
}

/* Verdadeiro se a.x == b.x * fator(). */
int comparaX(const struct Ponto *a, const struct Ponto *b, Fator fator) {
    return a->x == b->x * fator();
}

/* Verdadeiro se a.y == b.y * fator(). */
int comparaY(const struct Ponto *a, const struct Ponto *b, Fator fator) {
    return a->y == b->y * fator();
}

/* Retorna o índice do primeiro ponto de v que satisfaz a regra em relação a k, ou -1. */
int busca(const struct Ponto *v, int n, struct Ponto k, Regra regra, Fator fator) {
    for (int i = 0; i < n; i++) {
        if (regra(&v[i], &k, fator))
            return i;
    }
    return -1;
}

int main(void) {
    struct Ponto v[] = {{1, 1}, {6, 5}, {4, 0}, {1, 2}, {7, 4}, {8, 8}};
    struct Ponto b = {1, 0};

    printf("%d\n", busca(v, 6, b, comparaX, retorna2));
    printf("%d\n", busca(v, 6, b, comparaY, retorna3));

    return 0;
}
