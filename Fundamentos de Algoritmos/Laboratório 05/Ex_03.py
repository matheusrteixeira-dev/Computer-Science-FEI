"""Laboratório 05 - Exercício 03: carro mais econômico e custo para percorrer 1000 km.

O consumo de cada carro é dado em quilômetros por litro (km/l).
"""

DISTANCIA_KM = 1000
PRECO_LITRO = 4.09

if __name__ == "__main__":
    carros = ["Corolla", "Civic", "Vectra", "Duster", "Punto"]
    consumo_km_por_litro = [10, 20, 30, 40, 50]

    indice_mais_economico = consumo_km_por_litro.index(max(consumo_km_por_litro))
    print("Carro mais econômico:", carros[indice_mais_economico])
    print()
    print(f"Consumo de cada carro para percorrer {DISTANCIA_KM} km:")
    print()

    for carro, km_por_litro in zip(carros, consumo_km_por_litro):
        litros = DISTANCIA_KM / km_por_litro
        print(f"{carro:<8} {litros:6.1f} litros   R$ {litros * PRECO_LITRO:8.2f}")
