/*
 * Aula 01 - Escrita fora dos limites de uma área alocada no heap.
 * (Demonstração didática de comportamento indefinido; pode ou não gerar segmentation fault.)
 */
#include <stdlib.h>
#include <stdio.h>

int v1;

int main(void) {
    int v2;
    int *v3 = malloc(sizeof(int));

    v3[100] = 4;

    return 0;
}
