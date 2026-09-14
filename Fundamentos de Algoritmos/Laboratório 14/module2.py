"""Laboratório 14 - Classifica uma senha como boa ou fraca usando as regras do módulo conferir."""

from conferir import maiuscula, minuscula, numero, oito


def senha_forte(senha):
    return all(regra(senha) for regra in (oito, maiuscula, minuscula, numero))


def main():
    senha = input("Digite a senha: ")
    print("Senha boa" if senha_forte(senha) else "Senha fraca")


if __name__ == "__main__":
    main()
