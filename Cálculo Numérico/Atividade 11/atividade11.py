"""Atividade 11 - Análise espectral com a Transformada Rápida de Fourier (FFT).

1. Espectro de um cosseno de 25 Hz amostrado a 100 Hz.
2. Espectro de um sinal com componente contínua e cossenos de 2 Hz e 30 Hz amostrado a 50 Hz
   (a componente de 30 Hz está acima da frequência de Nyquist e aparece como alias em 20 Hz).
3. Espectrograma e periodograma de um arquivo de áudio (``musica.wav``).
"""

from pathlib import Path

import matplotlib.pyplot as plt
import numpy as np
from scipy import signal
from scipy.fft import fft
from scipy.io import wavfile

DIRETORIO = Path(__file__).resolve().parent


def plota_espectro(fs, n, gerador, limites_sinal, limites_fft):
    """Amostra ``gerador(t)`` com ``n`` pontos a ``fs`` Hz e exibe o sinal e seu espectro de amplitude."""
    T = 1 / fs
    t = np.arange(n) * T
    y = gerador(t)
    yf = fft(y)
    xf = np.linspace(0.0, 1.0 / (2.0 * T), n // 2)

    plt.figure()
    plt.title("Sinal original")
    plt.plot(t, y)
    plt.axis(limites_sinal)
    plt.show()

    plt.figure()
    plt.title("Espectro (FFT)")
    plt.plot(xf, 2.0 / n * np.abs(yf[0:n // 2]))
    plt.axis(limites_fft)
    plt.show()


def exercicio_1():
    plota_espectro(
        fs=100, n=64,
        gerador=lambda t: 10 * np.cos(2 * np.pi * 25 * t),
        limites_sinal=[0, 0.64, -11, 11],
        limites_fft=[0, 50, 0, 11],
    )


def exercicio_2():
    plota_espectro(
        fs=50, n=1024,
        gerador=lambda t: 10 + 2 * np.cos(2 * np.pi * 2 * t) + np.cos(2 * np.pi * 30 * t),
        limites_sinal=[0, 1, 0, 15],
        limites_fft=[0, 25, 0, 2.5],
    )


def exercicio_3():
    fs, dados = wavfile.read(DIRETORIO / "musica.wav")
    nfft = 1024

    plt.figure(figsize=(7, 5))
    plt.specgram(dados, NFFT=nfft, Fs=fs, noverlap=7 * nfft // 8)
    plt.xlabel("Tempo [s]")
    plt.ylabel("Frequência [Hz]")
    plt.show()

    f, pxx = signal.periodogram(dados, fs)
    plt.title("Periodograma da voz")
    plt.plot(f, pxx)
    plt.xlim(150, 280)
    plt.xlabel("Frequência [Hz]")
    plt.ylabel("Potência")
    plt.show()


if __name__ == "__main__":
    exercicio_1()
    exercicio_2()
    exercicio_3()
