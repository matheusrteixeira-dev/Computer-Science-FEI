"""Estatística descritiva: medidas de posição e dispersão, histogramas, boxplots,
dados agrupados em classes, correlação/covariância e normalização min-max."""

import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns
from scipy import stats
from sklearn.datasets import load_iris
from sklearn.preprocessing import MinMaxScaler


def descreve(base, histograma=False, boxplot=False, bins="auto"):
    """Imprime média, mediana, desvio padrão amostral e resumo; opcionalmente plota os dados."""
    print("Média:", np.mean(base))
    print("Mediana:", np.median(base))
    print("Desvio padrão (amostral):", np.std(base, ddof=1))
    print(stats.describe(base))
    print()

    if histograma:
        plt.hist(base, bins=bins)
        plt.title("Dados")
        plt.ylabel("Frequência")
        plt.xlabel("Valores")
        plt.show()

    if boxplot:
        sns.set_theme(style="whitegrid")
        sns.boxplot(x=base)
        plt.show()


def exercicios_descritivos():
    descreve([26, 39, 26, 29, 34, 27, 28, 30, 29, 32, 34, 30, 29, 32, 21, 24, 23, 29, 30, 36, 31, 37, 34, 30, 27,
              28, 33, 28, 32, 34, 27, 34, 29, 31, 27, 32, 33, 36, 37, 30, 33, 23, 26, 27, 30, 29, 30, 31, 28, 27],
             histograma=True, boxplot=True)
    descreve([10, 12, 12, 16, 20, 23, 25, 28], boxplot=True)

    base = [5, 2, 11, 8, 3, 8, 7, 4]
    print("Histograma (contagens, limites):", np.histogram(base, bins="auto"))
    descreve(base, histograma=True, boxplot=True)

    descreve([7, 5, 6, 6, 4, 6, 8, 6, 9, 3], boxplot=True)
    descreve([7, 5, 11, 8, 3, 6, 2, 1, 9, 8], boxplot=True)
    descreve([64, 49, 54, 64, 97, 66, 76, 44, 71, 89])
    descreve([70, 72, 71, 55, 60, 62, 46, 77, 86, 71])

    # Distribuição de frequências com repetições explícitas.
    descreve([94] * 3 + [101] * 8 + [108] * 10 + [115] * 8 + [122] * 11 + [129] * 6 + [136] * 2 + [143] * 2,
             histograma=True)
    descreve([70, 72, 71, 55, 60, 62, 46, 77, 86, 69, 78, 65, 71], histograma=True, bins=4)
    descreve([26, 39, 26, 29, 34, 27, 28, 30, 29, 32], histograma=True)
    descreve([64, 69, 54, 64, 97, 66, 76, 44, 71, 89])


def dados_agrupados():
    """Média, variância e desvio padrão amostrais de dados agrupados (pontos médios x frequências)."""
    pontos_medios = np.array([1.1, 1.2, 1.3, 1.4, 1.5])
    frequencias = np.array([12, 27, 35, 20, 6])
    n = frequencias.sum()  # 100 observações

    soma = np.sum(pontos_medios * frequencias)
    soma_quadrados = np.sum(frequencias * pontos_medios ** 2)

    media = soma / n
    variancia = (soma_quadrados - soma ** 2 / n) / (n - 1)
    print("Dados agrupados - média:", media)
    print("Dados agrupados - variância:", variancia)
    print("Dados agrupados - desvio padrão:", np.sqrt(variancia))
    print()


def normalizacao_iris():
    """Correlação, covariância e normalização min-max do comprimento e da largura da sépala (Iris)."""
    iris = load_iris(as_frame=True).frame.drop(columns="target")
    print("Número de linhas e colunas:", iris.shape)
    print(iris.head(25))
    print("Correlação de Pearson:\n", iris.corr(method="pearson"))
    print("Covariância:\n", iris.cov())

    x = iris["sepal length (cm)"].to_numpy()
    y = iris["sepal width (cm)"].to_numpy()
    print("Média de x:", np.mean(x), "| Média de y:", np.mean(y))
    print("Desvio padrão de x:", np.std(x), "| Desvio padrão de y:", np.std(y))

    # Normalização manual: (x - min) / (max - min)
    print("x normalizado manualmente:\n", (x - x.min()) / (x.max() - x.min()))

    for nome, valores in (("x", x), ("y", y)):
        normalizado = MinMaxScaler().fit_transform(valores.reshape(-1, 1))
        print(f"{nome} normalizado com MinMaxScaler - média: {normalizado.mean():.4f}, "
              f"desvio padrão: {normalizado.std():.4f}")


if __name__ == "__main__":
    exercicios_descritivos()
    dados_agrupados()
    normalizacao_iris()
