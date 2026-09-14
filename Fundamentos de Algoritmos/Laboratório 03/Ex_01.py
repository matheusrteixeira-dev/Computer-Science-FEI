"""Laboratório 03 - Exercício 01: investigação de um crime a partir de cinco perguntas.

Respostas positivas: 2 -> Suspeita; 3 ou 4 -> Cúmplice; 5 -> Culpada; demais -> Inocente.
"""

PERGUNTAS = [
    "Telefonou para a vítima?",
    "Esteve no local do crime?",
    "Mora perto da vítima?",
    "Devia para a vítima?",
    "Já trabalhou com a vítima?",
]


def pergunta_sim_nao(pergunta):
    """Repete a pergunta até receber 'Sim' ou 'Não'; retorna True para 'Sim'."""
    while True:
        resposta = input(f"{pergunta} (Sim/Não): ").strip().capitalize()
        if resposta in ("Sim", "Não"):
            return resposta == "Sim"
        print("Digite 'Sim' ou 'Não'")


def classifica(positivas):
    if positivas == 2:
        return "Suspeita"
    if 3 <= positivas <= 4:
        return "Cúmplice"
    if positivas == 5:
        return "Culpada"
    return "Inocente"


if __name__ == "__main__":
    total = sum(pergunta_sim_nao(p) for p in PERGUNTAS)
    print(classifica(total))
