/*
 * Aula 01 - Primeiro programa em C: entrada e saída, condicionais e laços.
 *
 * Lê valores reais e aplica uma regra:
 *   - 0 <= x <= 10  -> dobra o valor;
 *   - 10 < x < 100  -> triplica o valor;
 *   - caso contrário, mantém o valor.
 * O programa termina quando a entrada não for um número (por exemplo, EOF).
 */
#include <locale.h>
#include <stdio.h>

int main(void) {
    setlocale(LC_ALL, "");

    float x = 0;
    printf("Entre com o valor: ");
    while (scanf("%f", &x) == 1) {
        if (x >= 0 && x <= 10)
            x *= 2;
        else if (x > 10 && x < 100)
            x *= 3;

        printf("Resultado: %.2f\n", x);
        printf("Entre com o valor: ");
    }

    return 0;
}
