"""Laboratório 07 - Exercício 04: soma (S) ou média (M) dos elementos abaixo da diagonal principal
de uma matriz 12x12 aleatória."""

from random import randint

TAMANHO = 12


def imprime_matriz(matriz):
    for linha in matriz:
        print(" ".join(f"{valor:2d}" for valor in linha))


def abaixo_da_diagonal(matriz):
    """Elementos M[i][j] com j < i."""
    return [matriz[i][j] for i in range(len(matriz)) for j in range(i)]


def main():
    matriz = [[randint(0, 99) for _ in range(TAMANHO)] for _ in range(TAMANHO)]
    imprime_matriz(matriz)
    print()

    elementos = abaixo_da_diagonal(matriz)  # 66 elementos em uma matriz 12x12
    opcao = input("Digite a operação desejada (S ou M): ").strip().upper()

    if opcao == "S":
        print("A soma dos valores abaixo da diagonal é:", sum(elementos))
    elif opcao == "M":
        print("A média dos valores abaixo da diagonal é:", sum(elementos) / len(elementos))
    else:
        print("A opção desejada não é válida")


if __name__ == "__main__":
    main()
