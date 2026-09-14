/*
 * Aula 04 - Condição de corrida em memória compartilhada entre threads.
 *
 * O mesmo conjunto de depósitos (+1,5) e saques (-1,0) é executado três vezes:
 *   1. sem threads;
 *   2. com threads executadas uma após a outra (sem concorrência);
 *   3. com threads concorrentes, sem sincronização.
 * Nos dois primeiros casos o saldo final é 50.000.000; no terceiro, as atualizações
 * de `saldo` se sobrepõem e o resultado varia a cada execução (demonstração proposital).
 */
#include <pthread.h>
#include <stdio.h>

#define OPERACOES 100000000

static double saldo;

static void deposito(double valor) {
    saldo += valor;
}

static void saque(double valor) {
    saldo -= valor;
}

static void *muitos_depositos(void *args) {
    (void) args;
    for (size_t i = 0; i < OPERACOES; i++)
        deposito(1.5);
    return NULL;
}

static void *muitos_saques(void *args) {
    (void) args;
    for (size_t i = 0; i < OPERACOES; i++)
        saque(1.0);
    return NULL;
}

int main(void) {
    pthread_t t1, t2;

    // 1. Sem threads
    saldo = 0;
    muitos_depositos(NULL);
    muitos_saques(NULL);
    printf("Saldo final (sem threads)  : %lf\n", saldo);

    // 2. Threads sequenciais
    saldo = 0;
    pthread_create(&t1, NULL, muitos_depositos, NULL);
    pthread_join(t1, NULL);
    pthread_create(&t2, NULL, muitos_saques, NULL);
    pthread_join(t2, NULL);
    printf("Saldo final (sync  threads): %lf\n", saldo);

    // 3. Threads concorrentes (condição de corrida)
    saldo = 0;
    pthread_create(&t1, NULL, muitos_depositos, NULL);
    pthread_create(&t2, NULL, muitos_saques, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Saldo final (*com* threads): %lf\n", saldo);

    return 0;
}
