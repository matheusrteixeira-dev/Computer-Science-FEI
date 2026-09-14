"""Laboratório 11 - Exercício 04: conta as letras de duas palavras com dicionários e verifica se são anagramas."""


def conta_letras(palavra):
    contagem = {}
    for letra in palavra.lower():
        contagem[letra] = contagem.get(letra, 0) + 1
    return contagem


def main():
    texto1 = input("Digite a primeira palavra: ")
    texto2 = input("Digite a segunda palavra: ")

    contagem1 = conta_letras(texto1)
    contagem2 = conta_letras(texto2)

    for letra, quantidade in contagem1.items():
        print(letra, quantidade)

    if contagem1 == contagem2:
        print("As palavras são anagramas")
    else:
        print("As palavras não são anagramas")


if __name__ == "__main__":
    main()
