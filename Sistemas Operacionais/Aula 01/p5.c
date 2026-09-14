/*
 * Aula 01 - Estouro de buffer na pilha: sobrescreve o endereço de retorno de chamada()
 * para desviar a execução para esquecida(). (Demonstração didática de comportamento indefinido.)
 */
#include <stdlib.h>
#include <stdio.h>

void esquecida(){
    printf("Eu nunca sou chamada \n");
}

void chamada(){
    int* v[2];

    v[0] = NULL;
    v[1] = NULL;
    v[2] = NULL;
    v[3] = (int*) esquecida;

    printf("Eu fui chamada \n");
}

int main(void) {
    chamada();
    printf("Main prestes a acabar....\n");
    return 0;
}
