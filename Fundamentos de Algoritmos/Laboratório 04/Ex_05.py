"""Laboratório 04 - Exercício 05: cor de uma casa do tabuleiro de xadrez (enunciado em ../images/lab04_05.png).

A casa a1 é preta; as cores alternam a cada coluna e a cada linha.
"""

if __name__ == "__main__":
    coluna = input("Digite a coluna da posição (a-h): ").strip().lower()
    linha = int(input("Digite a linha da posição (1-8): "))

    if len(coluna) != 1 or coluna not in "abcdefgh" or not 1 <= linha <= 8:
        print("O valor inserido não se encontra em um tabuleiro de xadrez")
    else:
        indice_coluna = ord(coluna) - ord("a") + 1
        if (indice_coluna + linha) % 2 == 0:
            print("A posição digitada é de um quadrado preto")
        else:
            print("A posição digitada é de um quadrado branco")
