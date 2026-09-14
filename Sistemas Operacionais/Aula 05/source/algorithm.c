#include "../include/algorithm.h"

#include <stdio.h>

void calcula(const ProcessList *lista) {
    printf("\n%d processo(s) cadastrado(s)\n", lista->size);

    for (int i = 0; i < lista->size; i++) {
        const Process *p = &lista->items[i];
        printf("P%d: chegada = %d, duracao = %d, E/S =", i + 1, p->arrival, p->duration);

        if (p->numberIO == 0)
            printf(" nenhuma");
        for (int j = 0; j < p->numberIO; j++)
            printf(" %d", p->interruptions[j]);
        printf("\n");
    }
}
