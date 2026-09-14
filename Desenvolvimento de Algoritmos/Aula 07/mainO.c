/*
 * Aula 07 - Versão alternativa do cálculo do desvio padrão (leitura com aritmética de ponteiros).
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* Lê a quantidade de números (gravada em *pn) e os valores; retorna o vetor alocado. */
float *entraDadosUsuario(int *pn) {
    puts("Quantos numeros?");
    if (scanf("%d", pn) != 1 || *pn <= 0)
        return NULL;

    float *v = malloc(sizeof(float) * *pn);
    if (v == NULL)
        return NULL;

    for (int i = 0; i < *pn; ++i)
        scanf("%f", v + i);
    return v;
}

/* Desvio padrão populacional dos b valores de a. */
float calcDesvio(const float *a, int b) {
    float media = 0;
    for (int i = 0; i < b; ++i)
        media += a[i];
    media /= b;

    float dp = 0;
    for (int i = 0; i < b; i++)
        dp += pow(a[i] - media, 2);
    return sqrt(dp / b);
}

int main(void) {
    int n;
    float *v = entraDadosUsuario(&n);
    if (v == NULL)
        return 1;

    printf("%f\n", calcDesvio(v, n));

    free(v);
    return 0;
}
