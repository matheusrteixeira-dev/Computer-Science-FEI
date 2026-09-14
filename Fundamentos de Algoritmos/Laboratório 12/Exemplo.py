"""Laboratório 12 - Exemplo: primeira aplicação gráfica com Tkinter (rótulo, entrada e botão)."""

import tkinter as tk


def main():
    janela = tk.Tk()
    janela.title("Algoritmos")
    janela.geometry("400x400")

    # O posicionamento com place usa o centro do widget como referência (anchor=CENTER).
    rotulo = tk.Label(janela, text="Primeira aplicação gráfica no Python!", font=("Arial Bold", 14))
    rotulo.place(x=200, y=100, anchor=tk.CENTER)

    entrada = tk.Entry(janela, width=14, font=("Arial Bold", 14))
    entrada.place(x=200, y=50, anchor=tk.CENTER)

    def clique():
        rotulo["text"] = entrada.get()

    botao = tk.Button(janela, text="Clique aqui!", command=clique)
    botao.place(x=200, y=200, anchor=tk.CENTER)

    janela.mainloop()


if __name__ == "__main__":
    main()
