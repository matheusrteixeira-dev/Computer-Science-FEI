"""Maior subsequência comum (LCS) — recursão ingênua com contagem de chamadas."""

from collections import defaultdict

contagem = defaultdict(int)


def lcs(s1, s2):
    """Retorna o tamanho da maior subsequência comum entre ``s1`` e ``s2``."""
    contagem[(s1, s2)] += 1

    # Caso base
    if len(s1) == 0 or len(s2) == 0:
        return 0

    # Passo recursivo
    if s1[-1] == s2[-1]:
        return lcs(s1[:-1], s2[:-1]) + 1
    return max(lcs(s1[:-1], s2), lcs(s1, s2[:-1]))


if __name__ == "__main__":
    print(lcs("flavio", "balaio"))
    print(contagem)
