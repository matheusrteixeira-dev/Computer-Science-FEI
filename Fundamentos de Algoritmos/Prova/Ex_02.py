"""Prova - Exercício 02: jogo da forca no terminal (enunciado em ../images/p1_03.png e p1_04.png)."""

from palavra import aleatoria

TENTATIVAS = 6

# Desenhos da forca indexados pelo número de erros restantes.
FORCA = {
    6: ["X==:==", "X  :  ", "X     ", "X     ", "X     ", "X     ", "======"],
    5: ["X==:==", "X  :  ", "X  O  ", "X     ", "X     ", "X     ", "======"],
    4: ["X==:==", "X  :  ", "X  O  ", "X  |  ", "X     ", "X     ", "======"],
    3: ["X==:==", "X  :  ", "X  O  ", "X \\|  ", "X     ", "X     ", "======"],
    2: ["X==:==", "X  :  ", "X  O  ", "X \\|/ ", "X     ", "X     ", "======"],
    1: ["X==:==", "X  :  ", "X  O  ", "X \\|/ ", "X /   ", "X     ", "======"],
    0: ["X==:==", "X  :  ", "X  O  ", "X \\|/ ", "X / \\ ", "X     ", "======"],
}


def imprime_estado(erros_restantes, descoberta, digitadas):
    print("\n".join(FORCA[erros_restantes]))
    if erros_restantes == 0:
        print("Enforcado!")
    print(" ".join(descoberta))
    print("Letras já digitadas:", ", ".join(digitadas))
    print()


def main():
    secreta = aleatoria().lower()
    descoberta = ["." for _ in secreta]
    digitadas = []
    erros_restantes = TENTATIVAS

    imprime_estado(erros_restantes, descoberta, digitadas)

    while erros_restantes > 0 and "." in descoberta:
        letra = input("Digite uma letra: ").strip().lower()

        if len(letra) != 1:
            print("Digite apenas uma letra")
            continue
        if letra in digitadas:
            print("Letra repetida")
            continue

        digitadas.append(letra)
        if letra in secreta:
            for i, caractere in enumerate(secreta):
                if caractere == letra:
                    descoberta[i] = letra
        else:
            print("Você errou!")
            erros_restantes -= 1

        imprime_estado(erros_restantes, descoberta, digitadas)

    if "." not in descoberta:
        print("Você ganhou!")
    else:
        print("A palavra era:", secreta)


if __name__ == "__main__":
    main()
