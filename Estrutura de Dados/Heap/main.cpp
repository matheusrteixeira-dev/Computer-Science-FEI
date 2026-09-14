/**
 * @file    main.cpp
 * @brief   Max-heap sobre std::vector: construção em O(n), inserção e remoção do maior elemento.
 * @note    Baseado em código-base fornecido pelo professor da disciplina.
 */

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Heap {
private:
  vector<int> v;
  int n; // quantidade de elementos válidos em v (v pode guardar elementos já removidos)

  int fe(int i) const {
    return 2 * i + 1;
  }
  int fd(int i) const {
    return 2 * i + 2;
  }
  int pai(int i) const {
    return (i - 1) / 2;
  }

  /// Índice do último nó que possui filhos, ou -1 se não houver.
  int ultPai() const {
    if (n <= 1)
      return -1;
    return pai(n - 1);
  }

  /// Desce o elemento da posição i até restaurar a propriedade de max-heap.
  void sift(int i) {
    if (i > ultPai()) {
      return;
    }

    int maiorFilho = fe(i);
    if (fd(i) < n && v[fd(i)] > v[maiorFilho]) {
      maiorFilho = fd(i);
    }

    if (v[maiorFilho] > v[i]) {
      swap(v[maiorFilho], v[i]);
      sift(maiorFilho);
    }
  }

public:
  explicit Heap(vector<int> valores) : v(std::move(valores)), n(static_cast<int>(v.size())) {
    for (int i = ultPai(); i >= 0; i--) {
      sift(i);
    }
  }

  /// Insere o valor no final e restaura o heap ao longo do caminho até a raiz.
  bool insert(int value) {
    if (n < static_cast<int>(v.size()))
      v[n] = value;
    else
      v.push_back(value);
    n++;

    for (int i = ultPai(); i > 0; i = pai(i))
      sift(i);
    sift(0);
    return true;
  }

  /// Remove e retorna o maior elemento; ok indica se o heap tinha algum elemento.
  int remove(bool* ok = nullptr) {
    if (n == 0) {
      if (ok)
        *ok = false;
      return 0;
    }

    swap(v[0], v[n - 1]);
    n--;
    sift(0);

    if (ok)
      *ok = true;
    return v[n];
  }

  void print() const {
    for (int i = 0; i < n; i++) {
      cout << v[i] << " ";
    }
    cout << endl;
  }
};

int main() {
  vector<int> v{1, 3, 2, 5, 6, 3, 2, 7, 5};
  Heap h(v);
  h.insert(9);
  h.insert(0);

  bool ok;
  int x = h.remove(&ok);
  while (ok) {
    cout << "saiu " << x << endl;
    h.print();
    x = h.remove(&ok);
  }

  return 0;
}
