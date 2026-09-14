/*
 * Aula 04 - Passagem de argumentos para threads e coleta de valores de retorno.
 * Cria QTDE threads; cada uma recebe seu índice, executa uma tarefa longa e devolve um valor.
 */
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

#define QTDE 7
#define ITERACOES 10000000000UL

static void *funcao(void *args) {
    intptr_t indice = (intptr_t) args;
    unsigned long soma = (unsigned long) indice;

    printf("Iniciando contagem na thread %ld...\n", (long) indice);
    for (unsigned long i = 0; i < ITERACOES; i++)
        soma += i;

    printf("Saindo da thread %ld com %lu!\n", (long) indice, soma);
    return (void *) (uintptr_t) soma;
}

int main(void) {
    pthread_t ts[QTDE];

    for (intptr_t i = 0; i < QTDE; i++) {
        printf("Criando T%ld\n", (long) i + 1);
        pthread_create(&ts[i], NULL, funcao, (void *) i);
    }

    printf("Dormindo...\n");
    sleep(5);

    printf("Juntando tudo...\n");
    for (int i = 0; i < QTDE; i++) {
        void *resultado;
        pthread_join(ts[i], &resultado);
        printf("Resultado de T%d: %lu\n", i + 1, (unsigned long) (uintptr_t) resultado);
    }

    printf("Saindo!\n");
    return 0;
}
