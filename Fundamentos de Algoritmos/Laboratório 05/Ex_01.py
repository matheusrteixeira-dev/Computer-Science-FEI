"""Laboratório 05 - Exercício 01: conversão de decimal para binário por divisões sucessivas
(algoritmo em ../images/lab05_01.png)."""


def decimal_para_binario(q):
    """Retorna a representação binária de um inteiro não negativo como string."""
    if q == 0:
        return "0"

    resultado = ""
    while q > 0:
        r = q % 2
        resultado = str(r) + resultado
        q //= 2
    return resultado


if __name__ == "__main__":
    numero = int(input("Digite o número: "))
    print(decimal_para_binario(numero))
