"""Atividade 03 - Distribuições de probabilidade binomial e normal."""

from scipy.stats import binom, norm


def exercicio_2():
    """60% dos pacientes sobrevivem a um tratamento. Com 20 pacientes, P(no máximo 2 sobreviverem)."""
    p = binom.cdf(2, 20, 0.6)
    print(f"Ex. 2 - P(X <= 2) = {p:.3e}")


def exercicio_3():
    """Afogamentos: em média 2 a cada 50.000 habitantes (aproximação pela binomial)."""
    taxa = 2 / 50000

    # a) P(exatamente 5 afogamentos em 200.000 habitantes)
    print(f"Ex. 3a - P(X = 5) = {binom.pmf(5, 200000, taxa):.4f}")

    # b) P(pelo menos 3 afogamentos em 125.000 habitantes)
    print(f"Ex. 3b - P(X >= 3) = {1 - binom.cdf(2, 125000, taxa):.4f}")


def exercicio_4():
    """Vida útil de baterias ~ Normal(média = 120 min, variância = 100 -> desvio padrão = 10)."""
    media, desvio = 120, 10

    # a) P(X < 100)
    print(f"Ex. 4a - P(X < 100) = {norm.cdf(100, media, desvio):.4f}")

    # b) P(115 < X < 130)
    print(f"Ex. 4b - P(115 < X < 130) = {norm.cdf(130, media, desvio) - norm.cdf(115, media, desvio):.4f}")


if __name__ == "__main__":
    exercicio_2()
    exercicio_3()
    exercicio_4()
