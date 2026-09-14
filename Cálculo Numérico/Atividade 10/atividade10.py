"""Atividade 10 - Correlação e regressão linear no conjunto de dados Wine Quality (vinho tinto)."""

from pathlib import Path

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import seaborn as sns
from sklearn.linear_model import LinearRegression
from sklearn.metrics import r2_score

DIRETORIO = Path(__file__).resolve().parent


def analisa_par(df, coluna_x, coluna_y):
    """Imprime a correlação de Pearson e ajusta a reta coluna_y = a0 + a1 * coluna_x."""
    x = df[coluna_x].to_numpy().reshape(-1, 1)
    y = df[coluna_y].to_numpy()

    print(f"\n{coluna_y} (y) x {coluna_x} (x)")
    print("Matriz de correlação:\n", np.corrcoef(x.ravel(), y))

    modelo = LinearRegression().fit(x, y)
    print("Intercepto (a0):", modelo.intercept_)
    print("Coeficiente angular (a1):", modelo.coef_[0])
    print("R²:", r2_score(y, modelo.predict(x)))

    plt.scatter(x, y)
    plt.plot(x, modelo.predict(x), color="red")
    plt.xlabel(coluna_x)
    plt.ylabel(coluna_y)
    plt.show()


if __name__ == "__main__":
    sns.set()

    df = pd.read_csv(DIRETORIO / "winequality-red.csv")
    print("Número de linhas e colunas:", df.shape)
    print(df.head(10))

    analisa_par(df, "quality", "fixed acidity")
    analisa_par(df, "density", "citric acid")
    analisa_par(df, "alcohol", "quality")
    analisa_par(df, "pH", "sulphates")
