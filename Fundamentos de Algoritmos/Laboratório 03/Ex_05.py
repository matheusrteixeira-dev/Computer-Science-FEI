"""Laboratório 03 - Exercício 05: valor total dos ingressos de um grupo de visitantes.

Até 2 anos: gratuito; 3 a 12 anos: R$ 14,00; 65 anos ou mais: R$ 18,00; demais: R$ 23,00.
A leitura termina quando uma linha em branco é digitada.
"""


def preco_ingresso(idade):
    if idade <= 2:
        return 0.00
    if idade <= 12:
        return 14.00
    if idade >= 65:
        return 18.00
    return 23.00


if __name__ == "__main__":
    total = 0.0
    while True:
        entrada = input("Digite a idade do visitante (ou Enter para encerrar): ")
        if entrada == "":
            break
        total += preco_ingresso(int(entrada))

    print(f"O valor do ingresso de todos os visitantes é de R$ {total:.2f}")
