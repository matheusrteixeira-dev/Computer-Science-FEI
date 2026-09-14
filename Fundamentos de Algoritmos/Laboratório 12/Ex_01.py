"""Laboratório 12 - Exercício 01: soma de dois números em interface Tkinter (enunciado em ../images/lab12_01.png)."""

import tkinter as tk
from tkinter import messagebox

FONTE = ("Arial", 12)


def main():
    janela = tk.Tk()
    janela.title("Soma")
    janela.geometry("600x300")

    tk.Label(janela, text="Digite o primeiro número:", font=FONTE).place(x=200, y=100, anchor=tk.CENTER)
    tk.Label(janela, text="Digite o segundo número:", font=FONTE).place(x=200, y=140, anchor=tk.CENTER)
    tk.Label(janela, text="Resultado:", font=FONTE).place(x=200, y=180, anchor=tk.CENTER)

    entrada1 = tk.Entry(janela, width=14, font=FONTE)
    entrada1.place(x=400, y=100, anchor=tk.CENTER)
    entrada2 = tk.Entry(janela, width=14, font=FONTE)
    entrada2.place(x=400, y=140, anchor=tk.CENTER)
    saida = tk.Entry(janela, width=14, font=FONTE)
    saida.place(x=400, y=180, anchor=tk.CENTER)

    def soma():
        try:
            resultado = int(entrada1.get()) + int(entrada2.get())
        except ValueError:
            messagebox.showerror("Erro", "Digite dois números inteiros.")
            return
        saida.delete(0, tk.END)
        saida.insert(0, str(resultado))

    tk.Button(janela, text="Soma!", command=soma).place(x=200, y=220, anchor=tk.CENTER)

    janela.mainloop()


if __name__ == "__main__":
    main()
