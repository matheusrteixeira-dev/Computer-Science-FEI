"""Laboratório 05 - Exercício 04: lê números até uma linha em branco e os separa em pares e ímpares."""

if __name__ == "__main__":
    numeros, pares, impares = [], [], []

    while True:
        entrada = input("Digite um número (ou Enter para encerrar): ")
        if entrada == "":
            break

        num = int(entrada)
        numeros.append(num)
        if num % 2 == 0:
            pares.append(num)
        else:
            impares.append(num)

    print("Lista de todos os números:", numeros)
    print("Lista de todos os números pares:", pares)
    print("Lista de todos os números ímpares:", impares)
