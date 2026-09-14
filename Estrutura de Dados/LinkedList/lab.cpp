/**
 * @file    lab.cpp
 * @brief   Lista simplesmente encadeada ordenada de inteiros.
 * @note    Baseado em código-base fornecido pelo professor da disciplina (TAD, insert e main);
 *          o exercício consistia em implementar remove e search.
 */
#include <iostream>
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

class LinkedList;
class Node {
private:
  int value;
  Node* next;
  friend class LinkedList;
};

class LinkedList : public AbstractOrderedList {
private:
  Node* first;
  unsigned int n;

public:
  LinkedList() : first(nullptr), n(0) {}

  LinkedList(const LinkedList&) = delete;
  LinkedList& operator=(const LinkedList&) = delete;

  bool insert(int value) override {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    Node* ptrAnt = nullptr;
    Node* ptrAtual = first;
    while (ptrAtual != nullptr && ptrAtual->value < value) {
      ptrAnt = ptrAtual;
      ptrAtual = ptrAtual->next;
    }

    if (ptrAnt != nullptr)
      ptrAnt->next = newNode;
    else
      first = newNode;

    newNode->next = ptrAtual;

    n++;
    return true;
  }

  /// Remove a primeira ocorrência de value, religando o nó anterior ao seguinte.
  bool remove(int value) override {
    Node* anterior = nullptr;
    Node* atual = first;

    while (atual != nullptr && atual->value != value) {
      anterior = atual;
      atual = atual->next;
    }

    if (atual == nullptr)
      return false;

    if (anterior == nullptr)
      first = atual->next; // removendo o primeiro nó
    else
      anterior->next = atual->next;

    delete atual;
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

  void print() override {
    for (Node* tmp = first; tmp != nullptr; tmp = tmp->next) {
      cout << tmp->value << " ";
    }
    cout << endl;
  }

  unsigned int getSize() override {
    return n;
  }

  ~LinkedList() {
    Node* tmp = first;
    while (tmp) {
      Node* tmpNext = tmp->next;
      delete tmp;
      tmp = tmpNext;
    }
  }
};

int main() {
  // Main fornecido pelo enunciado.
  AbstractOrderedList* l = new LinkedList();

  cout << (l->remove(0) ? "removi 0" : "nao removi") << endl;
  l->print();
  cout << (l->insert(5) ? "inseri 5" : "nao inseri") << endl;
  l->print();
  cout << (l->insert(85) ? "inseri 85" : "nao inseri") << endl;
  l->print();
  cout << (l->insert(69) ? "inseri 69" : "nao inseri") << endl;
  l->print();
  cout << (l->remove(5) ? "removi 5" : "nao removi") << endl;
  l->print();
  cout << (l->insert(84) ? "inseri 84" : "nao inseri") << endl;
  l->print();
  cout << (l->insert(83) ? "inseri 83" : "nao inseri") << endl;
  l->print();
  cout << (l->remove(84) ? "removi 84" : "nao removi") << endl;
  l->print();
  cout << (l->remove(83) ? "removi 83" : "nao removi") << endl;
  l->print();
  cout << (l->insert(38) ? "inseri 38" : "nao inseri") << endl;
  l->print();
  cout << l->search(85) << endl;
  cout << l->search(86) << endl;
  cout << (l->insert(856) ? "inseri 856" : "nao inseri") << endl;
  l->print();
  cout << (l->insert(846) ? "inseri 846" : "nao inseri") << endl;
  l->print();
  cout << (l->remove(856) ? "removi 856" : "nao removi") << endl;
  l->print();
  cout << (l->insert(390) ? "inseri 390" : "nao inseri") << endl;
  l->print();
  cout << (l->remove(390) ? "removi 390" : "nao removi") << endl;
  l->print();
  cout << l->search(9000) << endl;
  cout << l->search(-1) << endl;

  // Remove todos os elementos duas vezes: a segunda rodada não deve encontrar nenhum.
  const int valores[] = {5, 38, 69, 83, 84, 85, 390, 846, 856};
  for (int rodada = 0; rodada < 2; rodada++) {
    for (int valor : valores) {
      cout << (l->remove(valor) ? "removi " + std::to_string(valor) : "nao removi") << endl;
      l->print();
    }
  }

  delete l;

  return 0;
}
