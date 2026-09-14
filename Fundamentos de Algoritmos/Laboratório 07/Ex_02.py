"""Laboratório 07 - Exercício 02: matriz 10x15 aleatória e sua transposta."""

from random import randint

LINHAS, COLUNAS = 10, 15


def imprime_matriz(matriz):
    for linha in matriz:
        print(" ".join(f"{valor:2d}" for valor in linha))


def transposta(matriz):
    return [[matriz[i][j] for i in range(len(matriz))] for j in range(len(matriz[0]))]


def main():
    matriz = [[randint(0, 99) for _ in range(COLUNAS)] for _ in range(LINHAS)]
    imprime_matriz(matriz)

    print()
    print("Transposta:")
    imprime_matriz(transposta(matriz))


if __name__ == "__main__":
    main()
