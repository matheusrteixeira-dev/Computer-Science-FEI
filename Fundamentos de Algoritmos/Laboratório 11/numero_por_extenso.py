"""Laboratório 11 - Escreve por extenso um número inteiro de 0 a 999."""

UNIDADES = ["zero", "um", "dois", "três", "quatro", "cinco", "seis", "sete", "oito", "nove"]
DEZ_A_DEZENOVE = ["dez", "onze", "doze", "treze", "quatorze", "quinze",
                  "dezesseis", "dezessete", "dezoito", "dezenove"]
DEZENAS = ["", "", "vinte", "trinta", "quarenta", "cinquenta",
           "sessenta", "setenta", "oitenta", "noventa"]
CENTENAS = ["", "cento", "duzentos", "trezentos", "quatrocentos", "quinhentos",
            "seiscentos", "setecentos", "oitocentos", "novecentos"]


def ate_99_por_extenso(numero):
    """Escreve por extenso um número de 1 a 99."""
    if numero < 10:
        return UNIDADES[numero]
    if numero < 20:
        return DEZ_A_DEZENOVE[numero - 10]

    dezena, unidade = divmod(numero, 10)
    if unidade == 0:
        return DEZENAS[dezena]
    return f"{DEZENAS[dezena]} e {UNIDADES[unidade]}"


def por_extenso(numero):
    """Escreve por extenso um número de 0 a 999."""
    if not 0 <= numero <= 999:
        raise ValueError("o número deve estar entre 0 e 999")
    if numero == 0:
        return UNIDADES[0]
    if numero == 100:
        return "cem"

    centena, resto = divmod(numero, 100)
    partes = []
    if centena:
        partes.append(CENTENAS[centena])
    if resto:
        partes.append(ate_99_por_extenso(resto))
    return " e ".join(partes)


if __name__ == "__main__":
    n = int(input("Digite um número inteiro entre 0 e 999: "))
    try:
        print("Resultado:", por_extenso(n))
    except ValueError:
        print("Número inválido")
