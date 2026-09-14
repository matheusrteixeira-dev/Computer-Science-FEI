"""Laboratório 04 - Desafio 03: aumento salarial pela avaliação do funcionário (enunciado em ../images/lab04_08.png).

Classificação 0.0: inaceitável; 0.4: aceitável; 0.6 ou mais: excelente.
O aumento é igual a classificação x R$ 2.400,00.
"""

BASE_AUMENTO = 2400

if __name__ == "__main__":
    classificacao = float(input("Digite o valor da classificação do funcionário: "))

    if classificacao == 0.0:
        status = "Inaceitável"
    elif classificacao == 0.4:
        status = "Aceitável"
    elif classificacao >= 0.6:
        status = "Excelente"
    else:
        status = None

    if status is None:
        print("A classificação não é válida")
    else:
        print(f"{classificacao} / {status} / R$ {classificacao * BASE_AUMENTO:.2f}")
