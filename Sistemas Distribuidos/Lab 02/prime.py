"""Contagem de números primos em uma lista, de forma serial e com múltiplas threads."""

import concurrent.futures

import sympy


def conta_primos(data):
    """Quantidade de números primos em data."""
    return sum(1 for valor in data if sympy.isprime(valor))


def is_prime(data):
    """Versão serial."""
    return conta_primos(data)


def is_prime_thread(data, number_of_threads):
    """Divide data em number_of_threads blocos e conta os primos de cada bloco em uma thread.

    Observação: por causa do GIL do CPython, threads não aceleram tarefas limitadas por CPU;
    este experimento mede justamente esse efeito.
    """
    number_of_threads = max(1, min(number_of_threads, len(data)))
    tamanho_bloco, resto = divmod(len(data), number_of_threads)

    blocos = []
    inicio = 0
    for i in range(number_of_threads):
        fim = inicio + tamanho_bloco + (1 if i < resto else 0)
        blocos.append(data[inicio:fim])
        inicio = fim

    with concurrent.futures.ThreadPoolExecutor(max_workers=number_of_threads) as executor:
        return sum(executor.map(conta_primos, blocos))
