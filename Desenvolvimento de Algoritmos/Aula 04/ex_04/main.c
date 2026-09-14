/*
 * Aula 04 - Exercícios com vetores: média, busca, ordenação (bubble sort) e incidências.
 * Um vetor ocupa uma área contínua da memória: v[i] equivale a *(v + i).
 */
#include <stdio.h>

float media(const int *vetor, int N) {
    float soma = 0;
    for (int i = 0; i < N; ++i)
        soma += vetor[i];
    return soma / N;
}

void imprimir(const int *vetor, int N) {
    for (int i = 0; i < N; i++)
        printf("%d ", *(vetor + i));
    printf("\n");
}

/* Retorna a posição de x no vetor, ou -1 se não encontrado. */
int busca(const int *vetor, int N, int x) {
    for (int i = 0; i < N; i++) {
        if (vetor[i] == x)
            return i;
    }
    return -1;
}

/* Ordena o vetor em ordem crescente com bubble sort. */
void ordenar(int *vetor, int N) {
    for (int k = 1; k < N; k++) {
        for (int j = 0; j < N - k; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

/* Conta quantas vezes os elementos de v1 aparecem em v. */
int incidencias(const int *v, const int *v1, int N, int N2) {
    int total = 0;
    for (int i = 0; i < N2; i++) {
        for (int j = 0; j < N; j++) {
            if (v[j] == v1[i])
                total++;
        }
    }
    return total;
}

int main(void) {
    int v[20];
    int v2[5];

    for (int i = 0; i < 20; i++)
        v[i] = (5 * i * i - i + 3) % 50;
    for (int j = 0; j < 5; j++)
        v2[j] = (2 * j * j - j + 3) % 50;

    imprimir(v, 20);
    imprimir(v2, 5);

    printf("Media de v: %.1f\n", media(v, 20));
    printf("O numero 15 ocorreu na posicao: %d\n", busca(v, 20, 15));
    printf("Total de incidencias: %d\n", incidencias(v, v2, 20, 5));

    ordenar(v, 20);
    imprimir(v, 20);

    return 0;
}
