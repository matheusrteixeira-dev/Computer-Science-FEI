/**
 * @file    main.cpp
 * @brief   Dicionário por tabela hash com encadeamento separado (listas encadeadas ordenadas).
 * @note    Baseado em código-base fornecido pelo professor da disciplina (TADs, lde.hpp e main);
 *          o exercício consistia em implementar a classe HashDictionary.
 */
#include <functional>
#include <iostream>
#include <ostream>
#include <string>

#include "lde.hpp"

using namespace std;

template <typename K, typename V>
struct KeyValue {
  K key;
  V value;
};

/// Compara pares apenas pela chave.
template <typename K, typename V>
struct KeyValueComp {
  bool operator()(KeyValue<K, V> a, KeyValue<K, V> b) {
    return a.key < b.key;
  }
};

template <typename K, typename V>
ostream& operator<<(ostream& out, const KeyValue<K, V>& p) {
  out << p.key << ":" << p.value;
  return out;
}

template <typename K, typename V>
class Dictionary {
public:
  virtual bool insert(KeyValue<K, V> item) = 0;
  virtual bool remove(K key) = 0;
  virtual V search(K key, bool* ok = nullptr) = 0;
  virtual int getSize() = 0;
  virtual void clear() = 0;
  virtual ~Dictionary() {}
};

template <typename K>
struct DefaultHashFunc {
  unsigned long long int operator()(K key) {
    return key;
  }
};

template <typename K, typename V, int MAX = 10, typename HashFunc = DefaultHashFunc<K>>
class HashDictionary : public Dictionary<K, V> {
private:
  LinkedList<KeyValue<K, V>, KeyValueComp<K, V>> ldes[MAX];
  HashFunc hashFunc;
  int n = 0;

  /// Índice do balde (lista) correspondente à chave.
  int hash(K key) {
    return static_cast<int>(hashFunc(key) % MAX);
  }

public:
  HashDictionary() {}

  /// Insere o par; se a chave já existir, o valor é atualizado.
  bool insert(KeyValue<K, V> item) override {
    LinkedList<KeyValue<K, V>, KeyValueComp<K, V>>& balde = ldes[hash(item.key)];

    if (balde.remove({item.key, V{}}))
      n--;

    if (!balde.insert(item))
      return false;

    n++;
    return true;
  }

  bool remove(K key) override {
    if (!ldes[hash(key)].remove({key, V{}}))
      return false;

    n--;
    return true;
  }

  V search(K key, bool* ok = nullptr) override {
    bool encontrado;
    KeyValue<K, V> obj = ldes[hash(key)].search({key, V{}}, &encontrado);

    if (ok)
      *ok = encontrado;
    return encontrado ? obj.value : V{};
  }

  int getSize() override {
    return n;
  }

  void clear() override {
    for (int i = 0; i < MAX; i++) {
      ldes[i].clear();
    }
    n = 0;
  }
};

int main() {
  // Main fornecido pelo enunciado.
  HashDictionary<int, string> h;
  h.insert({76, "sponsored"});
  h.insert({52, "technology"});
  h.insert({27, "transfer"});
  h.insert({26, "projects"});
  h.insert({71, "developing"});
  h.insert({38, "country"});
  h.insert({77, "context"});
  h.insert({18, "Journal"});
  h.insert({13, "Technology"});
  h.insert({78, "Transfer"});
  h.insert({55, "Technology"});
  h.insert({60, "transfer"});
  h.insert({52, "effective"});
  h.insert({31, "mechanism"});
  h.insert({65, "advance"});
  h.insert({17, "technological"});
  h.insert({55, "development"});
  h.insert({99, "developing"});
  h.insert({90, "country's"});
  h.insert({99, "economy."});
  h.insert({3, "Though"});

  bool ok;
  for (int chave : {90, 3, 60, 20, 18}) {
    cout << h.search(chave, &ok) << endl;
    cout << (ok ? "encontrou" : "nao encontrou") << endl << endl;
  }

  cout << (h.remove(18) ? "removeu" : "nao removeu") << endl;

  cout << h.search(18, &ok) << endl;
  cout << (ok ? "encontrou" : "nao encontrou") << endl << endl;

  return 0;
}
