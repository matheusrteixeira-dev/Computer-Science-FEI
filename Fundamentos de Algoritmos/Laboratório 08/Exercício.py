"""Laboratório 08 - Jogo da velha para dois jogadores no terminal (enunciado em ../images/lab08_01.png)."""

LINHAS_VENCEDORAS = [
    (0, 1, 2), (3, 4, 5), (6, 7, 8),  # linhas
    (0, 3, 6), (1, 4, 7), (2, 5, 8),  # colunas
    (0, 4, 8), (2, 4, 6),             # diagonais
]


def imprime_tabuleiro(casas, rodada=None, simbolo=None):
    """Mostra o tabuleiro ao lado do mapa de posições (1 a 9)."""
    if rodada is not None:
        print(f"RODADA {rodada} - Jogada de [{simbolo}]")
    for i in range(0, 9, 3):
        print(f" {casas[i]} | {casas[i + 1]} | {casas[i + 2]}       {i + 1} | {i + 2} | {i + 3} ")
        if i < 6:
            print("---+---+---     ---+---+---")
    print()


def venceu(casas, simbolo):
    return any(all(casas[i] == simbolo for i in linha) for linha in LINHAS_VENCEDORAS)


def le_jogada(casas):
    """Lê uma posição de 1 a 9 que ainda esteja livre e retorna seu índice (0 a 8)."""
    while True:
        try:
            posicao = int(input("Insira o número correspondente à casa: "))
        except ValueError:
            posicao = 0

        if not 1 <= posicao <= 9:
            print("Entrada inválida! Digite um número de 1 a 9.")
        elif casas[posicao - 1] != " ":
            print("Essa casa já está ocupada.")
        else:
            return posicao - 1


def main():
    print("--- JOGO DA VELHA ---")
    casas = [" "] * 9
    imprime_tabuleiro(casas)

    for rodada in range(1, 10):
        simbolo = "X" if rodada % 2 == 1 else "O"
        casas[le_jogada(casas)] = simbolo
        imprime_tabuleiro(casas, rodada, simbolo)

        if venceu(casas, simbolo):
            print(f"O jogador que representa o [{simbolo}] ganhou o jogo!")
            break
    else:
        print("--- EMPATE ---")

    print("--- GAME OVER ---")


if __name__ == "__main__":
    main()
