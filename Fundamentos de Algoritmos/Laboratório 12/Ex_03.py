"""Laboratório 12 - Exercício 03: cadastro e pesquisa de veículos para locadora em Tkinter.

Cada veículo é salvo em um arquivo <placa>.txt; a pesquisa é acessada pelo menu "Opções".
"""

import tkinter as tk
from tkinter import messagebox
from tkinter.ttk import Checkbutton

FONTE = ("Arial", 12)

CAMPOS_TEXTO = ["Marca", "Modelo", "Ano de Fabricação", "Placa", "Quilometragem"]
OPCIONAIS = ["Ar Condicionado", "Direção Hidráulica", "Rádio", "Airbag"]


def salvar_veiculo(entradas, opcionais):
    placa = entradas["Placa"].get().strip()
    if not placa:
        messagebox.showerror("Erro", "Informe a placa do veículo.")
        return
    try:
        int(entradas["Ano de Fabricação"].get())
    except ValueError:
        messagebox.showerror("Erro", "O ano de fabricação deve ser um número inteiro.")
        return

    with open(f"{placa}.txt", "w", encoding="utf-8") as arquivo:
        for campo in CAMPOS_TEXTO:
            arquivo.write(f"{entradas[campo].get().strip()}\n")
        for opcional in OPCIONAIS:
            arquivo.write(f"{opcionais[opcional].get()}\n")

    messagebox.showinfo("Resultado", "Veículo cadastrado com sucesso")


def abrir_pesquisa(janela_principal):
    janela = tk.Toplevel(janela_principal)
    janela.title("Pesquisa de Veículos")
    janela.geometry("500x500")

    tk.Label(janela, text="Placa do veículo", font=FONTE).place(x=250, y=50, anchor=tk.CENTER)
    placa_entrada = tk.Entry(janela, width=14, font=FONTE)
    placa_entrada.place(x=250, y=100, anchor=tk.CENTER)

    resultado = tk.Label(janela, text="", font=FONTE, justify=tk.LEFT)
    resultado.place(x=250, y=200, anchor=tk.CENTER)

    def buscar():
        placa = placa_entrada.get().strip()
        try:
            with open(f"{placa}.txt", "r", encoding="utf-8") as arquivo:
                valores = [linha.strip() for linha in arquivo]
        except OSError:
            messagebox.showinfo("Resultado", "Veículo não encontrado", parent=janela)
            return

        rotulos = CAMPOS_TEXTO + [f"Possui {o.lower()}" for o in OPCIONAIS]
        resultado["text"] = "\n".join(f"{r}: {v}" for r, v in zip(rotulos, valores))

    def limpar():
        resultado["text"] = ""

    tk.Button(janela, text="Buscar", command=buscar).place(x=280, y=350, anchor=tk.CENTER)
    tk.Button(janela, text="Limpar", command=limpar).place(x=220, y=350, anchor=tk.CENTER)


def main():
    janela = tk.Tk()
    janela.title("Aluguel de carros")
    janela.geometry("600x600")

    tk.Label(janela, text="Cadastro de Veículos", font=("Arial", 22)).place(x=200, y=10, anchor=tk.CENTER)

    entradas = {}
    y = 50
    for campo in CAMPOS_TEXTO:
        tk.Label(janela, text=campo, font=FONTE).place(x=100, y=y, anchor=tk.CENTER)
        entradas[campo] = tk.Entry(janela, width=14, font=FONTE)
        entradas[campo].place(x=250, y=y, anchor=tk.CENTER)
        y += 30

    opcionais = {}
    for opcional in OPCIONAIS:
        tk.Label(janela, text=opcional, font=FONTE).place(x=100, y=y, anchor=tk.CENTER)
        opcionais[opcional] = tk.BooleanVar(value=False)
        Checkbutton(janela, text="Possui", variable=opcionais[opcional]).place(x=250, y=y, anchor=tk.CENTER)
        y += 30

    tk.Button(janela, text="Enviar", command=lambda: salvar_veiculo(entradas, opcionais)).place(
        x=200, y=y + 20, anchor=tk.CENTER)

    menu = tk.Menu(janela)
    opcoes = tk.Menu(menu, tearoff=0)
    opcoes.add_command(label="Pesquisa", command=lambda: abrir_pesquisa(janela))
    menu.add_cascade(label="Opções", menu=opcoes)
    janela.config(menu=menu)

    janela.mainloop()


if __name__ == "__main__":
    main()
