"""Laboratório 06 - Exercício 03: soma e média dos números de um arquivo texto (um por linha)."""

from pathlib import Path

ARQUIVO = Path(__file__).resolve().parent / "numeros_6_3.txt"


def le_numeros(caminho):
    with open(caminho, "r", encoding="utf-8") as arquivo:
        return [int(linha) for linha in arquivo if linha.strip()]


def main():
    numeros = le_numeros(ARQUIVO)
    soma = sum(numeros)
    print("A soma dos números é:", soma)
    print("A média dos números é:", soma / len(numeros))


if __name__ == "__main__":
    main()
