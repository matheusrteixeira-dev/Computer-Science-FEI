/*
 * Aula 02 - Exercício: cálculo da conta de energia usando ponteiros.
 *
 * O valor por kWh depende da faixa de consumo:
 *   - 0 < consumo < 50    -> R$ 10,00
 *   - 50 <= consumo < 300 -> R$ 30,00
 *   - consumo >= 300      -> R$ 50,00
 */
#include <stdio.h>

int main(void) {
    float consumo = 0;
    float multiplicador = 0;
    float *p = &multiplicador; // ponteiro: endereço da variável na memória

    printf("Coloque o consumo em kWh\n");
    if (scanf("%f", &consumo) != 1)
        return 1;

    if (consumo > 0 && consumo < 50)
        *p = 10;
    else if (consumo >= 50 && consumo < 300)
        *p = 30;
    else if (consumo >= 300)
        *p = 50;
    else
        puts("Consumo invalido.");

    printf("Total a pagar R$: %.2f\n", consumo * multiplicador);

    return 0;
}
