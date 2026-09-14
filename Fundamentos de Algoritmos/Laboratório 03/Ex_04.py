"""Laboratório 03 - Exercício 04: valor a pagar em um posto de combustível com desconto por volume.

Álcool (R$ 2,80/l): 3% de desconto até 20 litros, 5% acima disso.
Gasolina (R$ 4,20/l): 4% de desconto até 20 litros, 6% acima disso.
"""

TABELA = {
    "Álcool": {"preco": 2.80, "desconto_ate_20": 0.03, "desconto_acima_20": 0.05},
    "Gasolina": {"preco": 4.20, "desconto_ate_20": 0.04, "desconto_acima_20": 0.06},
}

if __name__ == "__main__":
    litros = float(input("Digite a quantidade de litros vendidos: "))
    combustivel = input("Digite o tipo de combustível (Álcool ou Gasolina): ").strip().capitalize()

    if combustivel not in TABELA:
        print("Tipo de combustível inválido")
    else:
        dados = TABELA[combustivel]
        desconto = dados["desconto_ate_20"] if litros <= 20 else dados["desconto_acima_20"]
        valor = litros * dados["preco"] * (1 - desconto)
        print(f"O valor total é de: R$ {valor:.2f}")
