"""Laboratório 10 - Exercício 02: maior tamanho de palavra no arquivo Python.txt e quantas vezes ocorre."""

from pathlib import Path

ARQUIVO = Path(__file__).resolve().parent / "Python.txt"


def palavras_do_arquivo(caminho):
    """Lê o arquivo e retorna suas palavras em minúsculas, sem vírgulas e pontos."""
    with open(caminho, "r", encoding="utf-8") as arquivo:
        texto = arquivo.read().lower()
    return texto.replace(",", " ").replace(".", " ").split()


def main():
    palavras = palavras_do_arquivo(ARQUIVO)
    tamanho = max(len(p) for p in palavras)

    maiores = [p for p in palavras if len(p) == tamanho]
    for palavra in maiores:
        print("Maior palavra:", palavra)

    print("Maior tamanho de palavra:", tamanho, "- número de ocorrências:", len(maiores))


if __name__ == "__main__":
    main()
