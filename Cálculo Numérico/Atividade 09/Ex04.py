"""Atividade 09 - Exercício 04: área total a partir de dois perfis medidos.

Cada perfil é integrado pela regra do trapézio e as áreas são somadas.
"""

from scipy.integrate import trapezoid


def area_total():
    """Soma das integrais, pela regra do trapézio, dos dois conjuntos de medições."""
    x1 = [0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50]
    y1 = [0, 20, 22, 39, 42, 45, 47, 45, 40, 39, 0]

    x2 = [0, 10, 20, 30, 40, 50]
    y2 = [0, 34, 50, 52, 36, 0]

    return trapezoid(y1, x1) + trapezoid(y2, x2)


if __name__ == "__main__":
    print("Área total:", area_total())
