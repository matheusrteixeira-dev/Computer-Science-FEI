/*
 * Aula 16 - Livro-caixa com structs aninhadas: cadastro, remoção e impressão de receitas.
 */
#include <stdio.h>
#include <string.h>

#define MAX_RECEITAS 100

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Receita {
    struct Data data;
    float valor;
    char cliente[200];
};

struct Livro {
    struct Receita receita[MAX_RECEITAS];
    int n;
};

int menu(void) {
    puts("MINHA RIQUEZA");
    puts("=================");
    puts("1 - Insere");
    puts("2 - Remove");
    puts("3 - Imprime");
    puts("Outro - Sai");
    int op;
    if (scanf("%d", &op) != 1)
        return 0;
    return op;
}

/* Descarta o restante da linha atual da entrada padrão. */
void limpaEntrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

/* Remove o '\n' deixado pelo fgets no final da string. */
void tiraEnter(char *s) {
    s[strcspn(s, "\n")] = '\0';
}

struct Receita perguntaUsuarioReceita(void) {
    struct Receita r;

    puts("Entre com os dados da receita:");
    puts("Valor:");
    scanf("%f", &r.valor);
    puts("Data (dia mes ano):");
    scanf("%d %d %d", &r.data.dia, &r.data.mes, &r.data.ano);
    limpaEntrada();
    puts("Cliente:");
    fgets(r.cliente, sizeof(r.cliente), stdin);
    tiraEnter(r.cliente);
    puts("Obrigado!");

    return r;
}

void cadastraReceita(struct Livro *l) {
    if (l->n >= MAX_RECEITAS) {
        puts("Livro cheio!");
        return;
    }
    l->receita[l->n] = perguntaUsuarioReceita();
    l->n++;
}

void imprimeReceita(struct Receita r) {
    printf("Cliente: %s\n", r.cliente);
    printf("Valor: %.2f\n", r.valor);
    printf("Data: %02d/%02d/%04d\n", r.data.dia, r.data.mes, r.data.ano);
}

void imprimeLivro(const struct Livro *l) {
    for (int i = 0; i < l->n; i++) {
        printf("Receita %d\n", i + 1);
        imprimeReceita(l->receita[i]);
        puts("--------------------");
    }
}

/* Remove a receita da posição informada (1 a n), deslocando as seguintes. */
void removeReceita(struct Livro *l) {
    puts("Qual posicao?");
    int pos;
    if (scanf("%d", &pos) != 1 || pos < 1 || pos > l->n) {
        puts("Posicao invalida!");
        return;
    }
    for (int i = pos - 1; i < l->n - 1; ++i)
        l->receita[i] = l->receita[i + 1];
    l->n--;
}

int main(void) {
    static struct Livro l; // static: evita ocupar a pilha com o vetor de receitas
    l.n = 0;

    while (1) {
        int op = menu();
        if (op == 1)
            cadastraReceita(&l);
        else if (op == 2)
            removeReceita(&l);
        else if (op == 3)
            imprimeLivro(&l);
        else
            break;
    }

    return 0;
}
