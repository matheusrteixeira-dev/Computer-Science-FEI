"""Atividade 09 - Exercício 01: integral de x e^(2x) em [2, 3].

Compara a regra do trapézio (5 pontos) com a quadratura adaptativa ``scipy.integrate.quad``.
"""

import numpy as np
import scipy.integrate as si


def f(x):
    return x * np.exp(2 * x)


if __name__ == "__main__":
    x = np.linspace(2, 3, 5)
    trapezio = si.trapezoid(f(x), x)
    print("Trapézio:", trapezio)

    integral, erro_estimado = si.quad(f, 2, 3)
    print("quad:", integral, "(erro estimado:", erro_estimado, ")")

    print("Erro absoluto do trapézio:", np.abs(trapezio - integral))
