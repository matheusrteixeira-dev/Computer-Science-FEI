/**
 * @file    grafos.cpp
 * @brief   Grafo não direcionado com lista de adjacência e busca em largura (BFS).
 * @note    Baseado em código-base fornecido pelo professor da disciplina.
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/// Grafo não direcionado representado por listas de adjacência.
class Grafo {
private:
  vector<vector<int>> v;

public:
  explicit Grafo(int N) { v.assign(N, vector<int>()); }

  /// Retorna os vizinhos do vértice @p x.
  const vector<int> &getNeighbors(int x) const { return v[x]; }

  int getNumNodes() const { return static_cast<int>(v.size()); }

  /// Adiciona a aresta (f, t) nos dois sentidos.
  void addEdge(int f, int t) {
    v[f].push_back(t);
    v[t].push_back(f);
  }

  /// Remove a aresta (f, t) nos dois sentidos.
  void removeEdge(int f, int t) {
    v[f].erase(remove(v[f].begin(), v[f].end(), t), v[f].end());
    v[t].erase(remove(v[t].begin(), v[t].end(), f), v[t].end());
  }
};

/// Busca em largura: calcula a distância (em arestas) e o pai de cada vértice.
class BFS {
private:
  Grafo g;
  vector<int> dist;
  vector<int> pai;

public:
  explicit BFS(const Grafo &g) : g(g) {
    dist.assign(g.getNumNodes(), -1);
    pai.assign(g.getNumNodes(), -1);
  }

  /// Executa a BFS a partir do vértice @p start.
  void run(int start) {
    queue<int> fila;
    fila.push(start);
    dist[start] = 0;
    while (!fila.empty()) {
      int atual = fila.front();
      fila.pop();
      for (const auto &viz : g.getNeighbors(atual)) {
        if (dist[viz] == -1) {
          pai[viz] = atual;
          dist[viz] = dist[atual] + 1;
          fila.push(viz);
        }
      }
    }
  }

  void imprime() const {
    cout << "Distancias: ";
    for (const auto &e : dist) {
      cout << e << " ";
    }
    cout << endl << "Pais: ";
    for (const auto &e : pai) {
      cout << e << " ";
    }
    cout << endl;
  }
};

int main() {
  Grafo g(9);
  g.addEdge(0, 1);
  g.addEdge(0, 3);
  g.addEdge(0, 4);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.addEdge(4, 5);
  g.addEdge(3, 5);
  g.addEdge(3, 8);
  g.addEdge(4, 6);
  g.addEdge(4, 7);
  g.addEdge(5, 7);
  g.addEdge(6, 7);

  BFS bfs(g);
  bfs.run(0);
  bfs.imprime();

  return 0;
}
