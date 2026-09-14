"""Laboratório 02 - Exercício 04: função definida por partes (enunciado em ../images/lab02_4_1.png e lab02_4_2.png).

Para x >= 5:  y = (sqrt(ln(x³) + π² + 1) - ln(x⁵)) / (eˣ + x² + 3ˣ)
Para x < 5:   y = sen²(x) + cos²(x) + |x|
"""

from math import cos, exp, log, pi, sin, sqrt

if __name__ == "__main__":
    x = float(input("Digite um número: "))

    if x >= 5:
        y = (sqrt(log(x ** 3) + pi ** 2 + 1) - log(x ** 5)) / (exp(x) + x ** 2 + 3 ** x)
    else:
        y = sin(x) ** 2 + cos(x) ** 2 + abs(x)

    print("O valor de y é:", y)
