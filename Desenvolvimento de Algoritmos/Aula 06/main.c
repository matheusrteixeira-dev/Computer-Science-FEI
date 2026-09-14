/*
 * Aula 06 - Alocação dinâmica (malloc/free), inversão de vetor, integração numérica
 * pela regra do trapézio e desvio padrão de N números.
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void imprimir(const int *vetor, int N) {
    for (int i = 0; i < N; ++i)
        printf("%d ", vetor[i]);
    printf("\n");
}

/* Inverte o vetor in-place. */
void reverso(int *v, int N) {
    for (int i = 0; i < N / 2; i++) {
        int temp = v[i];
        v[i] = v[N - 1 - i];
        v[N - 1 - i] = temp;
    }
}

double y(double x) {
    return x * x;
}

/* Integral de y(x) em [a, b] pela regra do trapézio com passo h. */
double integraTrapezio(double a, double b, double h) {
    double total = 0;
    for (double x = a; x < b; x += h)
        total += (y(x) + y(x + h)) * h / 2;
    return total;
}

/* Aloca um vetor de n inteiros no heap com todos os elementos iguais a x. */
int *aloca(int n, int x) {
    int *p = malloc(sizeof(int) * n);
    if (p == NULL)
        return NULL;
    for (int i = 0; i < n; ++i)
        p[i] = x;
    return p;
}

/* Lê n inteiros e retorna o desvio padrão populacional. */
double desvio(int n) {
    int *p = malloc(sizeof(int) * n);
    if (p == NULL)
        return 0;

    double media = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", p + i);
        media += p[i];
    }
    media /= n;

    double somaQuadrados = 0;
    for (int i = 0; i < n; ++i)
        somaQuadrados += pow(p[i] - media, 2);

    free(p);
    return sqrt(somaQuadrados / n);
}

int main(void) {
    int v[] = {1, 3, 2, 5, 9, 7};
    reverso(v, 6);
    imprimir(v, 6);

    printf("Integral de x^2 em [0, 5]: %f\n", integraTrapezio(0, 5, 0.0001));

    int n;
    printf("Quantidade de numeros desejados: ");
    if (scanf("%d", &n) != 1 || n <= 0)
        return 1;

    printf("Desvio padrao: %f\n", desvio(n));

    return 0;
}
