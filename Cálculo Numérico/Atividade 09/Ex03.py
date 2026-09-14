"""Atividade 09 - Exercício 03: interpolação a partir de pontos tabelados.

Calcula o polinômio interpolador de Lagrange, a interpolação linear em x = 0.23
e um ajuste polinomial de grau 2 por mínimos quadrados.
"""

import numpy as np
from scipy.interpolate import lagrange

if __name__ == "__main__":
    x = np.array([0, 0.1250, 0.2500, 0.3750, 0.5000])
    y = np.array([0, 6.2400, 7.7500, 4.8500, 0])

    poly = lagrange(x, y)
    print("Coeficientes do polinômio de Lagrange (maior grau primeiro):", poly.coeffs)

    print("Interpolação linear em x = 0.23:", np.interp(0.2300, x, y))

    print("Ajuste polinomial de grau 2:", np.polyfit(x, y, 2))
