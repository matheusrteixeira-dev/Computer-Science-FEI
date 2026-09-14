"""Laboratório 03 - Exercício 03: raízes reais de uma equação do segundo grau ax² + bx + c = 0."""

from math import sqrt


def raizes(a, b, c):
    """Retorna uma tupla com as raízes reais (vazia se não houver)."""
    delta = b ** 2 - 4 * a * c
    if delta < 0:
        return ()
    if delta == 0:
        return (-b / (2 * a),)
    return ((-b - sqrt(delta)) / (2 * a), (-b + sqrt(delta)) / (2 * a))


if __name__ == "__main__":
    a = float(input("Digite o valor de A: "))
    if a == 0:
        print("A equação não é do segundo grau (A = 0)")
    else:
        b = float(input("Digite o valor de B: "))
        c = float(input("Digite o valor de C: "))

        resultado = raizes(a, b, c)
        if len(resultado) == 0:
            print("A equação não possui raízes reais")
        elif len(resultado) == 1:
            print("A equação possui apenas uma raiz real:", resultado[0])
        else:
            print("A equação possui duas raízes:", resultado[0], resultado[1])
