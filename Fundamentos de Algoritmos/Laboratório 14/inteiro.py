"""Laboratório 14 - Módulo que verifica se uma string representa um número inteiro."""


def is_integer(palavra):
    """Retorna True se a string for um inteiro, com sinal opcional (+ ou -)."""
    palavra = palavra.strip()
    if palavra[:1] in ("+", "-"):
        palavra = palavra[1:]
    return palavra.isdigit()
