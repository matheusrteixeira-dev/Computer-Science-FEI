"""Laboratório 13 - Cronômetro Pomodoro em Tkinter.

Cada tarefa tem 25 minutos. "Iniciar" começa a contagem regressiva, "Pausar" encerra a tarefa
atual e registra o tempo usado; o menu "Tarefas Completadas" lista as tarefas finalizadas.
"""

import tkinter as tk
from tkinter import messagebox

DURACAO_SEGUNDOS = 25 * 60
FONTE = ("Arial", 14)


class Pomodoro:
    def __init__(self, janela):
        self.janela = janela
        self.restante = DURACAO_SEGUNDOS
        self.agendamento = None  # identificador do janela.after em andamento
        self.tarefas_completadas = []

        tk.Label(janela, text="Tarefa:", font=FONTE).place(x=300, y=20, anchor=tk.CENTER)
        self.tarefa = tk.Entry(janela, width=30, font=("Arial", 12))
        self.tarefa.place(x=300, y=50, anchor=tk.CENTER)

        tk.Button(janela, text="Iniciar", command=self.iniciar).place(x=300, y=80, anchor=tk.CENTER)
        self.relogio = tk.Label(janela, text=self.formata(DURACAO_SEGUNDOS), font=FONTE, foreground="blue")
        self.relogio.place(x=300, y=110, anchor=tk.CENTER)
        tk.Button(janela, text="Pausar", command=self.pausar).place(x=300, y=140, anchor=tk.CENTER)

        menu = tk.Menu(janela)
        menu.add_command(label="Tarefas Completadas", command=self.mostrar_tarefas)
        janela.config(menu=menu)

    @staticmethod
    def formata(segundos):
        return f"{segundos // 60:02d}:{segundos % 60:02d}"

    def iniciar(self):
        self.cancelar_contagem()
        self.restante = DURACAO_SEGUNDOS
        self.tique()

    def tique(self):
        self.relogio["text"] = self.formata(self.restante)
        if self.restante == 0:
            self.finalizar("Tempo esgotado")
            return
        self.restante -= 1
        self.agendamento = self.janela.after(1000, self.tique)

    def pausar(self):
        if self.agendamento is not None:
            self.finalizar("Tarefa pausada")

    def finalizar(self, titulo):
        self.cancelar_contagem()
        usado = self.formata(DURACAO_SEGUNDOS - self.restante)
        self.tarefas_completadas.append(f"{self.tarefa.get()} / Tempo usado: {usado}")
        messagebox.showinfo(titulo, f"Fim da tarefa: {self.tarefa.get()}\nTempo usado: {usado}")
        self.restante = DURACAO_SEGUNDOS
        self.relogio["text"] = self.formata(DURACAO_SEGUNDOS)

    def cancelar_contagem(self):
        if self.agendamento is not None:
            self.janela.after_cancel(self.agendamento)
            self.agendamento = None

    def mostrar_tarefas(self):
        janela = tk.Toplevel(self.janela)
        janela.title("Tarefas Completadas")
        janela.geometry("600x300")
        texto = "\n".join(self.tarefas_completadas) or "Nenhuma tarefa completada."
        tk.Label(janela, text=texto, justify=tk.LEFT).place(x=20, y=20)


def main():
    janela = tk.Tk()
    janela.title("Cronômetro Pomodoro")
    janela.geometry("600x300")
    Pomodoro(janela)
    janela.mainloop()


if __name__ == "__main__":
    main()
