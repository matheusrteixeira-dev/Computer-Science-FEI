/*
 * Aula 05 - Ordenação com função de troca e interseção de vetores ordenados.
 */
#include <stdio.h>

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Ordena o vetor em ordem crescente com bubble sort. */
void ordenar(int *vetor, int N) {
    for (int k = 0; k < N - 1; k++) {
        for (int j = 0; j < N - 1 - k; j++) {
            if (vetor[j] > vetor[j + 1])
                troca(&vetor[j], &vetor[j + 1]);
        }
    }
}

void imprimir(const int *vetor, int N) {
    for (int i = 0; i < N; ++i)
        printf("%d ", vetor[i]);
    printf("\n");
}

/*
 * Grava em c a interseção (sem repetições) dos vetores ordenados a e b,
 * percorrendo ambos simultaneamente em O(n1 + n2). Retorna o tamanho de c.
 */
int intersecao(const int *a, const int *b, int *c, int n1, int n2) {
    int e = 0, d = 0, k = 0;

    while (e < n1 && d < n2) {
        // Pula elementos repetidos.
        while (e + 1 < n1 && a[e] == a[e + 1])
            e++;
        while (d + 1 < n2 && b[d] == b[d + 1])
            d++;

        if (a[e] == b[d]) {
            c[k++] = a[e];
            e++;
            d++;
        } else if (a[e] < b[d]) {
            e++;
        } else {
            d++;
        }
    }
    return k;
}

int main(void) {
    int v[] = {1, 4, 6, 7, 9};
    int v1[] = {1, 6, 8, 11};
    int v2[4];

    int k = intersecao(v, v1, v2, 5, 4);
    imprimir(v2, k);

    int desordenado[] = {5, 3, 8, 1, 9, 2};
    ordenar(desordenado, 6);
    imprimir(desordenado, 6);

    return 0;
}
