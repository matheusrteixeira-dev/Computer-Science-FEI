"""Laboratório 11 - Exercício 03: quantidade de letras distintas (a-z) em um texto, usando dicionário."""

from string import ascii_lowercase


def conta_letras(texto):
    """Retorna um dicionário {letra: ocorrências} para todas as letras de a a z."""
    contagem = {letra: 0 for letra in ascii_lowercase}
    for caractere in texto.lower():
        if caractere in contagem:
            contagem[caractere] += 1
    return contagem


if __name__ == "__main__":
    texto = input("Digite o texto: ")
    contagem = conta_letras(texto)
    total = sum(1 for quantidade in contagem.values() if quantidade > 0)
    print("O total de letras distintas é:", total)
