/*
 * Aula 17 - Calculadora de números complexos usando structs.
 */
#include <locale.h>
#include <math.h>
#include <stdio.h>

struct Complexo {
    float r; // parte real
    float i; // parte imaginária
};

void leiaComplexo(struct Complexo *p) {
    printf("Digite o valor da parte real:\n");
    scanf("%f", &p->r);
    printf("Digite o valor da parte imaginaria:\n");
    scanf("%f", &p->i);
    printf("%f + (%f)i\n", p->r, p->i);
}

void imprimeComplexo(struct Complexo p) {
    printf("%f + (%f)i\n", p.r, p.i);
}

struct Complexo adicao(struct Complexo p, struct Complexo q) {
    struct Complexo ret = {p.r + q.r, p.i + q.i};
    return ret;
}

struct Complexo multiplicacao(struct Complexo p, struct Complexo q) {
    struct Complexo ret = {p.r * q.r - p.i * q.i, p.r * q.i + p.i * q.r};
    return ret;
}

struct Complexo divisao(struct Complexo p, struct Complexo q) {
    float denominador = q.r * q.r + q.i * q.i;
    struct Complexo ret = {(p.r * q.r + p.i * q.i) / denominador,
                           (p.i * q.r - p.r * q.i) / denominador};
    return ret;
}

void modulo(struct Complexo p) {
    printf("O modulo e: %f\n", sqrt(p.r * p.r + p.i * p.i));
}

void argumento(struct Complexo p) {
    printf("O argumento e: %f rad\n", atan2(p.i, p.r));
}

struct Complexo conjugado(struct Complexo p) {
    struct Complexo ret = {p.r, -p.i};
    return ret;
}

int menu(void) {
    int op;
    puts("====================");
    puts("1 - Adicao");
    puts("2 - Multiplicacao");
    puts("3 - Divisao");
    puts("4 - Modulo z1");
    puts("5 - Modulo z2");
    puts("6 - Argumento z1");
    puts("7 - Argumento z2");
    puts("8 - Conjugado z1");
    puts("9 - Conjugado z2");
    printf("Opcao > ");
    if (scanf("%d", &op) != 1)
        return 0;
    return op;
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    struct Complexo z1, z2;

    printf("Numeros Complexos:\n\n");
    leiaComplexo(&z1);
    leiaComplexo(&z2);

    while (1) {
        switch (menu()) {
        case 1: imprimeComplexo(adicao(z1, z2)); break;
        case 2: imprimeComplexo(multiplicacao(z1, z2)); break;
        case 3: imprimeComplexo(divisao(z1, z2)); break;
        case 4: modulo(z1); break;
        case 5: modulo(z2); break;
        case 6: argumento(z1); break;
        case 7: argumento(z2); break;
        case 8: imprimeComplexo(conjugado(z1)); break;
        case 9: imprimeComplexo(conjugado(z2)); break;
        default:
            puts("Opcao invalida, fechando o sistema...");
            return 0;
        }
    }
}
