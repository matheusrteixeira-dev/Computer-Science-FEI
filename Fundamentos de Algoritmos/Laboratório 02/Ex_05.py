"""Laboratório 02 - Exercício 05: classificação de um triângulo quanto aos ângulos."""

from math import isclose

if __name__ == "__main__":
    a = float(input("Digite o valor do lado A (o maior lado): "))
    b = float(input("Digite o valor do lado B: "))
    c = float(input("Digite o valor do lado C: "))

    if a <= 0 or b <= 0 or c <= 0:
        print("Os lados devem ser positivos; não é possível realizar o cálculo")
    elif isclose(a ** 2, b ** 2 + c ** 2):
        print("O triângulo é retângulo")
    elif a ** 2 > b ** 2 + c ** 2:
        print("O triângulo é obtusângulo")
    else:
        print("O triângulo é acutângulo")
