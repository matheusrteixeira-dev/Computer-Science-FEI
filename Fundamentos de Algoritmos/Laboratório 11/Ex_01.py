"""Laboratório 11 - Exercício 01: busca reversa em dicionário (todas as chaves associadas a um valor)."""


def procura_reversa(dicionario, valor_procurado):
    return [chave for chave, valor in dicionario.items() if valor == valor_procurado]


def main():
    d = {1: "a", 2: "n", 3: "a", 4: "j", 5: "u", 6: "l", 7: "i", 8: "a"}
    print(procura_reversa(d, "a"))


if __name__ == "__main__":
    main()
