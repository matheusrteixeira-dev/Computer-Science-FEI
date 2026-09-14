"""Atividade 06 - Regressão linear simples e múltipla.

1. Ajuste manual potência x rotação de um motor e previsões com a reta obtida.
2. Regressão linear múltipla para a resistência à compressão do concreto
   (``concrete_data.csv``), avaliada pelo coeficiente R².
"""

from pathlib import Path

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from scipy.optimize import fsolve
from sklearn.linear_model import LinearRegression
from sklearn.metrics import r2_score
from sklearn.model_selection import train_test_split

DIRETORIO = Path(__file__).resolve().parent


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
    """Potência (hp) em função da rotação (rpm)."""
    x = np.array([400, 500, 600, 700, 750])
    y = np.array([600, 1050, 1440, 1900, 2120])

    a0, a1 = minimos_quadrados(x, y)
    print(f"Equação: y = {a1}x + ({a0})")

    plt.scatter(x, y, color="b", marker="o", s=50)
    plt.plot(x, a0 + a1 * x, color="r")
    plt.xlabel("x", fontsize=15)
    plt.ylabel("y", fontsize=15)
    plt.show()

    print("Resíduo:", residuo(x, y, a0, a1))
    print("Potência para 800 rpm:", a1 * 800 + a0)
    print("Rotação para 1650 hp:", fsolve(lambda rpm: a1 * rpm + a0 - 1650, 1))


def exercicio_2():
    """Regressão linear múltipla no conjunto de dados de concreto."""
    dados = pd.read_csv(DIRETORIO / "concrete_data.csv").to_numpy()
    X, y = dados[:, :-1], dados[:, -1]

    # 20% dos elementos no conjunto de teste
    x_train, x_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

    modelo = LinearRegression().fit(x_train, y_train)
    y_pred = modelo.predict(x_test)

    # Valores preditos x valores reais, com a reta identidade como referência.
    plt.plot(y_pred, y_test, "bo", markersize=10, markerfacecolor="C0")
    referencia = np.linspace(min(y_test), 1.2 * max(y_test), 10)
    plt.plot(referencia, referencia, "r--")
    plt.xlabel("Predição", fontsize=15)
    plt.ylabel("y", fontsize=15)
    plt.show()

    print("R²:", r2_score(y_test, y_pred))


if __name__ == "__main__":
    exercicio_1()
    exercicio_2()
