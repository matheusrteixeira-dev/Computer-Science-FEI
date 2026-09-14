"""Laboratório 04 - Exercício 01: verifica se uma letra é vogal ou consoante."""

if __name__ == "__main__":
    letra = input("Digite uma letra do alfabeto: ").strip().lower()

    if len(letra) != 1 or not letra.isalpha():
        print("Digite apenas uma letra")
    elif letra in "aeiou":
        print("A letra digitada é uma vogal:", letra)
    elif letra == "y":
        print("A letra digitada é o Y, podendo assumir o valor de vogal ou consoante, de acordo com o idioma")
    else:
        print("A letra digitada é uma consoante:", letra)
