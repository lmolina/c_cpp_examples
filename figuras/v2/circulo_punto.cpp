#include <iostream>
using std::cout;
using std::endl;

#include "punto.h"
#include "circulo.h"

int main() {
  Punto mi_punto(1, 2), * ptrPunto[2];
  Circulo mi_circulo(3, 4, 5.5);

  mi_punto.imprimir();
  mi_circulo.imprimir();

  ptrPunto[0] = & mi_punto;
  ptrPunto[1] = & mi_circulo;

  for(int i = 0; i < 2; ++i)
    ptrPunto[i]->imprimir();

  return 0;
}
