"""Laboratório 14 - Usa o módulo inteiro para verificar se o texto digitado é um número inteiro."""

from inteiro import is_integer


def main():
    n = input("Digite o número: ")
    print("É inteiro" if is_integer(n) else "Não é inteiro")


if __name__ == "__main__":
    main()
