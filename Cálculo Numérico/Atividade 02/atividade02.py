"""Atividade 02 - Resolução de sistemas lineares.

Compara a resolução pela matriz inversa, por ``numpy.linalg.solve`` e pela forma
simbólica do SymPy, e identifica um sistema indeterminado.
"""

import numpy as np
from sympy import Matrix, solve_linear_system
from sympy.abc import t, x, y, z


def exercicio_1():
    """Sistema 3x3 resolvido pela inversa e pelo SymPy."""
    A = np.array([[3, 5, 1], [2, 2, 2], [4, 7, 3]])
    b = np.array([[1], [3], [0]])
    print("Resolução com a inversa:\n", np.linalg.inv(A) @ b)

    sistema = Matrix(((3, 5, 1, 1), (2, 2, 2, 3), (4, 7, 3, 0)))
    print("Resolução com solve_linear_system:", solve_linear_system(sistema, x, y, z))


def exercicio_2():
    """Sistema 5x5 (matriz de Pascal) resolvido pela inversa e por solve."""
    A = np.array([[1, 1, 1, 1, 1],
                  [1, 2, 3, 4, 5],
                  [1, 3, 6, 10, 15],
                  [1, 4, 10, 20, 35],
                  [1, 5, 15, 35, 70]])
    b = np.array([[15], [35], [70], [126], [210]])

    print("Resolução com a inversa:\n", np.linalg.inv(A) @ b)
    print("Resolução com solve:\n", np.linalg.solve(A, b))


def exercicio_3():
    """Problema de câmbio: valor da libra esterlina."""
    A = np.array([[200, 100, 500], [250, 120, 400], [400, 80, 600]])
    b = np.array([[495.00], [532.50], [585.00]])

    solucao = np.linalg.inv(A) @ b
    print("Valor da libra esterlina:", solucao[1, 0])


def exercicio_4():
    """Sistema 4x4 indeterminado: solução paramétrica e verificação do posto."""
    sistema = Matrix(((2, 8, 4, 0, -1),
                      (4, -6, -2, -10, -14),
                      (6, -14, 2, -10, -16),
                      (0, 2, -2, -2, -2)))
    print("Resolução do sistema linear:", solve_linear_system(sistema, x, y, z, t))
    print("Como é possível observar, as variáveis não foram totalmente resolvidas,",
          "logo o sistema é indeterminado.\n")

    A = np.array([[2, 8, 4, 0],
                  [4, -6, -2, -10],
                  [6, -14, 2, -10],
                  [0, 2, -2, -2]])
    b = np.array([[-1], [-14], [-16], [-2]])

    print("Determinante:", np.linalg.det(A))
    print("Posto de A:", np.linalg.matrix_rank(A))
    print("Posto da matriz aumentada:", np.linalg.matrix_rank(np.hstack([A, b])))
    # Como det(A) = 0 (a menos de erro de ponto flutuante) e posto(A) = posto([A|b]) < 4,
    # o sistema possui infinitas soluções; inv(A) e solve(A, b) não produzem resultados válidos.


if __name__ == "__main__":
    exercicio_1()
    exercicio_2()
    exercicio_3()
    exercicio_4()
