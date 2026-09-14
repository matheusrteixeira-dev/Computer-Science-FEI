"""Problema do troco: menor número de moedas (recursão ingênua, para contar subproblemas repetidos)."""

import math
from collections import defaultdict

contagem = defaultdict(int)


def moedas(v, valor):
    """Retorna o menor número de moedas de ``v`` que somam ``valor``."""
    contagem[valor] += 1
    if valor in v:
        return 1

    menor = math.inf
    for moeda in v:
        if valor - moeda > 0:
            menor = min(menor, moedas(v, valor - moeda) + 1)

    return menor


if __name__ == "__main__":
    print(moedas([10, 6, 5, 1], 12))
    print(contagem)
