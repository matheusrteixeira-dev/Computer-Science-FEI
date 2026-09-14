/*
 * Aula 04 - Criação e junção de duas threads que executam uma tarefa longa de CPU.
 * Enquanto as threads trabalham, a thread principal dorme por 5 segundos.
 */
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define ITERACOES 10000000000UL

static void *funcao(void *args) {
    (void) args;
    unsigned long soma = 0;

    printf("Iniciando contagem na thread...\n");
    for (unsigned long i = 0; i < ITERACOES; i++)
        soma += i;

    printf("Saindo da thread! (soma = %lu)\n", soma);
    return NULL;
}

int main(void) {
    pthread_t t1, t2;

    printf("Criando T1\n");
    pthread_create(&t1, NULL, funcao, NULL);

    printf("Criando T2\n");
    pthread_create(&t2, NULL, funcao, NULL);

    printf("Dormindo...\n");
    sleep(5);

    printf("Juntando tudo...\n");
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Saindo da main!\n");
    return 0;
}
