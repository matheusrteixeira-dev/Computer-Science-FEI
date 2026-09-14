"""Laboratório 11 - Exercício 03 (versão alternativa): caracteres distintos de um texto usando as
chaves de um dicionário."""


def main():
    texto = input("Insira um texto qualquer: ")
    caracteres = dict.fromkeys(texto, 0)

    print(caracteres)
    print("Quantidade de caracteres distintos:", len(caracteres))


if __name__ == "__main__":
    main()
