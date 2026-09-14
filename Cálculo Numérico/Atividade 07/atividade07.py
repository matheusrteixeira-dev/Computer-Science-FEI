"""Atividade 07 - Ajuste exponencial, interpolação polinomial e integração numérica."""

import math

import matplotlib.pyplot as plt
import numpy as np
import scipy.integrate as si
from scipy.interpolate import lagrange
from sklearn.linear_model import LinearRegression


def exercicio_1():
    """Ajuste de y = a * b^x linearizando com logaritmo: ln(y) = ln(a) + x ln(b)."""
    x = np.array([1, 2, 3, 4])
    y = np.array([15.4, 10.8, 7.5, 5.3])

    modelo = LinearRegression().fit(x.reshape(-1, 1), np.log(y))
    b = np.exp(modelo.coef_[0])
    a = np.exp(modelo.intercept_)
    print(f"y = {a} * ({b})^x")

    plt.scatter(x, y)
    plt.plot(x, a * b ** x, color="red")
    plt.show()


def exercicio_2():
    """Polinômio interpolador de Lagrange para o preço de uma corrida em função da distância."""
    distancia = np.array([1, 7, 14])
    preco = np.array([10.5, 17.7, 35.2])

    poly = lagrange(distancia, preco)
    c2, c1, c0 = poly.coeffs
    print(f"Polinômio interpolador de Lagrange: {c2}*x^2 + {c1}*x + {c0}")
    print(f"Para uma distância de 4 km, o valor será R$ {poly(4):.2f}")

    # Distância percorrida com R$ 24,00: raiz real positiva de p(x) - 24.
    raizes = np.roots(poly - 24)
    distancia_24 = max(r.real for r in raizes if abs(r.imag) < 1e-9 and r.real > 0)
    print(f"Distância percorrida com R$ 24,00: {distancia_24:.2f} km")


def exercicio_3():
    """Integral de 1 / (1 + e^x) em [1, 2]: quadratura adaptativa x regra do trapézio."""
    def f(x):
        return 1 / (1 + math.exp(x))

    integral, _ = si.quad(f, 1, 2)
    print("Integral (quad):", integral)

    x = np.linspace(1, 2, 4)
    trapezio = si.trapezoid(1 / (1 + np.exp(x)), x)
    print("Integral (trapézio):", trapezio)
    print("Erro absoluto do trapézio:", np.abs(trapezio - integral))


if __name__ == "__main__":
    exercicio_1()
    exercicio_2()
    exercicio_3()
