/*
 * Aula 07 - Desvio padrão de n números lidos do usuário, com alocação dinâmica.
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

    for (int i = 0; i < *pn; i++)
        scanf("%f", &v[i]);
    return v;
}

/* Desvio padrão populacional dos n valores de a. */
float calcDesvio(const float *a, int n) {
    float media = 0;
    for (int i = 0; i < n; i++)
        media += a[i];
    media /= n;

    float dp = 0;
    for (int i = 0; i < n; i++)
        dp += pow(a[i] - media, 2);
    return sqrt(dp / n);
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
