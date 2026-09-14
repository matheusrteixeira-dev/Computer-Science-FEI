"""Laboratório 10 - Exercício 02 (versão alternativa): maiores palavras do arquivo Python.txt,
sem repetições."""

from pathlib import Path

ARQUIVO = Path(__file__).resolve().parent / "Python.txt"


def palavras_do_arquivo(caminho):
    with open(caminho, "r", encoding="utf-8") as arquivo:
        texto = arquivo.read()
    return texto.replace(".", " ").replace(",", " ").split()


def main():
    palavras = palavras_do_arquivo(ARQUIVO)
    maior_tamanho = max(len(p) for p in palavras)
    print(maior_tamanho)

    maiores = []
    for palavra in palavras:
        if len(palavra) == maior_tamanho and palavra not in maiores:
            maiores.append(palavra)
    print(maiores)


if __name__ == "__main__":
    main()
