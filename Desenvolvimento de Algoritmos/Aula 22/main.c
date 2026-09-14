/*
 * Aula 22 - Ponteiros para funções: ordenação genérica de structs com critério configurável.
 */
#include <stdio.h>
#include <string.h>

struct Pessoa {
    int cod;
    char nome[100];
    int idade;
};

/* Tipo de função de comparação: retorna verdadeiro se a deve vir depois de b. */
typedef int (*Comparador)(struct Pessoa a, struct Pessoa b);

void troca(struct Pessoa *a, struct Pessoa *b) {
    struct Pessoa temp = *a;
    *a = *b;
    *b = temp;
}

int ehMaiorIdade(struct Pessoa a, struct Pessoa b) {
    return a.idade > b.idade;
}

int ehMaiorCod(struct Pessoa a, struct Pessoa b) {
    return a.cod > b.cod;
}

int ehMaiorNome(struct Pessoa a, struct Pessoa b) {
    return strcmp(a.nome, b.nome) > 0;
}

/* Bubble sort que usa a função de comparação recebida por parâmetro. */
void ordena(struct Pessoa *v, int n, Comparador ehMaior) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (ehMaior(v[j], v[j + 1]))
                troca(&v[j], &v[j + 1]);
        }
    }
}

void imprime(const struct Pessoa *v, int n) {
    for (int j = 0; j < n; ++j)
        printf("Cod: %d | Nome: %s | Idade: %d\n", v[j].cod, v[j].nome, v[j].idade);
    puts("");
}

int main(void) {
    struct Pessoa v[] = {
        {1, "Carla", 32},
        {6, "Bruno", 10},
        {3, "Diego", 5},
        {4, "Ana", 50},
    };

    ordena(v, 4, ehMaiorNome);
    imprime(v, 4);

    ordena(v, 4, ehMaiorIdade);
    imprime(v, 4);

    ordena(v, 4, ehMaiorCod);
    imprime(v, 4);

    return 0;
}
