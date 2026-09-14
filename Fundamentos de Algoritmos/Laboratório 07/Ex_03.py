"""Laboratório 07 - Exercício 03: lê uma matriz 5x4 e a reorganiza com os valores em ordem crescente
(enunciado em ../images/lab07_03.png)."""

LINHAS, COLUNAS = 5, 4


def imprime_matriz(matriz):
    for linha in matriz:
        print(" ".join(f"{valor:3d}" for valor in linha))


def main():
    matriz = [[int(input("Digite o valor: ")) for _ in range(COLUNAS)] for _ in range(LINHAS)]
    print()

    valores = sorted(valor for linha in matriz for valor in linha)
    ordenada = [valores[i:i + COLUNAS] for i in range(0, len(valores), COLUNAS)]

    imprime_matriz(ordenada)


if __name__ == "__main__":
    main()
