/*
 * Aula 08 - Matriz 7x4 de floats alocada dinamicamente e preenchida com 1, 2, 3, ...
 */
#include <stdio.h>
#include <stdlib.h>

#define LINHAS 7
#define COLUNAS 4

int main(void) {
    float **m = malloc(sizeof(float *) * LINHAS);
    for (int i = 0; i < LINHAS; ++i)
        m[i] = malloc(sizeof(float) * COLUNAS);

    int x = 1;
    for (int i = 0; i < LINHAS; ++i)
        for (int j = 0; j < COLUNAS; ++j)
            m[i][j] = x++;

    for (int i = 0; i < LINHAS; ++i) {
        for (int j = 0; j < COLUNAS; ++j)
            printf("%-6.1f  ", m[i][j]);
        puts("");
    }

    for (int i = 0; i < LINHAS; ++i)
        free(m[i]);
    free(m);

    return 0;
}
