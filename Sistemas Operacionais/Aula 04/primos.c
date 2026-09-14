/*
 * Aula 04 - Números primos até LIMITE contando divisores em paralelo com duas threads.
 *
 * Para cada valor v, os candidatos a divisor em [1, v/2] são divididos em duas faixas,
 * cada uma verificada por uma thread. v é primo se o único divisor encontrado for 1.
 */
#include <pthread.h>
#include <stdio.h>

#define LIMITE 100

typedef struct {
    int valor;    // número testado
    int inicio;   // primeiro candidato a divisor (inclusive)
    int fim;      // último candidato a divisor (exclusive)
    int divisores; // resultado: quantidade de divisores na faixa
} Faixa;

/* Conta os divisores de faixa->valor em [inicio, fim). Cada thread escreve apenas na própria faixa. */
static void *conta_divisores(void *args) {
    Faixa *faixa = (Faixa *) args;
    faixa->divisores = 0;
    for (int i = faixa->inicio; i < faixa->fim; i++) {
        if (faixa->valor % i == 0)
            faixa->divisores++;
    }
    return NULL;
}

int main(void) {
    for (int valor = 2; valor <= LIMITE; valor++) {
        int metade = valor / 2 + 1; // candidatos a divisor próprio: 1..valor/2
        int quarto = metade / 2;

        Faixa parte1 = {valor, 1, quarto > 1 ? quarto : 1, 0};
        Faixa parte2 = {valor, parte1.fim, metade, 0};

        pthread_t t1, t2;
        pthread_create(&t1, NULL, conta_divisores, &parte1);
        pthread_create(&t2, NULL, conta_divisores, &parte2);
        pthread_join(t1, NULL);
        pthread_join(t2, NULL);

        if (parte1.divisores + parte2.divisores == 1)
            printf("O numero e primo: %d\n", valor);
    }
    return 0;
}
