"""Gráficos de barras para comparar tempos e speedups."""

import matplotlib.pyplot as plt


class Plot:
    @staticmethod
    def _barras(valores, rotulos, titulo, rotulo_y, rotulo_x=None):
        cores = ["yellow", "blue", "red", "green"]
        posicoes = range(len(valores))
        plt.bar(posicoes, valores, color=cores[:len(valores)], edgecolor="black")
        plt.xticks(posicoes, rotulos)
        plt.title(titulo)
        plt.ylabel(rotulo_y)
        if rotulo_x:
            plt.xlabel(rotulo_x)
        plt.show()

    def plot_bar(self, tempo_serial, tempo_threads, rotulos=("Sem threads", "20 threads")):
        """Compara o tempo médio do método serial com o do método com threads."""
        self._barras([tempo_serial, tempo_threads], rotulos, "Método x tempo", "Tempo médio (ms)")

    def plot_threads(self, valores, rotulos, titulo, rotulo_y):
        """Compara uma métrica (tempo ou speedup) para diferentes quantidades de threads."""
        self._barras(valores, rotulos, titulo, rotulo_y, "Número de threads")
