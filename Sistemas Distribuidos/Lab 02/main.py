"""Lab 02 - Contagem de primos serial x multithread: tempo médio, speedup e fração serial (Amdahl).

Uso: python main.py  (lê dataset/data.csv, um inteiro por linha)
"""

from pathlib import Path
from time import perf_counter_ns

import numpy as np

from plot import Plot
from prime import is_prime, is_prime_thread

ARQUIVO_DADOS = Path(__file__).resolve().parent / "dataset" / "data.csv"
REPETICOES = 50


def mede_tempo_ns(funcao, *args):
    """Executa funcao(*args) e retorna (resultado, tempo em nanossegundos)."""
    inicio = perf_counter_ns()
    resultado = funcao(*args)
    return resultado, perf_counter_ns() - inicio


def fracao_serial(threads, speedup):
    """Métrica de Karp-Flatt: f = (p/S - 1) / (p - 1) = (p - S) / ((p - 1) * S)."""
    return (threads - speedup) / ((threads - 1) * speedup)


def main():
    with open(ARQUIVO_DADOS, encoding="utf-8") as arquivo:
        data = [int(linha) for linha in arquivo if linha.strip()]

    print(f"\nAnálise de {len(data)} valores\n")
    threads_usuario = int(input("Digite o número de threads desejado: "))
    configuracoes = [threads_usuario, 20, 600]

    tempos_serial = []
    tempos = {t: [] for t in configuracoes}
    speedups = {t: [] for t in configuracoes}

    for _ in range(REPETICOES):
        _, tempo_serial = mede_tempo_ns(is_prime, data)
        tempos_serial.append(tempo_serial / 1e6)

        for threads in configuracoes:
            _, tempo = mede_tempo_ns(is_prime_thread, data, threads)
            tempos[threads].append(tempo / 1e6)
            speedups[threads].append(tempo_serial / tempo)

    rotulos = [f"{t} threads" for t in configuracoes]
    plot = Plot()
    plot.plot_bar(np.mean(tempos_serial), np.mean(tempos[20]))
    plot.plot_threads([np.mean(tempos[t]) for t in configuracoes], rotulos, "Tempo x threads", "Tempo médio (ms)")
    plot.plot_threads([np.mean(speedups[t]) for t in configuracoes], rotulos, "Speedup x threads", "Speedup")

    print("Fração serial estimada (20 threads):", fracao_serial(20, np.mean(speedups[20])))


if __name__ == "__main__":
    main()
