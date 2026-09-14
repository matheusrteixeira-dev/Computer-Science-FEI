"""Prova - Módulo que sorteia uma palavra do arquivo palavras.txt (palavras separadas por vírgula)."""

from pathlib import Path
from random import choice

ARQUIVO = Path(__file__).resolve().parent / "palavras.txt"


def aleatoria():
    """Retorna uma palavra sorteada do arquivo."""
    with open(ARQUIVO, "r", encoding="utf-8-sig") as arquivo:
        palavras = arquivo.read().replace(",", " ").split()
    return choice(palavras)
