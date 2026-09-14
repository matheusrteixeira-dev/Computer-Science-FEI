"""Laboratório 04 - Exercício 04: pontos correspondentes a um conceito (enunciado em ../images/lab04_04.png)."""

PONTOS = {
    "A+": 4.0, "A": 4.0, "A-": 3.7,
    "B+": 3.3, "B": 3.0, "B-": 2.7,
    "C+": 2.3, "C": 2.0, "C-": 1.7,
    "D+": 1.3, "D": 1.0, "F": 0.0,
}

if __name__ == "__main__":
    nota = input("Digite a nota: ").strip().upper()

    if nota in PONTOS:
        print("O número de pontos é", PONTOS[nota])
    else:
        print("A nota digitada não é válida:", nota)
