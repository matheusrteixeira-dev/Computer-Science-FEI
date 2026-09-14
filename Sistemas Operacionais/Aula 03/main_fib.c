/*
 * Aula 03 - Medição do tempo de execução de Fibonacci recursivo (versão sequencial).
 */
#include <stdio.h>
#include <time.h>

int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

/* Imprime o instante atual em UTC com precisão de nanossegundos. */
static void imprime_instante(const struct timespec *t) {
    char buff[100];
    strftime(buff, sizeof buff, "%D %T", gmtime(&t->tv_sec));
    printf("Current time: %s.%09ld UTC\n", buff, t->tv_nsec);
}

/* Diferença fim - inicio em nanossegundos. */
static long long diferenca_ns(const struct timespec *inicio, const struct timespec *fim) {
    return (fim->tv_sec - inicio->tv_sec) * 1000000000LL + (fim->tv_nsec - inicio->tv_nsec);
}

int main(void) {
    const int n = 10;

    printf("\nSerie de Fibonacci:\n\n");
    printf("Iniciando\n");
    struct timespec inicio;
    timespec_get(&inicio, TIME_UTC);
    imprime_instante(&inicio);

    printf("fib(%d) = %d\n", n, fib(n));

    printf("Saindo!\n");
    struct timespec fim;
    timespec_get(&fim, TIME_UTC);
    imprime_instante(&fim);
    printf("Tempo decorrido: %lld ns\n", diferenca_ns(&inicio, &fim));

    return 0;
}
