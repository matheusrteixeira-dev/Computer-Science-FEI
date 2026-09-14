# Análise e Complexidade de Algoritmos (Algorithm Analysis)

Implementations used to study asymptotic cost and to compare naive and dynamic-programming solutions. Several programs time themselves, so the measured results can be checked against the expected complexity.

| Folder | File | Description |
| --- | --- | --- |
| [bubbleSort](bubbleSort) | `bubbleSort.py` | Bubble sort. |
| [fibonacci](fibonacci) | `fib.py` | Execution-time comparison of four Fibonacci versions: naive recursion O(2ⁿ), memoized recursion, bottom-up DP with an array and iterative O(1) space. |
| [grafos](grafos) | `grafos.cpp` | Undirected graph as an adjacency list with breadth-first search (BFS). |
| [heapSort](heapSort) | `heapSort.cpp` | Heap sort on an array-based max-heap. |
| [mergeSort](mergeSort) | `mergeSort.cpp` | Merge sort with empirical timing on random inputs. |
| [radixSort](radixSort) | `radix.cpp`, `radix.py` | LSD radix sort with a stable counting sort. |
| [matrizes](matrizes) | `multiplicacaoMatrizes.py` | Matrix-chain multiplication: minimum parenthesization cost (memoized recursion and bottom-up DP). |
| [programacaoDinamica](programacaoDinamica) | `LinhaProducao.java` | Assembly-line scheduling with path reconstruction. |
| | `corteMadeiras.py` | Rod cutting: memoized recursion and bottom-up DP. |
| | `moedas.py` | Coin change by naive recursion, counting repeated subproblems. |
| | `Problema de subsequência comum/Lcs.py` | Longest common subsequence: naive recursion with a call counter. |

Files marked in their header as *based on instructor-provided code* started from a skeleton handed out in class.

## Running

```bash
python fibonacci/fib.py
g++ -std=c++17 -O2 grafos/grafos.cpp -o grafos && ./grafos
javac programacaoDinamica/LinhaProducao.java && java -cp programacaoDinamica LinhaProducao
```
