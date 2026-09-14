#ifndef PROCESS_H_
#define PROCESS_H_

/* Processo para o simulador de escalonamento. */
typedef struct {
    int duration;       // tempo total de CPU necessário
    int arrival;        // instante de chegada
    int numberIO;       // quantidade de operações de E/S
    int *interruptions; // instantes (relativos à execução) em que ocorrem as E/S
} Process;

/* Conjunto de processos lidos da entrada. */
typedef struct {
    int size;
    Process *items;
} ProcessList;

#endif
