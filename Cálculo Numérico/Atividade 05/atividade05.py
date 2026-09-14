"""Atividade 05 - Regressão linear por mínimos quadrados.

Ajuste implementado manualmente e com ``sklearn.linear_model.LinearRegression``.
"""

import matplotlib.pyplot as plt
import numpy as np
import sympy as sp
from sklearn.linear_model import LinearRegression


def minimos_quadrados(x, y):
    """Retorna os coeficientes (a0, a1) da reta y = a0 + a1 x ajustada aos dados."""
    n = np.size(x)
    sx, sy = np.sum(x), np.sum(y)
    sxy, sxx = np.sum(x * y), np.sum(x * x)
    a1 = (n * sxy - sx * sy) / (n * sxx - sx ** 2)
    a0 = (sxx * sy - sxy * sx) / (n * sxx - sx ** 2)
    return a0, a1


def residuo(x, y, a0, a1):
    """Soma dos quadrados dos resíduos da reta y = a0 + a1 x."""
    return np.sum((y - (a0 + a1 * x)) ** 2)


def exercicio_1():
    """Ajuste manual de uma reta a quatro pontos."""
    x = np.array([1, 2, 3, 4])
    y = np.array([2.50, 3.83, 4.96, 6.00])

    a0, a1 = minimos_quadrados(x, y)
    print(f"y = {a1}x + {a0}")

    plt.scatter(x, y, color="b", marker="o", s=50)
    plt.plot(x, a0 + a1 * x, color="r")
    plt.xlabel("x", fontsize=15)
    plt.ylabel("y", fontsize=15)
    plt.show()

    print("Resíduo:", residuo(x, y, a0, a1))


def exercicio_2():
    """Relação tensão x corrente com LinearRegression."""
    V = np.array([2, 3, 4, 5, 7, 10]).reshape(-1, 1)
    I = np.array([5.2, 7.8, 10.7, 13, 19.3, 27.5])

    modelo = LinearRegression().fit(V, I)
    a1, a0 = modelo.coef_[0], modelo.intercept_
    print(f"I = {a1}V + {a0}")

    plt.scatter(V, I)
    plt.plot(V, modelo.predict(V), color="red")
    plt.show()

    print("Corrente para V = 3.5:", a0 + a1 * 3.5)

    v = sp.Symbol("V")
    print("Tensão para I = 15:", sp.solve(a0 + a1 * v - 15, v))

    print("Resíduo:", residuo(V.ravel(), I, a0, a1))


if __name__ == "__main__":
    exercicio_1()
    exercicio_2()
