"""Laboratório 05 - Exercício 02: lê 20 números e os separa em listas de pares e ímpares."""

QUANTIDADE = 20

if __name__ == "__main__":
    numeros, pares, impares = [], [], []

    for _ in range(QUANTIDADE):
        num = int(input("Digite um número: "))
        numeros.append(num)
        if num % 2 == 0:
            pares.append(num)
        else:
            impares.append(num)

    print("Lista de todos os números:", numeros)
    print("Lista de todos os ímpares:", impares)
    print("Lista de todos os pares:", pares)
