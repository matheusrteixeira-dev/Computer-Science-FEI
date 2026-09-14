/**
 * @file    lde.hpp
 * @brief   Lista simplesmente encadeada ordenada e genérica, com comparador configurável.
 * @note    Código-base fornecido pelo professor da disciplina e usado pela tabela hash em main.cpp.
 */
#pragma once

#include <functional>
#include <iostream>

using std::cout;
using std::endl;
using std::less;

// Tipo abstrato de dados
template <typename T>
class AbstractOrderedList {
public:
  AbstractOrderedList() {}

  virtual bool insert(T value) = 0;
  virtual bool remove(T value) = 0;
  virtual T search(T value, bool* ok) = 0;
  virtual T getAtIndex(int index) = 0;
  virtual unsigned int getSize() = 0;

  virtual ~AbstractOrderedList() {}
};

template <typename T, typename LessFunc>
class LinkedList;

template <typename T, typename LessFunc>
class Node {
private:
  T value;
  Node<T, LessFunc>* next;

  friend class LinkedList<T, LessFunc>;
};

template <typename T, typename LessFunc = less<T>>
class LinkedList : public AbstractOrderedList<T> {
private:
  Node<T, LessFunc>* first;
  unsigned int n;
  LessFunc Less;

  /// Dois valores são diferentes se um for estritamente menor que o outro.
  bool DiffFunc(T a, T b) {
    return Less(a, b) || Less(b, a);
  }

public:
  LinkedList() : first(nullptr), n(0) {}

  LinkedList(const LinkedList&) = delete;
  LinkedList& operator=(const LinkedList&) = delete;

  bool insert(T value) override {
    Node<T, LessFunc>* newNode = new Node<T, LessFunc>;
    newNode->value = value;
    newNode->next = nullptr;

    Node<T, LessFunc>* ptrAnt = nullptr;
    Node<T, LessFunc>* ptrAtual = first;
    while (ptrAtual != nullptr && Less(ptrAtual->value, value)) {
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

  bool remove(T value) override {
    Node<T, LessFunc>* ptrAtual = first;
    Node<T, LessFunc>* ptrAnterior = nullptr;
    while (ptrAtual && Less(ptrAtual->value, value)) {
      ptrAnterior = ptrAtual;
      ptrAtual = ptrAtual->next;
    }

    if (!ptrAtual || DiffFunc(ptrAtual->value, value))
      return false;

    if (ptrAnterior)
      ptrAnterior->next = ptrAtual->next;
    else
      first = ptrAtual->next;

    delete ptrAtual;
    n--;

    return true;
  }

  /// Retorna o elemento equivalente a value; ok indica se ele foi encontrado.
  T search(T value, bool* ok = nullptr) override {
    Node<T, LessFunc>* ptrAtual = first;
    while (ptrAtual && Less(ptrAtual->value, value)) {
      ptrAtual = ptrAtual->next;
    }

    bool encontrado = ptrAtual && !DiffFunc(ptrAtual->value, value);
    if (ok)
      *ok = encontrado;

    return encontrado ? ptrAtual->value : T{};
  }

  T getAtIndex(int index) override {
    Node<T, LessFunc>* tmp = first;
    for (int i = 0; tmp != nullptr && i < index; i++) {
      tmp = tmp->next;
    }
    return (tmp != nullptr) ? tmp->value : T{};
  }

  virtual void print() {
    for (Node<T, LessFunc>* tmp = first; tmp; tmp = tmp->next) {
      cout << tmp->value << " ";
    }
    cout << endl;
  }

  unsigned int getSize() override {
    return n;
  }

  /// Remove todos os elementos.
  void clear() {
    Node<T, LessFunc>* tmp = first;
    while (tmp) {
      Node<T, LessFunc>* tmpNext = tmp->next;
      delete tmp;
      tmp = tmpNext;
    }
    first = nullptr;
    n = 0;
  }

  ~LinkedList() {
    clear();
  }
};
