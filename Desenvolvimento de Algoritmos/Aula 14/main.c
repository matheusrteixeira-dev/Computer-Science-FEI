/*
 * Aula 14 - Estruturas (struct): definição, passagem por valor e por referência.
 */
#include <stdio.h>
#include <string.h>

struct pessoa {
    char nome[80];
    int idade;
    char endereco[80];
    char cep[20];
};

struct ponto {
    float x;
    float y;
};

struct circulo {
    struct ponto centro;
    float raio;
};

/* Lê uma linha com fgets e remove o '\n' final. */
void leLinha(char *destino, int tamanho) {
    if (fgets(destino, tamanho, stdin) != NULL)
        destino[strcspn(destino, "\n")] = '\0';
}

void inicializaPessoa(struct pessoa *pp) {
    pp->idade = 0;
    strcpy(pp->nome, "");
    strcpy(pp->endereco, "");
    strcpy(pp->cep, "");
}

void imprimePessoa(struct pessoa pessoa) {
    printf("Nome: %s\n", pessoa.nome);
    printf("Endereco: %s\n", pessoa.endereco);
    printf("Cep: %s\n", pessoa.cep);
    printf("Idade: %d\n", pessoa.idade);
    puts("======================");
}

void usuarioPreenche(struct pessoa *pp) {
    puts("Digite o nome: ");
    leLinha(pp->nome, sizeof(pp->nome));
    puts("Digite o endereco: ");
    leLinha(pp->endereco, sizeof(pp->endereco));
    puts("Digite o cep: ");
    leLinha(pp->cep, sizeof(pp->cep));
    puts("Digite a idade: ");
    scanf("%d", &pp->idade);
}

int main(void) {
    struct pessoa p[100];

    inicializaPessoa(&p[0]);
    usuarioPreenche(&p[0]);
    imprimePessoa(p[0]);

    struct circulo c;
    c.centro.x = 4;
    c.centro.y = 8;
    c.raio = 5;
    printf("Circulo: centro (%.1f, %.1f), raio %.1f\n", c.centro.x, c.centro.y, c.raio);

    return 0;
}
