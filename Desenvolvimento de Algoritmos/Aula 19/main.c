/*
 * Aula 19 - Perímetro de um polígono com os vértices e o resultado gravados em arquivo.
 */
#include <math.h>
#include <stdio.h>

#define MAX_VERTICES 100

struct Ponto {
    int x;
    int y;
};

struct Poligono {
    int n;
    struct Ponto v[MAX_VERTICES];
};

/* Lê os n vértices do polígono e os registra no arquivo. */
void adicionaVertices(struct Poligono *p, int n, FILE *f) {
    p->n = n;
    fprintf(f, "Dado o poligono de %d vertices:\n", n);

    for (int i = 0; i < n; ++i) {
        printf("Digite as coordenadas x e y do vertice %d: ", i + 1);
        scanf("%d %d", &p->v[i].x, &p->v[i].y);
        fprintf(f, "x: %d\n", p->v[i].x);
        fprintf(f, "y: %d\n", p->v[i].y);
    }
}

float distancia(struct Ponto a, struct Ponto b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

/* Calcula o perímetro (incluindo a aresta que fecha o polígono) e o grava no arquivo. */
void perimetro(const struct Poligono *p, FILE *f) {
    float soma = 0;
    for (int i = 0; i < p->n - 1; ++i)
        soma += distancia(p->v[i], p->v[i + 1]);
    soma += distancia(p->v[0], p->v[p->n - 1]);

    fprintf(f, "O perimetro e: %f\n", soma);
    printf("O perimetro e: %f\n", soma);
}

int main(void) {
    struct Poligono poligono;
    int n;

    puts("Digite a quantidade de vertices:");
    while (scanf("%d", &n) != 1 || n < 3 || n > MAX_VERTICES) {
        printf("Informe um valor entre 3 e %d:\n", MAX_VERTICES);
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;
    }

    FILE *f = fopen("PoligonoW.txt", "w");
    if (f == NULL) {
        perror("Erro ao criar PoligonoW.txt");
        return 1;
    }

    adicionaVertices(&poligono, n, f);
    perimetro(&poligono, f);

    fclose(f);
    return 0;
}
