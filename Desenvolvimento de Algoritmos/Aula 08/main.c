/*
 * Aula 08 - Matrizes alocadas dinamicamente: criação, preenchimento, impressão,
 * multiplicação e liberação de memória.
 */
#include <stdio.h>
#include <stdlib.h>

/* Aloca uma matriz linha x coluna de inteiros (vetor de ponteiros para linhas). */
int **matriz(int linha, int coluna) {
    int **M = malloc(sizeof(int *) * linha);
    for (int i = 0; i < linha; i++)
        M[i] = malloc(sizeof(int) * coluna);
    return M;
}

void zera(int **M, int l, int c) {
    for (int i = 0; i < l; i++)
        for (int j = 0; j < c; j++)
            M[i][j] = 0;
}

/* Libera cada linha e o vetor de ponteiros. */
void destroi(int **M, int l) {
    for (int i = 0; i < l; ++i)
        free(M[i]);
    free(M);
}

void imprime(int **M, int l, int c) {
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < c; ++j)
            printf("%10d ", M[i][j]);
        printf("\n");
    }
}

/* Retorna a matriz produto M1 (l1 x c1) * M2 (c1 x c2), com dimensão l1 x c2. */
int **multiplicar(int **M1, int l1, int c1, int **M2, int c2) {
    int **MR = matriz(l1, c2);
    zera(MR, l1, c2);

    for (int a = 0; a < l1; a++)
        for (int b = 0; b < c2; b++)
            for (int i = 0; i < c1; i++)
                MR[a][b] += M1[a][i] * M2[i][b];
    return MR;
}

/* Preenche a matriz linha a linha com 1, 2, 3, ... */
void sequencia(int **M, int l, int c) {
    int z = 1;
    for (int i = 0; i < l; i++)
        for (int j = 0; j < c; j++)
            M[i][j] = z++;
}

/* Preenche a matriz com 0, 1, 2, ... começando pelo canto inferior direito, coluna a coluna. */
void preencher(int **M, int l, int c) {
    int z = 0;
    for (int j = c - 1; j >= 0; j--)
        for (int i = l - 1; i >= 0; i--)
            M[i][j] = z++;
}

/* Preenche a matriz em padrão de tabuleiro de xadrez com 0 e 1. */
void preencherZeroUm(int **M, int l, int c) {
    for (int i = 0; i < l; i++)
        for (int j = 0; j < c; j++)
            M[i][j] = (i + j) % 2;
}

int main(void) {
    int **M1 = matriz(3, 4);
    sequencia(M1, 3, 4);
    imprime(M1, 3, 4);
    puts("");

    int **M2 = matriz(4, 2);
    sequencia(M2, 4, 2);
    imprime(M2, 4, 2);
    puts("");

    int **M3 = multiplicar(M1, 3, 4, M2, 2);
    imprime(M3, 3, 2);
    puts("");

    destroi(M1, 3);
    destroi(M2, 4);
    destroi(M3, 3);

    int **M = matriz(4, 5);
    preencher(M, 4, 5);
    imprime(M, 4, 5);
    puts("");
    destroi(M, 4);

    int **M4 = matriz(4, 4);
    preencherZeroUm(M4, 4, 4);
    imprime(M4, 4, 4);
    destroi(M4, 4);

    return 0;
}
