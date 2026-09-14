/*
 * Aula 03 - Exemplos de funções com e sem retorno e troca de valores por ponteiros.
 */
#include <stdio.h>

/* Imprime de 1 a n, interrompendo a função ao chegar em 15. */
void contaAte(int n) {
    for (int i = 1; i <= n; i++) {
        if (i == 15)
            return;
        printf("%d\n", i);
    }
    printf("Acabei\n");
}

void imprimeMsg(void) {
    printf("Mensagem aqui!\n");
}

int soma(int a, int b) {
    return a + b;
}

void copia(const int *src, int *dst) {
    *dst = *src;
}

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int x = 5;
    int y = 10;
    troca(&x, &y);

    printf("%d\n", x);
    printf("%d\n", y);

    return 0;
}
