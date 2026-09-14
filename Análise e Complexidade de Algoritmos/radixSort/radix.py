"""Radix Sort (LSD) com Counting Sort estável e medição do tempo de execução."""

import random
import time

NUM_DIGITOS = 4  # Os números gerados vão de 0 a 9999.


def digito(num, dig):
    """Retorna o dígito de posição ``dig`` (0 = unidades) de ``num``."""
    return (num // 10 ** dig) % 10


def counting_sort_estavel(v, d):
    """Ordena ``v`` de forma estável considerando apenas o dígito ``d``."""
    count = [0] * 10
    temp = [0] * len(v)
    for el in v:
        count[digito(el, d)] += 1

    for i in range(1, len(count)):
        count[i] += count[i - 1]

    for el in reversed(v):
        count[digito(el, d)] -= 1
        temp[count[digito(el, d)]] = el
    return temp


def radix(v, num_digitos=NUM_DIGITOS):
    """Retorna uma cópia ordenada de ``v``."""
    for i in range(num_digitos):
        v = counting_sort_estavel(v, i)
    return v


if __name__ == "__main__":
    assert radix([123, 434, 255, 656, 744, 888]) == [123, 255, 434, 656, 744, 888]

    # Imprime "tamanho tempo_ns" para diferentes tamanhos de entrada.
    for i in range(10):
        n = i * 100
        vetor = [random.randint(0, 9999) for _ in range(n)]
        inicio = time.process_time_ns()
        radix(vetor)
        print(n, time.process_time_ns() - inicio)
