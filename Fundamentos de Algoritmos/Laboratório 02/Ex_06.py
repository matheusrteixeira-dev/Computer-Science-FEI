"""Laboratório 02 - Exercício 06: ordena três números usando apenas estruturas condicionais."""

if __name__ == "__main__":
    x = int(input("Digite o primeiro valor: "))
    y = int(input("Digite o segundo valor: "))
    z = int(input("Digite o terceiro valor: "))

    if x == y == z:
        print("Os valores digitados são iguais")
    elif x <= y <= z:
        print("Os valores em ordem crescente:", x, y, z)
    elif x <= z <= y:
        print("Os valores em ordem crescente:", x, z, y)
    elif y <= x <= z:
        print("Os valores em ordem crescente:", y, x, z)
    elif y <= z <= x:
        print("Os valores em ordem crescente:", y, z, x)
    elif z <= x <= y:
        print("Os valores em ordem crescente:", z, x, y)
    else:
        print("Os valores em ordem crescente:", z, y, x)

    print()
    print("Os valores digitados foram:", x, y, z)
