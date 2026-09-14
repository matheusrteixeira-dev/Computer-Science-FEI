"""Laboratório 04 - Desafio 02: calcula o dia seguinte a uma data, considerando anos bissextos."""


def eh_bissexto(ano):
    return ano % 400 == 0 or (ano % 4 == 0 and ano % 100 != 0)


def dias_no_mes(mes, ano):
    if mes == 2:
        return 29 if eh_bissexto(ano) else 28
    if mes in (4, 6, 9, 11):
        return 30
    return 31


def dia_seguinte(dia, mes, ano):
    """Retorna (dia, mes, ano) do dia seguinte à data informada (que deve ser válida)."""
    if dia < dias_no_mes(mes, ano):
        return dia + 1, mes, ano
    if mes < 12:
        return 1, mes + 1, ano
    return 1, 1, ano + 1


if __name__ == "__main__":
    dia = int(input("Digite o dia: "))
    mes = int(input("Digite o mês: "))
    ano = int(input("Digite o ano: "))

    if ano <= 0:
        print("O ano digitado não existe")
    elif mes < 1 or mes > 12:
        print("O mês digitado não existe")
    elif dia < 1 or dia > dias_no_mes(mes, ano):
        print("O dia digitado não existe nesse mês")
    else:
        status = "bissexto" if eh_bissexto(ano) else "não bissexto"
        d, m, a = dia_seguinte(dia, mes, ano)
        print(f"O dia seguinte é: {d:02d}/{m:02d}/{a} - ano {status}")
