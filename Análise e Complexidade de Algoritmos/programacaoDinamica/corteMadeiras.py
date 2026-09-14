"""Problema do corte de hastes (rod cutting): recursão com memoização e programação dinâmica."""

from collections import defaultdict
from functools import cache

contagens = defaultdict(int)


@cache
def melhor_corte(precos, tam):
    """Retorna ``(valor_maximo, cortes)`` para uma haste de tamanho ``tam``.

    ``precos[i]`` é o preço de um pedaço de tamanho ``i`` (``precos[0]`` não é usado).
    """
    contagens[tam] += 1
    valor_agregado = 0
    opcao_escolhida = []
    for i in range(1, len(precos)):
        sobra = tam - i
        if sobra >= 0:
            valor_sobras, cortes_sobras = melhor_corte(precos, sobra)
            if precos[i] + valor_sobras > valor_agregado:
                valor_agregado = precos[i] + valor_sobras
                opcao_escolhida = [*cortes_sobras, i]

    return valor_agregado, opcao_escolhida


def melhor_corte_prog_din(precos, tam):
    """Versão bottom-up: retorna os vetores de valor ótimo e do primeiro corte para cada tamanho."""
    cache_opt = [0] * (tam + 1)
    cache_esc = [0] * (tam + 1)
    for i in range(1, tam + 1):
        for c in range(1, len(precos)):
            sobra = i - c
            if sobra >= 0:
                valor = precos[c] + cache_opt[sobra]
                if valor > cache_opt[i]:
                    cache_opt[i] = valor
                    cache_esc[i] = c
    return cache_opt, cache_esc


if __name__ == "__main__":
    tabela_precos = (0, 1, 5, 8, 9, 10, 17, 17, 20)

    valor, cortes = melhor_corte(tabela_precos, 10)
    print(valor)
    print(cortes)

    valores, escolhas = melhor_corte_prog_din(tabela_precos, 10)
    print(valores)
    print(escolhas)
