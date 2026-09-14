/*
 * Aula 09 - Padrões em matrizes quadradas e ponto mais próximo da origem.
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int **matriz(int linha, int coluna) {
    int **M = malloc(sizeof(int *) * linha);
    for (int i = 0; i < linha; i++)
        M[i] = malloc(sizeof(int) * coluna);
    return M;
}

void destroi(int **M, int l) {
    for (int i = 0; i < l; ++i)
        free(M[i]);
    free(M);
}

void imprime(int **M, int l, int c) {
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < c; ++j)
            printf("%5d ", M[i][j]);
        printf("\n");
    }
}

/* Matriz triangular superior de uns (M[i][j] = 1 se j >= i). */
void preencherDiagonal1(int **M, int l) {
    for (int i = 0; i < l; ++i)
        for (int j = 0; j < l; ++j)
            M[i][j] = (j >= i);
}

/* Uns acima da diagonal secundária (M[i][j] = 1 se j < l - i). */
void preencherDiagonal2(int **M, int l) {
    for (int i = 0; i < l; ++i)
        for (int j = 0; j < l; ++j)
            M[i][j] = (j < l - i);
}

/* Triângulo de uns entre as duas diagonais (M[i][j] = 1 se i <= j < l - i). */
void preencherDiagonal3(int **M, int l) {
    for (int i = 0; i < l; ++i)
        for (int j = 0; j < l; ++j)
            M[i][j] = (j >= i && j < l - i);
}

float distancia(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void preencher(float *x, float *y, int n) {
    for (int i = 0; i < n; i++) {
        printf("Insira o ponto %d (x y): ", i + 1);
        scanf("%f %f", x + i, y + i);
    }
}

void imprimir(const float *x, const float *y, int n) {
    for (int j = 0; j < n; ++j)
        printf("Ponto %d: (%.2f, %.2f)\n", j + 1, x[j], y[j]);
}

/* Retorna o índice do ponto mais próximo de (xref, yref). */
int maisProximo(const float *xs, const float *ys, int n, float xref, float yref) {
    int idx = 0;
    float menorDist = distancia(xs[0], ys[0], xref, yref);

    for (int i = 1; i < n; ++i) {
        float dist = distancia(xs[i], ys[i], xref, yref);
        if (dist < menorDist) {
            menorDist = dist;
            idx = i;
        }
    }
    return idx;
}

int main(void) {
    int **M = matriz(5, 5);
    preencherDiagonal3(M, 5);
    imprime(M, 5, 5);
    destroi(M, 5);

    int n;
    puts("Digite a quantidade de pontos:");
    if (scanf("%d", &n) != 1 || n <= 0)
        return 1;

    float *xs = malloc(sizeof(float) * n);
    float *ys = malloc(sizeof(float) * n);

    preencher(xs, ys, n);
    imprimir(xs, ys, n);

    printf("Ponto mais proximo da origem: %d\n", maisProximo(xs, ys, n, 0, 0) + 1);

    free(xs);
    free(ys);
    return 0;
}
