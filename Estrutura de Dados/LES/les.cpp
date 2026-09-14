/**
 * @file    les.cpp
 * @brief   Lista Estática Sequencial (LES) ordenada, com busca binária.
 * @note    Baseado em código-base fornecido pelo professor da disciplina (TAD e main).
 */

#include <iostream>
using std::cout;
using std::endl;

// Tipo abstrato de dados
class AbstractOrderedList {
public:
  AbstractOrderedList() {}

  virtual bool insert(int value) = 0;
  virtual bool remove(int value) = 0;
  virtual bool search(int value) = 0;
  virtual int getAtIndex(int index) = 0;
  virtual unsigned int getSize() = 0;

  virtual void print() {
    for (unsigned int i = 0; i < getSize(); ++i) {
      cout << getAtIndex(i) << " ";
    }
    cout << endl;
  }

  virtual ~AbstractOrderedList() {}
};

#define MAX 200

class LES : public AbstractOrderedList {
private:
  unsigned int n;
  int v[MAX];

public:
  LES() : n(0) {}

  /// Insere mantendo a ordem crescente. Retorna false se a lista estiver cheia.
  bool insert(int value) override {
    if (n == MAX)
      return false;

    unsigned int i;
    for (i = 0; i < n && v[i] <= value; ++i)
      ;

    for (unsigned int j = n; j > i; j--) {
      v[j] = v[j - 1];
    }

    v[i] = value;
    n++;
    return true;
  }

  /// Remove a primeira ocorrência de value, deslocando os elementos seguintes.
  bool remove(int value) override {
    for (unsigned int i = 0; i < n; ++i) {
      if (v[i] == value) {
        for (unsigned int j = i; j + 1 < n; j++)
          v[j] = v[j + 1];
        n--;
        return true;
      }
    }
    return false;
  }

  /// Busca binária: O(log n).
  bool search(int value) override {
    int begin = 0;
    int end = static_cast<int>(n) - 1;

    while (begin <= end) {
      int half = begin + (end - begin) / 2;

      if (value < v[half])
        end = half - 1;
      else if (value > v[half])
        begin = half + 1;
      else
        return true;
    }
    return false;
  }

  int getAtIndex(int index) override {
    if (index >= 0 && static_cast<unsigned int>(index) < n)
      return v[index];
    return 0;
  }

  unsigned int getSize() override {
    return n;
  }

  virtual ~LES() {}
};

int main() {
  AbstractOrderedList* l = new LES();

  cout << (l->remove(0) ? "removi 0" : "nao removi") << endl;
  l->insert(5);
  l->insert(85);
  l->insert(69);
  l->remove(5);
  l->insert(84);
  l->insert(83);
  cout << (l->remove(84) ? "removi 84" : "nao removi") << endl;
  l->print();
  cout << (l->remove(83) ? "removi 83" : "nao removi") << endl;
  l->print();
  l->insert(38);
  cout << l->search(85) << endl;
  cout << l->search(86) << endl;
  l->insert(856);
  l->insert(846);
  l->print();
  cout << (l->remove(856) ? "removi 856" : "nao removi") << endl;
  l->print();
  l->insert(390);
  l->print();
  cout << (l->remove(390) ? "removi 390" : "nao removi") << endl;
  l->print();
  cout << l->search(9000) << endl;

  delete l;

  return 0;
}
