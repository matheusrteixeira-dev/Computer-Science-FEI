/*
 * Aula 02 - Alocação dinâmica: soma elemento a elemento de dois vetores de tamanho n.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Tamanho de float: %zu bytes\n", sizeof(float));

    int n;
    if (scanf("%d", &n) != 1 || n <= 0)
        return 1;

    float *b1 = malloc(sizeof(float) * n);
    float *b2 = malloc(sizeof(float) * n);
    float *b3 = malloc(sizeof(float) * n);
    if (b1 == NULL || b2 == NULL || b3 == NULL) {
        free(b1);
        free(b2);
        free(b3);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%f", b1 + i);
        scanf("%f", b2 + i);
        b3[i] = b1[i] + b2[i];
        printf("%f ", b3[i]);
    }
    printf("\n");

    free(b1);
    free(b2);
    free(b3);
    return 0;
}
