/**
 * @file    main.cpp
 * @brief   Lista Dinâmica Sequencial (LDS) ordenada e redimensionável, genérica (template).
 * @note    Baseado em código-base fornecido pelo professor da disciplina (TADs e main);
 *          o exercício consistia em implementar os métodos da classe LDS.
 */

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// Tipo abstrato de dados
template <typename T>
class AbstractOrderedList {
public:
  AbstractOrderedList() {
  }

  virtual bool insert(T value) = 0;
  virtual bool remove(T value) = 0;
  virtual bool search(T value) = 0;
  virtual T getAtIndex(unsigned int index) = 0;
  virtual unsigned int getSize() = 0;

  virtual void print() {
    for (unsigned int i = 0; i < getSize(); ++i) {
      cout << getAtIndex(i) << " ";
    }
    cout << endl;
  }


  virtual ~AbstractOrderedList() {
  }
};

template <typename T>
class AbstractResizableOrderedList : public AbstractOrderedList<T> {
public:
  // redimensiona a estrutura de modo que capacity=size
  virtual void shrink_to_fit() = 0;
  // redimensiona estrutura para novo newCapacity
  virtual bool resize(unsigned int newCapacity) = 0;
  virtual unsigned int capacity() = 0;


  virtual ~AbstractResizableOrderedList() {
  }
};


template <typename T>
class LDS : public AbstractResizableOrderedList<T> {
private:
  T* v;
  unsigned int cap;
  unsigned int size;

public:
  LDS() : v(new T[10]), cap(10), size(0) {}

  LDS(const LDS&) = delete;
  LDS& operator=(const LDS&) = delete;

  /// Insere mantendo a ordem crescente, dobrando a capacidade quando necessário.
  bool insert(T value) override {
    if (size == cap) {
      if (!this->resize(cap == 0 ? 1 : 2 * cap)) {
        return false;
      }
    }

    unsigned int i;
    for (i = 0; i < size && v[i] < value; i++)
      ;

    for (unsigned int j = size; j > i; j--) {
      v[j] = v[j - 1];
    }

    v[i] = value;
    size++;
    return true;
  }

  /// Realoca a área de armazenamento; se newCap < size, os últimos elementos são descartados.
  bool resize(unsigned int newCap) override {
    T* newV = new T[newCap];

    size = (size > newCap) ? newCap : size;
    for (unsigned int i = 0; i < size; i++) {
      newV[i] = v[i];
    }

    delete[] v;
    v = newV;
    cap = newCap;
    return true;
  }

  void shrink_to_fit() override {
    resize(size);
  }

  unsigned int capacity() override {
    return cap;
  }

  unsigned int getSize() override {
    return size;
  }

  T getAtIndex(unsigned int index) override {
    if (index >= size)
      throw std::out_of_range("indice fora dos limites da lista");
    return v[index];
  }

  bool search(T value) override {
    for (unsigned int i = 0; i < size; i++) {
      if (v[i] == value)
        return true;
    }
    return false;
  }

  bool remove(T value) override {
    for (unsigned int i = 0; i < size; i++) {
      if (v[i] == value) {
        for (unsigned int j = i; j + 1 < size; j++) {
          v[j] = v[j + 1];
        }
        size--;
        return true;
      }
    }
    return false;
  }

  void print() override {
    for (unsigned int i = 0; i < size; i++) {
      cout << v[i] << endl;
    }
  }

  ~LDS() {
    delete[] v;
  }
};

int main() {
  LDS<string> l;
  l.insert("babbs");
  l.insert("coldren");
  l.insert("highinterest");
  l.insert("loney");
  l.insert("bangwe");
  l.insert("datagrams");
  l.insert("needers");
  l.insert("proboscidial");
  l.insert("pighead");
  l.insert("warfel");
  l.insert("verbed");
  l.insert("cyprinidae");
  l.insert("dalmard");
  l.insert("unhumbled");
  l.insert("belinuridae");
  l.insert("malibu");
  l.insert("tuitionary");
  l.insert("pushball");
  l.insert("gatehouse");
  l.insert("goodsprings");
  l.insert("disillusion");
  l.insert("bidkar");
  l.insert("misumalpan");
  l.insert("nonadecane");
  l.insert("nahor");
  l.insert("bimahs");
  l.insert("cade");
  l.insert("mbwisi");
  l.insert("urfirnis");
  l.print();
  cout << "capacity: " << l.capacity() << endl;
  cout << "size: " << l.getSize() << endl;
  cout << "====================" << endl;
  l.resize(5);
  l.insert("jubilee");
  l.print();
  cout << "capacity: " << l.capacity() << endl;
  cout << "size: " << l.getSize() << endl;
  cout << "====================" << endl;
  l.shrink_to_fit();
  l.print();
  cout << "capacity: " << l.capacity() << endl;
  cout << "size: " << l.getSize() << endl;
  cout << "====================" << endl;
  cout << (l.remove("pighead") ? "removeu pighead" : "nao removeu pighead") << endl;
  cout << (l.remove("babbs") ? "removeu babbs" : "nao removeu babbs") << endl;
  cout << (l.remove("jubilee") ? "removeu jubilee" : "nao removeu jubilee") << endl;
  l.print();
  cout << "capacity: " << l.capacity() << endl;
  cout << "size: " << l.getSize() << endl;
  cout << "====================" << endl;
  l.insert("nonadecane");
  l.insert("nahor");
  l.insert("bimahs");
  l.insert("cade");
  l.insert("mbwisi");
  l.print();
  cout << "capacity: " << l.capacity() << endl;
  cout << "size: " << l.getSize() << endl;
  cout << "====================" << endl;

  return 0;
}
