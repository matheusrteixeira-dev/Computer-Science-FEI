/*
 * Aula 12 - Recursão: fatorial e contagem regressiva.
 * Cada chamada ocupa espaço na pilha; recursões muito profundas podem estourá-la.
 */
#include <stdio.h>

int fat(int i) {
    if (i <= 1)
        return 1;
    return i * fat(i - 1);
}

/* Imprime de i até 0. */
void contagem(int i) {
    printf("%d\n", i);
    if (i == 0)
        return;
    contagem(i - 1);
}

int main(void) {
    printf("5! = %d\n", fat(5));
    contagem(10);
    return 0;
}
