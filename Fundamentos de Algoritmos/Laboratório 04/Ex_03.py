"""Laboratório 04 - Exercício 03: estação do ano no Hemisfério Sul (enunciado em ../images/lab04_03.png).

Início das estações: Outono em 20/03, Inverno em 21/06, Primavera em 22/09 e Verão em 21/12.
"""

MESES = ["Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
         "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"]


def estacao(dia, mes):
    """Retorna a estação do ano para o dia e o mês (1 a 12) informados."""
    data = (mes, dia)
    if (3, 20) <= data < (6, 21):
        return "Outono"
    if (6, 21) <= data < (9, 22):
        return "Inverno"
    if (9, 22) <= data < (12, 21):
        return "Primavera"
    return "Verão"


if __name__ == "__main__":
    nome_mes = input("Digite o mês: ").strip().capitalize()
    dia = int(input("Digite o dia: "))

    if nome_mes not in MESES:
        print("O mês digitado não existe")
    elif dia < 1 or dia > 31:
        print("O dia digitado não existe")
    else:
        print("A estação na data digitada é", estacao(dia, MESES.index(nome_mes) + 1))
