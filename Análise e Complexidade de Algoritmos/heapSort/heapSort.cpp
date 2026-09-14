/**
 * @file    heapSort.cpp
 * @brief   Heap Sort utilizando um max-heap armazenado em vetor.
 * @note    Baseado em código-base fornecido pelo professor da disciplina.
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int pai(int idx) { return (idx - 1) / 2; }
int filhoEsquerdo(int idx) { return 2 * idx + 1; }
int filhoDireito(int idx) { return 2 * idx + 2; }

/// Desce o elemento em @p idx até restaurar a propriedade de max-heap em v[0, n).
void sift(vector<int> &v, int idx, int n) {
  int maior = idx;
  if (filhoEsquerdo(idx) < n && v[filhoEsquerdo(idx)] > v[maior]) {
    maior = filhoEsquerdo(idx);
  }
  if (filhoDireito(idx) < n && v[filhoDireito(idx)] > v[maior]) {
    maior = filhoDireito(idx);
  }

  if (maior != idx) {
    // Houve violação da propriedade de heap.
    swap(v[idx], v[maior]);
    sift(v, maior, n);
  }
}

/// Transforma o vetor em um max-heap em O(n).
void makeHeap(vector<int> &v) {
  int n = static_cast<int>(v.size());
  for (int i = pai(n - 1); i >= 0; i--) {
    sift(v, i, n);
  }
}

/// Ordena o vetor em ordem crescente em O(n log n).
void heapSort(vector<int> &v) {
  makeHeap(v);

  int n = static_cast<int>(v.size());
  while (n > 1) {
    swap(v[0], v[n - 1]);
    n--;
    sift(v, 0, n);
  }
}

int main() {
  vector<int> v = {8, 7, 7, 5, 7, 9, 10};

  heapSort(v);

  for (const auto &e : v) {
    cout << e << endl;
  }

  return 0;
}
