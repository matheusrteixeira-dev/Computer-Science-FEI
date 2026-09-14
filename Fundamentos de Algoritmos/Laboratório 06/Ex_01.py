"""Laboratório 06 - Exercício 01: média aritmética (A) ou ponderada (P, pesos 5, 3 e 2) de três notas."""


def media(nota1, nota2, nota3, tipo):
    """Retorna a média do tipo informado ('A' ou 'P'), ou None se o tipo for inválido."""
    if tipo == "A":
        return (nota1 + nota2 + nota3) / 3
    if tipo == "P":
        return (nota1 * 5 + nota2 * 3 + nota3 * 2) / 10
    return None


def main():
    nota1 = float(input("Digite a primeira nota: "))
    nota2 = float(input("Digite a segunda nota: "))
    nota3 = float(input("Digite a terceira nota: "))
    tipo = input("Digite a letra (A - aritmética, P - ponderada): ").strip().upper()

    resultado = media(nota1, nota2, nota3, tipo)
    if resultado is None:
        print("Tipo de média inválido")
    elif tipo == "A":
        print("Média aritmética:", resultado)
    else:
        print("Média ponderada:", resultado)


if __name__ == "__main__":
    main()
