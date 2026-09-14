/*
 * Aula 10 - Strings em C: vetores de char terminados em '\0'.
 */
#include <stdio.h>

/* Copia origem para dest, incluindo o terminador '\0'. */
void copiaString(char *dest, const char *origem) {
    int i;
    for (i = 0; origem[i] != '\0'; i++)
        dest[i] = origem[i];
    dest[i] = '\0';
}

void imprimeString(const char *string) {
    for (int i = 0; string[i] != '\0'; i++)
        printf("%c", string[i]);
    printf("\n");
}

/* Substitui todas as letras 'A' por 'Z' e imprime o resultado. */
void trocaAPorZ(char *string) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == 'A')
            string[i] = 'Z';
    }
    printf("%s\n", string);
}

/* Substitui todas as letras minúsculas por espaços e imprime o resultado. */
void trocaMinuscula(char *string) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] >= 'a' && string[i] <= 'z')
            string[i] = ' ';
    }
    printf("%s", string);
}

int main(void) {
    char s[10];

    copiaString(s, "ABC");
    printf("%s\n", s);

    imprimeString("ABCDEDF");

    copiaString(s, "ABCDAEF");
    trocaAPorZ(s);

    char linha[100];
    if (fgets(linha, sizeof(linha), stdin) != NULL)
        trocaMinuscula(linha);

    return 0;
}
