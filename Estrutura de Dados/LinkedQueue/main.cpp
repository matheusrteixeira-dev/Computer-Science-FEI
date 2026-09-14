/**
 * @file    main.cpp
 * @brief   Fila encadeada genérica (FIFO), com construtor de cópia e operador de atribuição.
 * @note    Baseado em código-base fornecido pelo professor da disciplina (TAD, nó com
 *          rastreamento de alocações e main); o exercício consistia em implementar a classe
 *          LinkedQueue.
 */
#include <cstdlib>
#include <iostream>
#include <new>
#include <set>

using std::cout;
using std::endl;

template <typename T>
class AbstractQueue {
public:
  virtual bool enqueue(T value) = 0;
  virtual bool dequeue(T* outElement = nullptr) = 0;
  virtual void clear() = 0;
  virtual ~AbstractQueue() {}
};

template <typename T>
class LinkedQueue;

/// Nó que registra cada alocação para detectar vazamentos e desalocações inválidas.
template <typename T>
class QueueNode {
private:
  T value;
  QueueNode* next;
  friend class LinkedQueue<T>;

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

template <typename T>
std::set<void*> QueueNode<T>::allocs;

template <typename T>
class LinkedQueue : public AbstractQueue<T> {
private:
  QueueNode<T>* first;
  QueueNode<T>* last;
  unsigned int n;

  /// Copia os elementos de other, na mesma ordem, para esta fila (que deve estar vazia).
  void copy(const LinkedQueue& other) {
    for (QueueNode<T>* tmp = other.first; tmp != nullptr; tmp = tmp->next) {
      enqueue(tmp->value);
    }
  }

public:
  LinkedQueue() : first(nullptr), last(nullptr), n(0) {}

  LinkedQueue(const LinkedQueue& other) : first(nullptr), last(nullptr), n(0) {
    copy(other);
  }

  LinkedQueue& operator=(const LinkedQueue& other) {
    if (this != &other) {
      clear();
      copy(other);
    }
    return *this;
  }

  /// Insere no final da fila.
  bool enqueue(T value) override {
    QueueNode<T>* newNode = new QueueNode<T>();
    newNode->value = value;
    newNode->next = nullptr;

    if (last)
      last->next = newNode;
    else
      first = newNode;
    last = newNode;

    n++;
    return true;
  }

  /// Remove do início da fila; o valor removido é gravado em outElement, se informado.
  bool dequeue(T* outElement = nullptr) override {
    if (!first)
      return false;

    if (outElement)
      *outElement = first->value;

    QueueNode<T>* tmp = first;
    first = first->next;
    if (!first)
      last = nullptr;

    delete tmp;
    n--;
    return true;
  }

  virtual void print() const {
    for (QueueNode<T>* tmp = first; tmp; tmp = tmp->next) {
      cout << tmp->value << " ";
    }
    cout << endl;
  }

  unsigned int getSize() const {
    return n;
  }

  void clear() override {
    while (dequeue())
      ;
  }

  ~LinkedQueue() {
    cout << "destrutor invocado" << endl;
    clear();
  }
};

int main() {
  // Main fornecido pelo enunciado.
  {
    LinkedQueue<int> l;
    int temp;
    cout << "==========TESTE 1==========" << endl;

    l.enqueue(5);
    l.enqueue(6);

    cout << "Tamanho: " << l.getSize() << endl;

    {
      cout << "==========TESTE 2==========" << endl;
      cout << "Construtor por copia sera invocado" << endl;
      LinkedQueue<int> l2 = l;
      l2.enqueue(10);
      l2.enqueue(11);
      l2.enqueue(15);
      int removido;
      while (l2.dequeue(&removido)) {
        cout << "Removido de l2 " << removido << endl;
      }
      l2.enqueue(13);
      l2.enqueue(19);
      cout << "imprimindo l2:" << endl;
      l2.print();
      l2.clear();
      cout << "imprimindo l2:" << endl;
      l2.print();
    }
    cout << "==========TESTE 2 acabou===" << endl;
    {
      cout << "==========TESTE 3==========" << endl;
      LinkedQueue<int> l3;
      cout << "Atribuicao por copia sera invocado" << endl;
      l3 = l;
      l3.enqueue(50);
      l3.enqueue(51);
      l3.enqueue(55);
      int removido;
      while (l3.dequeue(&removido)) {
        cout << "Removido de l3 " << removido << endl;
      }
      l3.enqueue(53);
      l3.enqueue(59);
      cout << "imprimindo l3:" << endl;
      l3.print();
      l3.clear();
      cout << "imprimindo l3:" << endl;
      l3.print();
      cout << "==========TESTE 3 acabou===" << endl;
    }

    cout << "imprimindo l:" << endl;
    l.print();

    l.enqueue(4);
    l.dequeue(&temp);
    cout << temp << endl;
    l.enqueue(8);

    l.print();
  }

  if (QueueNode<int>::allocs.size())
    cout << "Existem nos alocados" << endl;
  cout << "==========TESTE 1 acabou===" << endl;

  return 0;
}
