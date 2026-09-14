/**
 * @file    main.cpp
 * @brief   Lista duplamente encadeada ordenada, com construtor de cópia e operador de atribuição.
 * @note    Baseado em código-base fornecido pelo professor da disciplina (TAD, Node com
 *          rastreamento de alocações e main); o exercício consistia em implementar a classe
 *          DoubleLinkedList.
 */
#include <cstdlib>
#include <iostream>
#include <new>
#include <set>
#include <string>

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

class DoubleLinkedList;

/// Nó que registra cada alocação para detectar vazamentos e desalocações inválidas.
class Node {
private:
  int value;
  Node* next;
  Node* previous;
  friend class DoubleLinkedList;

public:
  static std::set<void*> allocs;

  void* operator new(size_t n) {
    void* x = malloc(n);
    if (!x)
      throw std::bad_alloc();
    allocs.insert(x);
    return x;
  }

  void operator delete(void* p) {
    if (allocs.erase(p) == 0) {
      cout << "ERRO DE DESALOCACAO" << endl;
    }
    free(p);
  }
};
std::set<void*> Node::allocs;

class DoubleLinkedList : public AbstractOrderedList {
private:
  Node* first;
  Node* last;
  unsigned int n;

  /// Copia os nós de other para esta lista (que deve estar vazia).
  void copy(const DoubleLinkedList& other) {
    first = nullptr;
    last = nullptr;
    for (Node* ptrOther = other.first; ptrOther; ptrOther = ptrOther->next) {
      Node* novo = new Node;
      novo->value = ptrOther->value;
      novo->next = nullptr;
      novo->previous = last;

      if (last)
        last->next = novo;
      else
        first = novo;
      last = novo;
    }
    n = other.n;
  }

public:
  using AbstractOrderedList::print;

  DoubleLinkedList() : first(nullptr), last(nullptr), n(0) {}

  DoubleLinkedList(const DoubleLinkedList& other) : first(nullptr), last(nullptr), n(0) {
    cout << "chamei o construtor por copia" << endl;
    copy(other);
  }

  DoubleLinkedList& operator=(const DoubleLinkedList& other) {
    if (this != &other) {
      clear();
      copy(other);
    }
    return *this;
  }

  /// Insere mantendo a ordem crescente, ligando os ponteiros nos dois sentidos.
  bool insert(int value) override {
    Node* novo = new Node;
    novo->value = value;

    // Encontra a posição de inserção.
    Node* ptrAnt = nullptr;
    Node* ptrAtual = first;
    while (ptrAtual != nullptr && ptrAtual->value < value) {
      ptrAnt = ptrAtual;
      ptrAtual = ptrAtual->next;
    }

    // Ligação para frente.
    if (ptrAnt)
      ptrAnt->next = novo;
    else
      first = novo;
    novo->next = ptrAtual;

    // Ligação para trás.
    if (ptrAtual)
      ptrAtual->previous = novo;
    else
      last = novo;
    novo->previous = ptrAnt;

    n++;
    return true;
  }

  bool remove(int value) override {
    Node* it = first;
    while (it != nullptr && it->value != value) {
      it = it->next;
    }

    if (it == nullptr)
      return false;

    if (it->previous)
      it->previous->next = it->next;
    else
      first = it->next;

    if (it->next)
      it->next->previous = it->previous;
    else
      last = it->previous;

    delete it;
    n--;
    return true;
  }

  bool search(int value) override {
    for (Node* it = first; it != nullptr; it = it->next) {
      if (it->value == value)
        return true;
    }
    return false;
  }

  int getAtIndex(int index) override {
    Node* tmp = first;
    for (int i = 0; tmp != nullptr && i < index; i++) {
      tmp = tmp->next;
    }
    return (tmp != nullptr) ? tmp->value : -1;
  }

  virtual void print() const {
    for (Node* tmp = first; tmp; tmp = tmp->next) {
      cout << tmp->value << " ";
    }
    cout << endl;
  }

  unsigned int getSize() override {
    return n;
  }

  void clear() {
    Node* tmp = first;
    while (tmp) {
      Node* tmpNext = tmp->next;
      delete tmp;
      tmp = tmpNext;
    }
    first = nullptr;
    last = nullptr;
    n = 0;
  }

  ~DoubleLinkedList() {
    cout << "destrutor invocado" << endl;
    clear();
  }
};

void ImprimeDoMeuJeito(const DoubleLinkedList x) {
  cout << "Vou imprimir" << endl;
  x.print();
}

int main() {
  // Main fornecido pelo enunciado.
  {
    DoubleLinkedList l;
    cout << (l.remove(0) ? "removi 0" : "nao removi") << endl;
    l.print();
    cout << (l.insert(5) ? "inseri 5" : "nao inseri") << endl;
    l.print();
    cout << (l.insert(85) ? "inseri 85" : "nao inseri") << endl;
    l.print();
    cout << (l.insert(69) ? "inseri 69" : "nao inseri") << endl;
    l.print();
    cout << (l.remove(5) ? "removi 5" : "nao removi") << endl;
    l.print();
    cout << (l.insert(84) ? "inseri 84" : "nao inseri") << endl;
    l.print();
    cout << (l.insert(83) ? "inseri 83" : "nao inseri") << endl;
    l.print();
    cout << (l.remove(84) ? "removi 84" : "nao removi") << endl;
    l.print();
    cout << (l.remove(83) ? "removi 83" : "nao removi") << endl;
    l.print();
    cout << (l.insert(38) ? "inseri 38" : "nao inseri") << endl;
    l.print();
    cout << l.search(85) << endl;
    cout << l.search(86) << endl;
    cout << (l.insert(856) ? "inseri 856" : "nao inseri") << endl;
    l.print();
    cout << (l.insert(846) ? "inseri 846" : "nao inseri") << endl;
    l.print();
    cout << (l.remove(856) ? "removi 856" : "nao removi") << endl;
    l.print();
    cout << (l.insert(390) ? "inseri 390" : "nao inseri") << endl;
    l.print();
    cout << (l.remove(390) ? "removi 390" : "nao removi") << endl;
    l.print();
    cout << l.search(9000) << endl;
    cout << l.search(-1) << endl;

    {
      // Construtor por cópia
      DoubleLinkedList q = l;

      // Remove todos os elementos duas vezes: a segunda rodada não deve encontrar nenhum.
      const int valores[] = {5, 38, 69, 83, 84, 85, 390, 846, 856};
      for (int rodada = 0; rodada < 2; rodada++) {
        for (int valor : valores) {
          cout << (l.remove(valor) ? "removi " + std::to_string(valor) : "nao removi") << endl;
          l.print();
        }
      }

      // Atribuição por cópia
      q = l;
      q.insert(800);
      cout << "Vou imprimir" << endl;
      ImprimeDoMeuJeito(q);
    }

    cout << "Vou imprimir" << endl;
    ImprimeDoMeuJeito(l);
  }

  if (Node::allocs.size() != 0) {
    cout << "SOBRARAM PONTEIROS NAO DESALOCADOS" << endl;
  }

  return 0;
}
