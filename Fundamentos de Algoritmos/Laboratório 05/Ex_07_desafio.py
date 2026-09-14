"""Laboratório 05 - Desafio 07: Crivo de Eratóstenes (algoritmo em ../images/lab05_07.png)."""


def crivo_de_eratostenes(limite):
    """Retorna a lista de primos de 2 até limite (inclusive)."""
    if limite < 2:
        return []

    # Anota todos os números de 0 até o limite; 0 e 1 não são primos.
    eh_primo = [True] * (limite + 1)
    eh_primo[0] = eh_primo[1] = False

    p = 2
    while p * p <= limite:
        if eh_primo[p]:
            # Descarta os múltiplos de p (menores que p² já foram descartados).
            for multiplo in range(p * p, limite + 1, p):
                eh_primo[multiplo] = False
        p += 1

    return [n for n, primo in enumerate(eh_primo) if primo]


if __name__ == "__main__":
    limite = int(input("Digite o limite: "))
    print(crivo_de_eratostenes(limite))
