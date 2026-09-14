"""Laboratório 06 - Exercício 02: estatísticas sobre as características físicas de cinco pessoas."""

QUANTIDADE_PESSOAS = 5


def le_pessoa():
    """Lê os dados de uma pessoa e os retorna como dicionário."""
    return {
        "sexo": input("Digite o sexo (M ou F): ").strip().upper(),
        "olhos": input("Digite a cor dos olhos: ").strip().capitalize(),
        "cabelos": input("Digite a cor dos cabelos: ").strip().capitalize(),
        "idade": int(input("Digite a idade: ")),
    }


def media_idade_olhos_castanhos_cabelos_pretos(pessoas):
    idades = [p["idade"] for p in pessoas if p["olhos"] == "Castanhos" and p["cabelos"] == "Pretos"]
    if not idades:
        print("Não há pessoas com essas características")
    else:
        print("A média de idade das pessoas de olhos castanhos e cabelos pretos é:",
              sum(idades) / len(idades))


def maior_idade(pessoas):
    print("A maior idade entre as pessoas é:", max(p["idade"] for p in pessoas))


def mulheres_loiras_olhos_azuis(pessoas):
    """Conta mulheres de cabelos louros e olhos azuis com idade entre 19 e 35 anos."""
    quantidade = sum(
        1 for p in pessoas
        if p["sexo"] == "F" and p["cabelos"] == "Louros" and p["olhos"] == "Azuis" and 18 < p["idade"] < 36
    )
    print("A quantidade de mulheres loiras de olhos azuis entre 19 e 35 anos é:", quantidade)


def main():
    pessoas = [le_pessoa() for _ in range(QUANTIDADE_PESSOAS)]
    print()
    media_idade_olhos_castanhos_cabelos_pretos(pessoas)
    mulheres_loiras_olhos_azuis(pessoas)
    maior_idade(pessoas)


if __name__ == "__main__":
    main()
