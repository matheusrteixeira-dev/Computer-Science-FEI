"""Laboratório 07 - Exercício 05: média de cada aluno e de cada turma a partir de uma lista 3D
(turmas -> alunos -> quatro notas)."""

NOTAS_EXEMPLO = [10, 8, 10, 8]
NOMES_TURMAS = ["A", "B", "C"]
ALUNOS_POR_TURMA = 8


def media(valores):
    return sum(valores) / len(valores)


def media_alunos(turmas):
    for nome, alunos in zip(NOMES_TURMAS, turmas):
        print(f"Média de cada aluno da turma {nome}:")
        for numero, notas in enumerate(alunos, start=1):
            print(f"  Aluno {numero}: {media(notas)}")
        print()


def media_turmas(turmas):
    for nome, alunos in zip(NOMES_TURMAS, turmas):
        todas_as_notas = [nota for notas in alunos for nota in notas]
        print(f"Média da turma {nome}: {media(todas_as_notas)}")


def main():
    turmas = [[list(NOTAS_EXEMPLO) for _ in range(ALUNOS_POR_TURMA)] for _ in NOMES_TURMAS]

    for nome, alunos in zip(NOMES_TURMAS, turmas):
        print(f"Alunos da turma {nome}:", alunos)
        print()

    media_alunos(turmas)
    media_turmas(turmas)


if __name__ == "__main__":
    main()
