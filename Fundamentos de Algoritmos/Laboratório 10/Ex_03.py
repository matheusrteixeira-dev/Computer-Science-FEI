"""Laboratório 10 - Exercício 03: tradutor para Pig Latin.

Palavras iniciadas por vogal recebem o sufixo "way"; nas demais, as consoantes iniciais
são movidas para o final, seguidas de "ay" (ex.: "python" -> "onpythay").
"""

VOGAIS = "aeiou"


def palavra_pig_latin(palavra):
    if palavra[0] in VOGAIS:
        return palavra + "way"

    for i, letra in enumerate(palavra):
        if letra in VOGAIS:
            return palavra[i:] + palavra[:i] + "ay"
    return palavra + "ay"  # palavra sem vogais


def frase_pig_latin(frase):
    for sinal in ",.!?":
        frase = frase.replace(sinal, " ")
    return " ".join(palavra_pig_latin(p) for p in frase.lower().split())


if __name__ == "__main__":
    s = input("Digite a frase: ")
    print("Frase em Pig Latin:", frase_pig_latin(s))
