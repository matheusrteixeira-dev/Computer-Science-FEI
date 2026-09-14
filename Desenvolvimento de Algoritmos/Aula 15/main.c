/*
 * Aula 15 - Exercícios de recursão e estruturas: Torre de Hanói, Fibonacci,
 * interseção de retas e classificação de triângulos quanto aos ângulos.
 */
#include <math.h>
#include <stdio.h>

/* Imprime os movimentos para transferir d discos de ori para dest usando aux. */
void moveDisco(int d, char ori, char dest, char aux) {
    if (d == 1) {
        printf("Mover disco %d de %c para %c\n", d, ori, dest);
        return;
    }
    moveDisco(d - 1, ori, aux, dest);
    printf("Mover disco %d de %c para %c\n", d, ori, dest);
    moveDisco(d - 1, aux, dest, ori);
}

/* Imprime os n primeiros termos de Fibonacci usando um vetor (n >= 2). */
void fibonacciVetor(int n) {
    long long vetor[n];
    vetor[0] = 1;
    vetor[1] = 1;
    for (int i = 2; i < n; i++)
        vetor[i] = vetor[i - 1] + vetor[i - 2];

    for (int i = 0; i < n; i++)
        printf("%lld ", vetor[i]);
    printf("\n");
}

/* Imprime os n primeiros termos de Fibonacci com duas variáveis (n >= 2). */
void fibonacciIterativo(int n) {
    int a = 1;
    int b = 1;
    printf("%d %d ", a, b);

    for (int i = 2; i < n; i++) {
        int proximo = a + b;
        a = b;
        b = proximo;
        printf("%d ", proximo);
    }
    printf("\n");
}

/* n-ésimo termo de Fibonacci (recursivo). */
int fibonacciRecursivo(int n) {
    if (n == 1 || n == 2)
        return 1;
    return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
}

struct ponto {
    float x;
    float y;
};

/* Reta na forma y = a*x + b. */
struct reta {
    float a;
    float b;
};

/* Informa se as retas são paralelas ou o ponto de interseção entre elas. */
void conferirReta(struct reta r1, struct reta r2) {
    if (r1.a == r2.a) {
        printf("Paralelas\n");
    } else {
        float x = (r2.b - r1.b) / (r1.a - r2.a);
        float y = r1.a * x + r1.b;
        printf("Concorrentes no ponto (%f, %f)\n", x, y);
    }
}

float distancia(struct ponto p, struct ponto q) {
    return sqrt(pow(p.x - q.x, 2) + pow(p.y - q.y, 2));
}

/* Classifica o triângulo pela lei dos cossenos comparando o maior lado com os outros dois. */
void triangulo(struct ponto p1, struct ponto p2, struct ponto p3) {
    const float EPS = 1e-4f;
    float d1 = distancia(p1, p2);
    float d2 = distancia(p2, p3);
    float d3 = distancia(p1, p3);

    printf("Lados formados: %.2f %.2f %.2f\n", d1, d2, d3);

    float maior = d1, outro1 = d2, outro2 = d3;
    if (d2 >= maior) {
        maior = d2;
        outro1 = d1;
        outro2 = d3;
    }
    if (d3 >= maior) {
        maior = d3;
        outro1 = d1;
        outro2 = d2;
    }

    float quadradoMaior = maior * maior;
    float somaQuadrados = outro1 * outro1 + outro2 * outro2;

    if (fabs(quadradoMaior - somaQuadrados) < EPS)
        printf("Retangulo\n");
    else if (quadradoMaior > somaQuadrados)
        printf("Obtusangulo\n");
    else
        printf("Acutangulo\n");
}

int main(void) {
    struct ponto p1, p2, p3;

    printf("P1 (x y): ");
    scanf("%f %f", &p1.x, &p1.y);
    printf("P2 (x y): ");
    scanf("%f %f", &p2.x, &p2.y);
    printf("P3 (x y): ");
    scanf("%f %f", &p3.x, &p3.y);

    triangulo(p1, p2, p3);

    return 0;
}
