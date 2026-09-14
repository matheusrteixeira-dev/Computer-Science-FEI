"""Atividade 03 - Raízes de equações não lineares.

Tabelamento de funções, resolução gráfica, ``scipy.optimize.fsolve``, método de
Newton-Raphson simbólico e raízes de polinômios.
"""

import matplotlib.pyplot as plt
import numpy as np
import sympy as sp
from scipy.optimize import fsolve


def metodo_de_newton(f, x0, iteracoes=5):
    """Executa ``iteracoes`` passos de Newton-Raphson para a expressão simbólica ``f(x)``."""
    x = sp.Symbol("x")
    expr = f(x)
    derivada = sp.diff(expr, x)
    for _ in range(iteracoes):
        x0 = x0 - expr.subs(x, x0) / derivada.subs(x, x0)
    return x0


def exercicio_1():
    """Tabelamento de f(x) = cos(x) + x^2 + 2x - 2 para x inteiro em [-4, 4]."""
    x = np.arange(-4, 5).reshape((1, 9))
    y = np.cos(x) + x ** 2 + 2 * x - 2
    print(x)
    print(y)


def exercicio_2():
    """Raízes de sin(x) = x^2 + x - 2 por gráfico, fsolve e Newton-Raphson."""
    x = np.linspace(-4, 4, 20)
    plt.plot(x, np.sin(x), color="blue", linewidth=2, label="sin(x)")
    plt.plot(x, x ** 2 + x - 2, color="red", linewidth=2, label="x^2 + x - 2")
    plt.legend()
    plt.grid(True)
    plt.show()

    def g(x):
        return np.sin(x) - x ** 2 - x + 2

    print("fsolve com x0 = -1.5:", fsolve(g, -1.5))
    print("fsolve com x0 = 1.2:", fsolve(g, 1.2))

    x_tabela = np.arange(-4, 5).reshape((1, 9))
    print(x_tabela)
    print(g(x_tabela))

    def f(x):
        return sp.sin(x) - x ** 2 - x + 2

    for xi in (-2.5, 0.5):
        xr = metodo_de_newton(f, xi)
        print(f"Newton com xi = {xi}: x = {sp.N(xr)}, f(x) = {sp.N(f(xr))}")


def exercicio_3():
    """Raízes do polinômio x^5 - 3.5x^4 + 2.75x^3 + 2.125x^2 - 3.975x + 1.25."""
    coeficientes = [1, -3.5, 2.75, 2.125, -3.975, 1.25]

    x = np.linspace(-2, 4, 20)
    plt.plot(x, np.polyval(coeficientes, x), color="red", linewidth=2, linestyle="--")
    plt.grid(True)
    plt.show()

    print("Raízes de x^5 - 3.5x^4 + 2.75x^3 + 2.125x^2 - 3.975x + 1.25:")
    print(np.roots(coeficientes))


if __name__ == "__main__":
    exercicio_1()
    exercicio_2()
    exercicio_3()
