"""Atividade 04 - Sistemas lineares aplicados e raízes de equações.

Problemas de mistura e investimento resolvidos com a inversa, resolução gráfica,
``fsolve`` e método de Newton-Raphson com critério de tolerância.
"""

import matplotlib.pyplot as plt
import numpy as np
import sympy as sp
from scipy.optimize import fsolve


def metodo_de_newton(f, x0, tolerancia=1e-6, max_iteracoes=100):
    """Newton-Raphson simbólico: para quando |x1 - x0| < ``tolerancia``."""
    x = sp.Symbol("x")
    expr = f(x)
    derivada = sp.diff(expr, x)
    for _ in range(max_iteracoes):
        x1 = x0 - expr.subs(x, x0) / derivada.subs(x, x0)
        if abs(x1 - x0) < tolerancia:
            return x1
        x0 = x1
    raise RuntimeError("O método de Newton não convergiu.")


def exercicio_1():
    """Sistema linear 3x3 de um problema de produção."""
    A = np.array([[50, 200, 160], [90, 100, 80], [180, 250, 120]])
    b = np.array([[11700], [7000], [14800]])
    print("Resultado do sistema linear:\n", np.linalg.inv(A) @ b)


def exercicio_2():
    """Sistema linear 3x3 de um problema de investimentos com taxas de juros."""
    A = np.array([[1, 1, 1], [0.07, 0.08, 0.09], [0.07, 0.08, 0.1]])
    b = np.array([[35000], [2830], [2960]])
    print("Resultado do sistema linear:\n", np.linalg.inv(A) @ b)


def exercicio_3():
    """Resolução gráfica da interseção entre -2.5 + 5x e sin(x)."""
    x = np.linspace(-5, 6, 10)  # 10 pontos igualmente espaçados em [-5, 6]
    plt.plot(x, -2.5 + 5 * x, label="-2.5 + 5x")
    plt.plot(x, np.sin(x), label="sin(x)")
    plt.legend()
    plt.grid()
    plt.show()


def exercicio_4():
    """Raiz de x - 0.2 sin(x) - 0.5 = 0 com fsolve."""
    def f(x):
        return x - 0.2 * np.sin(x) - 0.5

    print("Raiz aproximada:", fsolve(f, 0.5))


def exercicio_5():
    """Tabelamento de (x + 1)^2 - e^x e raízes de x^3 - 3x^2 + 6x - 15 por Newton-Raphson."""
    x = np.arange(-5, 6).reshape((1, 11))
    print(x)
    print((x + 1) ** 2 - np.exp(x))

    def f(x):
        return x ** 3 - 3 * x ** 2 + 6 * x - 15

    for xi in (3.5, 4.5):  # pontos médios dos intervalos analisados
        xr = metodo_de_newton(f, xi)
        print(f"Newton com xi = {xi}: x = {sp.N(xr)}, f(x) = {sp.N(f(xr))}")


if __name__ == "__main__":
    exercicio_1()
    exercicio_2()
    exercicio_3()
    exercicio_4()
    exercicio_5()
