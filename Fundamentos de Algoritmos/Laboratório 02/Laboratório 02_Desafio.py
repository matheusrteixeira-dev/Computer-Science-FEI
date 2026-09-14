"""Laboratório 02 - Desafio: ordena três números com trocas, preservando a entrada original."""

if __name__ == "__main__":
    x_entrada = int(input("x: "))
    y_entrada = int(input("y: "))
    z_entrada = int(input("z: "))

    x, y, z = x_entrada, y_entrada, z_entrada

    # Três comparações e trocas bastam para ordenar três valores.
    if x > y:
        x, y = y, x
    if y > z:
        y, z = z, y
    if x > y:
        x, y = y, x

    print("Ordenado (crescente)")
    print(x)
    print(y)
    print(z)
    print()
    print("Original, conforme entrada")
    print(x_entrada)
    print(y_entrada)
    print(z_entrada)
