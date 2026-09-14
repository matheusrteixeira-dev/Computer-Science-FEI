#include "../include/input.h"

#include <stdio.h>
#include <stdlib.h>

/* Lê um inteiro não negativo; em caso de entrada inválida, retorna 0. */
static int leInteiro(const char *mensagem) {
    int valor;
    printf("%s\n", mensagem);
    if (scanf("%d", &valor) != 1 || valor < 0)
        return 0;
    return valor;
}

ProcessList receberInput(void) {
    ProcessList lista = {0, NULL};

    lista.size = leInteiro("Quantos processos voce deseja inserir?");
    if (lista.size == 0)
        return lista;

    // Alocação no heap: a lista continua válida após o retorno da função.
    lista.items = calloc(lista.size, sizeof(Process));
    if (lista.items == NULL) {
        lista.size = 0;
        return lista;
    }

    for (int i = 0; i < lista.size; i++) {
        Process *process = &lista.items[i];

        printf("Criando o processo %d\n", i + 1);
        process->duration = leInteiro("Qual a duracao do processo?");
        process->arrival = leInteiro("Qual a chegada do processo?");
        process->numberIO = leInteiro("Quantas E/S existem no processo?");

        if (process->numberIO > 0)
            process->interruptions = malloc(process->numberIO * sizeof(int));
        if (process->interruptions == NULL)
            process->numberIO = 0;

        for (int j = 0; j < process->numberIO; j++)
            process->interruptions[j] = leInteiro("Quando ocorre a E/S?");
    }

    return lista;
}

void liberaProcessos(ProcessList *lista) {
    for (int i = 0; i < lista->size; i++)
        free(lista->items[i].interruptions);
    free(lista->items);
    lista->items = NULL;
    lista->size = 0;
}
