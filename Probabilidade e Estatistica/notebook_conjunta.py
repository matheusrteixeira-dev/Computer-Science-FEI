"""Distribuição conjunta: média, desvio padrão, covariância e correlação entre duas variáveis.

x = renda familiar (em R$ 1.000,00); y = número de aparelhos de TV em cores.
"""

import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns

if __name__ == "__main__":
    x = [1, 2, 3, 1, 3, 2, 3, 1, 2, 3]
    y = [2, 1, 3, 1, 3, 3, 2, 1, 2, 2]

    print("Média de x:", np.mean(x))
    print("Média de y:", np.mean(y))
    print("Desvio padrão de x:", np.std(x))
    print("Desvio padrão de y:", np.std(y))
    print("Matriz de covariância:\n", np.cov(x, y))
    print("Matriz de correlação:\n", np.corrcoef(x, y))

    sns.set_theme(style="whitegrid")
    sns.boxplot(x=y)
    plt.show()
