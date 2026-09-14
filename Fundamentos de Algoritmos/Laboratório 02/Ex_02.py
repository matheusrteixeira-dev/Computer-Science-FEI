"""Laboratório 02 - Exercício 02: classifica um número como positivo, negativo ou nulo."""

if __name__ == "__main__":
    x = int(input("Digite um número: "))

    if x > 0:
        print("O número é positivo")
    elif x < 0:
        print("O número é negativo")
    else:
        print("O número é nulo")
