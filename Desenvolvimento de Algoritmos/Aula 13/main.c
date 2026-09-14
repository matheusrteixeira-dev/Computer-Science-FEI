/*
 * Aula 13 - Exercícios de recursão.
 */
#include <stdio.h>
#include <stdlib.h>

/* Soma 1 + 2 + ... + i. */
int somaPA(int i) {
    if (i <= 1)
        return i;
    return i + somaPA(i - 1);
}

/* Quantidade de dígitos de um inteiro não negativo. */
int digitos(int i) {
    if (i < 10)
        return 1;
    return digitos(i / 10) + 1;
}

/* Produto a * b (b >= 1) usando somas sucessivas. */
int produto(int a, int b) {
    if (b == 1)
        return a;
    return a + produto(a, b - 1);
}

/* a elevado a b, para b inteiro (inclusive negativo). */
float potencia(float a, int b) {
    if (b == 0)
        return 1;
    if (b < 0)
        return 1 / potencia(a, -b);
    return a * potencia(a, b - 1);
}

/* Máximo divisor comum pelo algoritmo de Euclides. */
int mdc(int a, int b) {
    if (a % b == 0)
        return b;
    return mdc(b, a % b);
}

/* Torre de potências de 2: t(1) = 1 e t(i) = 2^t(i - 1). */
int torreDePotencias(int i) {
    if (i == 1)
        return 1;
    return (int) potencia(2, torreDePotencias(i - 1));
}

int main(void) {
    printf("somaPA(100) = %d\n", somaPA(100));
    printf("digitos(12345) = %d\n", digitos(12345));
    printf("produto(100, 65) = %d\n", produto(100, 65));
    printf("potencia(2, -3) = %f\n", potencia(2, -3));
    printf("mdc(23732, 180) = %d\n", mdc(23732, 180));
    printf("torreDePotencias(4) = %d\n", torreDePotencias(4));

    return 0;
}
