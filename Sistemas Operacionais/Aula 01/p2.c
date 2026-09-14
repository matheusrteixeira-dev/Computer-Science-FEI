/*
 * Aula 01 - Variante de p1.c que não verifica o retorno de malloc e nunca termina.
 * (Demonstração didática: mostra o comportamento do sistema sob falta de memória.)
 */
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int *s1;

    while(1){
        s1 = (int *) malloc (sizeof(int) * 100000000);
        printf("%p\n", (void*) s1);
    }

    return 0;
}
