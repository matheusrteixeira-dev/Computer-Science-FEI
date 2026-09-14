"""Laboratório 05 - Exercício 05: gera uma lista de 6 números aleatórios distintos entre 0 e 49."""

from random import randrange

QUANTIDADE = 6

if __name__ == "__main__":
    numeros = []
    while len(numeros) < QUANTIDADE:
        aleatorio = randrange(0, 50)
        if aleatorio not in numeros:
            numeros.append(aleatorio)

    print(numeros)
