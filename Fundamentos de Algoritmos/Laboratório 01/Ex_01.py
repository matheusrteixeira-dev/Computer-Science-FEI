"""Laboratório 01 - Primeiros programas em Python: entrada, saída e expressões aritméticas."""

PI = 3.14159


def primeiro_programa():
    print("Primeiro Programa em Python")


def ecoa_nome():
    nome = input("Insira seu nome: ")
    print(nome)


def soma_dois_valores():
    n1 = float(input("Insira o primeiro valor: "))
    n2 = float(input("Insira o segundo valor: "))
    print(n1 + n2)


def area_do_circulo():
    raio = float(input("Insira o valor do raio: "))
    print(PI * raio ** 2)


def fahrenheit_para_celsius():
    fahrenheit = float(input("Insira o valor da temperatura em Fahrenheit: "))
    celsius = 5 * (fahrenheit - 32) / 9
    print(f"A temperatura é {celsius:.2f} °C")


def media_ponderada():
    """Média com pesos 1 (laboratório), 2 (P1) e 3 (P2)."""
    lab = float(input("Insira a nota de laboratório: "))
    p1 = float(input("Insira a nota da P1: "))
    p2 = float(input("Insira a nota da P2: "))
    print((lab + 2 * p1 + 3 * p2) / 6)


if __name__ == "__main__":
    primeiro_programa()
    ecoa_nome()
    soma_dois_valores()
    area_do_circulo()
    fahrenheit_para_celsius()
    media_ponderada()
