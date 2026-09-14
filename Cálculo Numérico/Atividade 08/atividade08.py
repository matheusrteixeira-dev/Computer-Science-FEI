"""Atividade 08 - Equações diferenciais ordinárias.

Método de Euler, solução analítica com SymPy e integração numérica com ``odeint``.
"""

import matplotlib.pyplot as plt
import numpy as np
import sympy as sym
from scipy.integrate import odeint


def ode_euler(f, y0, t):
    """Resolve y' = f(y, t) com y(t[0]) = y0 pelo método de Euler explícito."""
    y = np.zeros(len(t))
    y[0] = y0
    for n in range(len(t) - 1):
        y[n + 1] = y[n] + f(y[n], t[n]) * (t[n + 1] - t[n])
    return y


def exercicio_1():
    """y' = y^2 t, y(0) = 1: método de Euler e solução analítica."""
    t = np.linspace(0, 1, 6)
    y = ode_euler(lambda y, t: y ** 2 * t, 1, t)
    print("Euler:", y)

    plt.plot(t, y, "b.-")
    plt.legend(["Euler"])
    plt.grid(True)
    plt.show()

    x = sym.symbols("x")
    f = sym.Function("f")
    solucao = sym.dsolve(f(x).diff(x) - f(x) ** 2 * x, f(x))
    constantes = sym.solve([solucao.rhs.subs(x, 0) - 1])  # condição inicial y(0) = 1
    print("Solução analítica:", solucao.subs(constantes))


def exercicio_2():
    """y' = y - 2t / y, y(1) = 2: odeint x método de Euler."""
    t = np.linspace(1, 1.5, 10)

    def modelo(y, t):
        return y - 2 * t / y

    y_odeint = odeint(modelo, 2, t).ravel()
    y_euler = ode_euler(modelo, 2, t)
    print("odeint:", y_odeint)
    print("Euler: ", y_euler)

    plt.plot(t, y_odeint, label="odeint")
    plt.plot(t, y_euler, "b.-", label="Euler")
    plt.xlabel("x")
    plt.ylabel("y(x)")
    plt.legend()
    plt.grid(True)
    plt.show()


if __name__ == "__main__":
    exercicio_1()
    exercicio_2()
