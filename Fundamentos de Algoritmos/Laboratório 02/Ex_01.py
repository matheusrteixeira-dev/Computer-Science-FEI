"""Laboratório 02 - Exercício 01: nome do mês correspondente a um número de 1 a 12."""

MESES = ["Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
         "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"]

if __name__ == "__main__":
    x = int(input("Digite um número de 1 a 12: "))

    if 1 <= x <= 12:
        print(MESES[x - 1])
    else:
        print("O número está fora do intervalo")
