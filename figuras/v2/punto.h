#ifndef PUNTO_H
#define PUNTO_H

#include <iostream>
using namespace std;

class Punto {
 public:
  Punto(int=0, int=0);
  ~Punto();
  int x() const; 
  int y() const;
  void x(int);
  void y(int);
  virtual void imprimir() const;

  // Comparacion
  bool igual(const Punto &) const;
  bool operator==(const Punto &) const;

  void operator=(const Punto &);

  Punto suma(const Punto &) const;
  Punto operator+(const Punto &) const;

  // Ambos operadores son llamados operator++, la diferencia esta en el
  // prototipo. La version prefija no recibe parametros
  Punto &operator++();

  // ... la version postfija recibe un parametro entero no utilizado (dummy)
  Punto operator++(int);
 private:
  int x_;
  int y_;
};

#endif
