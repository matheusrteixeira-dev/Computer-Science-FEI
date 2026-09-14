"""Ordenação por bolha (Bubble Sort)."""

import numpy as np


def bubble_sort(v):
    """Ordena ``v`` in-place em ordem crescente e retorna o próprio vetor.

    Complexidade: O(n²) no pior caso.
    """
    n = len(v)
    for i in range(n - 1):
        # Após cada passada, os ``i`` últimos elementos já estão na posição final.
        for j in range(n - 1 - i):
            if v[j] > v[j + 1]:
                v[j], v[j + 1] = v[j + 1], v[j]
    return v


if __name__ == "__main__":
    vetor = np.random.randint(1, 1000, 10)
    bubble_sort(vetor)
    print(vetor)
