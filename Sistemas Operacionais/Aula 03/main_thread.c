/*
 * Aula 03 - Fibonacci com threads POSIX: fib(n) = fib(n - 1) + fib(n - 2),
 * calculando cada parcela em uma thread.
 */
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

/* Recebe n (codificado no ponteiro) e devolve fib(n) (também codificado no ponteiro). */
static void *runner(void *arg) {
    int n = (int) (intptr_t) arg;
    return (void *) (intptr_t) fib(n);
}

static void imprime_instante(const struct timespec *t) {
    char buff[100];
    strftime(buff, sizeof buff, "%D %T", gmtime(&t->tv_sec));
    printf("Current time: %s.%09ld UTC\n", buff, t->tv_nsec);
}

static long long diferenca_ns(const struct timespec *inicio, const struct timespec *fim) {
    return (fim->tv_sec - inicio->tv_sec) * 1000000000LL + (fim->tv_nsec - inicio->tv_nsec);
}

int main(void) {
    const int n = 11;
    pthread_t t1, t2;

    printf("Iniciando\n");
    struct timespec inicio;
    timespec_get(&inicio, TIME_UTC);
    imprime_instante(&inicio);

    pthread_create(&t1, NULL, runner, (void *) (intptr_t) (n - 1));
    pthread_create(&t2, NULL, runner, (void *) (intptr_t) (n - 2));

    printf("Juntando tudo...\n");
    void *r1, *r2;
    pthread_join(t1, &r1);
    pthread_join(t2, &r2);

    int resultado = (int) (intptr_t) r1 + (int) (intptr_t) r2;
    printf("Resultado de fibonacci de %d: %d\n", n, resultado);

    printf("Saindo!\n");
    struct timespec fim;
    timespec_get(&fim, TIME_UTC);
    imprime_instante(&fim);
    printf("Tempo decorrido: %lld ns\n", diferenca_ns(&inicio, &fim));

    return 0;
}
