"""Multiplicação de cadeia de matrizes: custo mínimo de parentização.

As dimensões são dadas por ``v``: a matriz ``i`` tem dimensão ``v[i] x v[i + 1]``.
"""

import math
from collections import defaultdict
from functools import cache

contagem = defaultdict(int)


@cache
def custo_multiplicacao(v, inicio, fim):
    """Custo mínimo para multiplicar as matrizes ``inicio..fim`` (recursivo com memoização)."""
    contagem[(inicio, fim)] += 1

    if inicio == fim:
        return 0

    menor = math.inf
    for k in range(inicio, fim):
        custo_esquerda = custo_multiplicacao(v, inicio, k)
        custo_direita = custo_multiplicacao(v, k + 1, fim)
        custo_uniao = v[inicio] * v[k + 1] * v[fim + 1]
        menor = min(menor, custo_esquerda + custo_direita + custo_uniao)

    return menor


def custo_multiplicacao_din(v):
    """Custo mínimo para multiplicar toda a cadeia (programação dinâmica bottom-up)."""
    num_matrizes = len(v) - 1
    c = defaultdict(float)

    for i in range(num_matrizes):
        c[i, i] = 0

    # Resolve subcadeias em ordem crescente de tamanho.
    for tam in range(2, num_matrizes + 1):
        for i in range(num_matrizes - tam + 1):
            f = i + tam - 1
            c[i, f] = math.inf
            for k in range(i, f):
                total = c[i, k] + c[k + 1, f] + v[i] * v[k + 1] * v[f + 1]
                c[i, f] = min(c[i, f], total)

    return c[0, num_matrizes - 1]


if __name__ == "__main__":
    dim_matrizes = (30, 35, 15, 5, 10, 20, 25)
    print("Recursivo com memoização:", custo_multiplicacao(dim_matrizes, 0, len(dim_matrizes) - 2))
    print("Programação dinâmica:    ", custo_multiplicacao_din(dim_matrizes))
