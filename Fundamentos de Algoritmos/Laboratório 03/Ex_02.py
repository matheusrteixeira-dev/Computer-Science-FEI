"""Laboratório 03 - Exercício 02: folha de pagamento (enunciado em ../images/lab03_2.png).

Descontos: INSS de 10% e IR conforme a faixa do salário bruto; o FGTS (11%) é apenas informativo.
"""


def aliquota_ir(salario_bruto):
    """Alíquota do imposto de renda (em %) para o salário bruto informado."""
    if salario_bruto <= 900:
        return 0
    if salario_bruto <= 1500:
        return 5
    if salario_bruto <= 2500:
        return 10
    return 20


if __name__ == "__main__":
    valor_hora = float(input("Digite o valor por hora trabalhada: "))
    horas = float(input("Digite a quantidade de horas trabalhadas: "))

    salario_bruto = valor_hora * horas
    fgts = salario_bruto * 0.11
    inss = salario_bruto * 0.10
    ir = aliquota_ir(salario_bruto)
    valor_ir = salario_bruto * ir / 100
    descontos = inss + valor_ir
    salario_liquido = salario_bruto - descontos

    print()
    print(f"{f'Salário Bruto: ({valor_hora:g} * {horas:g})':<30}: R$ {salario_bruto:10.2f}")
    print(f"{f'(-) IR ({ir}%)':<30}: R$ {valor_ir:10.2f}")
    print(f"{'(-) INSS (10%)':<30}: R$ {inss:10.2f}")
    print(f"{'FGTS (11%)':<30}: R$ {fgts:10.2f}")
    print("_" * 46)
    print(f"{'Total de descontos':<30}: R$ {descontos:10.2f}")
    print("_" * 46)
    print(f"{'Salário Líquido':<30}: R$ {salario_liquido:10.2f}")
