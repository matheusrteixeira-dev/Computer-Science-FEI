"""Laboratório 10 - Exercício 01: verifica se um texto é um palíndromo (ignorando espaços e maiúsculas)."""


def eh_palindromo(texto):
    normalizado = texto.lower().replace(" ", "")
    return normalizado == normalizado[::-1]


if __name__ == "__main__":
    s = input("Digite o texto: ")
    print("É palíndromo" if eh_palindromo(s) else "Não é palíndromo")
