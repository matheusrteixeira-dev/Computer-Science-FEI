"""Laboratório 12 - Exercício 02: conversão de decimal para binário, hexadecimal e octal em Tkinter."""

import tkinter as tk
from tkinter import messagebox

FONTE = ("Arial", 12)


def main():
    janela = tk.Tk()
    janela.title("Conversão Numérica")
    janela.geometry("600x300")

    tk.Label(janela, text="Número decimal:", font=FONTE).place(x=200, y=100, anchor=tk.CENTER)
    tk.Label(janela, text="Resultado:", font=FONTE).place(x=200, y=180, anchor=tk.CENTER)

    entrada = tk.Entry(janela, width=14, font=FONTE)
    entrada.place(x=400, y=100, anchor=tk.CENTER)
    saida = tk.Entry(janela, width=14, font=FONTE)
    saida.place(x=400, y=180, anchor=tk.CENTER)

    def converte(formato):
        """Converte o valor digitado usando o especificador de formato ('b', 'x' ou 'o')."""
        try:
            valor = int(entrada.get())
        except ValueError:
            messagebox.showerror("Erro", "Digite um número inteiro.")
            return
        saida.delete(0, tk.END)
        saida.insert(0, format(valor, formato))

    tk.Button(janela, text="Binário", command=lambda: converte("b")).place(x=200, y=140, anchor=tk.CENTER)
    tk.Button(janela, text="Hexadecimal", command=lambda: converte("X")).place(x=280, y=140, anchor=tk.CENTER)
    tk.Button(janela, text="Octal", command=lambda: converte("o")).place(x=360, y=140, anchor=tk.CENTER)

    janela.mainloop()


if __name__ == "__main__":
    main()
