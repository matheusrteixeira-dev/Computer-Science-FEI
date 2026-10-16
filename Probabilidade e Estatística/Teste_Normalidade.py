"""Testes de normalidade (Shapiro-Wilk e D'Agostino-Pearson) e teste de hipótese.

1. Verifica se o comprimento da sépala e a largura da pétala do conjunto Iris seguem
   distribuição normal (Shapiro-Wilk, alfa = 5%).
2. Verifica a normalidade da variável qsec do conjunto mtcars (normaltest, alfa = 10%).
   O arquivo mtcars.csv deve estar na mesma pasta deste script.
"""

from pathlib import Path

import matplotlib.pyplot as plt
import pandas as pd
from scipy.stats import normaltest, shapiro
from sklearn.datasets import load_iris

DIRETORIO = Path(__file__).resolve().parent


def teste_shapiro(amostra, nome, alfa=0.05):
    """Aplica o teste de Shapiro-Wilk (H0: a amostra é normal) e exibe o histograma."""
    estatistica, p = shapiro(amostra)
    print(f"{nome}: estatística = {estatistica:.3f}, p = {p:.3f}")
    if p > alfa:
        print("  Amostra gaussiana (não rejeita H0)")
    else:
        print("  Amostra não gaussiana (rejeita H0)")

    plt.hist(amostra, bins="auto")
    plt.title(nome)
    plt.ylabel("Frequência")
    plt.xlabel("Valores")
    plt.show()


def teste_iris():
    iris = load_iris(as_frame=True).frame
    print("Número de linhas e colunas:", iris.shape)
    print(iris.head(25))

    teste_shapiro(iris["sepal length (cm)"], "Comprimento da sépala")
    teste_shapiro(iris["petal width (cm)"], "Largura da pétala")


def teste_mtcars(significancia=0.10):
    caminho = DIRETORIO / "mtcars.csv"
    if not caminho.exists():
        print(f"Arquivo {caminho.name} não encontrado; teste de hipótese do mtcars ignorado.")
        return

    dados = pd.read_csv(caminho)
    print("Número de linhas e colunas:", dados.shape)
    print(dados.head(25))

    dados["qsec"].hist(bins=10)
    plt.show()

    estatistica, p_valor = normaltest(dados["qsec"])
    print("Estatística:", estatistica)
    print("p-valor:", p_valor)
    print("Rejeitamos a hipótese nula:", p_valor <= significancia)


if __name__ == "__main__":
    teste_iris()
    teste_mtcars()
