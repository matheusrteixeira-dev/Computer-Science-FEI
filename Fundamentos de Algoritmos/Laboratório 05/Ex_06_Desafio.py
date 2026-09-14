"""Laboratório 05 - Desafio 06: quociente e resto de uma divisão inteira usando apenas subtrações."""


def divide(dividendo, divisor):
    """Retorna (quociente, resto) para inteiros não negativos, com divisor > 0."""
    quociente = 0
    while dividendo >= divisor:
        dividendo -= divisor
        quociente += 1
    return quociente, dividendo


if __name__ == "__main__":
    dividendo = int(input("Digite o dividendo: "))
    divisor = int(input("Digite o divisor: "))

    if divisor <= 0 or dividendo < 0:
        print("A divisão não é válida")
    else:
        quociente, resto = divide(dividendo, divisor)
        print("O quociente da divisão é:", quociente)
        print("O resto da divisão é:", resto)
