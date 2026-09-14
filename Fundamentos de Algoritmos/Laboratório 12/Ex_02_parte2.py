"""Laboratório 12 - Exercício 02 (parte 2): relógio digital em Tkinter atualizado a cada segundo."""

import tkinter as tk
from datetime import datetime

FONTE = ("Arial", 14)


def main():
    janela = tk.Tk()
    janela.title("Relógio Digital")
    janela.geometry("600x300")

    relogio = tk.Label(janela, font=FONTE, foreground="blue")
    relogio.place(x=200, y=100, anchor=tk.CENTER)
    data = tk.Label(janela, font=FONTE, foreground="blue")
    data.place(x=200, y=180, anchor=tk.CENTER)

    def atualiza():
        agora = datetime.now()
        data["text"] = agora.strftime("%d/%m/%Y")
        relogio["text"] = agora.strftime("%H:%M:%S")
        janela.after(1000, atualiza)

    atualiza()
    janela.mainloop()


if __name__ == "__main__":
    main()
