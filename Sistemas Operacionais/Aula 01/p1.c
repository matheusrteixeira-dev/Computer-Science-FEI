/*
 * Aula 01 - Esgotamento do heap: aloca blocos de ~400 MB até malloc retornar NULL.
 * (Demonstração didática: o programa consome toda a memória disponível de propósito.)
 */
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int *s1;

    do {
        s1 = (int *) malloc (sizeof(int) * 100000000);
        printf("%p\n", (void*) s1);
    } while (s1 != 0);

    return 0;
}
