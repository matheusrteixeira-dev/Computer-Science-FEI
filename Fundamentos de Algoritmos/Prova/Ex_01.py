"""Prova - Exercício 01: consumo de energia elétrica em interface Tkinter
(enunciado em ../images/p1_01.png e p1_02.png).

O arquivo consumo.txt contém medições acumuladas (em Wh) por hora, no formato:
    dia hora lampadas tomadas chuveiro ar_condicionado
"""

import tkinter as tk
from pathlib import Path
from tkinter import messagebox
from tkinter.ttk import Checkbutton

ARQUIVO = Path(__file__).resolve().parent / "consumo.txt"
FONTE = ("Arial", 12)

# Índice de cada equipamento nas colunas do arquivo.
COLUNAS = {"Lâmpadas": 2, "Tomadas": 3, "Chuveiro": 4, "Ar Condicionado": 5}


def le_medicoes(caminho):
    """Retorna um dicionário {(dia, hora): [valores acumulados em Wh]} na ordem do arquivo."""
    medicoes = {}
    with open(caminho, "r", encoding="utf-8") as arquivo:
        for linha in arquivo:
            partes = linha.split()
            if len(partes) == 6:
                medicoes[(partes[0], partes[1])] = [float(v) for v in partes]
    return medicoes


def consumo_total_kwh(medicoes):
    """Soma dos acumulados de todos os equipamentos na última medição."""
    ultima = list(medicoes.values())[-1]
    return sum(ultima[c] for c in COLUNAS.values()) / 1000


def consumo_periodo_kwh(medicoes, inicio, fim, equipamentos):
    """Consumo dos equipamentos selecionados entre as medições inicio e fim ((dia, hora))."""
    total = sum(medicoes[fim][COLUNAS[e]] - medicoes[inicio][COLUNAS[e]] for e in equipamentos)
    return total / 1000


def main():
    janela = tk.Tk()
    janela.title("Consumo de Energia Elétrica")
    janela.geometry("600x400")

    def campo(rotulo, x_rotulo, x_entrada, y):
        tk.Label(janela, text=rotulo, font=FONTE).place(x=x_rotulo, y=y, anchor=tk.CENTER)
        entrada = tk.Entry(janela, width=14, font=FONTE)
        entrada.place(x=x_entrada, y=y, anchor=tk.CENTER)
        return entrada

    data_inicial = campo("Data Inicial:", 100, 220, 50)
    data_final = campo("Data Final:", 100, 220, 80)
    hora_inicial = campo("Hora Inicial:", 380, 500, 50)
    hora_final = campo("Hora Final:", 380, 500, 80)
    consumo_total = campo("Consumo Total (kWh):", 150, 400, 300)
    consumo_calculado = campo("Consumo Calculado (kWh):", 150, 400, 330)

    selecionados = {}
    posicoes = {"Lâmpadas": (230, 200), "Tomadas": (350, 200), "Chuveiro": (230, 230), "Ar Condicionado": (370, 230)}
    for equipamento, (x, y) in posicoes.items():
        selecionados[equipamento] = tk.BooleanVar(value=False)
        Checkbutton(janela, text=equipamento, variable=selecionados[equipamento]).place(x=x, y=y, anchor=tk.CENTER)

    def mostra(entrada, valor):
        entrada.delete(0, tk.END)
        entrada.insert(0, f"{valor:.2f}")

    def calcular():
        medicoes = le_medicoes(ARQUIVO)
        mostra(consumo_total, consumo_total_kwh(medicoes))

        inicio = (data_inicial.get().strip(), hora_inicial.get().strip())
        fim = (data_final.get().strip(), hora_final.get().strip())
        if inicio not in medicoes or fim not in medicoes:
            messagebox.showerror("Erro", "Data ou hora não encontrada nas medições.")
            return

        equipamentos = [e for e, marcado in selecionados.items() if marcado.get()]
        mostra(consumo_calculado, consumo_periodo_kwh(medicoes, inicio, fim, equipamentos))

    def limpar():
        for entrada in (data_inicial, data_final, hora_inicial, hora_final, consumo_total, consumo_calculado):
            entrada.delete(0, tk.END)
        for marcado in selecionados.values():
            marcado.set(False)

    def sobre():
        messagebox.showinfo("P2 - Algoritmos", "Consumo de Energia Elétrica")

    tk.Button(janela, text="Calcular", command=calcular).place(x=200, y=150, anchor=tk.CENTER)
    tk.Button(janela, text="Limpar", command=limpar).place(x=270, y=150, anchor=tk.CENTER)
    tk.Button(janela, text="Sobre", command=sobre).place(x=330, y=150, anchor=tk.CENTER)

    janela.mainloop()


if __name__ == "__main__":
    main()
