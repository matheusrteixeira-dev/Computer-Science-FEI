/*
 * Aula 02 - Média de uma sequência de inteiros terminada por -1.
 */
#include <stdio.h>

int main(void) {
    float soma = 0;
    int n = 0;
    int atual;

    while (scanf("%d", &atual) == 1 && atual != -1) {
        soma += atual;
        n++;
    }

    if (n > 0)
        printf("%f\n", soma / n);
    else
        printf("Nenhum numero!\n");

    return 0;
}
