/*
 * Aula 03 - Funções: declaração, implementação, retorno e passagem por referência.
 */
#include <stdio.h>

// Declaração (protótipo): a implementação pode vir depois do main.
int sub(int a, int b);

int soma(int a, int b) {
    return a + b;
}

/* Imprime "Ola" N vezes; não imprime nada se N < 2. */
void digaOi(int N) {
    if (N < 2)
        return;
    for (int i = 0; i < N; i++)
        printf("Ola\n");
}

/* Zera a variável apontada: como recebe o endereço, altera o valor original. */
void zeraInt(int *x) {
    *x = 0;
}

void troca(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int menor(int x, int y) {
    return (x < y) ? x : y;
}

int main(void) {
    int a = 10;
    int b = 50;

    printf("menor(%d, %d) = %d\n", a, b, menor(a, b));
    printf("soma(%d, %d) = %d\n", a, b, soma(a, b));
    printf("sub(%d, %d) = %d\n", a, b, sub(a, b));

    troca(&a, &b);
    printf("Apos troca: a = %d, b = %d\n", a, b);

    zeraInt(&a);
    printf("Apos zeraInt: a = %d\n", a);

    digaOi(3);

    return 0;
}

int sub(int a, int b) {
    return a - b;
}
