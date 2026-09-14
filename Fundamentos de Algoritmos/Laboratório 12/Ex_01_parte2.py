"""Laboratório 12 - Exercício 01 (parte 2): verifica em interface Tkinter se uma letra é vogal ou consoante."""

import tkinter as tk
from tkinter import messagebox


def main():
    janela = tk.Tk()
    janela.title("Vogal ou consoante")
    janela.geometry("400x300")

    entrada = tk.Entry(janela, width=14, font=("Arial", 14))
    entrada.place(x=200, y=50, anchor=tk.CENTER)

    def avaliar():
        letra = entrada.get().strip().lower()
        if len(letra) != 1 or not letra.isalpha():
            messagebox.showinfo("Resultado", "Digite exatamente uma letra")
        elif letra in "aeiou":
            messagebox.showinfo("Resultado", "A letra é vogal")
        elif letra == "y":
            messagebox.showinfo("Resultado", "A letra às vezes é vogal e às vezes consoante")
        else:
            messagebox.showinfo("Resultado", "A letra é consoante")

    tk.Button(janela, text="Resultado", command=avaliar).place(x=200, y=200, anchor=tk.CENTER)

    janela.mainloop()


if __name__ == "__main__":
    main()
