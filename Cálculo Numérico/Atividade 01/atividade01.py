"""Atividade 01 - Introdução ao NumPy, Matplotlib e SymPy.

Gráficos de funções, derivadas, integrais e limites simbólicos, além de operações
básicas com matrizes.
"""

import matplotlib.pyplot as plt
import numpy as np
import sympy as sp


def exercicio_1():
    """f(x) = (x + 1)^(2/3) * (x - 3)^2: gráfico, derivadas e integrais."""
    # Gráfico com x variando de -4 a 4 com 50 pontos.
    # np.cbrt garante a raiz cúbica real também para x + 1 < 0.
    x = np.linspace(-4, 4, 50)
    y = np.cbrt((x + 1) ** 2) * (x - 3) ** 2
    plt.plot(x, y)
    plt.title("f(x) = (x + 1)^(2/3) (x - 3)^2")
    plt.grid(True)
    plt.show()

    xs = sp.symbols("x")
    f = sp.cbrt(xs + 1) ** 2 * (xs - 3) ** 2
    print("f'(x)   =", sp.diff(f, xs))
    print("f'''(x) =", sp.diff(f, xs, 3))
    print("Integral indefinida:", sp.integrate(f, xs))
    print("Integral de -1 a 2:", sp.integrate(f, (xs, -1, 2)))


def exercicio_2():
    """g(x) = (x^2 - 2x) / cos(x): valor numérico, limite e derivada."""
    def g(x):
        return (x ** 2 - 2 * x) / np.cos(x)

    print("g(sqrt(5)) =", g(np.sqrt(5)))

    xs = sp.symbols("x")
    expr = (xs ** 2 - 2 * xs) / sp.cos(xs)
    print("Limite de g(x) quando x -> 9:", sp.limit(expr, xs, 9))
    print("g'(x) =", sp.diff(expr, xs))


def exercicio_3():
    """Operações com matrizes: determinante, inversa, transposta, produto e subtração."""
    A = np.array([[1, 0, 1], [1, 2, 3], [1, 2, 4]])
    B = np.array([[3, 1, 4], [1, 2, 1], [3, 1, 1]])
    print("A =\n", A)
    print("B =\n", B)

    print("det(A) =", np.linalg.det(A))
    print("inv(B) =\n", np.linalg.inv(B))
    print("A^T =\n", A.T, "\nDimensão:", A.T.shape)
    print("A @ B =\n", A @ B)
    print("A - 4B =\n", A - 4 * B)


def exercicio_4():
    """Matriz 6x3 em que cada linha i contém o valor i + 1 (broadcasting)."""
    matriz = np.zeros((6, 3))
    coluna = np.arange(1, 7).reshape(6, 1)
    print("M =\n", matriz + coluna)


def exercicio_5():
    """Matriz binária aleatória 10x10: coluna com a maior soma."""
    M = np.random.randint(low=0, high=2, size=(10, 10))
    print("M =\n", M)

    soma_colunas = np.sum(M, axis=0)
    print("Soma dos valores das colunas:", soma_colunas)
    print("Maior soma das colunas:", np.max(soma_colunas), "- coluna:", np.argmax(soma_colunas))


if __name__ == "__main__":
    exercicio_1()
    exercicio_2()
    exercicio_3()
    exercicio_4()
    exercicio_5()
