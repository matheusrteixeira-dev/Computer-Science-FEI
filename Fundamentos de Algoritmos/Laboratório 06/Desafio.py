"""Laboratório 06 - Desafio: agenda de contatos em arquivos texto (criar, procurar, atualizar e apagar).

Cada contato é salvo em um arquivo chamado <nome>_<sobrenome>.txt.
"""

import os

MENU = """
0 - Sair
1 - Criar contato
2 - Procurar contato
3 - Atualizar contato
4 - Apagar contato
"""


def nome_do_arquivo():
    nome = input("Digite o nome: ").strip()
    sobrenome = input("Digite o sobrenome: ").strip()
    return f"{nome}_{sobrenome}.txt"


def grava_contato(arquivo):
    telefone = input("Digite o telefone: ").strip()
    email = input("Digite o email: ").strip()
    with open(arquivo, "w", encoding="utf-8") as f:
        f.write(f"Telefone: {telefone}\n")
        f.write(f"Email: {email}\n")


def criar():
    grava_contato(nome_do_arquivo())
    print("Contato criado.")


def procurar():
    arquivo = nome_do_arquivo()
    try:
        with open(arquivo, "r", encoding="utf-8") as f:
            print()
            print(f.read())
    except FileNotFoundError:
        print("Contato não encontrado.")


def atualizar():
    arquivo = nome_do_arquivo()
    if not os.path.exists(arquivo):
        print("Contato não encontrado.")
        return

    with open(arquivo, "r", encoding="utf-8") as f:
        print()
        print(f.read())

    grava_contato(arquivo)
    print("Contato atualizado.")


def apagar():
    arquivo = nome_do_arquivo()
    try:
        os.remove(arquivo)
        print("Contato apagado.")
    except FileNotFoundError:
        print("Contato não encontrado.")


def main():
    acoes = {1: criar, 2: procurar, 3: atualizar, 4: apagar}

    while True:
        print(MENU)
        try:
            opcao = int(input("Digite o que deseja fazer: "))
        except ValueError:
            opcao = -1

        if opcao == 0:
            break
        if opcao in acoes:
            acoes[opcao]()
        else:
            print("O comando digitado não é válido")


if __name__ == "__main__":
    main()
