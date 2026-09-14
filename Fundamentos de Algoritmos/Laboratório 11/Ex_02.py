"""Laboratório 11 - Exercício 02: simula lançamentos de dois dados e mostra a frequência de cada soma."""

from random import randint

LANCAMENTOS = 1000


def simula(lancamentos):
    """Retorna um dicionário {soma: quantidade} para as somas de 2 a 12."""
    frequencias = {soma: 0 for soma in range(2, 13)}
    for _ in range(lancamentos):
        frequencias[randint(1, 6) + randint(1, 6)] += 1
    return frequencias


def imprime(frequencias, lancamentos):
    for soma, quantidade in frequencias.items():
        print(f"{soma:2d} = {quantidade:4d}: {quantidade * 100 / lancamentos:5.1f}%")


def main():
    imprime(simula(LANCAMENTOS), LANCAMENTOS)


if __name__ == "__main__":
    main()
