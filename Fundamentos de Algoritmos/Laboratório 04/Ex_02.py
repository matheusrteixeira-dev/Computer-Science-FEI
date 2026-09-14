"""Laboratório 04 - Exercício 02: nome do polígono a partir do número de lados (3 a 10)."""

POLIGONOS = {
    3: "triângulo", 4: "quadrilátero", 5: "pentágono", 6: "hexágono",
    7: "heptágono", 8: "octógono", 9: "eneágono", 10: "decágono",
}

if __name__ == "__main__":
    lados = int(input("Digite o número de lados da figura geométrica: "))

    if lados in POLIGONOS:
        print("A figura é um", POLIGONOS[lados])
    else:
        print("O número de lados digitado está fora do intervalo")
