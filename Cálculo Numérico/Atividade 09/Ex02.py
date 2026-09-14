"""Atividade 09 - Exercício 02: y' = y + t y^2, y(0) = 1, pelo método de Euler com h = 0.2."""

import matplotlib.pyplot as plt
import numpy as np


def ode_euler(f, y0, t):
    """Resolve y' = f(y, t) com y(t[0]) = y0 pelo método de Euler explícito."""
    y = np.zeros(len(t))
    y[0] = y0
    for n in range(len(t) - 1):
        y[n + 1] = y[n] + f(y[n], t[n]) * (t[n + 1] - t[n])
    return y


if __name__ == "__main__":
    t = np.linspace(0, 1, 6)
    y = ode_euler(lambda y, t: y + t * y ** 2, 1, t)
    print(y)

    plt.plot(t, y, "b.-")
    plt.legend(["Euler"])
    plt.grid(True)
    plt.show()
