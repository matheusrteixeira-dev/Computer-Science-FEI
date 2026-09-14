"""Laboratório 04 - Desafio 01: animal do horóscopo chinês (enunciado em ../images/lab04_06.png).

O ciclo tem 12 anos; o ano 2000 corresponde ao Dragão (2000 % 12 == 8).
"""

ANIMAIS = {
    8: "Dragão", 9: "Cobra", 10: "Cavalo", 11: "Carneiro",
    0: "Macaco", 1: "Galo", 2: "Cachorro", 3: "Porco",
    4: "Rato", 5: "Boi", 6: "Tigre", 7: "Lebre",
}

if __name__ == "__main__":
    ano = int(input("Digite o ano de nascimento: "))

    if ano <= 0:
        print("O ano não é válido")
    else:
        print(ANIMAIS[ano % 12])
