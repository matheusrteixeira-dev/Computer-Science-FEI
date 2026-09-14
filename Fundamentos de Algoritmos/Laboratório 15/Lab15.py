"""Laboratório 15 - Detecção de discurso de ódio: busca uma palavra suspeita em um log de chat
(p2-chat.txt), exibindo as mensagens em que ela aparece e sua frequência
(enunciado em ../images/lab15_01.png)."""

import tkinter as tk
from pathlib import Path
from tkinter import scrolledtext

ARQUIVO = Path(__file__).resolve().parent / "p2-chat.txt"
FONTE = ("Arial", 12)
SEPARADORES = "\t,!?."


def palavras_da_linha(linha):
    for separador in SEPARADORES:
        linha = linha.replace(separador, " ")
    return linha.lower().split()


def main():
    janela = tk.Tk()
    janela.title("Discurso de Ódio - Software")
    janela.geometry("700x500")

    tk.Label(janela, text="Palavra suspeita:", font=FONTE).place(x=100, y=50, anchor=tk.CENTER)
    tk.Label(janela, text="Frequência:", font=FONTE).place(x=100, y=70, anchor=tk.CENTER)

    palavra_entrada = tk.Entry(janela, width=14, font=FONTE)
    palavra_entrada.place(x=250, y=50, anchor=tk.CENTER)
    frequencia_entrada = tk.Entry(janela, width=14, font=FONTE)
    frequencia_entrada.place(x=250, y=70, anchor=tk.CENTER)

    resultado = scrolledtext.ScrolledText(janela, width=80, height=15)
    resultado.place(x=350, y=250, anchor=tk.CENTER)

    def pesquisa():
        palavra = palavra_entrada.get().strip().lower()
        resultado.delete("1.0", tk.END)
        frequencia = 0

        with open(ARQUIVO, "r", encoding="utf-8") as arquivo:
            for linha in arquivo:
                ocorrencias = palavras_da_linha(linha).count(palavra)
                if ocorrencias:
                    frequencia += ocorrencias
                    resultado.insert(tk.END, linha + "\n")

        frequencia_entrada.delete(0, tk.END)
        frequencia_entrada.insert(0, str(frequencia))

    tk.Button(janela, text="Pesquisar", command=pesquisa).place(x=350, y=50, anchor=tk.CENTER)

    janela.mainloop()


if __name__ == "__main__":
    main()
