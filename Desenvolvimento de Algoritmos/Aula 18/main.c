/*
 * Aula 18 - Leitura e escrita de arquivos texto.
 * Lê o primeiro número real do arquivo arq.txt e grava um arquivo de contagem.
 */
#include <stdio.h>

int main(void) {
    FILE *entrada = fopen("arq.txt", "r");
    if (entrada == NULL) {
        perror("Erro ao abrir arq.txt");
        return 1;
    }

    float x;
    if (fscanf(entrada, "%f", &x) == 1)
        printf("Lido: %f\n", x);
    else
        puts("Nenhum numero encontrado em arq.txt");
    fclose(entrada);

    FILE *saida = fopen("contagem.txt", "w");
    if (saida == NULL) {
        perror("Erro ao criar contagem.txt");
        return 1;
    }
    for (int i = 0; i < 10; ++i)
        fprintf(saida, "contagem %d\n", i);
    fclose(saida);

    return 0;
}
