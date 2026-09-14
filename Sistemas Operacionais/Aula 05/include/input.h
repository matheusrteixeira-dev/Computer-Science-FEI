#ifndef INPUT_H_
#define INPUT_H_

#include "process.h"

/* Lê os processos da entrada padrão. A lista deve ser liberada com liberaProcessos(). */
ProcessList receberInput(void);

void liberaProcessos(ProcessList *lista);

#endif
