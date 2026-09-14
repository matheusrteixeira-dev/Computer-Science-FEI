/**
 * @file    Formas.cpp
 * @brief   Polimorfismo em C++: cálculo de área de formas geométricas via método virtual.
 */
#include <cmath>
#include <iostream>

using namespace std;

const double PI = acos(-1.0);

/// Classe base: toda forma sabe calcular a própria área.
class Forma {
public:
  virtual double area() const = 0;
  virtual ~Forma() = default;
};

class Retangulo : public Forma {
private:
  double largura;
  double altura;

public:
  Retangulo(double largura, double altura) : largura(largura), altura(altura) {}

  double area() const override {
    return largura * altura;
  }
};

class Triangulo : public Forma {
private:
  double base;
  double altura;

public:
  Triangulo(double base, double altura) : base(base), altura(altura) {}

  double area() const override {
    return base * altura / 2;
  }
};

class Circulo : public Forma {
private:
  double raio;

public:
  explicit Circulo(double raio) : raio(raio) {}

  double area() const override {
    return PI * raio * raio;
  }
};

/// Imprime a área de qualquer forma (despacho dinâmico pelo ponteiro para a classe base).
void calculaArea(const Forma* f) {
  cout << "Area = " << f->area() << endl;
}

int main() {
  Retangulo r1(10.2, 20);
  Triangulo t1(20.6, 3.1);
  Circulo c1(30.2);

  calculaArea(&r1);
  calculaArea(&t1);
  calculaArea(&c1);

  return 0;
}
