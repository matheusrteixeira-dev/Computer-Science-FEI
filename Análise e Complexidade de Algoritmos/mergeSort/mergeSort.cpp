/**
 * @file    mergeSort.cpp
 * @brief   Merge Sort com medição empírica do tempo de execução.
 * @note    Baseado em código-base fornecido pelo professor da disciplina.
 */

#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

/// Intercala as metades ordenadas v[l..p] e v[p+1..r]. Complexidade: Θ(n).
void merge(vector<int> &v, int l, int p, int r) {
  vector<int> s;
  s.reserve(r - l + 1);
  int e = l, d = p + 1;
  while (e <= p && d <= r) {
    if (v[e] <= v[d]) {
      s.push_back(v[e++]);
    } else {
      s.push_back(v[d++]);
    }
  }

  while (e <= p) {
    s.push_back(v[e++]);
  }

  while (d <= r) {
    s.push_back(v[d++]);
  }

  copy(s.begin(), s.end(), v.begin() + l);
}

/// Ordena v[l..r] recursivamente. Complexidade: Θ(n log n).
void mergeSort(vector<int> &v, int l, int r) {
  if (l < r) {
    int p = l + (r - l) / 2;
    mergeSort(v, l, p);
    mergeSort(v, p + 1, r);
    merge(v, l, p, r);
  }
}

int main() {
  random_device dev;
  mt19937 rng(dev());
  uniform_int_distribution<int> dist100(1, 100);

  // Imprime "tamanho<TAB>tempo em nanossegundos" para cada tamanho de entrada.
  for (int i = 100; i < 100000; i += 1000) {
    vector<int> l;
    l.reserve(i);
    for (int j = 0; j < i; j++) {
      l.push_back(dist100(rng));
    }

    auto tInicio = chrono::steady_clock::now();
    mergeSort(l, 0, static_cast<int>(l.size()) - 1);
    auto tFim = chrono::steady_clock::now();

    cout << i << "\t"
         << chrono::duration_cast<chrono::nanoseconds>(tFim - tInicio).count()
         << endl;
  }

  return 0;
}
