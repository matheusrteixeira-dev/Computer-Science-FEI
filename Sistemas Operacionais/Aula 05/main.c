/*
 * Aula 05 - Simulador de escalonamento de processos (etapa inicial).
 * Lê os processos (duração, chegada e instantes de E/S) e os exibe.
 *
 * Compilação: gcc -Wall -Wextra -o simulador main.c source/input.c source/algorithm.c
 */
#include "include/algorithm.h"
#include "include/input.h"

int main(void) {
    ProcessList processos = receberInput();
    calcula(&processos);
    liberaProcessos(&processos);
    return 0;
}
