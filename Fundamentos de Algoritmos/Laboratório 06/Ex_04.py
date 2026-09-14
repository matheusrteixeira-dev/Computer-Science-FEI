"""Laboratório 06 - Exercício 04: remove números repetidos de um arquivo, preservando a ordem,
e grava o resultado em outro arquivo."""

from pathlib import Path

DIRETORIO = Path(__file__).resolve().parent
ENTRADA = DIRETORIO / "numeros_6_4.txt"
SAIDA = DIRETORIO / "numeros_6_4_unicos.txt"


def le_numeros(caminho):
    with open(caminho, "r", encoding="utf-8") as arquivo:
        return [int(linha) for linha in arquivo if linha.strip()]


def remove_repetidos(numeros):
    unicos = []
    for x in numeros:
        if x not in unicos:
            unicos.append(x)
    return unicos


def grava_numeros(caminho, numeros):
    with open(caminho, "w", encoding="utf-8") as arquivo:
        for x in numeros:
            arquivo.write(f"{x}\n")


def main():
    numeros = le_numeros(ENTRADA)
    print(numeros)

    unicos = remove_repetidos(numeros)
    print(unicos)

    grava_numeros(SAIDA, unicos)


if __name__ == "__main__":
    main()
