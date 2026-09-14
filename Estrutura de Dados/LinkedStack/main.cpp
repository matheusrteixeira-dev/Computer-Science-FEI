/**
 * @file    main.cpp
 * @brief   Pilha encadeada genérica e verificação de balanceamento de parênteses, colchetes e chaves.
 * @note    Baseado em código-base fornecido pelo professor da disciplina (TAD, testaPilha e main);
 *          o exercício consistia em adaptar a pilha para manter o tamanho e implementar checaExpressao.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
class AbstractStack {
public:
  AbstractStack() {}
  virtual bool push(T x) = 0;
  virtual T pop(bool* ok) = 0;
  virtual void clear() = 0;
  virtual int size() = 0;
  virtual ~AbstractStack() {}
};

template <typename T>
class LinkedStack;

template <typename T>
class StackNode {
private:
  T value;
  StackNode* next;

public:
  T getValue() {
    return value;
  }

  friend class LinkedStack<T>;
};

template <typename T>
class LinkedStack : public AbstractStack<T> {
private:
  StackNode<T>* top;
  int n;

  /// Copia os elementos de other preservando a ordem (esta pilha deve estar vazia).
  void clone(const LinkedStack& other) {
    top = nullptr;
    StackNode<T>* lastInserted = nullptr;

    for (StackNode<T>* pOther = other.top; pOther != nullptr; pOther = pOther->next) {
      StackNode<T>* pThis = new StackNode<T>;
      pThis->value = pOther->value;
      pThis->next = nullptr;

      if (lastInserted)
        lastInserted->next = pThis;
      else
        top = pThis;
      lastInserted = pThis;
    }
    n = other.n;
  }

public:
  LinkedStack() : top(nullptr), n(0) {}

  LinkedStack(const LinkedStack& other) : top(nullptr), n(0) {
    clone(other);
  }

  LinkedStack& operator=(const LinkedStack& other) {
    if (this != &other) {
      clear();
      clone(other);
    }
    return *this;
  }

  int size() override {
    return n;
  }

  bool push(T x) override {
    StackNode<T>* newNode = new StackNode<T>;
    newNode->value = x;
    newNode->next = top;
    top = newNode;
    n++;
    return true;
  }

  /// Remove e retorna o topo; ok indica se a pilha tinha algum elemento.
  T pop(bool* ok = nullptr) override {
    if (!top) {
      if (ok)
        *ok = false;
      return T{};
    }

    StackNode<T>* temp = top->next;
    T r = top->value;
    delete top;
    top = temp;
    n--;

    if (ok)
      *ok = true;
    return r;
  }

  void clear() override {
    while (top != nullptr) {
      StackNode<T>* temp = top->next;
      delete top;
      top = temp;
    }
    n = 0;
  }

  ~LinkedStack() {
    clear();
  }
};

void testaPilha() {
  LinkedStack<int> s;
  s.push(9);
  s.push(6);
  s.push(5);
  s.push(8);
  LinkedStack<int> s2;
  s2 = s;

  bool ok;
  int r = s.pop(&ok);
  while (ok) {
    cout << r << endl;
    r = s.pop(&ok);
  }

  r = s2.pop(&ok);
  while (ok) {
    cout << r << endl;
    r = s2.pop(&ok);
  }
}

/// Verifica se todo '(', '[' e '{' é fechado pelo símbolo correspondente, na ordem correta.
bool checaExpressao(const string& s) {
  LinkedStack<char> pilha;

  for (char c : s) {
    if (c == '{' || c == '[' || c == '(') {
      pilha.push(c);
    } else if (c == '}' || c == ']' || c == ')') {
      bool ok;
      char abertura = pilha.pop(&ok);
      if (!ok || (c == '}' && abertura != '{') || (c == ']' && abertura != '[') ||
          (c == ')' && abertura != '(')) {
        return false;
      }
    }
  }

  return pilha.size() == 0;
}

int main() {
  vector<string> v = {
      "{ 2 + 3 + [ 2 - 3 ] * ( 1 + 2 + [ 3 / 1 ] ) }", // OK
      "{ 2 + 3 + ( 2 - 3 ] * ( 1 + 2 + [ 3 / 1 ] ) }", // Falha
      "{ 23 + [ 5 ] * ( 1 + 2 + [ 3 / 1 ) ] }",        // Falha
      "{ 2 + [ 2 - 3 ] * ( 1 + 2 + [ 3 / 1 ] ) }",     // OK
      "2 + 3",                                         // OK
      "2 + 3 )",                                       // Falha
      "2 + 3 }",                                       // Falha
      "{ 2 ",                                          // Falha
  };

  testaPilha();
  cout << "Fim do teste da pilha" << endl;

  for (const auto& e : v) {
    cout << (checaExpressao(e) ? "Expressao Ok" : "Expressao Falhou") << endl;
  }

  return 0;
}
