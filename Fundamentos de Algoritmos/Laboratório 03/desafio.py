"""Laboratório 03 - Desafio: caixa eletrônico com notas de 100, 50, 10, 5 e 1 (saque de R$ 10 a R$ 600)."""

NOTAS = (100, 50, 10, 5, 1)


def decompoe_saque(valor):
    """Retorna um dicionário {nota: quantidade} usando a menor quantidade de notas."""
    quantidades = {}
    for nota in NOTAS:
        quantidades[nota], valor = divmod(valor, nota)
    return quantidades


if __name__ == "__main__":
    saque = int(input("Digite o valor do saque R$: "))

    if saque < 10 or saque > 600:
        print("Valor fora do intervalo, digite um valor de saque válido!")
    else:
        print()
        for nota, quantidade in decompoe_saque(saque).items():
            print(f"A quantidade de notas de R$ {nota} é de: {quantidade}")
