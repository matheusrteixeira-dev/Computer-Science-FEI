/**
 * @file    main.cpp
 * @brief   Árvore binária de busca (BST): inserção, busca, remoção e percurso em ordem.
 * @note    Baseado em código-base fornecido pelo professor da disciplina (inserção, busca e main);
 *          o exercício consistia em implementar a remoção de um nó.
 */
#include <iostream>

using namespace std;

template <typename T>
class Tree;

template <typename T>
class Node {
private:
  Node<T>* father;
  Node<T>* left;
  Node<T>* right;
  T value;

public:
  T getValue() {
    return value;
  }
  Node() : father(nullptr), left(nullptr), right(nullptr), value(T{}) {}
  explicit Node(T value) : father(nullptr), left(nullptr), right(nullptr), value(value) {}

  friend class Tree<T>;
};

template <typename T>
class Tree {
private:
  Node<T>* root;
  int n;

  void print(Node<T>* x) {
    if (!x)
      return;

    print(x->left);
    cout << x->value << "\n";
    print(x->right);
  }

  void deleteSubTree(Node<T>* r) {
    if (!r)
      return;

    deleteSubTree(r->left);
    deleteSubTree(r->right);
    delete r;
  }

  /// Quantidade de filhos do nó (0, 1 ou 2).
  int child(Node<T>* node) {
    return (node->left != nullptr) + (node->right != nullptr);
  }

  /// Ponteiro, no pai, que aponta para o nó (ou para root, se o nó for a raiz).
  Node<T>** linkFromParent(Node<T>* node) {
    if (!node->father)
      return &root;
    return (node->father->left == node) ? &node->father->left : &node->father->right;
  }

  /// Menor nó da subárvore direita.
  Node<T>* sucessor(Node<T>* node) {
    node = node->right;
    while (node->left) {
      node = node->left;
    }
    return node;
  }

  bool remove(Node<T>* node) {
    if (!node)
      return false;

    if (child(node) == 2) {
      // Copia o valor do sucessor e remove o sucessor, que tem no máximo um filho.
      Node<T>* s = sucessor(node);
      node->value = s->value;
      return remove(s);
    }

    // Nó com zero ou um filho: o filho (se existir) ocupa o lugar do nó.
    Node<T>* filho = node->left ? node->left : node->right;
    if (filho)
      filho->father = node->father;
    *linkFromParent(node) = filho;

    delete node;
    n--;
    return true;
  }

public:
  Tree() : root(nullptr), n(0) {}

  Tree(const Tree&) = delete;
  Tree& operator=(const Tree&) = delete;

  bool insert(T value) {
    Node<T>* novo = new Node<T>(value);

    if (!root) {
      root = novo;
      n++;
      return true;
    }

    Node<T>* atual = root;
    Node<T>* anterior = nullptr;

    while (atual) {
      anterior = atual;
      atual = (value <= atual->value) ? atual->left : atual->right;
    }

    novo->father = anterior;
    if (value <= anterior->value)
      anterior->left = novo;
    else
      anterior->right = novo;

    n++;
    return true;
  }

  Node<T>* search(T value) {
    Node<T>* atual = root;
    while (atual) {
      if (value < atual->value)
        atual = atual->left;
      else if (value > atual->value)
        atual = atual->right;
      else
        return atual;
    }
    return nullptr;
  }

  void print() {
    print(root);
  }

  bool remove(T value) {
    return remove(search(value));
  }

  ~Tree() {
    deleteSubTree(root);
  }
};

int main() {
  Tree<int> v;
  for (int valor : {315, 25, 325, 962, 687, 778, 695, 245, 299, 135, 50, 307, 640}) {
    v.insert(valor);
  }
  cout << "=====================================" << endl;
  v.print();

  for (int valor : {564, 222, 913, 105, 279, 45, 826, 75, 495, 962, 913}) {
    v.insert(valor);
  }
  v.remove(315);
  cout << "=====================================" << endl;
  v.print();

  for (int valor : {25, 325, 962, 687, 778, 695, 245, 299, 135, 50, 307}) {
    v.remove(valor);
  }
  cout << "=====================================" << endl;
  v.print();

  for (int valor : {640, 564, 222, 913, 105, 279, 45, 826, 75, 495, 962, 913}) {
    v.remove(valor);
  }
  cout << "=====================================" << endl;
  v.print();

  return 0;
}
