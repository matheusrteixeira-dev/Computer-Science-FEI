/*
 * Aula 04 - Vetores: média, impressão, busca linear e contagem de elementos em comum.
 */
#include <stdio.h>

float media(const int *vetor, int tam) {
    float soma = 0;
    for (int i = 0; i < tam; i++)
        soma += vetor[i];
    return soma / tam;
}

void imprime(const int *v, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

/* Retorna a primeira posição de val em p, ou -1 se não encontrado. */
int busca(const int *p, int n, int val) {
    for (int i = 0; i < n; i++) {
        if (p[i] == val)
            return i;
    }
    return -1;
}

/* Conta quantos elementos de v2 também aparecem em v1. */
int contaInter(const int *v1, const int *v2, int tam1, int tam2) {
    int total = 0;
    for (int i = 0; i < tam2; i++) {
        int r = busca(v1, tam1, v2[i]);
        if (r != -1) {
            printf("Encontrado: %d\n", v1[r]);
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
    for (int i = 0; i < 5; i++)
        v2[i] = (2 * i * i - i + 3) % 50;

    imprime(v, 20);
    imprime(v2, 5);

    printf("O numero 15 ocorreu na posicao %d\n", busca(v, 20, 15));
    printf("Elementos em comum: %d\n", contaInter(v, v2, 20, 5));
    return 0;
}
