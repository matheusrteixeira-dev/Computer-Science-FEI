/**
 * @file    main.cpp
 * @brief   Árvore binária de busca com percurso em ordem sem recursão e sem pilha (Morris traversal).
 * @note    Baseado em código-base fornecido pelo professor da disciplina (inserção, busca e main);
 *          o exercício consistia em implementar a impressão em ordem com memória auxiliar O(1).
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

  void deleteSubTree(Node<T>* r) {
    if (!r)
      return;

    deleteSubTree(r->left);
    deleteSubTree(r->right);
    delete r;
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

  /**
   * Imprime em ordem usando o percurso de Morris: cria ligações temporárias do predecessor
   * de cada nó para o próprio nó, permitindo voltar sem pilha; as ligações são desfeitas
   * na segunda visita, de modo que a árvore termina inalterada.
   */
  void print() {
    Node<T>* current = root;

    while (current != nullptr) {
      if (current->left == nullptr) {
        cout << current->value << "\n";
        current = current->right;
        continue;
      }

      // Predecessor em ordem: nó mais à direita da subárvore esquerda.
      Node<T>* pre = current->left;
      while (pre->right != nullptr && pre->right != current)
        pre = pre->right;

      if (pre->right == nullptr) {
        pre->right = current; // cria a ligação temporária
        current = current->left;
      } else {
        pre->right = nullptr; // desfaz a ligação temporária
        cout << current->value << "\n";
        current = current->right;
      }
    }
  }

  ~Tree() {
    deleteSubTree(root);
  }
};

int main() {
  Tree<int> v;
  for (int valor : {315, 25, 325, 962, 687, 778, 695, 245, 299, 135, 50, 307,
                    640, 564, 222, 913, 105, 279, 45, 826, 75, 495, 962, 913}) {
    v.insert(valor);
  }

  v.print();

  return 0;
}
