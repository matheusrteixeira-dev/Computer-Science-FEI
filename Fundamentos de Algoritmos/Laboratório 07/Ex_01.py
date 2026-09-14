"""Laboratório 07 - Exercício 01: matriz 5x7 aleatória; encontra a linha que contém o menor elemento
e exibe o maior valor dessa linha (valor "minimax")."""

from random import uniform

LINHAS, COLUNAS = 5, 7


def imprime_matriz(matriz):
    for linha in matriz:
        print(" ".join(f"{valor:5.1f}" for valor in linha))


def main():
    matriz = [[uniform(0, 99) for _ in range(COLUNAS)] for _ in range(LINHAS)]
    imprime_matriz(matriz)
    print()

    linha_do_menor = min(matriz, key=min)
    print(f"Menor valor da matriz: {min(linha_do_menor):.1f}")
    print(f"Maior valor da linha que contém o menor valor (minimax): {max(linha_do_menor):.1f}")


if __name__ == "__main__":
    main()
