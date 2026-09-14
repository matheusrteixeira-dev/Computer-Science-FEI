"""Comparação de tempo entre três implementações da sequência de Fibonacci."""

import time


def cache(f):
    """Decorador simples de memoização baseado em dicionário."""
    memo = {}

    def wrapper(idx):
        if idx not in memo:
            memo[idx] = f(idx)
        return memo[idx]

    return wrapper


def fib(idx):
    """Fibonacci recursivo ingênuo — O(2^n)."""
    if idx <= 1:
        return idx
    return fib(idx - 1) + fib(idx - 2)


@cache
def fib_memo(idx):
    """Fibonacci recursivo com memoização — O(n)."""
    if idx <= 1:
        return idx
    return fib_memo(idx - 1) + fib_memo(idx - 2)


def fib_vetor(idx):
    """Fibonacci por programação dinâmica com vetor auxiliar — O(n) tempo e espaço."""
    if idx <= 1:
        return idx
    v = [0] * (idx + 1)
    v[1] = 1
    for i in range(2, idx + 1):
        v[i] = v[i - 1] + v[i - 2]
    return v[idx]


def fib_variaveis(idx):
    """Fibonacci iterativo com duas variáveis — O(n) tempo e O(1) espaço."""
    if idx <= 1:
        return idx
    penultimo, ultimo = 0, 1
    for _ in range(idx - 1):
        penultimo, ultimo = ultimo, penultimo + ultimo
    return ultimo


if __name__ == "__main__":
    # A versão ingênua cresce exponencialmente; acima de ~35 o tempo se torna proibitivo.
    for i in range(35):
        for funcao in (fib, fib_memo, fib_vetor, fib_variaveis):
            inicio = time.process_time()
            resultado = funcao(i)
            print(f"{funcao.__name__:>14} {i:2d} {resultado:>10} {time.process_time() - inicio:.6f}s")
