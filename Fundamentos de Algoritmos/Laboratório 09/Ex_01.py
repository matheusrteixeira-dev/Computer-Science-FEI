"""Laboratório 09 - Relatório de uso de disco por usuário (enunciado em ../images/lab09_01.png).

O arquivo usuarios.txt contém, em cada linha, o nome do usuário e o espaço ocupado em bytes.
"""

from pathlib import Path

ARQUIVO = Path(__file__).resolve().parent / "usuarios.txt"
BYTES_POR_MB = 1024 * 1024


def le_usuarios(caminho):
    """Retorna uma lista de tuplas (usuario, espaco_em_bytes)."""
    usuarios = []
    with open(caminho, "r", encoding="utf-8") as arquivo:
        for linha in arquivo:
            partes = linha.split()
            if len(partes) >= 2:
                usuarios.append((partes[0], int(partes[1])))
    return usuarios


def imprime_relatorio(usuarios):
    total_mb = sum(espaco for _, espaco in usuarios) / BYTES_POR_MB
    media_mb = total_mb / len(usuarios)

    print("XFiles            Uso do espaço em disco pelos usuários")
    print("-" * 60)
    print(f"{'Nr.':<5}{'Usuário':<15}{'Espaço utilizado':>20}{'% do uso':>15}")
    for numero, (usuario, espaco) in enumerate(usuarios, start=1):
        mb = espaco / BYTES_POR_MB
        porcentagem = mb * 100 / total_mb
        print(f"{numero:<5}{usuario:<15}{mb:>17.2f} MB{porcentagem:>14.2f}%")
    print()
    print(f"Espaço total ocupado: {total_mb:.2f} MB")
    print(f"Espaço médio ocupado: {media_mb:.2f} MB")


def main():
    imprime_relatorio(le_usuarios(ARQUIVO))


if __name__ == "__main__":
    main()
